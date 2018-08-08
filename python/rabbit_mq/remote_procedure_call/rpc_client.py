import pika
import uuid

class FibonacciRpcClient(object):
    def __init__(self):
        # establish a connection, channel and declare an exclusive 'callback' queue for replies
        self.connection = pika.BlockingConnection(pika.ConnectionParameters('localhost'))

        self.channel = self.connection.channel()

        result = self.channel.queue_declare(exclusive=True)
        self.callback_queue = result.method.queue

        # subscribe to the callback_queue: receive RPC response
        self.channel.basic_consume(self.on_response, no_ack=True, queue = self.callback_queue)

    # callback for every res: IF the correlation_id is the one we're looking for -> saves the response in self. response and breaks the consuming loop.
    def on_response(self, ch, method, props, body):
        if self.corr_id == props.correlation_id:
            self.response = body

    # RPC request
    def call(self, n):
        self.response = None
        self.corr_id = str(uuid.uuid4()) # generate a unique correlation_id. on_response callback will use this
        # publish request with reply_to: response queue, correlation_id: response id
        self.channel.basic_publish(exchange = '',
                                   routing_key = 'rpc_queue',
                                   properties = pika.BasicProperties(reply_to = self.callback_queue, correlation_id=self.corr_id),
                                   body = str(n))

        # wait response
        while self.response is None:
            self.connection.process_data_events()

        # return response
        return int(self.response)

fibonacci_rpc = FibonacciRpcClient()

print(" [x] Requesting fib(30)")
response = fibonacci_rpc.call(30)
print(" [.] God %r" % response)

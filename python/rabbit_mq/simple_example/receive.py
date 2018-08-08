import pika

connection = pika.BlockingConnection(pika.ConnectionParameters('localhost'))
channel = connection.channel()

channel.queue_declare(queue='msg_queue')

def callback(ch, method, properties, body):
    print("[x] Received %r" % body)

channel.basic_consume(callback, queue='msg_queue', no_ack=True)

print('[*] Waiting for message. To exit press CTRL+C')
channel.start_consuming();

import pika
import time

connection = pika.BlockingConnection(pika.ConnectionParameters('localhost'))
channel = connection.channel()

# durable=True: make queue durable even if RabbitMQ server stop
channel.queue_declare(queue='task_queue', durable=True)

def callback(ch, method, porperties, body):
    print("[x] Received %r" % body)
    time.sleep(body.count(b'.'))
    print("[x] Done")
    # make msg never lost - if a worker dies, the task to be delivered to another worker
    ch.basic_ack(delivery_tag = method.delivery_tag)

# fair dispatch
channel.basic_qos(prefetch_count=1)

channel.basic_consume(callback, queue='task_queue')

print('[*] Waiting for message. To exit press CTRL+C')
channel.start_consuming();

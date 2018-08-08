import pika

connection = pika.BlockingConnection(pika.ConnectionParameters('localhost'))
channel = connection.channel()

channel.queue_declare(queue='msg_queue')

channel.basic_publish(exchange='',
                      routing_key='msg_queue',
                      body='Simple Message')

print("[x] Sent 'Simple Message!'")

connection.close()

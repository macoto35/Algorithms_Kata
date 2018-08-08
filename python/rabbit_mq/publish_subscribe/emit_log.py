import pika
import sys

connection = pika.BlockingConnection(pika.ConnectionParameters('localhost'))
channel = connection.channel()

# exchange_type = fanout: broadcasts all the msgs to all the queues that exchange knows
channel.exchange_declare(exchange='logs', type='fanout')

message = ' '.join(sys.argv[1:]) or 'Info: default message!'
channel.basic_publish(exchange = 'logs',
                      routing_key = '',
                      body = message,
                      properties = pika.BasicProperties(
                        delivery_mode = 2
                      ))
print("[x] Sent %r" % message);
connection.close()

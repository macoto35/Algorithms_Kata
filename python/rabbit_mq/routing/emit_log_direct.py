import pika
import sys

connection = pika.BlockingConnection(pika.ConnectionParameters('localhost'))
channel = connection.channel()

# type = direct: A message goes to the queues whose binding key exactly matches the routing key of the message
channel.exchange_declare(exchange='direct_logs', type='direct')

severity = sys.argv[1] if len(sys.argv) > 2 else 'info'
message = ' '.join(sys.argv[2:]) or 'info log message!'
channel.basic_publish(exchange = 'direct_logs',
                      routing_key = severity,
                      body = message)

print("[x] Sent %r:%r" % (severity, message))
connection.close()

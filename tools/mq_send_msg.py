import pika
import sys

credentials = pika.PlainCredentials('name', 'pwd')
connection = pika.BlockingConnection(pika.ConnectionParameters('jjserver', 5672, 'vhost', credentials))
channel = connection.channel()
channel.exchange_declare(exchange='exchange', exchange_type='direct', durable=True)

message = '{"account": "1",  "server_id" : "testserver", "lang" : "Cantonese"}'

channel.basic_publish(exchange='exchange',
        routing_key='player_login',
        body=message)
print "sent"
print message
connection.close()

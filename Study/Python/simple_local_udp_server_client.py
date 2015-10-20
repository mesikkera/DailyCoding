# -*- coding: utf-8 -*-
# 가나다라

# UDP Client and Server on localhost in windows 7

import socket, sys

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

MAX_PORT_NUMBER = 65535
USE_PORT = 1010

if sys.argv[1:] == ['server']:
	s.bind(('127.0.0.1', USE_PORT))
	print "Listening at ", s.getsockname()
	while True:
		data, address = s.recvfrom(MAX_PORT_NUMBER)
		print "The Client at", address, 'says', repr(data)
		s.sendto('Your data wad %d bytes' % len(data), address)

elif sys.argv[1:] == ['client']:
	print 'Address before sending: ', s.getsockname()
	s.sendto('This is my message', ('127.0.0.1', USE_PORT))
	print 'Address after sending', s.getsockname()
	data, address = s.recvfrom(MAX_PORT_NUMBER)
	print 'The Server', address, 'says', repr(data)

else:
	print >> sys.stderr, 'usage: simple_local_udp_server_client.py server | client'
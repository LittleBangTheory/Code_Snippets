# Description: Envoi d'un mail avec Python

import smtplib, ssl
import sys
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart

# PARAMETRES A RENSEIGNER
# Serveur SMTP
# Pour Gmail : 'smtp.gmail.com'
# Pour Outlook : 'smtp-mail.outlook.com'
smtp_server = ''
# Port SMTP
port = 587
# Expéditeur
sender = ''
# Mot de passe
password = ''
# Destinataire (peut être une liste)
recipient = ''

message = MIMEMultipart('alternative')

# En-têtes du mail
message['Subject'] = ''
message['From'] = sender
message['To'] = ", ".join(recipient)

# Variables à ajouter dans le mail
var1 = ''
var2 = ''

email_html = """\
Objet du mail<br>
-----------------------------<br>
Info 1 : {0}<br>
Info 2 : {1}<br>
Site web : <a href="https://google.com">Google</a>.<br>
""".format(var1, var2)

# Formatage du mail
mimetext_html = MIMEText(email_html, "html")
message.attach(mimetext_html)
context = ssl.create_default_context()

# Envoi du mail
server = smtplib.SMTP(smtp_server, port)
server.starttls(context=context)
server.login(sender, password)
server.sendmail(sender, recipient, message.as_string())
server.quit()

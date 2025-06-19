import os
from email.message import EmailMessage
import smtplib
from dotenv import load_dotenv

# Carica variabili d'ambiente dal file .env
load_dotenv()

EMAIL_ADDRESS = os.getenv("EMAIL_USER")
EMAIL_PASSWORD = os.getenv("EMAIL_PASS")

msg = EmailMessage()
msg['Subject'] = 'Test invio da Python'
msg['From'] = EMAIL_ADDRESS
msg['To'] = 'massimo.giaccone2@studio.unibo.it'
msg.set_content('Ciao! Questo è un messaggio automatico inviato con Python.')

# Connessione sicura SSL con Gmail
with smtplib.SMTP_SSL('smtp.gmail.com', 465) as smtp:
    smtp.login(EMAIL_ADDRESS, EMAIL_PASSWORD)
    smtp.send_message(msg)

print("Email inviata con successo.")

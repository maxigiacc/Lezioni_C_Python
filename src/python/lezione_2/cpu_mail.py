import psutil
import smtplib
from email.message import EmailMessage
import os
from dotenv import load_dotenv

load_dotenv()
EMAIL = os.getenv("EMAIL_USER")
PASS = os.getenv("EMAIL_PASS")
DEST = os.getenv("EMAIL_DEST")

def check_resources():
    cpu = psutil.cpu_percent(interval=1)
    mem = psutil.virtual_memory().percent
    disk = psutil.disk_usage('/').percent
    return cpu, mem, disk

cpu, mem, disk = check_resources()
threshold = 23

if cpu > threshold or mem > threshold or disk > threshold:
    msg = EmailMessage()
    msg.set_content(f"🚨 Alert Risorse: CPU {cpu}%, RAM {mem}%, DISCO {disk}%")
    msg['Subject'] = 'Allarme sistema'
    msg['From'] = EMAIL
    msg['To'] = DEST

    with smtplib.SMTP_SSL('smtp.gmail.com', 465) as smtp:
        smtp.login(EMAIL, PASS)
        smtp.send_message(msg)

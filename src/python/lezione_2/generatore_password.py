import random
import string

def genera_password(lunghezza):
    caratteri = string.ascii_letters + string.digits + string.punctuation
    password = ''.join(random.choice(caratteri) for i in range(lunghezza))
    return password

password = genera_password(12)
print(f"Password generata: {password}")
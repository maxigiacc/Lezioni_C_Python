import json
from datetime import datetime

# Creazione struttura dati complessa
configurazione = {
    "applicazione": {
        "nome": "Sistema di Gestione",
        "versione": "2.1.0",
        "debug": False
    },
    "database": {
        "host": "localhost",
        "porta": 5432,
        "nome": "gestionale",
        "ssl": True
    },
    "utenti_autorizzati": ["admin", "operatore", "viewer"],
    "configurazione_email": {
        "server_smtp": "smtp.gmail.com",
        "porta": 587,
        "usa_tls": True
    },
    "ultimo_aggiornamento": datetime.now().isoformat()
}

# Scrittura con formattazione elegante
with open("./configurazione.json", "w", encoding="utf-8") as f:
    json.dump(configurazione, f, indent=2, ensure_ascii=False)

print("File di configurazione creato con successo!")

# Serializzazione in stringa
config_string = json.dumps(configurazione, indent=2, ensure_ascii=False)
print("Configurazione serializzata:")
print(config_string[:200] + "...")
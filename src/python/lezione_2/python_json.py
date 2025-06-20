import json

# Lettura da file
with open("./dati.json", "r", encoding="utf-8") as f:
    profilo = json.load(f)
    
print(f"Nome: {profilo['nome']} {profilo['cognome']}")
print(f"Città: {profilo['indirizzo']['città']}")
print(f"Linguaggi conosciuti: {len(profilo['linguaggi'])}")

# Iterazione sui progetti
for progetto in profilo['progetti']:
    status = "✅" if progetto['completato'] else "⏳"
    print(f"{status} {progetto['nome']} ({progetto['linguaggio']})")

# Lettura da stringa JSON
json_string = '{"temperatura": 23.5, "umidità": 65}'
dati_sensore = json.loads(json_string)
print(f"Temperatura: {dati_sensore['temperatura']}°C")
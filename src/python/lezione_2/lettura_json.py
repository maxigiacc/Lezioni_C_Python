import json

# Leggere da file
with open("./dati.json", "r", encoding="utf-8") as f:
    profilo = json.load(f)

print(f"Nome: {profilo['nome']} {profilo['cognome']}")
print(f"Città: {profilo['indirizzo']['città']}")
print(f"Linguaggi conosciuti: {len(profilo['linguaggi'])}")

progetti = profilo['progetti']

for progetto in progetti:
    if progetto['completato'] is True:
        status = "Completato"
    else:
        status = "In corso"
    print(f"{progetto['nome']}, {progetto['linguaggio']},  status: {status}")
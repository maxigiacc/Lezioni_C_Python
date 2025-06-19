import requests

def converti_valuta(importo, da_valuta, a_valuta):
    url = f"https://api.exchangerate-api.com/v4/latest/{da_valuta}"
    risposta = requests.get(url)
    dati = risposta.json()
    tasso = dati['rates'][a_valuta]
    return importo * tasso

valore = float(input("Inserisci il valore da convertire: "))
importo_convertito = converti_valuta(valore, 'EUR', 'USD')
print(f"{valore:.2f} EUR equivalgono a {importo_convertito:.2f} USD")
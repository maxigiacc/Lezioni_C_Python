import requests

def verifica_sito(url):
    try:
        risposta = requests.get(url)
        if risposta.status_code == 200:
            print(f"{url} è raggiungibile.")
        else:
            print(f"{url} ha risposto con lo stato {risposta.status_code}.")
    except requests.RequestException as e:
        print(f"Errore nel raggiungere {url}: {e}")

while(1): verifica_sito("https://www.google.com/maps")
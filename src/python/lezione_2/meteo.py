import requests
import json

def ottieni_dati_meteo(città):
    url = f"http://api.openweathermap.org/data/2.5/weather"
    params = {
        "q": città,
        "appid": "your_api_key",
        "units": "metric",
        "lang": "it"
    }
    
    response = requests.get(url, params=params)
    if response.status_code == 200:
        dati = response.json()  # Parsing automatico JSON
        return {
            "città": dati["name"],
            "temperatura": dati["main"]["temp"],
            "descrizione": dati["weather"][0]["description"],
            "umidità": dati["main"]["humidity"]
        }
    else:
        return None

# Salva i dati in formato JSON locale
citta = input("Inserisci la città di cui vuoi sapere il meteo: ")
meteo = ottieni_dati_meteo(citta)
if meteo:
    with open("meteo_corrente.json", "w") as f:
        json.dump(meteo, f, indent=2)
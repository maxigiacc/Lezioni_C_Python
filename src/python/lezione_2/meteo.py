import requests
from datetime import date

def get_coords(city: str):
    """Ottiene latitudine e longitudine da nome città."""
    r = requests.get(
        "https://geocoding-api.open-meteo.com/v1/search",
        params={"name": city}
    )
    r.raise_for_status()
    data = r.json()
    first = data.get("results", [])[0]
    return first["latitude"], first["longitude"]

def get_weather(lat: float, lon: float, days: int = 7):
    """Ottiene meteo corrente e previsioni orarie per n giorni."""
    params = {
        "latitude": lat,
        "longitude": lon,
        "current_weather": True,
        "hourly": "temperature_2m,relative_humidity_2m,wind_speed_10m",
        "forecast_days": days,
        "timezone": "auto"
    }
    r = requests.get("https://api.open-meteo.com/v1/forecast", params=params)
    r.raise_for_status()
    return r.json()

def main():
    city = input("Inserisci nome città (es. Venezia): ")
    lat, lon = get_coords(city)
    print(f"Città: {city}, lat: {lat}, lon: {lon}\n")

    data = get_weather(lat, lon, days=3)
    curr = data["current_weather"]
    print("🔹 Meteo corrente:")
    print(f"  Ora: {curr['time']}")
    print(f"  Temperatura: {curr['temperature']} °C")
    print(f"  Vento: {curr['windspeed']} km/h\n")

    print(f"🔹 Previsioni orarie prossimi giorni:")
    for t, temp, hum, wind in zip(
        data["hourly"]["time"],
        data["hourly"]["temperature_2m"],
        data["hourly"]["relative_humidity_2m"],
        data["hourly"]["wind_speed_10m"]
    ):
        print(f"{t}: {temp} °C, umidità {hum}%, vento {wind} km/h")

if __name__ == "__main__":
    main()

# Input: temperatura in Fahrenheit
fahrenheit = float(input("Inserisci la temperatura in gradi Fahrenheit: "))

# Conversione
celsius = (5 / 9) * (fahrenheit - 32)

# Output
print(f"{fahrenheit} gradi Fahrenheit corrispondono a {celsius:.2f} gradi Celsius")

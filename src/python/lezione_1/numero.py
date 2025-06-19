# Richiesta input all'utente
numero = int(input("Inserisci un numero intero: "))

# Calcoli
precedente = numero - 1
successivo = numero + 1
doppio = numero * 2
elevato = numero ** 2

# Output dei risultati
print(f"Il numero precedente è: {precedente}")
print(f"Il numero successivo è: {successivo}")
print(f"Il doppio del numero è: {doppio}")
print("L'elevato del numero è: " + str(elevato))

# Inizializzazione variabili
positivi = 0
negativi = 0
pari = 0
dispari = 0
totale = 0

# Input: numero di elementi
n = int(input("Quanti numeri vuoi inserire? "))

# Ciclo di inserimento e controllo
for i in range(n):
    numero = int(input(f"Inserisci il numero {i+1}: "))
    totale = totale + numero

    if numero > 0:
        positivi += 1
        if numero % 2 == 0:
            pari += 1
            print("Positivo e pari")
        else:
            dispari += 1
            print("Positivo e dispari")
    elif numero < 0:
        negativi += 1
        print("Numero negativo")
    else:
        print("È zero")

# Calcolo media
media = totale / n

# Output finale
print("\n--- Risultato ---")
print(f"Numeri positivi: {positivi}")
print(f"Numeri negativi: {negativi}")
print(f"Numeri pari: {pari}")
print(f"Totale: {totale}")
print(f"Media: {media:.2f}")

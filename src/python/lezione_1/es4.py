'''
Scrivi un programma che:

Chieda all’utente quanti numeri desidera inserire.
Per ciascun numero:
1. Se è positivo e pari, stampa "Positivo e pari".
2. Se è positivo e dispari, stampa "Positivo e dispari".
3. Se è zero, stampa "È zero".
4. Se è negativo, stampa "Numero negativo".

Al termine, stampa:
Il conteggio dei numeri positivi, negativi e pari.
Il totale e la media dei numeri inseriti.

'''

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
print(f"Numeri dispari: {dispari}")
print(f"Totale: {totale}")
print(f"Media: {media:.2f}")

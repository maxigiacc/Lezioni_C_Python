#include <stdio.h>
#include "funzione.h"

// Definizione della funzione fattoriale
int fattoriale(int n) {
    // Caso base: 0! = 1 e 1! = 1
    if (n == 0 || n == 1) {
        return 1;
    }
    
    // Calcolo iterativo del fattoriale
    int risultato = 1;
    for (int i = 2; i <= n; i++) {
        risultato *= i;
    }
    
    return risultato;
}

void stampa_risultato(int num, int ris) {
    printf("Il fattoriale di %d è: %d\n", num, ris);
}

void somma_indice(int* i) {
    *i++;
    //printf("\nSono qui: %d", i);
}
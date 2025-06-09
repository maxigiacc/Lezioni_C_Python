#include <stdlib.h>
#include <stdio.h>

int main () {

    // operatore address of
    int numero = 42;
    printf("Il valore di numero è: %d\n", numero);          // Stampa: 42
    printf("L'indirizzo di numero è: %p\n", &numero);       // Stampa: Indirizzo

    // operatore dereference
    int *puntatore = &numero;
    printf("Il puntatore contiene l'indirizzo: %p\n", puntatore);    // Indirizzo
    printf("All'indirizzo c'è il valore: %d\n", *puntatore);         // 42
    
    return 0;
}
#include <stdio.h>

// Passaggio per VALORE (copia)
void incrementa_copia(int x) {
    x = x + 1;
    printf("Dentro la funzione (copia): x = %d\n", x);
}

// Passaggio per RIFERIMENTO (puntatore)
void incrementa_originale(int *x) {
    *x = *x + 1;
    printf("Dentro la funzione (riferimento): *x = %d\n", *x);
}

int main() {
    int numero = 10;
    
    printf("Valore iniziale: %d\n", numero);
    
    // Test passaggio per valore
    incrementa_copia(numero);
    printf("Dopo passaggio per valore: %d\n", numero);  // Ancora 10!
    
    // Test passaggio per riferimento
    incrementa_originale(&numero);
    printf("Dopo passaggio per riferimento: %d\n", numero);  // Ora è 11!
    
    return 0;
}
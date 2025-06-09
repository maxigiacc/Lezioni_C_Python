#include <stdio.h>

int main() {
    // Passo 1: Creiamo una variabile normale
    int eta = 25;
    
    // Passo 2: Creiamo un puntatore che punti a 'eta'
    int *p_eta = &eta;
    
    // Passo 3: Visualizziamo tutto
    printf("Valore di eta: %d\n", eta);                    // 25
    printf("Indirizzo di eta: %p\n", &eta);                // es. 0x7fff5fbff6ac
    printf("Valore del puntatore p_eta: %p\n", p_eta);     // stesso indirizzo
    printf("Valore puntato da p_eta: %d\n", *p_eta);       // 25
    
    return 0;
}
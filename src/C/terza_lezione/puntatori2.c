#include <stdio.h>

int main() {
    int saldo_conto = 1000;
    int *ptr_saldo = &saldo_conto;
    
    printf("Saldo iniziale: %d euro\n", saldo_conto);
    
    // Modifica diretta
    saldo_conto = saldo_conto - 200;
    printf("Dopo spesa diretta: %d euro\n", saldo_conto);
    
    // Modifica tramite puntatore
    *ptr_saldo = *ptr_saldo + 500;
    printf("Dopo accredito tramite puntatore: %d euro\n", saldo_conto);
    
    return 0;
}
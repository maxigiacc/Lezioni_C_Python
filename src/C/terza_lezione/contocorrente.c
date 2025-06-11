#include <stdio.h>
#include <string.h>

typedef struct CC {
    char intestatario[50];
    char iban[35];
    float saldo;
    int numero_conto;
} ContoCorrente;

int main() {
    ContoCorrente conto1;
    ContoCorrente array [] = {conto1};
    ContoCorrente *ptr_conto = &conto1;
    
    // Metodo 1: Accesso tramite puntatore con ->
    strcpy(ptr_conto->intestatario, "Mario Rossi");
    strcpy(ptr_conto->iban, "IT60 X054 2811 XXXX XXXX XXXX 456");
    ptr_conto->saldo = 2500.75;
    ptr_conto->numero_conto = 123456789;
    
    // Metodo 2: Accesso tramite dereferenziazione (equivalente ma meno leggibile)
    printf("=== CONFRONTO METODI DI ACCESSO ===\n");
    printf("Con ->: %s\n", ptr_conto->intestatario);
    printf("Con (*ptr).campo: %s\n", (*ptr_conto).intestatario);
    printf("Sono identici!\n");
    
    // Visualizzazione completa
    printf("\n=== DETTAGLI CONTO ===\n");
    printf("Intestatario: %s\n", ptr_conto->intestatario);
    printf("IBAN: %s\n", ptr_conto->iban);
    printf("Saldo: %.2f euro\n", ptr_conto->saldo);
    printf("Numero conto: %d\n", ptr_conto->numero_conto);
    
    return 0;
}
#include <stdio.h>
#include <string.h>

typedef struct {
    char titolare[50];
    float saldo;
    int numero_transazioni;
} BankAccount;

// Funzione che riceve un PUNTATORE alla struct originale
void deposita(BankAccount *conto, float importo) {
    if (importo > 0) {
        conto->saldo += importo;
        conto->numero_transazioni++;
        printf("Depositati %.2f euro. Nuovo saldo: %.2f\n", 
               importo, conto->saldo);
    } else {
        printf("Importo non valido!\n");
    }
}

void preleva(BankAccount *conto, float importo) {
    if (importo > 0 && importo <= conto->saldo) {
        conto->saldo -= importo;
        conto->numero_transazioni++;
        printf("Prelevati %.2f euro. Nuovo saldo: %.2f\n", 
               importo, conto->saldo);
    } else {
        printf("Operazione non autorizzata!\n");
    }
}

void stampa_estratto_conto(BankAccount conto) {
    printf("\n=== ESTRATTO CONTO ===\n");
    printf("Titolare: %s\n", conto.titolare);
    printf("Saldo attuale: %.2f euro\n", conto.saldo);
    printf("Numero transazioni: %d\n", conto.numero_transazioni);
    printf("======================\n");
}

int main() {
    BankAccount conto_mario = {
        .titolare = "Mario Bianchi",
        .saldo = 1000.00,
        .numero_transazioni = 0
    };
    
    stampa_estratto_conto(conto_mario);
    
    // Operazioni che modificano l'originale
    deposita(&conto_mario, 250.50);
    preleva(&conto_mario, 100.00);
    deposita(&conto_mario, 75.25);
    preleva(&conto_mario, 2000.00);  // Operazione non autorizzata
    
    stampa_estratto_conto(conto_mario);
    
    return 0;
}
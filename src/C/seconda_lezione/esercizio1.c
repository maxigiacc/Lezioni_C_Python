#include <stdio.h>

// Dichiarazione della funzione fattoriale
int fattoriale(int n);

int main() {
    printf("=== ESERCIZI C ===\n\n");
    
    // ESERCIZIO 1: Valutazione voto
    printf("1. VALUTAZIONE VOTO\n");
    int voto;
    printf("Inserisci un voto numerico: ");
    scanf("%d", &voto);
    
    if (voto >= 28) {
        printf("Ottimo\n");
    } else if (voto >= 24 && voto <= 27) {
        printf("Buono\n");
    } else if (voto >= 18 && voto <= 23) {
        printf("Sufficiente\n");
    } else {
        printf("Insufficiente\n");
    }
    
    printf("\n");
    
    // ESERCIZIO 2: Somma dei numeri da 1 a N
    printf("2. SOMMA DEI NUMERI DA 1 A N\n");
    int N, somma = 0, i = 1;
    printf("Inserisci un numero N: ");
    scanf("%d", &N);
    
    // Controllo per numeri negativi
    if (N < 1) {
        printf("Errore: N deve essere un numero positivo\n");
    } else {
        // Calcolo somma usando while
        while (i <= N) {
            somma += i;
            i++;
        }
        printf("La somma dei numeri da 1 a %d è: %d\n", N, somma);
    }
    
    printf("\n");
    
    // ESERCIZIO 3: Calcolo del fattoriale
    printf("3. CALCOLO DEL FATTORIALE\n");
    int numero;
    printf("Inserisci un numero per calcolare il fattoriale: ");
    scanf("%d", &numero);
    
    if (numero < 0) {
        printf("Errore: Il fattoriale non è definito per numeri negativi\n");
    } else {
        int risultato = fattoriale(numero);
        printf("Il fattoriale di %d è: %d\n", numero, risultato);
    }
    
    return 0;
}

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

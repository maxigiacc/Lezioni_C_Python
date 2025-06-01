// ============================================================================
// ESERCIZIO: CALCOLATRICE INTERATTIVA CON MENU
// ============================================================================

#include <stdio.h>
#include <stdlib.h>

int main() {
    int scelta;
    float num1, num2, risultato;
    int continua = 1;
    
    // Statistiche semplici (solo variabili)
    int operazioni_eseguite = 0;
    int divisioni_per_zero = 0;
    
    printf("=== CALCOLATRICE INTERATTIVA ===\n");
    
    do {
        printf("\n=== MENU PRINCIPALE ===\n");
        printf("1. Addizione\n");
        printf("2. Sottrazione\n");
        printf("3. Moltiplicazione\n");
        printf("4. Divisione\n");
        printf("6. Statistiche utilizzo\n");
        printf("7. Esci\n");
        printf("Scelta: ");
        scanf("%d", &scelta);
        
        switch (scelta) {
            case 1: {
                // Addizione
                printf("\n--- ADDIZIONE ---\n");
                printf("Primo numero: ");
                scanf("%f", &num1);
                printf("Secondo numero: ");
                scanf("%f", &num2);
                
                risultato = num1 + num2;
                printf("%.2f + %.2f = %.2f\n", num1, num2, risultato);
                operazioni_eseguite++;
                break;
            }
            
            case 2: {
                // Sottrazione
                printf("\n--- SOTTRAZIONE ---\n");
                printf("Primo numero: ");
                scanf("%f", &num1);
                printf("Secondo numero: ");
                scanf("%f", &num2);
                
                risultato = num1 - num2;
                printf("%.2f - %.2f = %.2f\n", num1, num2, risultato);
                operazioni_eseguite++;
                break;
            }
            
            case 3: {
                // Moltiplicazione
                printf("\n--- MOLTIPLICAZIONE ---\n");
                printf("Primo numero: ");
                scanf("%f", &num1);
                printf("Secondo numero: ");
                scanf("%f", &num2);
                
                risultato = num1 * num2;
                printf("%.2f × %.2f = %.2f\n", num1, num2, risultato);
                operazioni_eseguite++;
                break;
            }
            
            case 4: {
                // Divisione con controllo divisione per zero
                printf("\n--- DIVISIONE ---\n");
                printf("Dividendo: ");
                scanf("%f", &num1);
                
                do {
                    printf("Divisore: ");
                    scanf("%f", &num2);
                    
                    if (num2 == 0) {
                        printf("Errore: impossibile dividere per zero!\n");
                        divisioni_per_zero++;
                        printf("Inserisci un divisore diverso da zero: ");
                    }
                } while (num2 == 0);
                
                risultato = num1 / num2;
                printf("%.2f ÷ %.2f = %.2f\n", num1, num2, risultato);
                operazioni_eseguite++;
                break;
            }
            
            case 6: {
                // Statistiche
                printf("\n=== STATISTICHE UTILIZZO ===\n");
                printf("Operazioni eseguite: %d\n", operazioni_eseguite);
                printf("Tentativi di divisione per zero: %d\n", divisioni_per_zero);
                
                if (operazioni_eseguite > 0) {
                    printf("Sessione attiva: programma utilizzato\n");
                } else {
                    printf("Sessione vuota: nessuna operazione eseguita\n");
                }
                break;
            }
            
            case 7: {
                printf("Grazie per aver usato la calcolatrice!\n");
                continua = 0;
                break;
            }
            
            default: {
                printf("Opzione non valida! Riprova.\n");
                continue;
            }
        }
        
        // Chiedi se continuare (solo se non ha scelto di uscire)
        if (continua && scelta >= 1 && scelta <= 5) {
            int altra_operazione;
            printf("\nVuoi eseguire un'altra operazione? (1=Sì, 0=No): ");
            scanf("%d", &altra_operazione);
            
            if (altra_operazione == 0) {
                printf("Grazie per aver usato la calcolatrice!\n");
                continua = 0;
            }
        }
        
    } while (continua);
    
    return 0;
}

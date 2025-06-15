#include "persona.h"

void mostra_menu() {
    printf("\n=== MENU RUBRICA ===\n");
    printf("1. Crea nuova rubrica\n");
    printf("2. Leggi rubrica da file\n");
    printf("3. Esci\n");
    printf("Scegli un'opzione: ");
}

int main() {
    int scelta;
    int n = 0;
    Persona* rubrica = NULL;
    
    printf("=== PROGRAMMA RUBRICA ===\n");
    
    do {
        mostra_menu();
        
        while (scanf("%d", &scelta) != 1 || scelta < 1 || scelta > 3) {
            printf("Scelta non valida. Inserire 1, 2 o 3: ");
            while (getchar() != '\n');
        }
        while (getchar() != '\n');
        
        switch (scelta) {
            case 1: // Crea nuova rubrica
                // Libera memoria precedente se presente
                if (rubrica != NULL) {
                    libera_memoria(rubrica);
                    rubrica = NULL;
                }
                
                printf("\nQuante persone vuoi inserire nella rubrica? ");
                while (scanf("%d", &n) != 1 || n <= 0) {
                    printf("Numero non valido. Inserire un numero positivo: ");
                    while (getchar() != '\n');
                }
                while (getchar() != '\n');
                
                // Alloca memoria dinamicamente per n persone
                rubrica = crea_rubrica(n);
                if (rubrica == NULL) {
                    printf("Errore nell'allocazione della memoria.\n");
                    break;
                }
                
                // Legge i dati delle persone
                leggi_persone(rubrica, n);
                
                // Salva i dati su file
                printf("\nSalvataggio dei dati su file '%s'...\n", NOME_FILE);
                if (salva_su_file(rubrica, n, NOME_FILE)) {
                    printf("✓ Rubrica salvata con successo!\n");
                    stampa_rubrica(rubrica, n);
                } else {
                    printf("✗ Errore nel salvataggio del file\n");
                }
                break;
                
            case 2: // Leggi rubrica da file
                // Libera memoria precedente se presente
                if (rubrica != NULL) {
                    libera_memoria(rubrica);
                    rubrica = NULL;
                }
                
                printf("\nLettura rubrica dal file '%s'...\n", NOME_FILE);
                if (leggi_da_file(&rubrica, &n, NOME_FILE)) {
                    printf("✓ Rubrica caricata con successo!\n");
                    stampa_rubrica(rubrica, n);
                } else {
                    printf("✗ Errore nella lettura del file\n");
                    printf("Assicurati che il file '%s' esista e sia nel formato corretto.\n", NOME_FILE);
                }
                break;
                
            case 3: // Esci
                printf("\nUscita dal programma...\n");
                break;
        }
        
    } while (scelta != 3);
    
    // Libera la memoria allocata
    if (rubrica != NULL) {
        libera_memoria(rubrica);
    }
    
    printf("Programma terminato.\n");
    return 0;
}
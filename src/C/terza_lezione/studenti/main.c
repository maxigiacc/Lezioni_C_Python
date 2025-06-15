#include "studenti.h"

void mostra_menu() {
    printf("\n=== GESTIONE ARCHIVIO STUDENTI UNIVERSITARI ===\n");
    printf("1. Crea nuovo archivio studenti\n");
    printf("2. Carica archivio da file\n");
    printf("3. Visualizza archivio completo\n");
    printf("4. Cerca studente per matricola\n");
    printf("5. Mostra statistiche\n");
    printf("6. Ordina per media voti\n");
    printf("7. Filtra per anno di corso\n");
    printf("8. Salva archivio su file\n");
    printf("9. Esci\n");
    printf("Scegli un'opzione (1-9): ");
}

int main() {
    int scelta;
    int n = 0;
    Studente* archivio = NULL;
    char matricola_ricerca[MAX_MATRICOLA];
    int anno_filtro;
    
    printf("🎓 SISTEMA GESTIONE ARCHIVIO STUDENTI UNIVERSITARI 🎓\n");
    printf("Sviluppato per la gestione completa degli studenti\n");
    
    do {
        mostra_menu();
        
        while (scanf("%d", &scelta) != 1 || scelta < 1 || scelta > 9) {
            printf("Scelta non valida. Inserire un numero da 1 a 9: ");
            while (getchar() != '\n');
        }
        while (getchar() != '\n');
        
        switch (scelta) {
            case 1: // Crea nuovo archivio
                if (archivio != NULL) {
                    libera_memoria(archivio);
                    archivio = NULL;
                }
                
                printf("\n📝 CREAZIONE NUOVO ARCHIVIO\n");
                printf("Quanti studenti vuoi inserire? ");
                while (scanf("%d", &n) != 1 || n <= 0) {
                    printf("Numero non valido. Inserire un numero positivo: ");
                    while (getchar() != '\n');
                }
                while (getchar() != '\n');
                
                archivio = crea_archivio(n);
                if (archivio == NULL) {
                    printf("❌ Errore nell'allocazione della memoria.\n");
                    break;
                }
                
                inserisci_studenti(archivio, n);
                printf("✅ Archivio creato con successo! (%d studenti)\n", n);
                break;
                
            case 2: // Carica da file
                if (archivio != NULL) {
                    libera_memoria(archivio);
                    archivio = NULL;
                }
                
                printf("\n📂 CARICAMENTO DA FILE\n");
                printf("Caricamento archivio dal file '%s'...\n", NOME_FILE);
                
                if (leggi_da_file(&archivio, &n, NOME_FILE)) {
                    printf("✅ Archivio caricato con successo! (%d studenti)\n", n);
                } else {
                    printf("❌ Errore nel caricamento del file\n");
                    printf("Assicurati che il file '%s' esista e sia nel formato corretto.\n", NOME_FILE);
                }
                break;
                
            case 3: // Visualizza archivio
                if (archivio == NULL) {
                    printf("❌ Nessun archivio caricato. Crea o carica prima un archivio.\n");
                } else {
                    stampa_archivio(archivio, n);
                }
                break;
                
            case 4: // Cerca per matricola
                if (archivio == NULL) {
                    printf("❌ Nessun archivio caricato.\n");
                } else {
                    printf("\n🔍 RICERCA STUDENTE\n");
                    printf("Inserisci la matricola da cercare: ");
                    fflush(stdout);
                    if (fgets(matricola_ricerca, MAX_MATRICOLA, stdin) != NULL) {
                        matricola_ricerca[strcspn(matricola_ricerca, "\n")] = '\0';
                        cerca_studente_per_matricola(archivio, n, matricola_ricerca);
                    }
                }
                break;
                
            case 5: // Statistiche
                if (archivio == NULL) {
                    printf("❌ Nessun archivio caricato.\n");
                } else {
                    statistiche_archivio(archivio, n);
                }
                break;
                
            case 6: // Ordina per media
                if (archivio == NULL) {
                    printf("❌ Nessun archivio caricato.\n");
                } else {
                // Usa la nuova funzione che gestisce la scelta dell'ordinamento
                gestisci_ordinamento_media(archivio, n);
                }
                break;
                
            case 7: // Filtra per anno
                if (archivio == NULL) {
                    printf("❌ Nessun archivio caricato.\n");
                } else {
                    printf("\n🎯 FILTRO PER ANNO DI CORSO\n");
                    printf("Inserisci l'anno di corso (1-6): ");
                    while (scanf("%d", &anno_filtro) != 1 || anno_filtro < 1 || anno_filtro > 6) {
                        printf("Anno non valido. Inserire un numero tra 1 e 6: ");
                        while (getchar() != '\n');
                    }
                    while (getchar() != '\n');
                    studenti_per_anno(archivio, n, anno_filtro);
                }
                break;
                
            case 8: // Salva su file
                if (archivio == NULL) {
                    printf("❌ Nessun archivio da salvare.\n");
                } else {
                    printf("\n💾 SALVATAGGIO SU FILE\n");
                    printf("Salvataggio archivio nel file '%s'...\n", NOME_FILE);
                    if (salva_su_file(archivio, n, NOME_FILE)) {
                        printf("✅ Archivio salvato con successo!\n");
                    } else {
                        printf("❌ Errore nel salvataggio del file\n");
                    }
                }
                break;
                
            case 9: // Esci
                printf("\n👋 Uscita dal programma...\n");
                printf("Grazie per aver utilizzato il Sistema di Gestione Archivio Studenti!\n");
                break;
        }
        
        if (scelta != 9) {
            printf("\nPremi INVIO per continuare...");
            getchar();
        }
        
    } while (scelta != 9);
    
    // Libera la memoria allocata
    if (archivio != NULL) {
        libera_memoria(archivio);
    }
    
    printf("🎓 Programma terminato correttamente.\n");
    return 0;
}
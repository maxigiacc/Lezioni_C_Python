#include "studenti.h"

// Alloca memoria dinamicamente per n studenti
Studente* crea_archivio(int n) {
    Studente* studenti = (Studente*)malloc(n * sizeof(Studente));
    if (studenti == NULL) {
        printf("Errore: impossibile allocare memoria per %d studenti\n", n);
        return NULL;
    }
    return studenti;
}

// Inserisce i dati di n studenti
void inserisci_studenti(Studente* studenti, int n) {
    printf("\n=== INSERIMENTO DATI STUDENTI ===\n");
    
    for (int i = 0; i < n; i++) {
        printf("\nStudente %d:\n", i + 1);
        printf("--------------------\n");
        
        // Matricola
        printf("Matricola: ");
        fflush(stdout);
        if (fgets(studenti[i].matricola, MAX_MATRICOLA, stdin) != NULL) {
            size_t len = strlen(studenti[i].matricola);
            if (len > 0 && studenti[i].matricola[len - 1] == '\n') {
                studenti[i].matricola[len - 1] = '\0';
            }
        }
        
        // Nome
        printf("Nome: ");
        fflush(stdout);
        if (fgets(studenti[i].nome, MAX_NOME, stdin) != NULL) {
            size_t len = strlen(studenti[i].nome);
            if (len > 0 && studenti[i].nome[len - 1] == '\n') {
                studenti[i].nome[len - 1] = '\0';
            }
        }
        
        // Cognome
        printf("Cognome: ");
        fflush(stdout);
        if (fgets(studenti[i].cognome, MAX_COGNOME, stdin) != NULL) {
            size_t len = strlen(studenti[i].cognome);
            if (len > 0 && studenti[i].cognome[len - 1] == '\n') {
                studenti[i].cognome[len - 1] = '\0';
            }
        }
        
        // Corso di laurea
        printf("Corso di laurea: ");
        fflush(stdout);
        if (fgets(studenti[i].corso_laurea, MAX_CORSO, stdin) != NULL) {
            size_t len = strlen(studenti[i].corso_laurea);
            if (len > 0 && studenti[i].corso_laurea[len - 1] == '\n') {
                studenti[i].corso_laurea[len - 1] = '\0';
            }
        }
        
        // Anno di corso
        printf("Anno di corso (1-6): ");
        while (scanf("%d", &studenti[i].anno_corso) != 1 || 
               studenti[i].anno_corso < 1 || studenti[i].anno_corso > 6) {
            printf("Anno non valido. Inserire un numero tra 1 e 6: ");
            while (getchar() != '\n');
        }
        
        // Media voti
        printf("Media voti (18.0-30.0): ");
        while (scanf("%f", &studenti[i].media_voti) != 1 || 
               studenti[i].media_voti < 18.0 || studenti[i].media_voti > 30.0) {
            printf("Media non valida. Inserire un valore tra 18.0 e 30.0: ");
            while (getchar() != '\n');
        }
        
        // Crediti acquisiti
        printf("Crediti acquisiti (0-300): ");
        while (scanf("%d", &studenti[i].crediti_acquisiti) != 1 || 
               studenti[i].crediti_acquisiti < 0 || studenti[i].crediti_acquisiti > 300) {
            printf("Crediti non validi. Inserire un numero tra 0 e 300: ");
            while (getchar() != '\n');
        }
        
        // Pulisce il buffer
        while (getchar() != '\n');
    }
}

// Salva l'archivio su file
int salva_su_file(const Studente* studenti, int n, const char* nome_file) {
    FILE* file = fopen(nome_file, "w");
    if (file == NULL) {
        printf("Errore: impossibile aprire il file %s per la scrittura\n", nome_file);
        return 0;
    }
    
    // Scrive il numero di studenti
    fprintf(file, "%d\n", n);
    
    // Scrive i dati di ogni studente
    for (int i = 0; i < n; i++) {
        fprintf(file, "%s\n", studenti[i].matricola);
        fprintf(file, "%s\n", studenti[i].nome);
        fprintf(file, "%s\n", studenti[i].cognome);
        fprintf(file, "%s\n", studenti[i].corso_laurea);
        fprintf(file, "%d\n", studenti[i].anno_corso);
        fprintf(file, "%.2f\n", studenti[i].media_voti);
        fprintf(file, "%d\n", studenti[i].crediti_acquisiti);
    }
    
    fclose(file);
    return 1;
}

// Legge l'archivio da file
int leggi_da_file(Studente** studenti, int* n, const char* nome_file) {
    FILE* file = fopen(nome_file, "r");
    if (file == NULL) {
        printf("Errore: impossibile aprire il file %s per la lettura\n", nome_file);
        return 0;
    }
    
    // Legge il numero di studenti
    if (fscanf(file, "%d", n) != 1 || *n <= 0) {
        printf("Errore: formato file non valido o numero di studenti non valido\n");
        fclose(file);
        return 0;
    }
    fgetc(file); // Consuma newline
    
    // Alloca memoria
    *studenti = crea_archivio(*n);
    if (*studenti == NULL) {
        fclose(file);
        return 0;
    }
    
    // Legge i dati di ogni studente
    for (int i = 0; i < *n; i++) {
        // Matricola
        if (fgets((*studenti)[i].matricola, MAX_MATRICOLA, file) == NULL) {
            printf("Errore nella lettura della matricola dello studente %d\n", i + 1);
            libera_memoria(*studenti);
            *studenti = NULL;
            fclose(file);
            return 0;
        }
        (*studenti)[i].matricola[strcspn((*studenti)[i].matricola, "\n")] = '\0';
        
        // Nome
        if (fgets((*studenti)[i].nome, MAX_NOME, file) == NULL) {
            printf("Errore nella lettura del nome dello studente %d\n", i + 1);
            libera_memoria(*studenti);
            *studenti = NULL;
            fclose(file);
            return 0;
        }
        (*studenti)[i].nome[strcspn((*studenti)[i].nome, "\n")] = '\0';
        
        // Cognome
        if (fgets((*studenti)[i].cognome, MAX_COGNOME, file) == NULL) {
            printf("Errore nella lettura del cognome dello studente %d\n", i + 1);
            libera_memoria(*studenti);
            *studenti = NULL;
            fclose(file);
            return 0;
        }
        (*studenti)[i].cognome[strcspn((*studenti)[i].cognome, "\n")] = '\0';
        
        // Corso di laurea
        if (fgets((*studenti)[i].corso_laurea, MAX_CORSO, file) == NULL) {
            printf("Errore nella lettura del corso dello studente %d\n", i + 1);
            libera_memoria(*studenti);
            *studenti = NULL;
            fclose(file);
            return 0;
        }
        (*studenti)[i].corso_laurea[strcspn((*studenti)[i].corso_laurea, "\n")] = '\0';
        
        // Anno, media e crediti
        if (fscanf(file, "%d", &(*studenti)[i].anno_corso) != 1 ||
            fscanf(file, "%f", &(*studenti)[i].media_voti) != 1 ||
            fscanf(file, "%d", &(*studenti)[i].crediti_acquisiti) != 1) {
            printf("Errore nella lettura dei dati numerici dello studente %d\n", i + 1);
            libera_memoria(*studenti);
            *studenti = NULL;
            fclose(file);
            return 0;
        }
        fgetc(file); // Consuma newline finale
    }
    
    fclose(file);
    return 1;
}

// Stampa l'archivio completo
void stampa_archivio(const Studente* studenti, int n) {
    printf("\n=== ARCHIVIO STUDENTI ===\n");
    printf("Numero totale studenti: %d\n\n", n);
    
    for (int i = 0; i < n; i++) {
        printf("Studente %d:\n", i + 1);
        printf("  Matricola: %s\n", studenti[i].matricola);
        printf("  Nome: %s %s\n", studenti[i].nome, studenti[i].cognome);
        printf("  Corso: %s\n", studenti[i].corso_laurea);
        printf("  Anno: %d°\n", studenti[i].anno_corso);
        printf("  Media: %.2f\n", studenti[i].media_voti);
        printf("  Crediti: %d\n", studenti[i].crediti_acquisiti);
        printf("  -------------------------\n");
    }
}

// Cerca uno studente per matricola
void cerca_studente_per_matricola(const Studente* studenti, int n, const char* matricola) {
    printf("\n=== RICERCA STUDENTE ===\n");
    
    for (int i = 0; i < n; i++) {
        if (strcmp(studenti[i].matricola, matricola) == 0) {
            printf("✓ Studente trovato:\n");
            printf("  Matricola: %s\n", studenti[i].matricola);
            printf("  Nome: %s %s\n", studenti[i].nome, studenti[i].cognome);
            printf("  Corso: %s\n", studenti[i].corso_laurea);
            printf("  Anno: %d°\n", studenti[i].anno_corso);
            printf("  Media: %.2f\n", studenti[i].media_voti);
            printf("  Crediti: %d\n", studenti[i].crediti_acquisiti);
            return;
        }
    }
    
    printf("✗ Studente con matricola '%s' non trovato\n", matricola);
}

// Calcola e mostra statistiche
void statistiche_archivio(const Studente* studenti, int n) {
    if (n == 0) {
        printf("Nessuno studente nell'archivio\n");
        return;
    }
    
    float somma_medie = 0;
    float media_max = studenti[0].media_voti;
    float media_min = studenti[0].media_voti;
    int crediti_totali = 0;
    
    printf("\n=== STATISTICHE ARCHIVIO ===\n");
    
    for (int i = 0; i < n; i++) {
        somma_medie += studenti[i].media_voti;
        crediti_totali += studenti[i].crediti_acquisiti;
        
        if (studenti[i].media_voti > media_max) {
            media_max = studenti[i].media_voti;
        }
        if (studenti[i].media_voti < media_min) {
            media_min = studenti[i].media_voti;
        }
    }
    
    printf("Numero studenti: %d\n", n);
    printf("Media generale: %.2f\n", somma_medie / n);
    printf("Media più alta: %.2f\n", media_max);
    printf("Media più bassa: %.2f\n", media_min);
    printf("Crediti totali: %d\n", crediti_totali);
    printf("Media crediti per studente: %.1f\n", (float)crediti_totali / n);
}

// Ordina studenti per media (bubble sort)
void ordina_per_media(Studente* studenti, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (studenti[j].media_voti < studenti[j + 1].media_voti) {
                // Scambia gli studenti
                Studente temp = studenti[j];
                studenti[j] = studenti[j + 1];
                studenti[j + 1] = temp;
            }
        }
    }
    printf("✓ Studenti ordinati per media (dal più alto al più basso)\n");
}

// Mostra studenti di un anno specifico
void studenti_per_anno(const Studente* studenti, int n, int anno) {
    printf("\n=== STUDENTI DEL %d° ANNO ===\n", anno);
    
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (studenti[i].anno_corso == anno) {
            printf("%d. %s %s - %s (Media: %.2f)\n", 
                   ++count, studenti[i].nome, studenti[i].cognome, 
                   studenti[i].matricola, studenti[i].media_voti);
        }
    }
    
    if (count == 0) {
        printf("Nessuno studente trovato per il %d° anno\n", anno);
    } else {
        printf("\nTotale studenti %d° anno: %d\n", anno, count);
    }
}

// Libera la memoria allocata
void libera_memoria(Studente* studenti) {
    if (studenti != NULL) {
        free(studenti);
    }
}

// Ordina studenti per media con opzione crescente/decrescente
void ordina_per_media_con_opzione(Studente* studenti, int n, int crescente) {
    printf("\n📊 ORDINAMENTO PER MEDIA\n");
    printf("Ordinamento in corso...\n");
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            // Se crescente = 1: ordina dal più basso al più alto
            // Se crescente = 0: ordina dal più alto al più basso
            int scambia = 0;
            if (crescente) {
                scambia = (studenti[j].media_voti > studenti[j + 1].media_voti);
            } else {
                scambia = (studenti[j].media_voti < studenti[j + 1].media_voti);
            }
            
            if (scambia) {
                // Scambia gli studenti
                Studente temp = studenti[j];
                studenti[j] = studenti[j + 1];
                studenti[j + 1] = temp;
            }
        }
    }
    
    if (crescente) {
        printf("✅ Studenti ordinati per media (dal più basso al più alto)\n");
    } else {
        printf("✅ Studenti ordinati per media (dal più alto al più basso)\n");
    }
}

// Funzione helper per mostrare menu di ordinamento e gestire la scelta
void gestisci_ordinamento_media(Studente* studenti, int n) {
    int scelta_ordinamento;
    
    printf("\n📊 ORDINAMENTO PER MEDIA\n");
    printf("1. Ordine crescente (dal più basso al più alto)\n");
    printf("2. Ordine decrescente (dal più alto al più basso)\n");
    printf("Scegli il tipo di ordinamento (1-2): ");
    
    while (scanf("%d", &scelta_ordinamento) != 1 || 
           (scelta_ordinamento != 1 && scelta_ordinamento != 2)) {
        printf("Scelta non valida. Inserire 1 o 2: ");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');
    
    // Chiama la funzione di ordinamento
    if (scelta_ordinamento == 1) {
        ordina_per_media_con_opzione(studenti, n, 1); // crescente
    } else {
        ordina_per_media_con_opzione(studenti, n, 0); // decrescente
    }
    
    // Chiede se visualizzare l'archivio ordinato
    printf("Vuoi visualizzare l'archivio ordinato? (s/n): ");
    char risposta;
    scanf(" %c", &risposta);
    while (getchar() != '\n');
    
    if (risposta == 's' || risposta == 'S') {
        stampa_archivio(studenti, n);
    }
}

// Funzione per stampare solo la classifica per media (senza tutti i dettagli)
void stampa_classifica_per_media(const Studente* studenti, int n, int crescente) {
    if (crescente) {
        printf("\n🏆 CLASSIFICA STUDENTI - ORDINE CRESCENTE (dal più basso)\n");
    } else {
        printf("\n🏆 CLASSIFICA STUDENTI - ORDINE DECRESCENTE (dal più alto)\n");
    }
    
    printf("═══════════════════════════════════════════════════════════════\n");
    printf("Pos.  Matricola        Nome Cognome                Media\n");
    printf("═══════════════════════════════════════════════════════════════\n");
    
    for (int i = 0; i < n; i++) {
        printf("%-4d  %-15s %-25s %.2f\n", 
               i + 1, 
               studenti[i].matricola,
               // Concatena nome e cognome in un buffer temporaneo
               (char[50]){0}, // Array temporaneo inizializzato a zero
               studenti[i].media_voti);
        
        // Metodo alternativo più sicuro per concatenare nome e cognome
        char nome_completo[100];
        snprintf(nome_completo, sizeof(nome_completo), "%.20s %.20s", 
                studenti[i].nome, studenti[i].cognome);
        
        // Ristampa la riga con il nome completo formattato correttamente
        printf("\r%-4d  %-15s %-25s %.2f\n", 
               i + 1, 
               studenti[i].matricola,
               nome_completo,
               studenti[i].media_voti);
    }
    
    printf("═══════════════════════════════════════════════════════════════\n");
}
#include "persona.h"

// Alloca memoria dinamicamente per n persone
Persona* crea_rubrica(int n) {
    Persona* persone = (Persona*)malloc(n * sizeof(Persona));
    if (persone == NULL) {
        printf("Errore: impossibile allocare memoria per %d persone\n", n);
        return NULL;
    }
    return persone;
}

// Legge i dati di n persone da input
void leggi_persone(Persona* persone, int n) {
    printf("\n=== INSERIMENTO DATI PERSONE ===\n");
    
    for (int i = 0; i < n; i++) {
        printf("\nPersona %d:\n", i + 1);
        
        // Legge il nome
        printf("Nome: ");
        fflush(stdout);
        if (fgets(persone[i].nome, MAX_NOME, stdin) != NULL) {
            // Rimuove il carattere newline se presente
            size_t len = strlen(persone[i].nome);
            if (len > 0 && persone[i].nome[len - 1] == '\n') {
                persone[i].nome[len - 1] = '\0';
            }
        }
        
        // Legge l'età con controllo di validità
        printf("Età: ");
        while (scanf("%d", &persone[i].eta) != 1 || persone[i].eta < 0 || persone[i].eta > 150) {
            printf("Età non valida. Inserire un numero tra 0 e 150: ");
            // Pulisce il buffer di input
            while (getchar() != '\n');
        }
        
        // Pulisce il buffer per la prossima iterazione
        while (getchar() != '\n');
    }
}

// Salva la rubrica su file usando fprintf
int salva_su_file(const Persona* persone, int n, const char* nome_file) {
    FILE* file = fopen(nome_file, "w");
    if (file == NULL) {
        printf("Errore: impossibile aprire il file %s per la scrittura\n", nome_file);
        return 0;
    }
    
    // Scrive il numero di persone come prima riga
    fprintf(file, "%d\n", n);
    
    // Scrive i dati di ogni persona
    for (int i = 0; i < n; i++) {
        fprintf(file, "%s\n", persone[i].nome);
        fprintf(file, "%d\n", persone[i].eta);
    }
    
    fclose(file);
    return 1; // Successo
}

// Legge la rubrica da file
//Persona** --> array di puntatori a struct persona
int leggi_da_file(Persona** persone, int* n, const char* nome_file) {
    FILE* file = fopen(nome_file, "r");
    if (file == NULL) {
        printf("Errore: impossibile aprire il file %s per la lettura\n", nome_file);
        return 0;
    }
    
    // Legge il numero di persone
    if (fscanf(file, "%d", n) != 1 || *n <= 0) {
        printf("Errore: formato file non valido o numero di persone non valido\n");
        fclose(file);
        return 0;
    }
    
    // Consuma il carattere newline dopo il numero
    fgetc(file);
    
    // Alloca memoria per le persone
    *persone = crea_rubrica(*n);
    if (*persone == NULL) {
        fclose(file);
        return 0;
    }
    
    // Legge i dati di ogni persona
    for (int i = 0; i < *n; i++) {
        // Legge il nome
        if (fgets((*persone)[i].nome, MAX_NOME, file) == NULL) {
            printf("Errore: impossibile leggere il nome della persona %d\n", i + 1);
            libera_memoria(*persone);
            *persone = NULL;
            fclose(file);
            return 0;
        }
        
        // Rimuove il carattere newline dal nome
        size_t len = strlen((*persone)[i].nome);
        if (len > 0 && (*persone)[i].nome[len - 1] == '\n') {
            (*persone)[i].nome[len - 1] = '\0';
        }
        
        // Legge l'età
        if (fscanf(file, "%d", &(*persone)[i].eta) != 1) {
            printf("Errore: impossibile leggere l'età della persona %d\n", i + 1);
            libera_memoria(*persone);
            *persone = NULL;
            fclose(file);
            return 0;
        }
        
        // Consuma il carattere newline dopo l'età
        fgetc(file);
    }
    
    fclose(file);
    return 1; // Successo
}

// Stampa la rubrica a schermo
void stampa_rubrica(const Persona* persone, int n) {
    printf("\n=== CONTENUTO RUBRICA ===\n");
    printf("Numero di persone: %d\n\n", n);
    
    for (int i = 0; i < n; i++) {
        printf("Persona %d:\n", i + 1);
        printf("  Nome: %s\n", persone[i].nome);
        printf("  Età: %d anni\n", persone[i].eta);
        printf("------------------------\n");
    }
}

// Libera la memoria allocata dinamicamente
void libera_memoria(Persona* persone) {
    if (persone != NULL) {
        free(persone);
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char titolo[100];
    int anno;
    float rating;
} Film;

// Funzione per creare array dinamico di film
Film* crea_database_film(int capacita) {
    Film* database = malloc(capacita * sizeof(Film));
    if (database == NULL) {
        printf("Errore: impossibile allocare memoria!\n");
        return NULL;
    }
    return database;
}

// Funzione per aggiungere film al database
void aggiungi_film(Film* database, int indice, const char* titolo, int anno, float rating) {
    strcpy(database[indice].titolo, titolo);
    database[indice].anno = anno;
    database[indice].rating = rating;
}

// Funzione per stampare database
void stampa_database(Film* database, int num_film) {
    printf("=== DATABASE FILM ===\n");
    for (int i = 0; i < num_film; i++) {
        printf("%d. %-30s (%d) - Rating: %.1f/10\n",
               i+1, database[i].titolo, database[i].anno, database[i].rating);
    }
    printf("\n");
}

// Funzione per trovare film con rating più alto
Film* trova_miglior_film(Film* database, int num_film) {
    if (num_film == 0) return NULL;
    
    Film* migliore = &database[0];
    for (int i = 1; i < num_film; i++) {
        if (database[i].rating > migliore->rating) {
            migliore = &database[i];
        }
    }
    return migliore;
}

int main() {
    int capacita = 10;
    int num_film = 0;
    
    // Creazione database dinamico
    Film* cinema = crea_database_film(capacita);
    if (cinema == NULL) {
        return 1;
    }
    
    // Aggiunta film
    aggiungi_film(cinema, num_film++, "Il Padrino", 1972, 9.2);
    aggiungi_film(cinema, num_film++, "Pulp Fiction", 1994, 8.9);
    aggiungi_film(cinema, num_film++, "Il Signore degli Anelli", 2001, 8.8);
    aggiungi_film(cinema, num_film++, "Forrest Gump", 1994, 8.8);
    aggiungi_film(cinema, num_film++, "Inception", 2010, 8.7);
    
    // Stampa database
    stampa_database(cinema, num_film);
    
    // Trova miglior film
    Film* migliore = trova_miglior_film(cinema, num_film);
    if (migliore != NULL) {
        printf("Miglior film: %s (%.1f/10)\n\n", migliore->titolo, migliore->rating);
    }
    
    // Liberazione memoria
    free(cinema);
    cinema = NULL;
    printf("Memoria liberata correttamente.\n");
    
    return 0;
}
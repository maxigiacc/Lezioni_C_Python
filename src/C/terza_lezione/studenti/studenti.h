#ifndef STUDENTE_H
#define STUDENTE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50
#define MAX_COGNOME 50
#define MAX_CORSO 100
#define MAX_MATRICOLA 20
#define NOME_FILE "archivio_studenti.txt"

// Definizione della struct Studente
typedef struct {
    char matricola[MAX_MATRICOLA];
    char nome[MAX_NOME];
    char cognome[MAX_COGNOME];
    char corso_laurea[MAX_CORSO];
    int anno_corso;
    float media_voti;
    int crediti_acquisiti;
} Studente;

// Dichiarazioni delle funzioni esistenti
Studente* crea_archivio(int n);
void inserisci_studenti(Studente* studenti, int n);
int salva_su_file(const Studente* studenti, int n, const char* nome_file);
int leggi_da_file(Studente** studenti, int* n, const char* nome_file);
void stampa_archivio(const Studente* studenti, int n);
void cerca_studente_per_matricola(const Studente* studenti, int n, const char* matricola);
void statistiche_archivio(const Studente* studenti, int n);
void ordina_per_media(Studente* studenti, int n);
void studenti_per_anno(const Studente* studenti, int n, int anno);
void libera_memoria(Studente* studenti);

// Nuove funzioni per l'ordinamento migliorato
void ordina_per_media_con_opzione(Studente* studenti, int n, int crescente);
void gestisci_ordinamento_media(Studente* studenti, int n);
void stampa_classifica_per_media(const Studente* studenti, int n, int crescente);

#endif
#ifndef PERSONA_H
#define PERSONA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50
#define NOME_FILE "rubrica.txt"

// Definizione della struct Persona
typedef struct {
    char nome[MAX_NOME];
    int eta;
} Persona;

// Dichiarazioni delle funzioni
Persona* crea_rubrica(int n);
void leggi_persone(Persona* persone, int n);
int salva_su_file(const Persona* persone, int n, const char* nome_file);
int leggi_da_file(Persona** persone, int* n, const char* nome_file);
void stampa_rubrica(const Persona* persone, int n);
void libera_memoria(Persona* persone);

#endif
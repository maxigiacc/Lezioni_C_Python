#include <stdio.h>
#include <string.h>

typedef struct {
    int ore;
    int minuti;
} Orario;

typedef struct {
    char nome_corso[50];
    char docente[40];
    int crediti;
    Orario inizio_lezione;
    Orario fine_lezione;
    char aula[10];
} Corso;

typedef struct {
    char nome[30];
    char cognome[30];
    int matricola;
    char corso_di_laurea[50];
    int anno_accademico;
    Corso corsi_seguiti[10];  // Array di struct annidate
    int numero_corsi;
} Studente;

// Funzione per stampare un orario
void stampa_orario(Orario o) {
    printf("%02d:%02d", o.ore, o.minuti);
}

// Funzione per stampare un corso
void stampa_corso(Corso c) {
    printf("  • %s (Prof. %s) - %d CFU\n", c.nome_corso, c.docente, c.crediti);
    printf("    Orario: ");
    stampa_orario(c.inizio_lezione);
    printf(" - ");
    stampa_orario(c.fine_lezione);
    printf(" | Aula: %s\n", c.aula);
}

// Funzione per stampare studente completo
void stampa_studente_completo(Studente s) {
    printf("=== SCHEDA STUDENTE ===\n");
    printf("Nome: %s %s\n", s.nome, s.cognome);
    printf("Matricola: %d\n", s.matricola);
    printf("Corso di Laurea: %s\n", s.corso_di_laurea);
    printf("Anno Accademico: %d\n", s.anno_accademico);
    printf("Corsi seguiti (%d):\n", s.numero_corsi);
    
    for (int i = 0; i < s.numero_corsi; i++) {
        stampa_corso(s.corsi_seguiti[i]);
        printf("\n");
    }
}

int main() {
    // Creazione studente
    Studente mario = {
        .nome = "Mario",
        .cognome = "Rossi",
        .matricola = 123456,
        .corso_di_laurea = "Informatica",
        .anno_accademico = 2024,
        .numero_corsi = 0
    };
    
    // Aggiunta corsi con struct annidate
    mario.corsi_seguiti[0] = (Corso){
        "Programmazione in C",
        "Prof. Bianchi",
        9,
        {9, 0},   // Inizio: 09:00
        {11, 0},  // Fine: 11:00
        "Aula A1"
    };
    mario.numero_corsi++;
    
    mario.corsi_seguiti[1] = (Corso){
        "Algoritmi e Strutture Dati",
        "Prof. Verdi",
        12,
        {14, 30}, // Inizio: 14:30
        {17, 30}, // Fine: 17:30
        "Aula B2"
    };
    mario.numero_corsi++;
    
    mario.corsi_seguiti[2] = (Corso){
        "Matematica Discreta",
        "Prof. Neri",
        6,
        {11, 15}, // Inizio: 11:15
        {13, 15}, // Fine: 13:15
        "Aula C1"
    };
    mario.numero_corsi++;
    
    // Stampa completa
    stampa_studente_completo(mario);
    
    // Calcolo crediti totali
    int crediti_totali = 0;
    for (int i = 0; i < mario.numero_corsi; i++) {
        crediti_totali += mario.corsi_seguiti[i].crediti;
    }
    printf("Crediti totali: %d CFU\n", crediti_totali);
    
    return 0;
}
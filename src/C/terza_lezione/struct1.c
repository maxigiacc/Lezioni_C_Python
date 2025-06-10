#include <stdio.h>
//nuova libreria per la gestione delle stringhe
#include <string.h>

struct Persona {
    char nome[50];
    int eta;
    float stipendio;
};

int main() {
    // Metodo 1: Dichiarazione semplice
    struct Persona dipendente1;
    //inizializzazione
    strcpy(dipendente1.nome, "Giovanni Keplero");   //funzione che copia nel primo argomento, il secondo
    dipendente1.eta = 32;
    dipendente1.stipendio = 20000.12;
    // Metodo 2: Dichiarazione con inizializzazione
    struct Persona dipendente2 = {"Luigi ", 25, 1500.50};
    printf("Dipendente 1: Nome: %s, Età: %d, Stipendio: %.3f\n", dipendente1.nome, dipendente1.eta, dipendente1.stipendio);
    printf("Dipendente 2: Nome: %s, Età: %d, Stipendio: %.3f\n", dipendente2.nome, dipendente2.eta, dipendente2.stipendio);

    return 0;
}
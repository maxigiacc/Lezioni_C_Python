#include <stdio.h>

int main() {

    int eta;    //variabile intera
    char nome[10];      // array di caratteri --> Stringa "Massimo" "Pippo ".
    float media;

    // nome variabile valore cella indirizzo
    // eta              23          4545F
    //int* eta           4545F       XXXXXX


    printf("Inserisci il tuo nome: \n");
    scanf("%s", nome);
    printf("Inserisci l'età: ");
    scanf("%d", &eta);
    printf("Inserisci la tua media universitaria: ");
    scanf("%f", &media);


    printf("Nome: %s\n", nome);
    printf("Età: %d", eta);
    printf("");

    return 0;
}
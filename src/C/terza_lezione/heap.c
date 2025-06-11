#include <stdio.h>
#include <stdlib.h>

#define DIMENSIONE 5

int main () {

    //dichiarazione array e inizializzazione nulla
    double* array;
    int dimensione = 0;
    printf("Inserisci la dimensione dell'array: \n");
    scanf("%d", &dimensione);

    //allocazione di memoria
    array = malloc(dimensione * sizeof(double));
    // inizializzazione
    for(int i = 0; i < dimensione; i++) {
        if(i == 0){
            array[i] = 0;
            continue;
        }
        array[i] = array[i-1] + 2.3;
    }
    //stampa
    for(int i = 0; i < dimensione; i++) {
        printf("%.3f, ", array[i]);
    }

    free(array);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define DIMENSIONE 5

int main () {

    //dichiarazione array e inizializzazione nulla
    double array [DIMENSIONE] = {};

    // inizializzazione
    for(int i = 0; i < DIMENSIONE; i++) {
        array[i] = array[i] + 2.3;
    }

    //stampa
    for(int i = 0; i < DIMENSIONE; i++) {
        printf("%.3f, ", array[i]);
    }

}

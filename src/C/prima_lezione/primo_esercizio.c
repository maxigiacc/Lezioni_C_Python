/*
========
Dato un numero intero come input, il programma deve restituire prima il suo precedente, 
poi il suo successivo, infine il doppio del numero inserito.
=====

*/

#include <stdio.h>

int main() {

    int numero = 0;
    int successivo = 0, precedente = 0, doppio = 0;
    char carattere = 'c';

    printf("%c", carattere);
    printf("%d", carattere);

    printf("Inserisci il numero: ");
    scanf("%d", &numero);

    successivo = numero + 1 ;
    precedente = numero - 1 ;
    doppio = numero * 2;

    printf("====RISULTATI====\n");
    printf("Successivo: %d, Precedente: %d, Doppio: %d", successivo, precedente, doppio);

	return 0;
}

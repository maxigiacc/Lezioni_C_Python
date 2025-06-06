#include <stdio.h>
#include <stdbool.h>

int main () {

    int cifra = 4;
    int result = 0;

    //operatore ternario 
    
    bool risultato = (cifra % 2 == 1) ? true : false;

    result = (cifra % 2 == 1 ) ? 8 : 10;

    printf("Risultato %d\n", result);

    return 0;

}

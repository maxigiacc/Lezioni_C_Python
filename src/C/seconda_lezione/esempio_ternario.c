#include <stdio.h>
#include <stdbool.h>

int main () {

    int cifra = 4;

    bool risultato = (cifra % 2 == 1) ? true : false;

    printf("Risultato %d\n", risultato);

    return 0;

}

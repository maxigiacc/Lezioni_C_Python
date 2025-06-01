#include <stdio.h>

int main () {

    int cifra = 3;

    //se la cifra è dispari, entra dentro il blocco if
    if ( cifra % 2 == 1) {
        printf("Inserita una cifra dispari");   //blocco condizione vera
    }
    else {
        printf("Inserita una cifra pari");      //blocco condizione falsa
    }

}

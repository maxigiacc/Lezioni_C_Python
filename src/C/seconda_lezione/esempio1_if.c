#include <stdio.h>

int main () {

    int cifra = 0;
    int c = 0.0;

    printf("Inseriamo la cifra: ");
    scanf("%d", &cifra);
    printf("\nInserisci un decimale: ");
    scanf("%d", &c);


    //se la cifra è dispari && il carattere è c, entra dentro il blocco if

    // 13 0
    if ( (cifra % 2 == 1) && (c == 0)) {
        printf("Inserita una cifra dispari e inserito c");   //blocco condizione vera
    }
    //12 0, 12 2, 13 2 
    else if ((cifra % 2 == 0) || (c == 2)){
        printf("Inserita una cifra pari o inserito d");      //blocco condizione falsa
    }
    else {
        printf("\nErrore.");
    }

    return 0;
}

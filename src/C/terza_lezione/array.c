#include <stdio.h>

int main() {

    // array con dimensione fissa 6
    int arrInteri [6];

    int arrInteri2 [] = {3, 1, 2, 3, 0, 5}; //array di dimensione fissa = 6

    for(int i = 0; i < 6; i++) {
        //inizializzazione arrInteri
        int temp = 0;
        printf("Inserisci il valore %d -esimo dell'array: ", i);
        scanf("%d", &temp);
        arrInteri[i] = temp;
        // 0 1 2 3 4 5
    }
    printf("Primo array: ");
    for(int i = 0; i < 6; i++) {
        printf("%d, ", arrInteri[i]);
    }
    printf("\n\n");
    printf("Secondo array: ");
    for(int i = 0; i < 5; i++) {
        printf("%d, ", arrInteri2[i]);
    }
    printf("\n\nCiao ciao: %d\n\n", *arrInteri2);


}
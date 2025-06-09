#include <stdio.h>
#include <stdlib.h>

int* crea_array(int dimensione) {
    if (dimensione <= 0) {
        return NULL;  // Segnala errore
    }
    
    int *array = malloc(dimensione * sizeof(int));
    if (array == NULL) {
        printf("Errore: memoria insufficiente!\n");
        return NULL;
    }
    int temp;
    // Inizializza l'array
    for (int i = 0; i < dimensione; i++) {
        printf("\nInserisci il valore per l'array: ");
        scanf("%d", &temp);
        array[i] = temp;
    }
    
    return array;
}

int main() {
    int *numeri = crea_array(5);
    
    if (numeri != NULL) {
        printf("Array creato con successo:\n");
        for (int i = 0; i < 5; i++) {
            printf("%d ", numeri[i]);
        }
        printf("\n");
        free(numeri);
    } else {
        printf("Impossibile creare l'array!\n");
    }
    
    return 0;
}
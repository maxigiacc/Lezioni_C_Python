#include <stdio.h>

int main() {
    FILE *fp;
    char buffer[100];
    
    // Apertura del file in modalità lettura
    fp = fopen("saluto.txt", "r");
    
    if (fp == NULL) {
        printf("Errore: impossibile aprire il file per la lettura!\n");
        return 1;
    }
    
    // Lettura e stampa riga per riga
    printf("Contenuto del file:\n");
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }
    
    fclose(fp);
    return 0;
}
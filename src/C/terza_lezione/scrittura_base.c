#include <stdio.h>

int main() {
    FILE *fp;
    
    // Apertura del file in modalità scrittura
    fp = fopen("saluto.txt", "w");
    
    // Controllo errori
    if (fp == NULL) {
        printf("Errore: impossibile aprire il file!\n");
        return 1;
    }
    
    // Scrittura di dati
    fprintf(fp, "Benvenuto nel mondo della programmazione C!\n");
    fprintf(fp, "Oggi è una bella giornata per imparare.\n");
    fprintf(fp, "Numero magico: %d\n", 42);
    
    // Chiusura del file
    fclose(fp);
    
    printf("File scritto con successo!\n");
    return 0;
}
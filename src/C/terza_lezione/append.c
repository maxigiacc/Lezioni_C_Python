#include <stdio.h>
#include <time.h>

int main() {
    FILE *fp;
    time_t ora_corrente;
    char *stringa_tempo;
    
    // Ottieni l'ora corrente
    time(&ora_corrente);
    stringa_tempo = ctime(&ora_corrente);
    
    // Apri il file in modalità append
    fp = fopen("log.txt", "a");
    
    if (fp == NULL) {
        printf("Impossibile aprire il file di log!\n");
        return 1;
    }
    
    // Aggiungi una nuova voce al log
    fprintf(fp, "Accesso al programma: %s", stringa_tempo);
    fprintf(fp, "Operazione completata con successo.\n");
    fprintf(fp, "------------------------\n");
    
    fclose(fp);
    
    printf("Voce aggiunta al file di log!\n");
    return 0;
}
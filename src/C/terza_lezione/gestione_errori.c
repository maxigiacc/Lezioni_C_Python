#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char nome_file[100];
    char contenuto[200];
    
    printf("Inserisci il nome del file da leggere: ");
    scanf("%s", nome_file);
    
    fp = fopen(nome_file, "r");
    
    if (fp == NULL) {
        printf("ERRORE: Il file '%s' non può essere aperto.\n", nome_file);
        printf("Possibili cause:\n");
        printf("- Il file non esiste\n");
        printf("- Non hai i permessi di lettura\n");
        printf("- Il percorso non è valido\n");
        return 1;
    }
    
    printf("File aperto con successo!\n");
    printf("Contenuto:\n");
    printf("----------\n");
    
    // Lettura sicura con controllo EOF
    while (fgets(contenuto, sizeof(contenuto), fp) != NULL) {
        printf("%s", contenuto);
    }
    
    // Verifica se si è raggiunta la fine del file normalmente
    if (feof(fp)) {
        printf("\n----------\n");
        printf("Lettura completata con successo.\n");
    } else {
        printf("Errore durante la lettura del file.\n");
    }
    
    fclose(fp);
    return 0;
}
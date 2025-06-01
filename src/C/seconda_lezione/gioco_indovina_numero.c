// ============================================================================
// ESERCIZIO 2: GIOCO INDOVINA IL NUMERO CON LIVELLI
// ============================================================================


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Inizializza generatore casuale
    
    int scelta_modalita;
    int continua_gioco = 1;
    
    // Statistiche globali (variabili semplici)
    int partite_totali = 0;
    int partite_vinte = 0;
    int tentativo_migliore = 999; // Inizializzato alto
    
    printf(" === GIOCO INDOVINA IL NUMERO ===\n");
    
    do {
        printf("\n=== SCEGLI MODALITÀ ===\n");
        printf("1.  Facile (1-20, 8 tentativi)\n");
        printf("2.  Medio (1-50, 6 tentativi)\n");
        printf("3.  Difficile (1-100, 4 tentativi)\n");
        printf("4.  Statistiche\n");
        printf("5.  Esci\n");
        printf("Scelta: ");
        scanf("%d", &scelta_modalita);
        
        // Variabili di gioco
        int numero_segreto, range_max, tentativi_max;
        int tentativo_utente, tentativi_rimasti;
        int indovinato = 0;
        
        switch (scelta_modalita) {
            case 1: {
                // Modalità Facile
                printf("\n🟢 === MODALITÀ FACILE ===\n");
                range_max = 20;
                tentativi_max = 8;
                numero_segreto = 1 + rand() % range_max;
                break;
            }
            
            case 2: {
                // Modalità Media
                printf("\n🟡 === MODALITÀ MEDIA ===\n");
                range_max = 50;
                tentativi_max = 6;
                numero_segreto = 1 + rand() % range_max;
                break;
            }
            
            case 3: {
                // Modalità Difficile
                printf("\n🔴 === MODALITÀ DIFFICILE ===\n");
                range_max = 100;
                tentativi_max = 4;
                numero_segreto = 1 + rand() % range_max;
                break;
            }
            
            case 4: {
                // Statistiche
                printf("\n📊 === STATISTICHE ===\n");
                printf("Partite giocate: %d\n", partite_totali);
                printf("Partite vinte: %d\n", partite_vinte);
                printf("Partite perse: %d\n", partite_totali - partite_vinte);
                
                if (partite_totali > 0) {
                    float percentuale = (float)partite_vinte / partite_totali * 100;
                    printf("Percentuale vittorie: %.1f%%\n", percentuale);
                }
                
                if (partite_vinte > 0 && tentativo_migliore < 999) {
                    printf("Miglior risultato: %d tentativi\n", tentativo_migliore);
                }
                
                continue; // Torna al menu senza giocare
            }
            
            case 5: {
                printf("Grazie per aver giocato! 👋\n");
                continua_gioco = 0;
                continue; // Esci dal programma
            }
            
            default: {
                printf("Scelta non valida!\n");
                continue; // Torna al menu
            }
        }
        
        // Se arriviamo qui, una modalità di gioco è stata scelta
        if (scelta_modalita >= 1 && scelta_modalita <= 3) {
            partite_totali++;
            tentativi_rimasti = tentativi_max;
            indovinato = 0;
            
            printf("Ho pensato a un numero tra 1 e %d!\n", range_max);
            printf("Hai %d tentativi. Buona fortuna!\n\n", tentativi_max);
            
            // Loop principale di gioco
            while (tentativi_rimasti > 0 && !indovinato) {
                printf("Tentativo %d/%d: ", tentativi_max - tentativi_rimasti + 1, tentativi_max);
                scanf("%d", &tentativo_utente);
                
                // Validazione input
                if (tentativo_utente < 1 || tentativo_utente > range_max) {
                    printf("Inserisci un numero tra 1 e %d!\n", range_max);
                    continue; // Non conta come tentativo
                }
                
                // Controllo risposta
                if (tentativo_utente == numero_segreto) {
                    indovinato = 1;
                    int tentativi_usati = tentativi_max - tentativi_rimasti + 1;
                    
                    printf("🎉 BRAVO! Hai indovinato in %d tentativi!\n", tentativi_usati);
                    
                    // Aggiorna statistiche
                    partite_vinte++;
                    if (tentativi_usati < tentativo_migliore) {
                        tentativo_migliore = tentativi_usati;
                        printf("🏆 Nuovo record personale!\n");
                    }
                    
                } else if (tentativo_utente < numero_segreto) {
                    printf("📈 Troppo basso!\n");
                    tentativi_rimasti--;
                } else {
                    printf("📉 Troppo alto!\n");
                    tentativi_rimasti--;
                }
                
                // Suggerimenti quando rimangono pochi tentativi
                if (tentativi_rimasti > 0 && !indovinato) {
                    if (tentativi_rimasti == 1) {
                        printf("💡 ULTIMO TENTATIVO! ");
                        if (numero_segreto % 2 == 0) {
                            printf("Il numero è pari.\n");
                        } else {
                            printf("Il numero è dispari.\n");
                        }
                    } else if (tentativi_rimasti == 2) {
                        printf("💡 SUGGERIMENTO: ");
                        if (numero_segreto <= range_max / 2) {
                            printf("Il numero è nella prima metà del range.\n");
                        } else {
                            printf("Il numero è nella seconda metà del range.\n");
                        }
                    }
                    
                    printf("Tentativi rimasti: %d\n\n", tentativi_rimasti);
                }
            }
            
            // Fine partita
            if (!indovinato) {
                printf("💥 Hai esaurito i tentativi!\n");
                printf("Il numero era: %d\n", numero_segreto);
            }
            
            // Chiedi se giocare ancora
            int gioca_ancora;
            printf("\nVuoi giocare un'altra partita? (1=Sì, 0=Menu, -1=Esci): ");
            scanf("%d", &gioca_ancora);
            
            if (gioca_ancora == -1) {
                printf("Grazie per aver giocato! 👋\n");
                continua_gioco = 0;
            } else if (gioca_ancora == 0) {
                // Torna al menu (continua il do-while)
                continue;
            }
            // Se gioca_ancora == 1, continua con il menu per scegliere modalità
        }
        
    } while (continua_gioco);
    
    return 0;
}
#include <stdio.h>
#include <string.h>

typedef struct {
    char marca[30];
    char modello[30];
    int anno;
    float chilometraggio;
    int cavalli;
} Automobile;

int main() {
    Automobile auto1;
    
    // Accesso diretto con operatore punto
    strcpy(auto1.marca, "Toyota");
    strcpy(auto1.modello, "Corolla");
    auto1.anno = 2020;
    auto1.chilometraggio = 15000.5;
    auto1.cavalli = 132;
    
    // Lettura con operatore punto
    printf("Auto: %s %s del %d\n", auto1.marca, auto1.modello, auto1.anno);
    printf("Km: %.1f - Potenza: %d CV\n", auto1.chilometraggio, auto1.cavalli);
    
    return 0;
}
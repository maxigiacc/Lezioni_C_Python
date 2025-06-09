#include <stdio.h>

/*
Data la seguente formula:
𝐶= 5/9 (𝐹−32)
Dove:
- C: gradi Celsius;
- F: gradi Fahreneit
Si scriva un programma che, preso in input la temperatura in gradi Fahreneit, 
faccia la conversione in gradi Celsius

Esempio: 77 gradi Fahreneit —> 25 gradi Celsius


*/

int main() {

    int temperaturaF = 0;
    float resultC = 0.0;
    int numeratore = 5;
    int den = 9;

    printf("Inserisci la temperatura in gradi Fahreneit: ");
    scanf("%d", &temperaturaF);

    //operazione di casting: esempio: int -> float
    // 𝐶= 5/9 (𝐹−32)

    resultC = (float)numeratore / den  * (temperaturaF - 32);

    printf("La temperatura in gradi Celsius è: %.3f", resultC);
    return 0;
}
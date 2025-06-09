#include <stdio.h>

void scambia(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("Dentro scambia: a=%d, b=%d\n", *a, *b);
}

int main() {
    int x = 5, y = 10;
    
    printf("Prima dello scambio: x=%d, y=%d\n", x, y);
    scambia(&x, &y);
    printf("Dopo lo scambio: x=%d, y=%d\n", x, y);
    
    return 0;
}
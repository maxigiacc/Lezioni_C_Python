#include <stdio.h>

int main() {
    int numeri[] = {10, 20, 30, 40, 50};
    int *ptr = numeri;  // Equivale a: int *ptr = &numeri[0];
    
    printf("=== DIMOSTRAZIONI ===\n");
    printf("numeri: %p\n", numeri);
    printf("&numeri[0]: %p\n", &numeri[0]);
    printf("ptr: %p\n", ptr);
    printf("Tutti e tre sono uguali!\n\n");
    
    // Accesso agli elementi
    printf("=== ACCESSO AGLI ELEMENTI ===\n");
    for (int i = 0; i < 5; i++) {
        printf("Elemento %d:\n", i);
        printf("  numeri[%d] = %d\n", i, numeri[i]);
        printf("  *(numeri + %d) = %d\n", i, *(numeri + i));
        printf("  *(ptr + %d) = %d\n", i, *(ptr + i));
        printf("  ptr[%d] = %d\n", i, ptr[i]);
        printf("\n");
    }
    
    return 0;
}
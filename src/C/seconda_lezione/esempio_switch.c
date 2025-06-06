#include <stdio.h>

int main () {

    char c = getchar();
    switch (c) {
        case 'A':
            printf("Hai inserito la Vocale A");
            break;
        case 'E':
            printf("Hai inserito la Vocale E");
            break;
        case 'I':
            printf("Hai inserito la Vocale I");
            break;
        case 'O':
            printf("Hai inserito la Vocale O");
            break;
        case 'U':
            printf("Hai inserito la Vocale U");
            break;
        default:
            printf("Non hai inserito nessuna vocale");
            break;
    }

    return 0;

}

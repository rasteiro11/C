#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int count = 10, x;
    int *int_pointer;

    int_pointer = &count;
    x = *int_pointer;

    printf("count = %i, x = %i\n", count, x);

    int numero = 54, num;
    int *pnumero = &numero;

    num = *pnumero;

    printf("numero = %i, x = %i\n", numero, num);

    char nome[] = "titico03", name;
    char *pnome = nome;

    
    printf("meu nome e: %s", pnome);


    return 0;
}
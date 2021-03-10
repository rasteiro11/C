#include <stdlib.h>
#include <stdio.h>

int main() {
    int i = 10;
    float f = 2.34;
    char ch = 'k';

    void *vptr;

    vptr = &i;
    printf("Value of i = %i\n", *(int*)vptr);

    vptr = &f;
    printf("Value of f = %.2f\n", *(float*)vptr);

    vptr = &ch;
    printf("Value of ch = %c\n", *(char*)vptr);






    return 0;
}
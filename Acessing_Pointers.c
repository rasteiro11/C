#include <string.h>
#include <stdio.h>

int main() {
    int number = 0;
    int *pnumber = NULL;

    number = 10;
    printf("number`s address: %p\n", &number);
    printf("number`s value: %d\n\n", number);

    pnumber = &number; //Pointer: &
    
    printf("pnumber`s address: %p\n", (void*) &pnumber);
    printf("pnumber`s size: %d bytes\n", sizeof(pnumber));
    printf("pnumber`s value: %p\n", pnumber);
    printf("value pointed to: %d\n", *pnumber); //Value inside Pointer: *

    return 0;   
}
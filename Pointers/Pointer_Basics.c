#include <stdlib.h>
#include <stdio.h>

int main() {
    int num = 150, x;
    int *pNum = NULL;


    pNum = &num;

    printf("num address is: %p\n", &num);
    printf("address of pNum: %p\n", &pNum);
    printf("Value of the pNum: %p\n", pNum);
    printf("Value inside pNum %i\n", *pNum);

    






    return 0;
}
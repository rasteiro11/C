#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int a = 33;
    int b = 15;
    int result1 = 0;

    result1 = a + b;
    printf("c is %d\n", result1);

   //divisao com resto: %
   //acrescentar 1 antes: ++a ou --a (subtracao)
   //acrescentar 1 depois: a++ ou a-- (subtracao)

    bool c = true;
    bool d = false;
    bool result2;

    result2 = c || d;
    // && : AND
    // || : OR
    // ! : NOT

    printf("%d", result2);


    return 0;
}
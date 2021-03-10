#include <stdlib.h>
#include <stdio.h>

void square(int * x);




int main(){
    /*
    int *num = (int *)malloc(sizeof(int));
    *num = 4;
    */
   int num = 5;
    square(&num);
    printf("The square of the given number is %d", num);



    return 0;
}

void square(int * x){
    *x = (*x) * (*x);
}
 #include <stdio.h>

 int arraySum(int *ptr, const int n);



 void main(void) {
     int values[10] = { 3, 7, -9, 3, 6, -1, 7, 9, 1, -5 };
     printf("The sum is %i\n", arraySum(values, 10));
 }

 int arraySum(int *ptr, const int n){
    int sum = 0;
    int * const arrayEnd = ptr + n;

    for( ; ptr < arrayEnd; ++ptr )
        sum += *ptr;

    return sum;
 }
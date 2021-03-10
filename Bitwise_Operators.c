#include <stdio.h>

int main(){
    unsigned int a = 60; // 0011 1100     
    unsigned int b = 13; // 0000 1101                                           
    int result = 0;                                                             
                                                                                
    //result = a & b; // 0000 1100                                              
    //result = a | b; // 0011 1101
    result = a >> 2; // 0000 0011
    printf("result is: %d", result);

    return 0;
}
/*
The & (bitwise AND) in C or C++ takes two numbers as operands and does AND on every bit of two numbers. The result of AND is 1 only if both bits are 1.
The | (bitwise OR) in C or C++ takes two numbers as operands and does OR on every bit of two numbers. The result of OR is 1 if any of the two bits is 1.
The ^ (bitwise XOR) in C or C++ takes two numbers as operands and does XOR on every bit of two numbers. The result of XOR is 1 if the two bits are different.
The << (left shift) in C or C++ takes two numbers, left shifts the bits of the first operand, the second operand decides the number of places to shift.
The >> (right shift) in C or C++ takes two numbers, right shifts the bits of the first operand, the second operand decides the number of places to shift.
The ~ (bitwise NOT) in C or C++ takes one number and inverts all bits of it
*/
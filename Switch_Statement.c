#include <stdlib.h>
#include <stdio.h>

int main(){
    enum Weekday { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };
    enum Weekday today = Monday; 

    switch (today)
    {
    case Sunday:
        printf("Today is Sunday");
        break;
    case Monday:
        printf("Today is Monday");
        break;
    case Tuesday:
        printf("Today is Tuesday");
    default:
        printf("Whatever");
        break;
    }
    return 0;
}

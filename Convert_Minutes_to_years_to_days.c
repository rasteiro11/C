#include <stdio.h>
#include <stdlib.h>

int main()
 {
     int minutesEntered = 0;
     double years = 0.0;
     double days = 0.0;
     double minutesInYear = 0.0;

    printf("Please enter the number of minutes: ");
    //get the input from user
    scanf("%d", &minutesEntered);

    minutesInYear = (60 * 24 * 365);

    years = (minutesEntered / minutesInYear);
    days = (int)(minutesEntered / 60.0) / 24.0;

    printf("%d mmiutes is approx %f years and %f days \n", minutesEntered, years, days);
    return 0;
 }

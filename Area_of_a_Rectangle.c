#include <stdio.h>
#include <stdlib.h>

int  main(int argc, char *argv[]) {
    double width = atoi(argv[1]);
    double height = atoi(argv[2]);
    double perimiter = 0.0;
    double area = 0.0;

    perimiter = 2.0 * (height + width);
    area = width * height;

    printf("Width is: %.2f, Height is: %.2f, Perimiter is: %.2f\n", width, height, perimiter);
    printf("Area is: %f\n", area);

    return 0;
}
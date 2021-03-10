#include <stdio.h>
#include <string.h>

int main() {
    char myString[] = "My name is Jason";
    char temp[50];
    printf("The length is: %d\n", strlen(myString));
    printf("The string is: %s\n", myString);
    strncpy(temp, myString, sizeof(temp) - 1);
    printf("The string is: %s\n", temp);

    char src[50], dest[50];

    strcpy(src, "This is source");
    strcpy(dest, "This is destination");

    strncat(dest, src, 15);
    printf("Final Destination string: |%s|\n", dest);

    printf("strcmp(\"A\", \"A\") is ");
    printf("%d\n", strcmp("A", "A"));

    printf("strcmp(\"A\", \"B\") is ");
    printf("%d\n", strcmp("A", "B"));

    printf("strcmp(\"C\", \"A\") is ");
    printf("%d\n", strcmp("C", "A"));

    printf("strcmp(\"Z\", \"a\") is ");
    printf("%d\n", strcmp("Z", "a"));

    printf("strcmp(\"apples\", \"apple\") is ");
    printf("%d\n", strcmp("apples", "apple"));
    
    
    



    return 0;
}


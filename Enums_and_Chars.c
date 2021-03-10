#include <stdio.h>
#include <stdbool.h>

int main() {
    enum gender {male, female};

    enum gender myGender;
    myGender = male;

    enum gender anotherGender = female;

    bool isMale = (myGender == anotherGender);

    char myCharacter = '\n';
    printf("%c", myCharacter);


    return 0;
}
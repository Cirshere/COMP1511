// Programs that will print out inputted text if it has not been printed before
// Christopher Hoang, z5259780
// 08/04/2020

#include<stdio.h>
#include<string.h>

#define SIZE 256

int main (void) {

    char input[SIZE];
    fgets(input, SIZE, stdin);
    
    while (input != NULL) {
        putchar(input);
        input = getchar();
    } 

    return 0;
}

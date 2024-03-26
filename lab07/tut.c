// Tutorial 7
// z5259780 31/03/2020

#include<stdio.h>

//getchar putchar fgets

// %c for chacters
// %d for ascii no of character
// %s for printing a string of charactesr

// getchar -> accepts text from console and assigns to a char
// E.g. int character = getchar();

// putchar -> Prints the character that has been inputted
// E.g. putchar(character);

// Example of a program that accepts a string of text until ended.

int main (void) {
 
    int character = getchar();
    
    while (character != EOF) {
        putchar(character);
        character = getchar();
    }
    
    return 0;
}

// Strings
// # 1
// char buff[SIZE] ] {'H', 'i'};

// printf ("the string is: %s\n", buffer); < - %s prints till end of array

// # 2

// char buffer[] = "Hello!";

// printf("string is: %s\n", buffer);

// Character arrays can not be assignment to UNLESS it is a pointer

// char *buf = "Hello";
// buf = "world!";

// fgets

    char buff[SIZE];
    fgets(buff, SIZE, stdin);
    printf("%s\n", buff);

// Program that parrots back
// Christopher Hoang, z5259780
// 28/04/2020

#include<stdio.h>
#include<string.h>

int main (void) {

    int input;
    input = getchar();
    
    while (input != EOF) {
        putchar(input);
        input = getchar();
    }

    return 0;
}

// Program which takes in text, and prints their decimal values.
// Christopher Hoang, z5259780
// 29/04/2020

#include<stdio.h>
#include<string.h>

int main (void) {

    int input = getchar();
    
    while (input != EOF) {
    
        printf("%d\n", input);
        input = getchar();
    
    }


    return 0;
}

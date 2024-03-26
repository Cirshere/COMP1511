// Program that reverses lines of inputted text.
// Christopher Hoang, z5259780
// 08/04/2020

#include<stdio.h>
#include<string.h>

#define SIZE 256

void reverse(char *input);

int main (void) {
 
    char input[SIZE];
    
    while (fgets(input,SIZE,stdin) != NULL) {
        reverse(input);
        printf("\n");
    }
    
    return 0;    
}

void reverse (char *input) {
    
    int i = strlen(input) - 2;   
    
    while(i >= 0) {    
        putchar(input[i]);
        i--;        
    }

}

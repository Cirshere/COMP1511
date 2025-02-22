// Program that takes converts upper case to lower case in an argument
// Christopher Hoang, z5259780
// 14/04/2020

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define SIZE 40

int main (int argc, char* argv[]) {

    int i = 1;   
    
    while (i < argc) {
        
        char word[SIZE];
        
        strcpy(word, argv[i]);
        
        int j = 0;
        
        while (j < strlen(argv[i])) {
            
            if (word[j] >= 'A' && word[j] <= 'Z') {
                putchar(word[j] + 32);
            }
            else {
                putchar(word[j]);
            }
            
            j++;
        }
        
        i++;
    }
    
    printf("\n");
    
    return 0;

}


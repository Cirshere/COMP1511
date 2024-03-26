// Program that shifts letters by an inputted amount
// Christopher Hoang , z5259780
// 31/03/2020

#include<stdio.h>

void encrypt(int character, int shift);

int main (void) {

    int shift;
    scanf("%d", &shift);
    printf("\n");
    
    
    
    while (shift > 26 || shift < -26) {
        if (shift > 26) {
            shift -= 26;
        }
        else if (shift < -26) {
            shift += 26;
        }        
    }
    
    if (shift < 0) {
        shift += 26;
    }
    
    int character = getchar();

    
    while (character != EOF) {
        encrypt(character, shift);
        character = getchar();
    }
    
    return 0;
}

void encrypt(int character, int shift) {

    if (character >= 'a' && character <= 'z') {
        if (character + shift > 'z') {
            putchar ('a' + (character + shift - 'z') - 1);
        }
        else if (character + shift < 'a') {
            putchar('z' - (character + shift - 'a') - 1); 
        }
        else
            putchar(character + shift);
    }
    else if (character >= 'A' && character <= 'Z') {
        if (character + shift > 'Z') {
            putchar ('A' + (character + shift - 'Z') - 1);
        }
        else if (character + shift < 'A') {
            putchar ('Z' - (character + shift - 'A') - 1);
        }
        else {
            putchar (character + shift);
        }
    }
    else {
        putchar(character);
    }
    
}

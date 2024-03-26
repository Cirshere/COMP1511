// Program to display the integers 32 - 126 in decimal and hexadecimal
// Christopher Hoang, z5259780
// 28/04/2020

#include<stdio.h>

int main (void) {

    int i = 32;
    
    while (i >= 32 && i <= 126) {
        
        // %d - integer associated %x - Hexadecimal "" %c - Character ""
        printf ("%d 0x%x %c\n", i, i, i);
        
        i++;
    }

    return 0;
}

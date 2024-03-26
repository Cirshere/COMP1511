// Program that removes lower case vowels from a string of text
// Christopher Hoang, z5259780
// 31/03/2020

#include<stdio.h>

int main (void) {

    int ch = getchar();
    
    while (ch != EOF) {
        if (ch != 'a'&& ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u') {
            putchar(ch);
        }
        ch = getchar();
    }

    return 0;
}

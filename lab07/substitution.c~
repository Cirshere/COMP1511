// Program that encrypts using the substitution cypher
// Christopher Hoang, z5259780
// 31/03/2020

#include<stdio.h>

#define SIZE 26 + 1

void encrypt(char *alphabet, char *cipher, int input);

int main (void) {
    
    char alphabet[SIZE] = "abcdefghijklmnopqrstuvwxyz";
    char cipher[SIZE];
    fgets (cipher, SIZE, stdin);
    int input = getchar();
    
    while (input != EOF) {
    
        input = getchar();
        encrypt(alphabet, cipher, input);
    }
    
    return 0; 
}

void encrypt (char *alphabet, char *cipher, int input) {

    int i = 0;

    if ( (input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z')) {

        while (i < SIZE) {
            
            if (input == alphabet[i]) {
                putchar(cipher[i]);
                i = SIZE;
            }
            else if (input == alphabet[i] - 32) {
                putchar(cipher[i] - 32);
                i = SIZE;
            }
            i++;
        }
    
    }
    
    else if (input != EOF) {
        putchar(input);
    }

}

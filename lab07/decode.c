// Program that decrypts text encrypted by subsitition
// Christopher Hoang, z5259780
// 05/04/2020

#include<stdio.h>

#define SIZE 26 + 1

void decrypt(char *alphabet, char *cipher, int input);

int main (void) {
    
    char alphabet[SIZE] = "abcdefghijklmnopqrstuvwxyz";
    char cipher[SIZE];
    fgets (cipher, SIZE, stdin);
    int input = getchar();
    
    while (input != EOF) {
    
        input = getchar();
        decrypt(alphabet, cipher, input);
    }
    
    return 0; 
}

void decrypt (char *alphabet, char *cipher, int input) {

    int i = 0;

    if ( (input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z')) {

        while (i < SIZE) {
            
            if (input == cipher[i]) {
                putchar(alphabet[i]);
                i = SIZE;
            }
            else if (input == cipher[i] - 32) {
                putchar(alphabet[i] - 32);
                i = SIZE;
            }
            i++;
        }
    
    }
    
    else if (input != EOF) {
        putchar(input);
    }

}

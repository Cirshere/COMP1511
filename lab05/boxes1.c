// Program to print a grid of n boxes 
// z5259780, Christopher Hoang 20/03/2020

#include<stdio.h>

int main (void) {
    
    int input;
    int size;
    
    printf("How many boxes: ");
    scanf("%d", &input);
    
    size = input * 4 - 1;
    
    int box[size][size];
    
    int i = 0;
    int j = 0;
    
    // Sets up up array to be 1s
    while (i < size) {   
        j = 0;
        while (j < size) {    
            box[i][j] = 1;            
            j++;
        }
        i++;
    }
    
    i = 0;
    j = 0;
    int k = 0;
    
    // Creates the 0 boxes
    while (i < size) {
        j = 0;
        while (j < size) {
            if(i % 2 != 0 && i + k < size - 1) {
                box[i][j + k] = 0;
                k += 2;       
            }                
        }    
    }     
    
    i = 0;
    j = 0;
    
    while (i < size) {
        j = 0;
        while (j < size) {
            printf("%d", box[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }

    
    return 0;

}

// Program to print a grid of n boxes 
// z5259780, Christopher Hoang 20/03/2020

#include<stdio.h>

int main (void) {
    
    int input;
    int size;
    
    printf("How many boxes: ");
    scanf("%d", &input);
    
    if (input <= 0) {
        return 0;
    }
    
    size = input * 4 - 1;
    
    int box[size][size];
    
    int i = 0;
    int j = 0;
    
    // Sets up up array to be 0s
    while (i < size) {   
        j = 0;
        while (j < size) {    
            box[i][j] = 0;            
            j++;
        }
        i++;
    }
    
    // Creates the 1 boxes
    i = 0;
    int k = 0;
    

    while (k <= (input - 1) * 2) {
        i = k;
        while (i < size - k) {
            j = k;
            
            while (j < size - k) {
                if (i == k || j == k) {
                    box[i][j] = 1;
                }    
                else if (i == size - k - 1 || j == size - k - 1) {
                    box[i][j] = 1;
                }
                j++;
            }
            
            i++;
        }
        k += 2;
    }
    
    // Prints the array
        
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

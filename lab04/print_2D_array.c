// Print a 2D array

#include <stdio.h>

#define SIZE 4

void print_2D_array(int array[SIZE][SIZE]);


int main(void) {
    int array[SIZE][SIZE] = {
        {0, 1, 2, 3}, 
        {4, 5, 6, 7}, 
        {8, 9, 10, 11}, 
        {12, 13, 14, 15}
    };
    print_2D_array(array);
    return 0;
}

void print_2D_array(int array[SIZE][SIZE]) {
    
    int i = 0;
    
    while (i < SIZE) {
        int j = 0;
        
        while (j < SIZE) {
            if(array[i][j] < 10) {
                printf("0%d ", array[i][j]);        
            }
            
            else {
                printf("%d ", array[i][j]);
            }
            
            
            j++;
        }
    
        i++;
        printf("\n");
    }
}

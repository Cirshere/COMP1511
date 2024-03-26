//Loops - Grid of stars

#include<stdio.h>

int main (void) {

    int y = 0;
    
    while (y < 10) {
        
        int x = 0;
        
        while (x < 10) {
            printf ("*");
            
            x = (x + 1);            
        }
        
    printf("\n");
    
    y = (y + 1);
    
    }    
    
    return 0;
}

// Program that accepts an integer (n) and prints out an n*n X
// z5259780 Christopher Hoang 03/03/2020

#include<stdio.h>

int main (void) {

    int input;
    printf("Enter size:");
    scanf("%d", &input);

    int i = 0;     
    
    while (i < input/2 + 1) {
    
        int k = 0;
        while (k < i) {
            
            printf("-");
            k++;            
        }
        
        printf("*");
        
        int j = 0;
        
        while (j < input - 2*i) {
        
            printf("-");
            j++;
        
        }
        
        printf("*");
        
        int l = 0;
        
        while (l < i) {
            printf("-");
            l++;
        }
        
    i++;
    printf("\n");
    }
    
    int x = 0;
    while (x < i) {
        printf("-");
        x++;
    }
    
    printf("*");
    
    int y = 0;
    while (y < i) {
        printf("-");
        y++;
   
    printf("\n");
    }
    i = 1;
    
    while (i <= input/2 + 1){
    
        int a = 0;
        while (a <= input - i) {
        
            printf("-");
            a++;
        
        }
        
        printf("*");     
     
        
    }
    
    return 0;
}

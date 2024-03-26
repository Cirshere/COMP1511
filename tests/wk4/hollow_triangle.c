// Prints a hollow triangle made of astrisks
// z5259780, Christopher Prints

#include<stdio.h>

int main (void){
    
    int size;
    
    printf("Enter size: ");
    scanf("%d", &size);
    
    printf("*\n");
    
    int i = 0;
    
    while(i < size - 2){
        int j = 0;
        printf("*");
        
        while (j < i) {
            printf(" ");
            j++;
        }
        printf("*");
        if (i < size) {
            printf("\n");
        }
        i++;
    }
    
    i = 0;
    
    while (i < size) {
    
        printf("*");
        i++;
    }
    
    printf("\n");
    
    return 0;

}

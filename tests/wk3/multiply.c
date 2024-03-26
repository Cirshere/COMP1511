// Program that reads 2 integers and then displays their multiple
// z5259780, Christopher Program

#include<stdio.h>

int main (void) {

    int inputa;
    int inputb;
    
    scanf("%d", &inputa);
    scanf("%d", &inputb);
    
    int multiple = inputa * inputb;
    
    if(multiple == 0) {
        
        printf("zero\n");
    
    }

    else if(multiple < 0) {
    
        printf("%d\n", -1 * multiple);
    
    }
    
    else {
    
        printf("%d\n", multiple);
    
    }
    
    
    return 0;

}

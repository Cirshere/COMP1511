//Number to Words from 1 - 5
//z5259780, Christopher Hoang 25/02/20

#include<stdio.h>

int main(void) {
    
    int input;
    
    printf("Please enter an integer:");
    
    scanf("%d", &input);
    
    if (input == 1) {
        printf("You entered one.\n");
    }
    else if (input == 2) {
        printf("You entered two.\n");
    }
    else if (input == 3) {
        printf("You entered three.\n");
    }
    else if (input == 4) {
        printf("You entered four.\n");
    }
    else if (input == 5) {
        printf("You entered five.\n");
    }
    else if (input < 1) {
        printf("You entered a number less than one.\n");
    }
    else {
        printf("You entered a number greater than five.\n");
    }
    
    return 0;    
}

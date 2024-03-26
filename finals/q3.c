// COMP1511 Finals - Q3
// Program that accepts input until 0, then prints half of the values
// Christopher Hoang, z5259780
// 05/05/2020

#include<stdio.h>
#define MAX_SIZE 1000

int main (void) {

    int array[MAX_SIZE];
    int i = 1;
    int input;
    
    scanf("%d", &input);
    array[0] = input;
    
    while (input != 0) {
        scanf ("%d", &input);
        array[i] = input;
        i++;
    }
    
    int j = i / 2;
    i = 0;

    printf ("First Half: ");
    
    while (i < j) {
        printf ("%d ", array[i]);
        i++;
    }
    
    printf ("\n");

    return 0;
}

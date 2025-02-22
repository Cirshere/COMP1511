//Dice Range - Checks the range and average of the inputted dice
//z5259780, Christopher Hoang 25/02/20

#include<stdio.h>
#define DICE_MIN 1

int main (void) {

    int diceSides;
    int diceNumber;

    printf("Enter the number of sides on your dice:");
    scanf("%d", &diceSides);
    
    printf("Enter the number of dice being rolled:");
    scanf("%d", &diceNumber);
    
    if (diceSides <= 0 || diceNumber <= 0) {
        printf ("These dice will not produce a range.\n");
        
        return 1;    
    }
    
    printf("Your dice range is %d to %d.\n", diceNumber, diceNumber * diceSides);
    
    double avg = ((diceNumber + (diceNumber * diceSides)) / 2.0);
        
    printf("The average value is %lf\n", avg);
    
    return 0;
}

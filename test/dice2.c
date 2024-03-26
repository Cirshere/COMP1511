//Dice Check 2
//25/02/2020

#include<stdio.h>
#define TARGET 7
#define DICE_MIN 1
#define DICE_MAX 6

int main(void) {
    int dieOne;
    int dieTwo;
    
    printf("Please input your first dice roll, between %d and % d\n", DICE_MIN, DICE_MAX);
    scanf("%d", &dieOne);
    
    if (DICE_MIN <= dieOne && dieOne <= DICE_MAX) {
        printf("Roll is valid");
    } else {
        dieOne = (dieOne % DICE_MAX) + 1, 
    
    } 

}

//Clamping solution    
/*    else if (dieOne > DICE_MAX) {dieOne = DICE_MAX;
    
    }else (dieOne < DICE_MIN) {dieOne = DICE_MIN;}
    
       */
    
//End program solution
  
/*      else {
        printf(
            "The roll of %d is not between %d and %d. The program will now exit\n",
            dieOne, DICE_MIN, DICE_MAX);
            
        return 1; //Ends program
    }*/
    
    scanf("%d", &dieTwo);
    printf("%d\n", dieTwo);
    
    
    return 0;
    } 
   


//Lecture 5 - Code Styles and Functions
//z5259780 Christopher Hoang 03/03/2020

#include<stdio.h>

//Function is declared but not defined
int add (int a, int b);

//Numbers are defined
int main (void) {
    
    int firstNum = 4;
    int secondNum = 5;
    int total = add(firstNum, secondNum); 
    //The line above will refer to line 7 and 27 in order to define 'add'
    //Line 27 defines 'add,' add = 10, then returns answer for 'total'
    
    
    printf("%d\n", total);
    
    return 0;

}

//Function is now defined

int add (int a, int b) {
    return a + b;

//Void functions --> Returns no output. E.g. can be used to give info to user
//but will not retain
}

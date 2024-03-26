// Introduction to arrays -- Program to store and provide test sccores
// z5259780 Christopher Hoang 04/03/2020

// Arrays allow us to store a collection of variables together 
// [] are used to declare the size of the array
// Elements are a single variable inside an arry. They are accessed from their
// index, starting from 0

#include<stdio.h>

int main (void) {
    
    int arrayOfMarks[10] = {0}; 
    
    int inputCount = 0;
    int studentNum = 0;
    
    while (inputCount <= 9) {
        printf("Enter Student %d marks:", studentNum);
        scanf("%d", &arrayOfMarks[studentNum]);
    
        inputCount++;
        studentNum++;
    
    }
    
    studentNum = 0;
    
    while (studentNum <= 9) {
        printf("Student %d got %d\n", studentNum, arrayOfMarks[studentNum]);
        studentNum++;
        
    }

    return 0;

}

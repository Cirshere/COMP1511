// COMP1511 - Finals - Q5
// Program that prints the most common argument
// Christopher Hoang, z5259780
// 05/05/2020

#include<stdio.h> 
#include<string.h>

int main (int argc, char* argv[]) {
    
    int i = 1;
    int highest = 0;
    int common = 1;
    
    while (i < argc) {
        
        int count = 0; 
        int j =  1;
        
        while (j < argc) {
            if (strcmp(argv[i],argv[j]) == 0) {
                count++;
            }
            j++;
        }
        
        if (count > highest) {
            highest = count;
            common = i;
        }
        
        i++;
    }
    
    printf("%s", argv[common]);
    
    return 0;
}

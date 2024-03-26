#include<stdio.h>

struct person {
    int age;
    double height;
    char name;
    double mark;
};

int main (void) {

    //1. Decleration

    struct person Tom;
    //2. Initialisation

    Tom.age = 18;
    Tom.name = "Tom";
    Tom.height 175.5;
    Tom.mark = 88.9;
    
    

    return 0;
}

// When using arrows in C, consider 1. Is it a pointer? 2. Is this equal to null

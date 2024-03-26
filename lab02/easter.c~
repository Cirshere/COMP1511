//Easter - Program to determine the date of easter depending on the year
//z5259780, Christopher Hoang 25/02/20

#include<stdio.h>

int main (void) {
    
    int year, a, b, c, d, e, f, g, h, i, k, l, m, p;
    int easter_month, easter_date;
    
    printf ("Enter year:");
    scanf ("%d", &year);
    
    a = (year % 19);
    b = (year / 100);
    c = (year % 100);
    d = (b / 4);
    e = (b % 4);
    f = ((b + 8) / 25);
    g = ((b - f + 1) / 3);
    h = ((19 * a + b - d - g + 15) % 30);
    i = (c / 4);
    k = (c % 4);
    l = ((32 + 2 * e + 2 * i - h - k) % 7);
    m = ((a + 11 * h + 22 * l) / 451);
    p = ((h + l - 7 * m + 114) % 31);
    easter_month = ((h + l - 7 * m + 114) / 31);
    easter_date = ((p + 1));
    
    if (easter_month == 3) {
        printf("Easter is March %d in %d.\n", easter_date, year);
    }    
    
    else {
        printf("Easter is April %d in %d.\n", easter_date, year);
    }
    
    return 0;
}

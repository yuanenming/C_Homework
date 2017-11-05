#include <stdio.h>
/* lower: convert upper case letter to lower case */
int lower (int c) {
      c = (c >='A' && c <= 'Z')?c + 'a' -'A':c;
            return c; }
int main(){
    char x='T',y='o';
    printf("Input character:%c\tLower case:%c\n", x, lower(x));
    printf("Input character:%c\tLower case:%c\n", y, lower(y));
    return 0;
}

#include <stdio.h>
/* bitcount: count the number of 1-bits in x */
int bitcount (unsigned x) {
  int b;
  for (b = 0; x!=0; x &= (x-1))
	 ++b;
return b;
}


int main(){
unsigned x = 1023,y=1024;
printf("Input number:%d\tNumber of 1-bits:%d\n", x, bitcount(x));
printf("Input number:%d\tNumber of 1-bits:%d\n", y, bitcount(y));
 return 0;
}

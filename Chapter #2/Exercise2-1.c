#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    
   printf("The range of CHAR is :  (%d,%d)\n", CHAR_MIN,CHAR_MAX);
   printf("The range of SIGNED CHAR is :  (%d,%d)\n", SCHAR_MIN, SCHAR_MAX);
   printf("The range of UNSIGNED CHAR is :  (%d,%u)\n\n", 0, ULONG_MAX);
   
   printf("The range of SHORT is : (%d,%u)\n", 0, USHRT_MAX);
   printf("The range of UNSIGNED SHORT is : (%d,%d)\n\n", SHRT_MIN, SHRT_MAX);// I DIDN'T FIND A SIGNED VALUE FOR SHORT
   
   printf("The range of INT is : (%d,%d)\n", SHRT_MIN, SHRT_MAX);
   printf("The range of UNSIGNED INT is : (%d,%d)\n\n", 0, USHRT_MAX);
   
   printf("The range of LONG is :  (%ld,%ld)\n", LONG_MIN, LONG_MAX);
   printf("The range of UNSIGNED LONG is : (%d,%lu)\n\n", 0, ULONG_MAX);
   
   //SOME RANGES OF FLOAT
   
   printf("The range of FLOATING POINT NUMBER is ; (%.4e,%.4e)\n\n", FLT_MIN,FLT_MAX);
   
   printf("The range of DOUBLE FLOATING POINT NUMBER is ; (%.4e,%.4e)", DBL_MIN,DBL_MAX);
   return 0;
}

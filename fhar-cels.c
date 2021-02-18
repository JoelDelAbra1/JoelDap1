
#include <stdio.h>
  
int main () {
  
 printf ("     Fharenheit to celsius\n");
  
 float celsius, fahr;
  
 float lower=0, upper=300, step=20;
  
 fahr=lower;
  
while (fahr <= upper) {
    
    celsius = 5.0 * (fahr - 32) / 9.0;
      
    printf ("\t%3.0f\t%3.1f\n", fahr, celsius);
      
    fahr += step;
    
    }

}

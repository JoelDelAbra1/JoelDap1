#include <stdio.h>

int main ( ){
printf("     Celsius to fahrenheit\n");

 float cel,fahr;
 float low=0, up=300, st=20 ;

 cel = low;

 while (cel <= up){
     
 fahr = ( (cel * 9) /5)  + 32;
 
 printf("\t%3.0f\t%3.1f\n", cel, fahr);
 
 cel += st;
 }
}

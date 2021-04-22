#include <stdio.h>
#include <ctype.h>

int main (){
   int i = 0;
   char c;
   char str[] = "HELLO THERE";
	
   while ( str[i] ){
      putchar(tolower(str[i]));
      i++;
   }
   
   return(0);
}

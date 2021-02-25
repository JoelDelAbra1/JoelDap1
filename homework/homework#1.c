// i based in the exercise 1-23
#include <stdio.h>
#define MAX 500 // se puede cambiar

char fin[MAX];

int main() {
   char c;
   int tri(){
       
    extern char fin[];
    
    int c, i = 0;
    int p = 0;
   	    for (; i < MAX - 1  && (c = getchar()) != EOF && c != '>' ;) {
   	        
      if (c == '<' ) {
          p ++;   
      }if (p == 0) {
          fin[i++] = c;
      }
    }fin[i] = '\0'; //En i termina y borra
     
  return c == EOF;
  }
  
    extern char fin[];
    int l ;
    
  while ((l = tri()) == 0){
     printf("%s", fin);
     }   
}

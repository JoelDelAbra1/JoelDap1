#include <stdio.h> // My classmate rulgamer03 helped me
#include <ctype.h> // isdigit() & ispunct()

#define IN 1
#define OUT 0

int main() {
  int  digit = OUT, paren = OUT, c ;
  while ((c = getchar()) != EOF) {
      switch(c){
      case '[' : case '(' : case '{' : case '<' :  case '"' :
          paren = IN;
          putchar(c);
          break;
          
      case ']' : case ')' : case '}' :case '>' :
          paren = OUT;
          putchar(c);
          break;
          
      default:
        if(!ispunct(c)){
            if (paren == IN){
            putchar(c);
            }else{
                if(!ispunct(c)){
            if (paren == IN){
            putchar(c);
            }if (isdigit(c) ){
            	digit++;
			}else{
				digit = 0;
			}if (digit == 1){
                    putchar('x');
                }if (digit == 0){
                    putchar(c);
                 }
               }
            }
		}
    }
    }
return 0;
}
    

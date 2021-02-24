#include <stdio.h>

#define MAX 500

char linea[MAX];

int main (){
  char c;
  int space = 0;
  int saca ()
  {
    extern char linea[];
    int c, i = 0;
    int sc = 0;
    for (; i < MAX - 1 && (c = getchar ()) != EOF && c != '>';) {
	if (c == '<') {
	    sc++;
	    if (sc == 2) {
		i++;		//posible error
	      }
	  }
	if (sc < 1) {
	    linea[i++] = c;
	  }
      }
    linea[i] = '\0';
    return c == EOF;
  }
  extern char linea[];
  int l;
  while ((l = saca ()) == 0) {
      printf ("%s", linea);
    }
}

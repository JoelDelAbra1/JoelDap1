#include <stdio.h>

/* second version , Ctrl + c to finish */

int main( ){
int c;
while ((c = getchar( )) != EOF) /*EOF = End Of File , != bigger than = */
putchar(c);
}

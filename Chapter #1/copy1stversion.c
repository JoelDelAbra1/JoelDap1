#include <stdio.h>
/** Ctrl + c to finish **/
int main()
{
    int c ;

    c=getchar();

    while (c != EOF) {
        putchar(c);
        c=getchar();
    }
}

#include <stdio.h>

int main()
{
    int c,line;
    line=0;
    while((c = getchar()) != EOF)
    if (c == '\n')
        ++line;
    printf("total of new lines %d ",line);

    return 0;
}


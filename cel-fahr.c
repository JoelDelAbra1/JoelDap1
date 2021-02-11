#include <stdio.h>

int main ( )
{
printf("     Celsius to fahrenheit\n");

int low, up, st , cel , fahr;
low = 0;
up = 300;
st = 20;
cel = low;
while (cel <= up)
{
fahr = ( (cel * 9) /5)  + 32;
printf("\t%d\t%d\n", cel, fahr);
cel += st;
}
}

#include <stdio.h>

enum week { Monday = 1 , Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};

int main()
{
    enum week today;
    today = Tuesday; // Change
    printf("Day %d",today);
    return 0;
}

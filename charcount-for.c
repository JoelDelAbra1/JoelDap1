#include <stdio.h>

int main() {
  long nc;
  for (nc = 0; getchar() != EOF; nc++); /* for all in (  ) separated ;*/

  printf("%ld characters\n",nc);
}

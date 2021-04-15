#include <stdio.h>

double pop(void);
void push(double);
int getop(char[]);

char buf[BUFSIZE];
int bufp ;

int getch(void);
void ungetch(int);

#define MAX 10000


#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define BUFSIZE 100
#define FA '0'
#define VAX 100


double val[VAX];
void push(double f){
    int cop = 0;
    if (cop < VAX)
        val[cop++] = f;
    else
        printf("error:stack full, cant push %g\n", f);
} double pop(void) {
    if (cop > 0)
        return val[--cop];
    else{
        printf("error: stack empty\n");
        return 0;
    }
}
/*
while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER: push(atof(s)); break;
			case '+': push(pop() + pop()); break;
			case '*': push(pop() * pop()); break;
			case '-': op2 = pop(); push(pop() - op2); break;
			case '/': op2 = pop(); 
				if (op2 != 0.0) 
					push(pop() / op2); 
				else
					printf("error: zero divisor\n"); break;
			case '%': op2 = pop(); 
				if (op2 != 0.0) 
					push((int)pop() % (int)op2); 
				else
					printf("error: zero divisor\n"); break;
					*/
int getch(void);
void ungetch(int);
int getop(char s[])

{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t') 
        s[1] = '\n';
    i = 0;
    if (!isdigit(c) && c != '.' && c != '-')
        return c;
    if (c == '-')
        if (isdigit(c = getch()) || c == '.')
            s[++i] = c;
        else{
            if (c != EOF)
                ungetch(c);
            return '-';
        }
    
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            if (c == '.')
                while (isdigit(s[++i] = c = getch()))
                    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return FA;
}
char buf[BUFSIZE];
int buff = 0;

int getch(void)
{
    return (buff > 0) ? buf[--buff] : getchar();
}
void ungetch(int c)
{
    if (buff >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[buff++] = c;
}

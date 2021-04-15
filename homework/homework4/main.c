#include <stdio.h>
#include <stdlib.h> //atof
#include "suma.h"
#include "lib.h"
int main(){

 /*enum abcd={ 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};*/
    double op2;
    int cancelar, type, positionabc = 0, valor = 0, found_value = 0, asignado = 0, no_warning = 0;
    char c[MAX];
     double abecedario[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'}; /*sirve para que 
    el programa de la primera advertencia al querer darle un valor*/
    while ((type = getop(c)) != EOF)
        switch (tolower(type)) {
        case 'a':push(abecedario[0]);
            positionabc = 0;break;
        case 'b':push(abecedario[1]);
            positionabc = 1;break;
        case 'c':push(abecedario[2]);
            positionabc = 2;break;
        case 'd':push(abecedario[3]);
            positionabc = 3;break;
        case 'e':push(abecedario[4]);
            positionabc = 4;break;
        case 'f':push(abecedario[5]);
            positionabc = 5;break;
        case 'g':push(abecedario[6]);
            positionabc = 6;break;
        case 'h':push(abecedario[7]);
            positionabc = 7;break;
        case 'i':push(abecedario[8]);
            positionabc = 8;break;
        case 'j':push(abecedario[9]);
            positionabc = 9;break;
        case 'k':push(abecedario[10]);
            positionabc = 10;break;
        case 'l':push(abecedario[11]);
            positionabc = 11;break;
        case 'm':push(abecedario[12]);
            positionabc = 12;break;
        case 'n':push(abecedario[13]);
            positionabc = 13;break;
        case 'o':push(abecedario[14]);
            positionabc = 14;break;
        case 'p':push(abecedario[15]);
            positionabc = 15;break;
        case 'q':push(abecedario[16]);
            positionabc = 16;break;
        case 'r':push(abecedario[17]);
            positionabc = 17;break;
        case 's':push(abecedario[18]);
            positionabc = 18;break;
        case 't':push(abecedario[19]);
            positionabc = 19;break;
        case 'u':push(abecedario[20]);
            positionabc = 20;break;
        case 'v':push(abecedario[21]);
            positionabc = 21;break;
        case 'w':push(abecedario[22]);
            positionabc = 22;break;
        case 'x':push(abecedario[23]);
            positionabc = 23;break;
        case 'y':push(abecedario[24]);
            positionabc = 24;break;
        case 'z':push(abecedario[25]);
            positionabc = 25;break;
        case '=':valor = 1;
		break;
        case ':':no_warning=1;
		break;
        case FA:
            if(valor == 0) {
                push(atof(c));
            }if (valor == 1) {
                asignado = atof(c);
                found_value = 1;
            }break;
      
        case '+':push(pop() + pop());    
		break;
        case '*':push(pop() * pop());
		break;
        case '-':op2 = pop();
            push(pop() - op2);break;
        case '/': op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
         
          /*  int getop(char s[]) {

	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t');
	s[1] = '\0';
		
	if (isalpha(c)) {
		options(c, s);
	}
	
	if (c == ':') {
		c = getch();
		op3 = 1;
	}
	
	if (c == '=') {
		c = getch();
		op1 = 1;
	}

	if (c == '\n') {
		op1 = 0;
		op3 = 0;
	}
		
	if (!isdigit(c) && c != '.')
		return c; 
	i = 0;
	if (isdigit(c)) 
		while (isdigit(s[++i] = c = getch()));
	if (c == '.') 
		while (isdigit(s[++i] = c = getch()));
			s[i] = '\0';
	if (c != EOF)
		ungetch(c);
		
	return NUMBER;
	
}

int getch(void) {

	return (bufp > 0) ? buf[--bufp] : getchar();
	
}

void ungetch(int c) {
	
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
		
}

int options(int c, char chars[]) {
	
	int i = 0, o;
	double op2, n = 0;
	
	chars[i] = c;
	
	while (isalpha(chars[++i] = c = getch()));
	
	chars[i] = '\0';
	ungetch(c);
	
	if(i == 1) 
		var = tolower(chars[0]);
	else 
		var = 0;
	
	if(i == 1 && variables[var] != 0 && var == chars[0])
		push(variables[var]);
	
	if(chars[0] == 'a' && chars[1] == 'n' && chars[2] == 's') {
		push(variables['$']);
		var = '$';
	}
	
	return chars[0];
}
*/
        case '\n':;
            if (positionabc != 100 && valor == 1 && found_value == 1) { /*Empieza el proceso de asiganciónd e variables, preguntando si es forzado, si es nuevo o si se sobreescribira la variable*/
                for (int i = 0; i < 26; i++) {
                     if (positionabc == i) {
                        if (abecedario[i] != 0 && no_warning ==0) {
                            printf("WARNING  ---> 1 To confirm  ---> 2 Cancel \n");
                            if ((cancelar = getchar()) == '2') {
                                pop();
                                cancelar;
                                printf("Canceled \n");
                            } else {
                                pop();
                                printf("Successful);
                                abecedario[i] = asignado;
                          }
                            no_warning=0;
                        } else {
                            abecedario[i] = asignado;
                            no_warning=0;
                        }
                    }
                }
            }else
                printf("\t%.8g\n", pop());
            positionabc = 100; 
            valor = 0;
            found_value = 0;
            asignado = 0;
            break;
        default:
            printf("error: unknown command %s\n", c);
            break;
        }
}

/*busqueda secuencial */
#include <stdio.h>

int main(){ 
	
	int a[5] = {5,10,20,45,27};// lista de numeros desordenados 
	char flag = 'F';
	int i=0, busq=27;//valor que buscamos
	
	while ((flag=='F') && (i<5)){
		if (a[i] == busq){
			flag = 'V';
		}
		i++;
	}
	if (flag == 'F') {
		printf("NO ESTA EN LA SECUENCIA");
	}
	else if (flag == 'V'){
		printf ("El numero esta en la posicion %i\n",i);
	}
	return 0;
}

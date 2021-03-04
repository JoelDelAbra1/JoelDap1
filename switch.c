#include <stdio.h>

 int main () {
 	
 	 float a = 4 , b = 5 , x;
	 int l = 1 ; // 1 = Suma // 2 = Resta
	 
	 /*SWITCH*/
	 switch( l ){
	 	
	 	case 1 : {
		  
	 		x = a + b;
	 		printf("%f", x);
			break;
			
		 } case 2 : {
		 	x= a - b ;
		 	printf("%f",x);
		 	break;
		 }
    }
 }

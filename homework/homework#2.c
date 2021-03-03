#include <stdio.h>/*I had help from my partner rulegamer07 and some youtube videos*/
#include <math.h> // sqrt

#define FALSE 0
#define TRUE 1
#define K 7 //  define the #k

void numbin(int l);
void primonum(int n);

int main(){
    /*printf("Put the # "); I Try but it doesnt work xd
    scanf("%d", &k); */
  primonum(K) ;
}
void numbin(int l){
    printf("-> ");
    int i = FALSE, b = 3 ;
    int zerl [4] = {FALSE} ;
while(l > FALSE){
    zerl[i] = (l % 2) ;
	l /= 2 ;
	i++ ;
}
for( b ; b >= FALSE; --b ){
       printf( "%01d",zerl[b] );
 }
     printf( "\n\n" );
}
void primonum(int k){
  int i, marcador, stuff , count = 1, c = TRUE ; //it looks bad but i want to save space
while(count <= k){
    stuff = sqrt(c);
    marcador = FALSE ;
for(i = 2; i <= stuff; i++){
     if(c % i == FALSE){
        marcador = TRUE ;
        break ;
  }
}
    if(marcador == FALSE){
      numbin(c);
      count++ ;
    }
    c++ ;
  }
}

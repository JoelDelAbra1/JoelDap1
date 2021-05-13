#include <stdio.h>
#include <math.h>


int main() {
 int VOT, cand1 = 0, cand2 = 0, cand3  = 0, cand4 = 0, nulos = 0, total;
 float porc1,porc2,porc3,porc4,porcnull;

 printf("\nIngresa el primer voto: ");
 scanf("%d", &VOT);

while(VOT){
  switch(VOT){
  case 1: cand1++; 
  break; 
  case 2: cand2++; 
  break;
  case 3: cand3++; 
  break;
  case 4: cand4++; 
  break;
  default: nulos++; 
  break;  
  }
  printf("Ingresa el siguiente voto o un 0 para terminar: ");
  scanf("%d", &VOT);
}
  total = cand1 + cand2 + cand3 + cand4 + nulos;
  porc1 = ((float) cand1/ total * 100);
  porc2 = ((float)cand2/ total * 100);
  porc3 = ((float )cand3/ total * 100);
  porc4 = ((float) cand4 / total * 100);
  porcnull = ((float) nulos / total * 100);

  printf("\nVotos Totales Registrados: %d",total);
  printf("\nCanditato #1: %d de votos -- Porcentaje %5.2f", cand1,porc1);
  printf("\nCanditato #2: %d de votos -- Porcentaje %5.2f", cand2,porc2); 
  printf("\nCanditato #3: %d de votos -- Porcentaje %5.2f", cand3,porc3); 
  printf("\nCanditato #4: %d de votos -- Porcentaje %5.2f", cand4,porc4); 
  printf("\nNulos %d -- Porcentaje %5.2f", nulos,porcnull);  

}

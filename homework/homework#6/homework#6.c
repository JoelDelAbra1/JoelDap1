/* Por favor correr el progrma  en https://www.onlinegdb.com/
Ahi es donde funciona 
Hecho tomando ideas y basandome en el repositorio de rulgame03 y el de la profe --- THkss!!!   
*/
#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 
#include <ctype.h> 
#include "struct.h"

void copy (char l[MAX],char p[MAX],char u[MAX]){
    int a = 4, b = 0, c=0;
    while (l[a] != ' '){
        u[b]=l[a];
        b++;
        a++;
    }
    u[b]='\0';
    int longt = strlen(u);
    a++;
    while (l[a]!=' ' && l[a] != '\0'){
       p[c]=l[a];
       c++;
       a++;
    }
    p[c]='\0';
    int longi = strlen(p);
}

void celim(node* rama, char* u, char* p, int* n){
    if (rama != NULL) {
        celim (rama->leftChild, u, p, n);
        celim (rama->rightChild, u, p, n);
        if (strcmp(rama->nickname, u) == FALSE && strcmp(rama->contra, p) == FALSE){
            rama->contra=NULL;
            *n = 1;
            printf("Usuario eliminado\n\n");
        }
    }
}

int entrace() {// parte sacada del repo de la profe
  extern char linea[];
  int c, i = 0;
  for (; i < MAX - 1 && (c = getchar()) != EOF && c != '\n';) {
        linea[i++] = c;
  }
  linea[i] = '\0'; // final
  return c == EOF;
}

node* mensaje(char* u, char* p, node* pos, int d) {
  node* temp;
  if (pos == NULL) {
    pos = (node*)malloc(sizeof(node));
    pos->nickname = u;
    pos->contra = p;
    pos->depth = d;
 
    printf ("Registro completado\n\n");
  }else{
    if (strcmp(pos->nickname, u) == FALSE){
      if (pos->contra != NULL){
      }else{
      printf("Usuario registrado anteriormemte\n\n");
          pos->contra = p;
      }
          printf ("Registro completado\n\n");
    }else if (strcmp(pos->nickname, u) > FALSE){ 
      temp = mensaje(u, p, pos->leftChild, d++);
      if (pos->leftChild == NULL){
	pos->leftChild = temp;
      }
    }else if (strcmp(pos->nickname, u) < FALSE){
      temp = mensaje(u, p, pos->rightChild, d + 1); 
      if (pos->rightChild == NULL){
	pos->rightChild = temp;
      }
    }
  }
  return pos;
}

void ordenamiento(node* rama){
  if (rama != NULL){
    ordenamiento(rama->leftChild);
    if (rama->contra!=NULL){
    printf("%s ", rama->nickname);
    }
    ordenamiento(rama->rightChild);
  }
}

int main(){
     printf("-------------------Lista de comandos-------------------\n/rg ----> registrar usuario ( ejemplo rg/ alex 123 )\n");
     printf("/el ----> eliminar usuario (es necesaria la contraseña)\n/ver ----> Ver lista de usuarios\n");
     printf("-------------------------------------------------------\n\n");
  int flag=0, tab =0, l = 0;
  int i, j;
  char* u;
  char* p;
  node* n = NULL;
  node* main = NULL;
  extern char linea[];
  
  while ((l = entrace()) == FALSE) {
      tab=0;
    for (j=0; j<MAX; j++){
        if (linea[j]== ' ' || linea[j] == '\t'){
            tab++;
        }
    }
    if (strstr(linea, "/el") != NULL && strlen(linea) >= 7 && tab== 2){ 
      copy(linea, contra, nickname);
      u = (char*)malloc(sizeof(int*) * strlen(nickname));
      p = (char*)malloc(sizeof(int*) * strlen(contra));
      for (i=0; i < strlen(nickname); i++){
          u[i]=nickname[i];
      }for (i=0; i < strlen(contra); i++){
          p[i]= contra[i];
     }
      flag=0;
      celim(main, u, p, &flag);
      if (flag== FALSE){
   }
      flag=0;
      tab=0;
      
  }else if (strstr(linea, "/rg") != NULL && strlen(linea) >= 10 && tab == 2) { 
      copy(linea, contra, nickname);
      u = (char*)malloc(sizeof(int*) * strlen(nickname));
      p = (char*)malloc(sizeof(int*) * strlen(contra));
      for (i=0; i < strlen(nickname); i++){
          u[i]= nickname[i];
      }for (i=0; i < strlen(contra); i++){
          p[i]= contra[i];
     }
      if (strlen(contra) > FALSE && strlen(nickname) > FALSE){
      n = mensaje(u,p, main, FALSE); 
	  if (main == NULL) {
	    main = n; 
	    }
	   tab= 0;
      }else if (strlen(contra) <= FALSE || strlen(nickname) <= FALSE){
          printf ("Comando no encontrado\n\n");
      }
    }else if (strstr(linea, "/ver") != NULL && strlen(linea) == 4) {
      ordenamiento(main);
      printf("\n\n");
      tab=0;
    }else{
        tab=0;
        printf("Comando no encontrado\n\n");
    }
  }
return 0;
}

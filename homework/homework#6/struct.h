#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 
#include <ctype.h> 

#define FALSE 0
#define TRUE 0
#define MAX 666

typedef struct treenode {
 
  struct treenode* leftChild;
  struct treenode* rightChild;
  
  char* nickname;
  char* contra; 
  unsigned int depth;
} node;

node* insert(char* u, char* p, node* pos, int d); // agregar
 
void copy(char l[MAX],char p[MAX],char u[MAX]);
void ordenamiento(node* position); // odernar por abecedario
void celim(node* rama, char* u, char* p, int* n); //eliminar

int saca(); // Function that give us the line
char linea[MAX], contra[MAX], nickname[MAX];

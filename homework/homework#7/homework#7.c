
/// -----------------------------------IMPORTANTE-------------------------------------------------- 
//  |                                                                                             |
//  | PUEDES COPIAR Y PEGAR ESTE LINK Y ASI NO COPIAR TODO : ---> https://onlinegdb.com/By6fK5bu_ |
//  |                                                                                             |
//  -----------------------------------------------------------------------------------------------

// ABRIR EN : https://www.onlinegdb.com/
// Hecho tomando ideas y basandome en el repositorio de rulgame03 y el de la profe --- THkss!!!  
// Para terminar de agregar usuarios primero se usa /nuevo y se completa , 
// despues tienes queponer /terminar para que se agregen satisfactoriamente

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "struct.h"

int salto (){
FILE * base_datos = fopen ("base_datos.txt", "r"); //read
char c;
int salto = 0;
while ((c = fgetc (base_datos)) != EOF){
    if (c == '\n'){
        salto++;		
        }
    
}
return salto;
    
}

void add (){
int id;
id = salto () + 1;
char nombre[MAX];
int time;
int min;
int trabajo;
int horas;
printf ("\nSu id sera: %d \n", id);
cuantos++;
printf ("\nIngresa el nombre del usuario:\n");
scanf ("%s", nombre);
do{
    printf("\nEscriba la hora de entrada (ejemplo 11 11)\n");
    scanf ("%d %d", &horas, &min);
    
}while (horas < 0 || horas > 23 || min < 0 || min > 60);
printf ("\nCompletado.\n\n"); 
FILE * escribirsistema = fopen ("base_datos.txt", "a");
fprintf (escribirsistema, "%d %s Hora de entrada: %d : %d \n", id, nombre, horas, min);
fclose (escribirsistema);
    
}

void reg_in_out (int id, int estado){			
  int diferencia = 0;		
  time_t tiempoahora;
  time (&tiempoahora);
struct tm *mitiempo = localtime (&tiempoahora);
int segundos = mitiempo->tm_sec;
int minutos = mitiempo->tm_min;
int hour = mitiempo->tm_hour;
int actualyear = mitiempo->tm_year + 1900;
int mom = mitiempo->tm_mon + 1;
int now_day = mitiempo->tm_mday;
int day = mitiempo->tm_wday;
if (estado == 0){				//es una entrada
      FILE *entrada = fopen ("reg_in.txt", "a");
      fprintf (entrada, "%d %d %d/%d/%d %d:%d:%d\n", id, day,now_day, mom, actualyear, hour, minutos,segundos);
      fclose (entrada);
      conjunto[id - 1][0] = hour;
      conjunto[id - 1][1] = minutos;
      conjunto[id - 1][2] = segundos;
      printf ("\nRegistrando....\nCompletado.\n\n");
    
}
if (estado == 1){
    FILE * salida = fopen ("reg_out.txt", "a");
    fprintf (salida, "%d %d %d/%d/%d %d:%d:%d\n", id, day, now_day, mom, actualyear, hour, minutos, segundos);
    fclose (salida);
    printf ("\nRegistrando....\nCompletado.\n\n");
    conjunto[id - 1][3] = hour;
    conjunto[id - 1][4] = minutos;
    conjunto[id - 1][5] = segundos;
    FILE * reporte = fopen ("attendance_report.txt", "a");
    if (attendance == 0){
        fprintf (reporte, "Fecha en la que se realizo este reporte:  ");
        fprintf (reporte, " %d-%d-%d\n", now_day, mom, actualyear);
        
    }
    diferencia = (conjunto[id - 1][3] * 3600 + conjunto[id - 1][4] * 60 + conjunto[id - 1][5]) - (conjunto[id - 1][0] * 3600 + conjunto[id - 1][1] * 60 + conjunto[id - 1][2]);
      
int horapin = conjunto[id - 1][0];
int minpin = conjunto[id - 1][1];
int segundopin = conjunto[id - 1][2];	
     fprintf (reporte,"Usuario con id: %d registro su entrada a las %d:%d:%d el dia %d-%d-%d y estubo trabajando activo por %d segundos\n",id, horapin, minpin, segundopin, now_day, mom,actualyear, diferencia);
     fclose (reporte);
     conjunto[id - 1][0] = -1;
     conjunto[id - 1][1] = -1;
     conjunto[id - 1][2] = -1;
     conjunto[id - 1][3] = -1;
     conjunto[id - 1][4] = -1;
     conjunto[id - 1][5] = -1;
     attendance = 9;
    
}
    
} 

int main(){
int i;
int j;
int pin_usr;
conjunto = (int **) malloc (sizeof (int *) * DATOS);
for (i = 0; i < DATOS; i++){
    conjunto[i] = (int *) malloc (sizeof (int) * 6);
    for (j = 0; j < 6; j++){
        conjunto[i][j] = -1;
        
    }
}
int salir = 0;
char opcion[20];
int limite;
limite = salto ();

printf ("\n--------------------COMANDOS--------------------");
printf("\n--> /entrada   Para registrar una entrada.\n--> /salida    Para registrar una salida.\n--> /nuevo     Para registrar un trabajador.\n--> /dato      Ver cuantos usuarios registrados hay.\n--> /com       Ver comandos de nuevo.\n--> /terminar  Cerrar el programa.\n\n");
while (salir == 0){
    scanf ("%s", opcion);
    int contador = strlen(opcion);
    if (contador == 8){	//   /entrada	
    printf ("Cual es su id?\n");
    scanf ("%d", &pin_usr);
    if (pin_usr <= 0){
        printf ("\nEntrada no valida\n");
        
    }else if (pin_usr <= limite){
    if (conjunto[pin_usr - 1][1] == -1){	
    reg_in_out (pin_usr, 0);
    }else{
        printf ("\nHora de entrada registrada anteriormente\n");
        
    }
        
    }else{
        printf("\nError\n");
        
    }
        
    }else if (contador == 7){ //   /salida
        printf ("Ingresar id:\n");
        scanf ("%d", &pin_usr);
        if (pin_usr <= 0){
            printf ("\nError\n");
            
        }else if (pin_usr <= limite){
            if (conjunto[pin_usr - 1][1] != -1){		
            reg_in_out (pin_usr, 1);
            }else{
                printf("\nError\n");
                
            }
            
        }else{
            printf("\nSaturacion de usarios\n");
            
        }
        
    }else if (contador == 6){ //  /nuevo
        add();
    }else if (contador == 5){ // /dato
    printf ("\nEn este momento hay %d trabajadores registrados\n", limite);
    }else if (contador == 9){ // /terminar
        int flag = 0;
        
        for (i = 0; i < MAX; i++){
            if (conjunto[i][0] * conjunto[i][1] * conjunto[i][2] > 0 && conjunto[i][3] * conjunto[i][4] * conjunto[i][5] < 0)
		{
		    flag = -1;
		    printf("\nError: El usaario %d falta de registrar su salida\n\n",i + 1);
		    
		}
}if (flag == 0){
    printf ("\nSaliendo....\n");
    salir = 1;
    
}
        
    }else if (contador == 4){ //   /com
 printf ("\n--------------------COMANDOS--------------------");
printf("\n--> /entrada   Para registrar una entrada.\n--> /salida    Para registrar una salida.\n--> /nuevo     Para registrar un trabajador.\n--> /dato      Ver cuantos usuarios registrados hay.\n--> /com       Ver comandos de nuevo.\n--> /terminar  Cerrar el programa.\n\n");

    }else{
        printf ("\nOpcion no disponible\n\n");
        
    }
}
return 0;
    
}

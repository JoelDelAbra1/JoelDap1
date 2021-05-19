#include <stdio.h>
#include "header.h"


int main (){
  int opcion;  // guardar la opcion que el usuario quiera realizar

  float a,b; // variables para poder calcular y guardar 
  

  do{ // Seguir funcionando hata que el ususario quiera
    
    menu(); // Se llama ala funcion menu para mostrar las opciones dispoibles

    scanf("%d",&opcion); //Se guarda la opcion

    switch(opcion){ // Segun la opcion ingresada 
      case 1:
    printf("\nSu salrio neto es de : $ %.2f\n",isr(a,b)); 
    break;

    case 2:
      printf("\nIngresa la cantidad que pagaste por tu producto: "); //se pide lo que se pago por el producto para obtener lo que pagaste de iva
    scanf("%f",&a);
    printf("\nLo que pagarias SIN EL IVA sera : $ %.2f$\n",siniva(a)); //se imprime el resultado
    break;
    
    case 3:
      printf("\nIngrese el valor de tu producto: "); //Solicita el valor antes del IVA para calcular cuanto sera en total
    scanf("%f",&a);
    printf("\nLo que PAGARAS CON EL IVA sera : $ %.2f$\n",coniva(a,b)); //Se imprme el resultado
    break;
    
    case 4:
    printf("\nIngresa la cantidad en litros: ");
    scanf("%f",&a);
    printf("\nLo que pagaras de IESP sera: : $%.2f\n",ieps(a));
    break;

    case 5:
    printf("\nIngrese el importe del deposito: "); // Se pide la cantidad que sera depositada
    scanf("%f",&cantidad);
    printf("\nImporte que el banco recaudara: $%.2f\n",deposito(a));
    break;
case 6:
    printf("\nLo que pagaras en total YA CON EL ISAN : $ %.2f\n",ISAN(a,b));
    break;
    default:
    printf("\n\nSaliendo...");
    break;
    }
    
  }while(opcion != 0); // Si la opcion es 0 se termina de ejecutar
  
  
  return 0;
}

void menu(){ // Se despliega el menu de opciones 
  printf("\nQue quires calcular\n\n");
  printf("0.-Salir\n1.-Impuesto Sobre la Renta\n2.-LO QUE PAGASTE DE IVA\n3.-LO QUE PAGARAS CON EL IVA\n4.-IESP-Gasolinas\n5.-Impuesto sobre Depósitos en Efectivo\n6.-Impuesto sobre Automóviles Nuevos\n\n");
}


float isr(float sueldo, float neto){

char nom[20]; // Poder guardar el nombre 

  printf("\nIngresa tu nombre:  "); // Se pide nombre y se guarda
  scanf("%s",nom);

  printf("\n%s ingresa tu sueldo neto mensual: ",nom); // Salario neto, se guarda y se utiliza para realizar las operaciones 
  scanf("%f",&sueldo);

  neto=sueldo; 

  FILE * escribirsistema = fopen ("ISR.txt", "a");  // Generar el reporte 
  fprintf(escribirsistema, "%s\t\t\t", nom);  //primero el nombre
  fprintf(escribirsistema, "%0.2f\t\t", sueldo); // sueldo antes del impuesto

/*calculos

1.- Ubicar el rango del salario
2.- Salario - Limite inferior
3.-Multiplicar por el % correspondiente
4.-Sumar la cuota fija

*/
  if(sueldo  <= 578.52){  
     sueldo = ((sueldo-0.01)*(0.0192));
  }else if(sueldo  <= 4910.18){
    sueldo = ((sueldo-578.53)*(0.064) + (11.11));
  }else if(sueldo <= 8629.20){
     sueldo = ((sueldo-4910.19)*(0.1088) + (288.33));
  }else if(sueldo <= 10031.07){
     sueldo = ((sueldo-8629.21)*(0.16) + (692.96));
  }else if(sueldo <= 12009.94){
    sueldo = ((sueldo-10031.08)*(0.1792) + (917.26));
  }else if(sueldo <=24222.31){
    sueldo = ((sueldo-12009.95)*(0.2136) + (1271.87));
  }else if(sueldo <= 38177.69){
    sueldo = ((sueldo-24222.32)*(0.2352) + (3880.44));
  }else if(sueldo <= 72887.5){ 
    sueldo = ((sueldo-38177.7)*(0.3) + (7162.14));
  }else if(sueldo <= 97183.33){
     sueldo = ((sueldo-72887.51)*(0.32) + (17575.69));
  }else if(sueldo <=291550){
    sueldo = ((sueldo-97183.34)*(0.34) + (25350.35));
  }else{ //  En adelante
     sueldo = ((sueldo-291550.01)*(0.35) + (91435.02)); 
  }

  fprintf(escribirsistema, "%0.2f\t\t\t", sueldo); // Se impreme lo que quitan de impuesto
  neto -= sueldo;
  fprintf(escribirsistema, "%0.2f\n", neto); //Salario neto
  fclose (escribirsistema);

  return neto; // return el valor para poder imprimirlo
}

   /*
  
  1.- Solicitar precio con IVA
  2.- Si esta en frontera el IVA es del 8% , en el resto del pais %16
  3.- Sacar lo que se pago de impuesto 

   */

float siniva(float precio){


  int opcion; // Opcion de frontera
  char producto[25]; // Poder guardar el nombre del producto

  printf("\nIngresa el nombre del producto : ");
  scanf("%s",producto); 

  printf("\nEstas en Forntera?\n\n1.-Si\n2.-No\n\n"); // Si esta en forntera el impuesto sera del 8%
  scanf("%d",&opcion);

  FILE * escribirsistema = fopen ("IVA.txt", "a");
  fprintf(escribirsistema, "%s\t\t     ", producto);
  fprintf (escribirsistema, "%.2f\t\t\t\t", precio);
 

if(opcion <= 1){ 
  precio /= 1.08; //VA Frontera
  fprintf (escribirsistema, "%.2f\t\t(FRONTERA)\n", precio);  // Se imprime el valor sin iva y se identifica como frontera

}else{
  precio /= 1.16; //IVA normal
  fprintf (escribirsistema, "%.2f\n", precio);
}

fclose (escribirsistema);

return precio;
}

 /*
  
  1.- Solicitar precio SIN  IVA
  2.- Si esta en frontera el IVA es del 8% , en el resto del pais %16
  3.- Sacar el precio sin el IVA 

   */

float coniva(float antes, float ya_con_iva){

   int opcion;
   char producto[25]; // Poder guardar el nombre del producto

  printf("\nIngresa el nombre del producto : ");
  scanf("%s",producto); 

   ya_con_iva=antes; //Se iguala para poder modificar su valor

  printf("\n\nEstas en Forntera?\n1.-Si\n2.-No\n\n"); // IVA menor en la forntera
  scanf("%d",&opcion);

  FILE * escribirsistema = fopen ("IVA.txt", "a");
   fprintf(escribirsistema, "%s\t\t     ", producto);
   
  if(opcion <= 1){

     ya_con_iva =  ya_con_iva * 0.08 + antes; // Frontera
    
     fprintf (escribirsistema, "%.2f\t\t\t\t", ya_con_iva);
     fprintf (escribirsistema, "%.2f\t\t(FRONTERA)\n", antes);

  }else{

    ya_con_iva = ya_con_iva * 0.16 + antes;  // Normal
    
    fprintf (escribirsistema, "%.2f\t\t\t\t", ya_con_iva);
    fprintf (escribirsistema, "%.2f\n", antes);

    }
    
    fclose (escribirsistema);

    return ya_con_iva; // Valor listo
    }

float ieps(float litros){

  int opcion; //Guaradar la opcion que el usuario quiera

  printf("\nQue tipo de gasolina es?\n\n1.-Magna\n2.-Premium\n3.-Diesel\n\n");
  scanf("%d",&opcion);

  switch(opcion){  //Segun el tipo de gasolina se pagan 'x' cantidad de centavos por litro
    case 1: litros *= 0.4369;
     break;
    case 2: litros *= 0.5331;
     break;
    case 3: litros *=0.3626;
     break;
  }
  return litros; // Se regresa el monto qwe deberas pagar
}

float deposito(float amount){  

FILE * escribirsistema = fopen ("IDE.txt", "a");
  fprintf(escribirsistema, "%.2f \t\t", cantidad);
  
  if(cantidad <= 15000){  // El deposito debe de ser 

    printf("\nNo excede el minimo\n");
    cantidad = 0; //como se imprime la cantidad que pagaras se iguala a 0
   fprintf(escribirsistema, "%.2f    \t\t", cantidad);

  }else{
    cantidad -= 15000;
    fprintf(escribirsistema, "%.2f\t\t", cantidad);

    cantidad *= 0.03; //Se calcula el IDE
  }
  fprintf(escribirsistema, "%.2f\t\t\t\t  \n", cantidad);
  fclose (escribirsistema);
  return cantidad;
  
}

float ISAN(float carro_precio, float carro_neto){ //Impuesto sobre Automóviles Nuevos

char marca[20]; // Poder guardar la marca del auto

  printf("\nIngresa la marca de tu coche:  ");
  scanf("%s",marca);

  printf("\nIngresa el costo de tu %s : ",marca); //Se pide ingresar el precio antes del Impuesto
  scanf("%f",&carro_precio);

  carro_neto=carro_precio; // Para poder modificarlo

  FILE * escribirsistema = fopen ("ISAN.txt", "a"); //Hacer un registro
  fprintf(escribirsistema, "%s\t\t", marca);
  fprintf(escribirsistema, "%0.2f\t\t", carro_precio);


/*calculos

1.- Ubicar el rango del precio
2.- Precio - Limite inferior
3.- Multiplicar por el % correspondiente
4.- Sumar la cuota fija

*/

  if(carro_precio  <= 283241.20){ 
     carro_precio = ((carro_precio-0.01)*(0.2));
  }else if(carro_precio  <= 339889.38){
    carro_precio = ((carro_precio- 283241.21)*(0.05) + (5664.73));
  }else if(carro_precio <= 396537.78){
     carro_precio = ((carro_precio-339889.39)*(0.10) + (8497.27));
  }else if(carro_precio <= 509833.94){
     carro_precio = ((carro_precio-396537.79)*(0.15) + (14162.08));
  }else{
     carro_precio = ((carro_precio-509833.95)*(0.17) + (31156.48));
  }

  fprintf(escribirsistema, "%0.2f\t\t", carro_precio);
  carro_neto += carro_precio;    // sacar e precio total
  fprintf(escribirsistema, "%0.2f\n", carro_neto);
  fclose (escribirsistema);

  return carro_neto; // return el precio ya modificado
}
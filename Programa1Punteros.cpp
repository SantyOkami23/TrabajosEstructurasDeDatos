/*1. Escribir un programa que utilice el concepto de STRUCT de forma que almacene en un array los nombres, número de
teléfono fijo y celular y, las edades de hasta 50 personas. El programa debe leer los datos introducidos por el usuario y
guardarlos en memoria. Después debe ser capaz de buscar el nombre correspondiente a un número de teléfono fijo (o
celular) y, el teléfono correspondiente a una persona que se indique, además deberá listar las personas que correspondan
a un rango de edades dada por el usuario. Las opciones deben ser accesibles a través de un menú, así como la opción de
salir del programa. El menú debe tener esta forma, más o menos:

1) Ingreso de datos 
2) Buscar por nombre
3) Buscar por número de teléfono
4) Listar personas entre X y Y años
5) Salir
Pulsa una opción:

Santiago Ramirez Arenas 
*/

#include <iostream>
#include <math.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;
// Declaramos la estructura 
typedef struct DATOS{

char nombre[50];
char celular[11];
char fijo[8];
int edad;

}DATOS_PERSONALES;

// Funcion qu guarda os datos ingresados  de cada persona 
void ingresar(DATOS_PERSONALES *personas,int posicion){

   if(posicion < 50){// Limite para el ingreo de personas 
   
    cout<<endl;
    cout<<"ingrese nombre: "; fflush(stdin);
    
    cin.getline((personas + posicion) -> nombre, 50, '\n');
    cout<<" Por favor ingrese elnumero del celular: "; fflush(stdin);
    
    cin.getline((personas + posicion) -> celular, 11, '\n' );
    cout<<"Por favor ingrese el numero   fijo: ";
    
    cin.getline((personas + posicion) -> fijo, 8, '\n');
    cout<<"Por favor ingrese la edad: "; fflush(stdin);
    cin>>(personas + posicion) -> edad;
   
   cout<<"Los datos de la perona se han registrado"<<endl;
   
   }else{
      cout<<"Lo sentimos, ya no hay mas espacio :c"<<endl;}
   
}
   
//Funcion que nos ayuda a buscar por nombre 
void buscar_nombre(DATOS_PERSONALES *personas, int posicion){

    char nombre_auxiliar[50]; //variable auxiliar 
    int verificador = 0;

if(posicion == 0){ cout<<"Debe ingresar un usuario primero"<<endl;   getch();}
   
else{
   
    cout<<"Por favor ingrese la persona que desea buscar: ";   //si se encuentran registrados al menos una persona se procede a perdir el nombre a buscar
    fflush(stdin);  // para limpiar el buffer del teclado
    cin.getline(nombre_auxiliar, 50, '\n'); // se registra el nombre y se guarda en la variable nombre_buscar

   
    for(int i = 0; i <  posicion && verificador == 0; i++){
   
      if(strcmp((personas + i) -> nombre,nombre_auxiliar)==0){  
   
         cout<<"nombre:  "<<(personas + i) -> nombre<<endl;
         
         cout<<"celular: "<<(personas + i) -> celular<<endl;
         
         cout<<"fijo:    "<<(personas + i) -> fijo<<endl;
         
         cout<<"edad:    "<<(personas + i) -> edad<<endl;
         
         verificador = 1;
      }
   
    }
   
   
    if(verificador == 0){  cout<<"\El usuario que desea buscar no se encuntra en nuestra base de datos "<<endl;}
   }  
}

//funcion que busca por telefono 
int buscar_telefono(DATOS_PERSONALES *personas,int posicion){
	
   char telefono_auxiliar[11];
   int verificador = 0;
   
   if(posicion == 0){ cout<<"Por favor registre inicialmente un usuario "<<endl;   getch();}// Por si aún o hay registros 
   else{
   	cout<<"Por favor ingrese la persona que desea buscar: ";  
	    
    fflush(stdin);  
    cin.getline(telefono_auxiliar, 11, '\n'); // Guardamos la vaeiable auxiliar 
    
    for(int i = 0; i <  posicion && verificador  == 0; i++){
   
      if(strcmp((personas + i) -> celular,telefono_auxiliar)==0){  
   
         cout<<"nombre:  "<<(personas + i) -> nombre<<endl;
         cout<<"celular: "<<(personas + i) -> celular<<endl;
         cout<<"fijo:    "<<(personas + i) -> fijo<<endl;
         cout<<"edad:    "<<(personas + i) -> edad<<endl;
         verificador = 1;
        }
      }
	}  
   	
   if(verificador  == 0){  cout<<"\nLo sentimos el telefono no se encuentra registrado en la base de datos :c"<<endl;}

}


//Funcion para comparar cadenas de caracteres 
int com(char cadena1[50], char cadena2 [50]){
int señal  = 0;  //sirve para saber cual cadena es mayor, segun lo que me devulva 


   for(int i = 0; i < 50; i++){
   
  if(cadena1[i] > cadena2[i]){return 1; break;}
  if(cadena1[i] < cadena2[i]){return 0; break;}
   }

}
// Utilizamos el metodo de insercion
void ordenar_imprimir(DATOS_PERSONALES *personas,int posicion){

   int edad = 0, edad2 = 0;
   DATOS_PERSONALES aux;
   int pos = 0;
   
   if(posicion <= 1){
    cout<<"Debe ingresar al menos dos usuarios primero"<<endl;
    getch();
  }else{
  	
  	cout<<"Ingrese los rangos de edad por favor: "<<endl;
  	
    cout<<"Ingrese Edad x: ";cin>>edad;
    cout<<"Ingrese Edad y: ";cin>>edad2; 

   for(int i=0; i < posicion; i++){
     pos = i;
     aux = *(personas + i);
   //ordenamiento por inserción
    while((pos > 0 ) && (com((personas + (pos-1)) -> nombre,aux.nombre) == 1)){ 
      
	  *(personas + pos) = *(personas + (pos -1));
      pos--;
      }
       *(personas + pos) = aux;
	  }

   cout<<"\nListado de las personas entre "<<edad<<" y "<<edad2<<endl<<endl;
   
   for(int i = 0; i < posicion; i++){
   
     if((personas + i) -> edad >= edad && (personas + i) -> edad <= edad2){

    cout<<"Persona #: "<<i+1<<endl;
    
        cout<<"Nombre: "<<(personas + i) -> nombre<<endl;
        
        cout<<"Celular: "<<(personas + i) -> celular<<endl;
        
        cout<<"Fijo: "<<(personas + i) -> fijo<<endl;
        
        cout<<"Edad: "<<(personas + i) -> edad<<endl;
       
        cout<<endl<<endl;
    }
   }
  }  
}

int main(){    

    DATOS_PERSONALES  persona;
    
    DATOS_PERSONALES *personas = &persona;
    int verificador = 0; 
    char celular_auxiliar[11];
    char nombre_auxiliar[50];
    int edad = 0, edad2 = 0;
    int posicion = 0;
    int Opcion;
    personas = (DATOS_PERSONALES*) malloc(4*sizeof(DATOS_PERSONALES));
   
   
   
   
    do{
verificador = 0;
   
   system("cls");
   cout<<"-------Base datos grupo de personas------- "<<endl<<endl;
   
   
   cout<<"1. Ingreso de datos "<<endl;
   
   cout<<"2. Buscar por nombre"<<endl;
   
   cout<<"3. Buscar por numero de telefono"<<endl;
   
   cout<<"4. Listar personas entre X y Y años"<<endl;
   
   cout<<"5. salir."<<endl;
   
   cout<<"Seleccione una opcion : ";cin>>Opcion;
   cout<<endl;
   
   switch(Opcion){
   case 1:
   
   ingresar(personas, posicion);
   
   posicion++;//Aqui llevamos la cuenta de cuantas personas fueron ingresadas 
   
   getch();
   break;
   
   case 2:
   
   buscar_nombre(personas,posicion);
   
   getch();
   break;
 
   case 3:
   
   buscar_telefono(personas,posicion);
   
   getch();
   break;


   case 4:
      
    ordenar_imprimir(personas,posicion); 
   
   getch();
   break;

   
   default:
   cout<<"Hasta pronto xD"<<endl;
   
   getch();
   break;
   }
   
 }while(Opcion != 5);


return 0;
getch();
}

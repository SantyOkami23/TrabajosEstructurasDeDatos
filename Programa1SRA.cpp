/*1. Escribir un programa que utilice el concepto de STRUCT de forma que almacene en un array los nombres, número de
teléfono fijo y celular y, las edades de hasta 50 personas. El programa debe leer los datos introducidos por el usuario y
guardarlos en memoria. Después debe ser capaz de buscar el nombre correspondiente a un número de teléfono fijo (o
celular) y, el teléfono correspondiente a una persona que se indique, además deberá listar las personas que correspondan
a un rango de edades dada por el usuario. Las opciones deben ser accesibles a través de un menú, así como la opción de
salir del programa. El menú debe tener esta forma, más o menos:

a) Ingreso de datos (los datos de una persona)
b) Buscar por nombre
c) Buscar por número de teléfono
d) Listar personas entre X y Y años
e) Salir

Santiago Ramirez Arenas 

*/

#include <iostream>
#include <math.h>
#include <conio.h>
#include <string.h>

using namespace std;
////////////////////////////////////////////////////////////////////////////////////////
//Declaramos la estructura correspondiente para  los datos de cada persona 
typedef struct DATOS{

char nombre[50];
char num_celular[11];
char num_fijo[8];
int edad;

}DATOS_PERSONALES;
/////////////////////////////////////////////////////////////////////////////////////////
//funcion  del tipo de datos DATOS, retorna la infomación de una persona
DATOS_PERSONALES ingresar(){

DATOS_PERSONALES persona;

    cout<<endl;
    
    cout<<"ingrese nombre: "; fflush(stdin);
    cin.getline(persona.nombre, 50, '\n');
    
    cout<<"ingrese celular: "; fflush(stdin);
    cin.getline(persona.num_celular, 11, '\n' );
    
    cout<<"ingrese fijo: ";
    cin.getline(persona.num_fijo, 8, '\n');
    
    cout<<"ingrese edad: "; fflush(stdin);
    cin>>persona.edad;
    
    
    cout<<"******************************"<<endl;
   
    return persona;
   
   }
/////////////////////////////////////////////////////////////////////////////////////////////////////
//funcion que me busca por nomobre, comparamos una variable auxiliar y las que se encuentran anteriormente ingresadas, con el comando strcmp
int buscar_nombre(DATOS_PERSONALES personas,char nombre_buscar[50]){
   
   if(strcmp(personas.nombre,nombre_buscar)==0){
   	
   	
    cout<<"nombre:   "<<personas.nombre<<endl;
    
    cout<<"celular:  "<<personas.num_celular<<endl;
    
    cout<<"fijo:     "<<personas.num_fijo<<endl;
    
    cout<<"edad:     "<<personas.edad<<endl;
	
	return 1;

   }else
   
   {
     return 0;
   }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
//Esta función es exactamente igual, simplemnete  se comparan"numeros"
int buscar_telefono(DATOS_PERSONALES personas,char celular_buscar[11]){
 
 
  if(strcmp(personas.num_celular,celular_buscar)==0){
   	
    cout<<"nombre:  "<<personas.nombre<<endl;
    cout<<"celular: "<<personas.num_celular<<endl;
    cout<<"fijo:    "<<personas.num_fijo<<endl;
    cout<<"edad:    "<<personas.edad<<endl;
	
	return 1;

   }else{
     return 0;
   }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//funcion que me dice si una cadena es mayor a otra
int com(char cadena1[50], char cadena2 [50]){
	
int bandera = 0;  // si es uno cadena1>cadena2


   for(int i = 0; i < 50; i++){// recorremos todos los datos de la estructura
   	 
	   if(cadena1[i] > cadena2[i]){return 1; break;}
	   if(cadena1[i] < cadena2[i]){return 0; break;}
   }

}
/
//funcion que ordena mediande el metodo de insercion y luego imrpime los datos
void ordenar_imprimir(DATOS_PERSONALES personas[50],int edad,int edad2,int posicion){
	
   DATOS_PERSONALES aux;
   int pos = 0;

   for(int i=0; i < posicion; i++){
   	  pos = i;
   	  aux = personas[i];
   	
   	while((pos > 0 ) && (com(personas[pos-1].nombre,aux.nombre) == 1)){
   		
   		   personas[pos] = personas[pos -1];
   		   pos--;
	   }
   	    
   	    personas[pos] = aux;
   	
   	 }
		

   // Imprimimos los datos previamente ordenados
   for(int i = 0; i < posicion; i++){
   	 
   	
   		cout<<"Persona #: "<<i+1<<endl;
        cout<<"Nombre:    "<<personas[i].nombre<<endl;
        cout<<"Celular:   "<<personas[i].num_celular<<endl;
        cout<<"Fijo:      "<<personas[i].num_fijo<<endl;
        cout<<"Edad:      "<<personas[i].edad<<endl;
        
        cout<<endl<<endl;
   } 	
}
// Funcion principal
int main(){    

    DATOS_PERSONALES  personas[50];
    int Opcion;
    int posicion = 0;
    int si_esta = 0; //variable que me dice en la funcion de busqueda si esta o no esta
    char nombre_buscar[50]; //variables auxiliares, raliza la busqueda comparandola con los dats anteriormente registrados
    char celular_buscar[11];
    int edad;
   	int edad2;
   
    do{
   
   system("cls");
   cout<<"Registro de Personas: "<<endl<<endl;
   
   cout<<"Cantidad de personas dentro del registro: "<<posicion<<endl<<endl<<endl;
   
   cout<<"1. Ingreso de datos "<<endl;
   cout<<"2. Hacer una busqueda  por nombre "<<endl;
   cout<<"3. Hacer una busqueda por numero de telefono "<<endl;
   cout<<"4. Mostrar el listado de personas entre un rango de edad "<<endl;
   cout<<"5. salir."<<endl;
   cout<<"Pulsa una opcion: ";cin>>Opcion;
   cout<<endl;
   
   switch(Opcion){
   	
////////////////////////////////////////////////////////////////////////////////////////////////

   case 1:
   	
   //Vamos aumnetado la posicion segun ingresen nuevas personas
   
   if(posicion < 50){
   
   personas[posicion] = ingresar();
   
   posicion++;
   
   cout<<"Los datos de la persona se han guardado exitosamente"<<endl;
   }else{
   
    cout<<"Lo sentimos, el sistema esta lleno "<<endl;
   }
   
   getch();
   break;
   
////////////////////////////////////////////////////////////////////////////////////////////
   case 2:
   // Nos aseguaramos de que hayan usuarios anteriormente registrados 
    if(posicion == 0){
    cout<<"Debe ingresar un usuario primero"<<endl;
   
    getch();
    break;
  }
   
    cout<<"Por favor ingrese la persona que desea buscar: ";  
    fflush(stdin);  // Por si hay basura
    cin.getline(nombre_buscar, 50, '\n'); // Guardamos la variable auxiliar

   
   for(int i = 0; i <= posicion && si_esta == 0 ; i++){
   
    si_esta = buscar_nombre(personas[i],nombre_buscar);
    
   }
   
   
    if(si_esta == 0){
    cout<<"\nLo sentimos el ususario no esta en el sistema"<<endl;
   }
   
   
   si_esta = 0;
   getch();
   break;

/////////////////////////////////////////////////////////////////////////////////////
   case 3:
//Si la posicion se encuntra en 0 no se puede realizar la busqueda
   	if(posicion == 0){                               
    cout<<"Debe ingresar un usuario primero"<<endl;  
   
    getch();
    break;
    }
    
    cout<<"Por favor ingrese el celular de la persona que desea buscar: ";   //si se encuentran registrados al menos una persona se procede a perdir el celular  a buscar 
    fflush(stdin);
    cin.getline(celular_buscar, 11, '\n'); // se registra el celular y se guarda en la variable  celular_buscar
    
        
   for(int i = 0; i <= posicion && si_esta == 0 ; i++){
   
    si_esta = buscar_telefono(personas[i],celular_buscar);
    
   }
   
   // Si devuelve un uno, entoces el usuario esta, de lo contrario no se encunetra en el sistema
    if(si_esta == 0){
    cout<<"\nLo sentimos el ususario no esta en el sistema"<<endl;
   } 
  
   	
   
   getch();
   break;
///////////////////////////////////////////////////////////////////////////////
   case 4:
   	
   	if(posicion <= 1){
    cout<<"Debe ingresar al menos dos usuarios primero"<<endl;
   
    getch();
    break;
  }
   	
   	cout<<"Ingrese los rangos de edad por favor: "<<endl;
   	
   	
   	cout<<"Por favor ingrese la edad 1: "<<endl;
   	cin>>edad;
   	cout<<"Por favor ingrese la edad 2: "<<endl;
   	cin>>edad2;
   	cout<<"Listado de las personas entre "<<edad<<" y "<<edad2<<endl<<endl;  //variables que guardan las edades en las que se quiere listar
   	
   	ordenar_imprimir(personas, edad, edad2,posicion); //esta funcion ordena y luego imprime la lista de las personas que esta entre el rango de edad    	
   
   getch();
   break;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   
   default:
   cout<<"El programa termino :D"<<endl;
   
   getch();
   break;
   }//fin del menu
   
 }while(Opcion != 5);


return 0;
getch();
}

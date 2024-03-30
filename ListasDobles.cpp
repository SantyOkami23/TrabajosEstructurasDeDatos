/*
a) Ingreso de datos al final de la lista (los datos de una persona)
b) Buscar por identificación y mostrar datos
c) Buscar por número de teléfono y mostrar datos -> pendiente
d) Listar datos de personas entre X y Y años   -> pendiente
e) Eliminar una persona (por posición), mostrar datos para confirmar antes de eliminar //ya lo tienen
f) Eliminar una persona (por identificación), mostrar datos para confirmar antes de eliminar -> pendiente
g) Intercambiar dos personas (por posición) //ya lo tienen escrito en la hoja entregada
h) Intercambiar dos personas (por posición) //pero cambiando los punteros, no los datos
i) Ingreso de datos en una posición de la lista (los datos de una persona) //por posición
j) Ingreso de datos en una posición de la lista (los datos de una persona) //por posición// indicando
antes o después de alguien por identificación
k) Salir
Pulsa una opción:
*/

#include <iostream>
#include <math.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>


using namespace std;

typedef struct DATOS{

char nombre[50];
char celular[11];
char fijo[8];
int edad;

}DATOS_PERSONALES;


typedef struct NODO {

struct NODO *ant;
    DATOS_PERSONALES  *ptr_datos;
    struct NODO *sig;

}nodo;

nodo *primero = NULL;
nodo *ultimo = NULL;

//--------------------------------Funcion para mostrar un nodo de la lista-----------------------------------------------------------------
void MOSTRAR(DATOS_PERSONALES *ptr_datos){

    cout<<endl;
    cout<<"Ingrese Nombre: "<<ptr_datos -> nombre<<endl;
    cout<<"Ingrese Numero de Celular: "<<ptr_datos -> celular<<endl;
    cout<<"Ingrese Numero fijo: "<<ptr_datos -> fijo<<endl;
    cout<<" Ingrese Edad: "<<ptr_datos -> edad<<endl;

}
//----------------MUESTRA TODOS LOS NODOS DE LA LISTA --------------------------------
void MOSTRAR_TODO(){

nodo *temp = primero;

    while(temp  != NULL){
    MOSTRAR(temp -> ptr_datos);
    temp = temp -> sig;
  }
}
//CEUNTA LOS NODOS DE LA LISTA
int CUENTA (){

 nodo *temp = primero;
 int cant = 0;

 while(temp != NULL){
  cant++;
  temp = temp -> sig;
 }

 return cant;
}

//-----------------------FUNCION PARA INSERTAR NUEVOS NODOS A LISTA ----------------------------------
void INGRESAR (DATOS_PERSONALES *ptr_datos){

cout<<endl;
    cout<<"Ingrese Nombre: ";
    cin.getline(ptr_datos -> nombre, 50, '\n');

    cout<<"Ingrese numero de celular: ";
    cin.getline(ptr_datos -> celular, 11, '\n' );

    cout<<"ingrese  numero fijo: ";
    cin.getline(ptr_datos -> fijo, 8, '\n');

    cout<<"ingrese edad: ";
    cin>>ptr_datos -> edad;
}

void INSERTAR(){

   nodo *nuevo;
   nuevo = new(nodo);
   nuevo -> ptr_datos = new(DATOS_PERSONALES);


   INGRESAR(nuevo -> ptr_datos);
   if(primero == NULL)
   {
      nuevo -> ant = NULL;
 nuevo -> sig = NULL;
     primero = nuevo;
     ultimo = nuevo;

   }else
   {
    nodo *temp = primero;

   temp = ultimo;
   temp -> sig = nuevo;
   nuevo -> ant = temp;
   nuevo -> sig = NULL;

   ultimo = nuevo;
    }

    cout<<endl<<"OPERACION COMPLETADA "<<endl;
}
//----------------------FUNCION PARA BUSCAR LOS DATOS POR NOMBRE-------------------
void BUSCAR_NOMBRE(){

nodo *temp = primero;
char nombre_aux[50];
int buscador = 0;

cout<<"Ingrese el nombre a buscar: "<<endl;
cin.getline(nombre_aux, 50, '\n');


    while(temp != NULL && buscador == 0)
{

           if(strcmp(temp -> ptr_datos -> nombre,nombre_aux)==0)
  {
           MOSTRAR(temp -> ptr_datos);
   buscador  = 1;

  }else  temp = temp -> sig;
        }


if(buscador == 0){cout<<endl<<"Este nombre no se encuentra en la base de datos"<<endl<<endl;}


}

//-------------------FUNCION QUE BUSCA POR TELEFONO
void BUSCAR_TELEFONO(){

nodo *temp = primero;
char celular_aux[50];
int buscador = 0;

cout<<"Ingrese el numero de celular a buscar: ";
cin.getline(celular_aux, 11, '\n');


    while(temp != NULL && buscador == 0)
    {
  if(strcmp(temp -> ptr_datos -> celular,celular_aux)==0)
   {
           MOSTRAR(temp -> ptr_datos);
   buscador  = 1;
}else  temp = temp -> sig;
    }


if(buscador == 0) cout<<endl<<"ESTE NUMERO DE CELULAR NO SE ENCUENTRA EN LA BASE DE DATOS "<<endl;

}

//---------FUNCION QUE ORDENA-----------------------------------------------
void ORDENAR(){
 nodo *temp = primero;
 int edad1 = 0, edad2 = 0;
 int si = 0;


 cout<<"Ingrese los rango de edad por favor:"<<endl;
 cout<<"Edad 1: ";cin>>edad1;
 cout<<"Edad 2: ";cin>>edad2;

    if(edad2 < edad1)
{
    int aux = 0;

    aux = edad2;
    edad2 = edad1;
    edad1 = aux;
}


   while(temp != NULL)
 {
   if(temp -> ptr_datos -> edad >= edad1 && temp -> ptr_datos -> edad <= edad2)
 {
        MOSTRAR(temp -> ptr_datos);
         si = 1;
 }
 cout<<endl;
   temp = temp -> sig;
 }


   if(si == 0){cout<<"\nLO SENTIMOS, NO SE HAN ENCONTRADO USUARIOS EN DICHOS RANGOS DE EDAD"<<endl;}
}
//----------------FUNCION PARA ELIMINAR UN NODO DE LA LISTA -----------------------------
int  decision(DATOS_PERSONALES *ptr_datos){
  int d = 0;

  MOSTRAR(ptr_datos);
  cout<<endl<<"si desea borrar oprima 1, SINO contrario oprimima 0 : ";cin>>d;

  if (d == 1) cout<<endl<<"OPERACION REALIZADA EXITOSAMENTE"<<endl;

  return d;
}

void ELIMINAR_POSICION(){

 nodo *temp = primero;
 nodo *aux;
 int pos = 0;
 int numero_de_nodos = 0;

 numero_de_nodos = CUENTA();

 cout<<"Ingrese la posicion que desea borrar: ";cin>>pos;

    if(pos == 1)
{

   if(decision(primero -> ptr_datos) == 1)
{
   if(primero -> sig == NULL)
{
    primero = NULL;
}
else
{
primero -> sig -> ant = NULL;
       primero = primero -> sig;
}
delete(temp);
}

    }

    if(pos >= 2 && pos <= numero_de_nodos)
{

      for(int i = 1;  i <  pos  && temp -> sig != NULL; i++){ temp = temp -> sig;}


 if(decision(temp -> ptr_datos) == 1)
 {
  aux = temp;

  if(temp -> sig != NULL) {temp -> sig -> ant = temp -> ant;}
  else {ultimo = temp -> ant;}

           temp -> ant -> sig = temp -> sig;

         delete(aux);
      }

    }

    if(pos > numero_de_nodos) cout<<"\nLO SENTIMOS, ESA POSICION NO EXISTE :C"<<endl;

}
//------------------------ELIMINA LA INFROMACION MEDIANTE UN IDENTIFICADOR, UN NOMBRE EN ESTE CASO--------------------------------------
void ELIMINAR_IDENTIFICADOR(){

   nodo *temp = primero;
   nodo *aux;
   char nombre_aux[50];
   int buscador = 0;

   cout<<"Ingrese el nombre que desea borrar: ";
   cin.getline(nombre_aux, 50, '\n');


   while(temp != NULL && buscador == 0)
   {
    if(strcmp(temp -> ptr_datos -> nombre,nombre_aux)==0) buscador = 1;
    else temp = temp -> sig;
   }

   if(buscador == 0) cout<<endl<<"EL USUARIO NO SE ENCUNTRA REGISTRADO EN LA BASE DE DATOS :C"<<endl;
   else
   {

   if(decision(temp -> ptr_datos) == 1)
    {
      if(temp == primero)
      {
           if(primero -> sig == NULL)
{
    primero = NULL;
}
else
{
primero -> sig -> ant = NULL;
       primero = primero -> sig;
}
delete(temp);
      }else
      {
      if(temp -> sig != NULL) temp -> sig -> ant = temp -> ant;
      temp -> ant -> sig = temp -> sig;

      delete(temp);
 }

   }
  }
}

//-----------FUNCION QUE INTERCAMBIA SOLO LOS DATOS--------------------------------------
void INTERCAMBIAR_DATOS(){

  nodo *temp = primero;
  nodo *pos1;
  nodo *pos2;
  int p1 = 0, p2 = 0;

  cout<<endl<<"Por favor ingrese las posiciones que desea  intercambiar"<<endl;
  cout<<"Posicion 1: ";cin>>p1;
  cout<<"Posicion 2: ";cin>>p2;

  if(p2 < p1){
    int aux = 0;
    aux  = p2;
p2 = p1;
p1 = aux;
  }

   if(p2 <= CUENTA())
   {

 for(int i = 1; i < p2; i++)
   {

   if(i == p1){pos1 = temp;}
   temp = temp -> sig;
   }
          pos2 = temp;

        DATOS_PERSONALES *aux_p;

        aux_p = pos2 -> ptr_datos;
        pos2 -> ptr_datos = pos1 -> ptr_datos;
        pos1 -> ptr_datos = aux_p;

        cout <<"OPERACION REALIZADA EXITOSAMENTE"<<endl;

    }else cout<<endl<<"LO SENTIMOS, LAS POSICIONES NO SE ENCUENTRAN EN LA BAS DE DATOS :C"<<endl;
}


//-------------------------------------FUNCION QUE INTERCAMBIA DOS POSICIONES POR PUNTEROS-------------------------------
void INTERCAMBIAR_PUNTEROS(){

  nodo *temp = primero;
  nodo *pos1;
  nodo *pos2;
  nodo *aux1;
  nodo *aux2;
  int p1 = 0, p2 = 0;

  cout<<endl<<"Por favor ingrese las posiciones que intercambiar"<<endl;
  cout<<"Posicion 1: ";cin>>p1;
  cout<<"Posicion 2: ";cin>>p2;

  if(p2 < p1){
    int aux = 0;
    aux  = p2;
	p2 = p1;
	p1 = aux;
  }

  if(p2 <= CUENTA())
   {
   	 for(int i = 1; i < p2; i++)
	    {
  		  if(i == p1){pos1 = temp;}
  		  temp = temp -> sig;
	    }pos2 = temp;

	   if(p1 == 1)
	   {
	   	 if(p2 == 2)
			{
	   	 	  aux1 = pos2 -> ant;
	   	 	  aux2 = pos2 -> sig;

	          if(pos2 != ultimo ) pos2 -> sig -> ant = pos1;
	   	 	  pos2 -> sig = aux1;
	   	 	  pos2 -> ant = pos1 -> ant;
	   	 	  pos1 -> ant = pos2;
	   	 	  pos1 -> sig = aux2;


	   	 	  primero = pos2;
	   	 	  if(pos2 == ultimo) ultimo = pos1;

			}

	   }
	   else
	   {

	       if( p2 == (p1 + 1) )
		  {

		   aux1 = pos1 -> ant;
	       pos1 -> ant -> sig = pos1 -> sig;
	       pos1 -> ant = pos1 -> sig;
	       pos1 -> sig = pos2 ->sig;
	       pos2 -> sig -> ant = pos2 -> ant;
	       pos2 -> sig = pos2 -> ant;
	       pos2 -> ant = aux1;
		  }
		  else
		  {

	      aux1 = pos1 -> ant;
	      pos1 -> ant -> sig = pos2;
	      pos1 -> ant = pos1 -> sig;
	      pos1 -> sig -> sig = pos1;
	      pos1 -> sig -> ant = pos2;
	      pos1 -> sig = pos2 -> sig;
	      pos2 -> sig = pos2 -> ant;
	      pos2 -> ant = aux1;
	      }

       }

	}else cout<<"\nLO SENTIMOS, LAS POSICIONES INDICADAS NO ESTAN EN LA LISTA"<<endl;
}
// -----------------------FUNCION PARA INVERTIR LOS NODOS DE LA LISTA---------------------------
void invertir(){

nodo *temp = primero;
nodo *aux;
nodo *aux2;
nodo *aux3;

while(aux3 != NULL){

aux3 = temp -> sig;
aux = temp -> sig;
temp -> sig = temp -> ant;
temp -> ant = aux;


temp = aux3;
}

aux2 = primero;
primero = ultimo;
ultimo = aux2;

}
//-----------------FUNCION PRINCIPAL---------------------------
int main(){


  int opcion = 0;

  do{
  system("cls");
      cout<<"EJERCICIO LISTAS DOBLES" <<endl<<endl;
    cout<<"1.Ingreso de datos al final de la lista "<<endl<<endl;
    cout<<"2.Buscar por identificacion y mostrar datos."<<endl<<endl;
    cout<<"3.Buscar por numero de telefono y mostrar datos."<<endl<<endl;
    cout<<"4.Listar datos de personas entre X y Y anos."<<endl<<endl;
    cout<<"5.Eliminar una persona (por posicion), mostrar datos para confirmar antes de eliminar."<<endl<<endl;
    cout<<"6.Eliminar una persona (por identificacion), mostrar datos para confirmar antes de eliminar"<<endl<<endl;;
    cout<<"7.Intercambiar dos personas (por posicion) "<<endl<<endl;
    cout<<"8.Intercambiar dos personas (por posicion) //pero cambiando los punteros, no los datos."<<endl<<endl;
    cout<<"9.Ingreso de datos en una posicion de la lista  //por posicion."<<endl<<endl;
    cout<<"10.Ingreso de datos en una posicion de la lista  //por posicion//  indicando\n antes o despues de alguien por identificacion"<<endl<<endl;
    cout<<"11.Mostrar todos los datos."<<endl<<endl;
    cout<<"12.Invertir los nodos de la lista "<<endl<<endl;
    cout<<"13.Salir."<<endl<<endl;
    cout<<"Por favor ingrese una opcion: "<<endl;
    cin>>opcion;

    switch(opcion){
    case 1:

INSERTAR();
cout<<endl<<CUENTA()<<endl;
    getch();
         break;

        case 2:
        if(primero == NULL){
        cout<<endl<<"Ingrese datos primero"<<endl;
        INSERTAR();

}else BUSCAR_NOMBRE();

        getch();
         break;

         case 3:
if(primero == NULL){
        cout<<endl<<"Ingrese datos primero"<<endl;
        INSERTAR();
}else BUSCAR_TELEFONO();

    getch();
         break;

    case 4:
    if(primero == NULL){
        cout<<endl<<"Ingrese datos primero"<<endl;
        INSERTAR();
}else ORDENAR();

    getch();
         break;

case 5:

if(primero == NULL){
        cout<<endl<<"Ingrese datos primero"<<endl;
        INSERTAR();
}else  ELIMINAR_POSICION();

getch();
         break;

         case 6:

if(primero == NULL){
        cout<<endl<<"Ingrese datos primero"<<endl;
        INSERTAR();
}else ELIMINAR_IDENTIFICADOR();

         getch();
         break;

         case 7:
    if(CUENTA() < 2){
         cout<<endl<<"Ingrese mas datos primero"<<endl;

         }else INTERCAMBIAR_DATOS();

    getch();
         break;

         case 8:

         if(CUENTA() < 2){
         cout<<endl<<"Ingrese mas datos primero"<<endl;

         }else INTERCAMBIAR_PUNTEROS();


    getch();
         break;

         case 9:

if(primero == NULL){
        cout<<endl<<"Ingrese datos primero"<<endl;
        INSERTAR();
}else

    getch();
         break;

         case 10:

        if(primero == NULL){
        cout<<endl<<"Ingrese datos primero"<<endl;
        INSERTAR();
}else

    getch();
         break;

         case 11:

        if(primero == NULL) {
        cout<<endl<<"Ingrese datos primero"<<endl;
        INSERTAR();
}else  MOSTRAR_TODO();

    getch();
         break;

         case 12:
            if (primero=NULL){
         cout<<endl<<"Ingrese datos primero"<<endl;
        INSERTAR();

        }else invertir();

default:

cout<<endl<<"HASTA PRONTO :D"<<endl;

getch();
         break;
}
  }while(opcion != 13);

  return 0;
}






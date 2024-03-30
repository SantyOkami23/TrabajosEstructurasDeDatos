#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

using namespace std;

struct nodo
{
	char id[12];
	char nombre[30];
	char numeroTelefono[11];
	char numeroCelular[11];
	int edad; 
	struct nodo *siguiente;
};

struct nodo *primero=NULL;

void imprimir()
{
	struct nodo *nuevo;
	nuevo=primero;
	cout<<"Contenido de la lista..."<<"\n";	
	
	while(nuevo!=NULL)
	{
		cout<<"Código: "<<nuevo->codigo<<"\n";	
		cout<<"Nombre: "<<nuevo->nombre<<"\n";	
 	    cout<<"Telefono: "<<nuevo->numeroTelefono<<"\n";	
	    cout<<"Celular: "<<nuevo->numeroCelular<<"\n";	
	    cout<<"Edad: "<<nuevo->edad<<"\n";
		cout<<"------------------------------------"<<"\n";	
		nuevo=nuevo->siguiente;
	}
}




 	
 	
 	
 }
//_---------------------------funcion para ingresar-------------------------

void INGRESAR(struct nodo* persona){

	cout<<endl;
    cout<<"ingrese identificacion ";
    fflush(stdin);
    cin.getline(nodo -> id, 12, '\n');

    cout<<"ingrese Nombre: ";
    fflush(stdin);
    cin.getline(nodo->nombre, 50, '\n' );

    cout<<"ingrese telefono: ";
    fflush(stdin);
    cin.getline(nodo->numeroTelefono, 8, '\n');

    cout<<"ingrese celular: ";
    fflush(stdin);
    cin.getline(nodo -> numeroCelular,11,'\n');
}

//-----------------------------


void INSERTAR(){

   nodo *nuevo;
   nuevo = new(nodo);
  


   INGRESAR(nuevo );  

   if(primero == NULL)
   {
      nuevo -> sig = NULL;
   	  primero = nuevo;

   }else
   {
   	 nodo *temp = primero;
     nodo*aux;
     nodo *aux2;
     
	 
	 
	 aux = comparar (temp, nuevo);
	 aux2 =aux-> nuevo;
	 aux-> siguiente =nuevo;
	 nuevo->siguiente =aux2;
	 
     
   
	    
    }

    cout<<endl<<"DATOS GUARDADOS CORRECTAMENTE"<<endl;
}



//------------------------------------Funcion para comparar-----------------
 struct nodo *comparar (struct nodo *temp, struct nodo *nuevo  ){
 	
 	for(int i=0 ; 1 < 50; 1++){
 		
 		
 		if (temp-> siguiente-> id[i] <    nuevo->id[i])
 		
 		return 1;
 		
	 }
	 
	 else temp= temp->sig;





int menu()
{
	int x;
	cout<<" 1) ingresar una persona al sistema"<<"\n";
	cout<<" 2) Imprimir la lista"<<"\n";
	cout<<" 3) salir"<<"\n";
	cin>>x;
return x;	
}
	



int main()
{
	int op;
	do
	{
		system("cls");
		op=menu();
		system("cls");
		switch(op)
		{
			case 1:
	            INSERTAR();
			break;
			case 2:
				imprimir();
				break;
			case 3:
				cout<<"El programa finalizara ahora..."<<"\n";
				break;
			default:
				cout<<"Opcion invalida, vuelva a intentar..."<<"\n";
				break;
		}
		system("PAUSE");
	}while(op!=3);	
}

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

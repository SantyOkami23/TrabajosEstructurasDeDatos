#include <iostream>
#include <conio.h>


using namespace std;

//-----------------------------------------------------------------------------------------------------------------------

struct informacion_celda
{
	
unsigned int identificador;
char nombre[100];
float calidad_senal;

struct informacion_operador *ptr_operador;
};

struct informacion_operador
{
	
char nombre[100];
unsigned int prioridad;
unsigned int ultima_comprob;
};

struct informacion_celda persona; //Creo una variable para guardar los datos
struct informacion_celda *ptr_persona = &persona; // Agrego puntero que es igual a la direccion de memoria de persona para agregar los datos.
struct informacion_operador ptr_op; //Creo una variable para guardar los datos del operador
//-----------------------------------------------------------------------------------------------------------------------

 llenar(){
	
	fflush(stdin);
	cout<<"Ingrese la identificacion: ";
	cin>>ptr_persona->identificador;
	fflush(stdin);
	cout<<"Ingrese el nombre: ";
	cin.getline(ptr_persona->nombre,100,'\n');
	fflush(stdin);
	cout<<"Ingrese la calidad de la señal: ";
	cin>>ptr_persona->calidad_senal;
	cout<<endl;
	
	cout<<"Ahora va a ingresar los datos del operador"<<endl;
	fflush(stdin);
	cout<<"Ingrese el nombre: ";
	cin.getline(ptr_op.nombre,100,'\n');
	fflush(stdin);
	cout<<"Ingrese la prioridad: ";
	cin>>ptr_op.prioridad;
	fflush(stdin);
	cout<<"Ingrese la ultima comprovacion: ";
	cin>>ptr_op.ultima_comprob;
	cout<<endl;

}

//-----------------------------------------------------------------------------------------------------------------------

 actualizar(){
	
	cout<<"Se va a actualizar la informacion del operador: "<<endl;
	
	fflush(stdin);
	cout<<"Ingrese el nombre: ";
	cin.getline(ptr_op.nombre,100,'\n');
	fflush(stdin);
	cout<<"Ingrese la prioridad: ";
	cin>>ptr_op.prioridad;
	fflush(stdin);
	cout<<"Ingrese la ultima comprovacion: ";
	cin>>ptr_op.ultima_comprob;
	cout<<endl;
	
}

//-----------------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------------

int main() {
	
	char personas[10];
	char operadores[10];
	
	int op=0, cant=0, j=0, cont=0;
	
	cout<<"Menu"<<endl;
	cout<<"1. Ingresar datos"<<endl;
	cout<<"2. Cambiar datos del operador"<<endl;
	cout<<"Elija la opcion que desee: "; cin>>op;
	
	while(op!=3){
		
	switch(op){
		case 1: system("CLS");
				
				for(int i=0;i<cant;i++){
					personas[i]=llenar();
				}
				return main();
				break;
				
		case 2: int i=0;
				for(i=0;i<=cant;i++)
				operadores[i]=actualizar(); 
				}
				return main();
				break;	
				
	}
	
	return 0;
}

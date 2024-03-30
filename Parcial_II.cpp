#include <iostream>
#include <conio.h>

using namespace std;

typedef struct informacion_operador{

char nombre[100];
unsigned  int prioridad;
unsigned int ultima_comprob;
}INFORMACION_OPERADOR;


typedef struct informacion_celda{

unsigned int identificador;
char nombre[100];
float calidad_senal;
info_operador *ptr_operador;
}INFORMACION_CELDA;




void llenar(INFORMACION_CELDA *puntero_datos, int *posicion){


if(*posicion >= 10){
	
	
cout<<"LO SENTIMOS YA NO HAY ESPACIO EN LA BAS DE DATOS "<<endl;

}
else{

(puntero_datos + *posicion) -> ptr_operador = new(INFORMACION_OPERADOR);

 
      cout<<"POR FAVOR INGRESE LOS SIGUIENTES DATOS  "<<endl<<endl;



          
         cout<<"Ingrese identificador de la celda: "<<endl;
         cin>> (puntero_datos + *posicion) -> identificador;
          
         cout<<"Ingrese nombre del propietario: "<<endl;
         cin.getline((puntero_datos + *posicion) -> nombre ,100,'\n');
         
         cout<<"Ingrese calidad de la senal: "<<endl;
         cin>>(puntero_datos + *posicion) -> calidad_senal;
        
         cout<<"\nAPARTADO PARA DATOS DEL OPERADOR : "<<endl;
         
         cout<<"Ingrese nombre: "<<endl;
         cin.getline((puntero_datos + *posicion) -> ptr_operador -> nombre, 100, '\n');
         
         cout<<"Ingrese prioridad: "<<endl;
         cin>>(puntero_datos + *posicion) -> ptr_operador -> prioridad;
         
         
         cout<<"Ingrese ultima comprobacion: "<<endl;
         cin>>(puntero_datos + *posicion) -> ptr_operador -> ultima_comprob;
        


         *posicion = *posicion +1;
         
     }
}


void modificar(INFORMACION_OPERADOR *operador){
	     

	    cout<<"Ingrese nuevo nombre: ";
        cin.getline(operador -> nombre, 100, '\n');
        cout<<"Ingrese nueva prioridad: ";
        cin>>operador -> prioridad;
        cout<<"Ingrese ultima comprobacion: ";
        cin>>operador -> ultima_comprob;
        
        cout<<"Usuario ingresado correctamente"<<endl;
}


void actualizar(INFORMACION_CELDA *puntero_datos, int *posicion){

  int comprobante = 0;

  if(*posicion == 0){
  	cout<<"AÚN NO SE HA INGRESADO INFORMACION "<<endl;
  	
  }
  else{
  	
    unsigned int identificador_aux = 0;
 
	cout<<"Ingrese el idenficador que desea  actualizar: ";cin>>identificador_aux;
	
	for(int i = 0 ; i <= *posicion; i++){
		
		if(identificador_aux == (puntero_datos + i) -> identificador){
			modificar((puntero_datos + i) -> ptr_operador); 
			comprobante = 1; }  
	}
	
	if(comprobante == 0) cout<<"No se ha encontrado el identificador "<<endl;


}




int main(){

      info_celda DATOS[10];
      info_celda *puntero_datos;
      int X = 0;
      int *posicion;
      int opcion = 0;

      posicion = &X;
      puntero_datos = &DATOS[0];
     
      do{
 
      system("cls");
     
      cout<<"---------MENU----------"<<endl<<endl;
      cout<<""<<endl;
      
      cout<<"1) Ingeresar"<<endl;
      
      cout<<"2) Actualizar"<<endl;
      
      cout<<"3) Salir"<<endl;
      
      cout<<"Seleccione una opcion : ";cin>>opcion;
     
     
   
       
      switch(opcion) {
     
      case 1:
      	
      fflush(stdin);
      llenar(puntero_datos,posicion);
      
      getch();
      break;
      case 2:
      	
      actualizar(puntero_datos,posicion);
     
      getch();
      break;
     
      default:
     
      cout<<endl<<"HASTA PRONTO"<<endl;
     
      getch();
      break;
 }

     
     }while(opcion == 1 || opcion == 2);
       



return 0;
}

/*2. Escriba un programa que utilice STRUCT, funciones y archivos. El programa permitirá manejar la información de
estudiantes de la UTP (código, nombre, dirección, teléfono, [semestre, periodo, promediointegral, #materiascursadas],
estado) creando una estructura anidada (dos estructuras, una anidada con la otra y que permita registrar por estudiante
hasta 12 períodos académicos. El programa debe permitir a través de un menú:
1. Ingresar un estudiante al sistema. Se ingresan los datos de un estudiante, exceptuando el estado.
2. Definir estado de los estudiantes. El sistema debe asignar a los estudiantes registrados, su estado así:
Si promediointegral menor a 2.5, estado FUERA
Si promediointegral entre 2.5 y 2.9, estado PRUEBA
Si promediointegral mayor o igual a 3.0, estado NORMAL
3. Mostrar toda la información de los estudiantes en estado FUERA registrados en el sistema.
4. Salir
Pulsa una opción:

Santiago Ramirez Arenas 

*/

#include <iostream>
#include <math.h>
#include <conio.h>
#include <string.h>


using namespace std;
 
// Estructura principal

typedef struct DATOS{

 int   semestre;
 char  periodo[7];   
 float promedio_integral;
 int   materias_cursadas;

}Datos;

//Estructura anidada

typedef struct INFORMACION_ESTUDIANTE{
char    codigo[13];
char    nombre[50];
char    direccion[50];
char    telefono[11];
Datos   general[12];  // Aqui se guardaran todos los datos correspondintes a cada estudiante 
int     estado;// definimos estado como un entero
int     posicion;

}Informacion_estudiante;
///////////////////////////////////////////////////////////////////////////////////////

// constante de tipo char que a su vez es un puntero a un vector
const char *Estado_es[]={"Sin Asignar", "Fuera", "Prueba", "Normal" }; 

//////////////////////////////////////////////////////////////////////////////////////
//funcion que  nos ayuda a inicializar todas y cada una de las varibles
Informacion_estudiante inicializar(){
 
 Informacion_estudiante estudiante;
	
	for(int i=0; i < 13; i++){
		estudiante.codigo[i] = 0;
			}
    for(int i=0; i < 50; i++){
    	estudiante.nombre[i] = 0;
	}
	
	for(int i=0; i < 50; i++){
	   estudiante.direccion[i] = 0;
	}
	
	for(int i=0; i < 11; i++){
	   estudiante.telefono[i] = 0;
	}
	
	for(int i = 0; i < 12; i++){
	  
	  estudiante.general[i].semestre = 0;
	  estudiante.general[i].materias_cursadas = 0;
	  estudiante.general[i].promedio_integral = 0.0;	
	  for(int k=0; k < 7; k++){
	  	estudiante.general[i].periodo[k]  = 0;// leemos los caracteres correpondientes a lo que se encuentra en la variable periodo
	  }	
	}
	
	estudiante.estado = 0;
	
	return estudiante;
}

//////////////////////////////////////////////////////////////////////////////////////

//funcion que buscar por codigo, correspondiente a cada estudiante 


int buscar(char codigo_aux[13]){

Informacion_estudiante estudiante;
int tamest = sizeof(estudiante);
int si_esta = 0;


  FILE *usuario;	
  
    usuario = fopen("USUARIO.txt", "r");
	
	while(fread(&estudiante, tamest, 1, usuario) == 1 && si_esta == 0){
   
          if(strcmp(estudiante.codigo,codigo_aux) == 0){
          	 si_esta = 1;
	}  
   } 
   
   cout<<"Lo sentimos pero no es posible guardar los datos ya que el estudiante ya se encuntra en el sistema"<<endl;
   fclose(usuario);
   return si_esta;
}
///////////////////////////////////////////////////////////////////////////////////////////////////

//funcion donde se inicia el archivo y se ingresan nuevos ================================================================================
void ingresar(){

Informacion_estudiante estudiante;
int tamest = sizeof(estudiante);
int si_esta = 0;
system("cls");
FILE *usuario;  //nombre del archivo donde se van a guardar los datos

     estudiante = inicializar();
 
     cout<<" Base de Datos Municiapl"<<endl;
     cout<<" Base de datos Estudiantes           "<<endl<<endl<<endl;
     cout<<"Por favor ingrese los datos solicitados  "<<endl<<endl;
   
     usuario = fopen("USUARIO.txt", "a+");
    
     
    fflush(stdin);
    cout<<"Ingrese el codigo del estudiante: ";
    cin.getline(estudiante.codigo, 13, '\n' );
    fflush(stdin);
    
    cout<<"Ingrese el Nombre: ";
    cin.getline(estudiante.nombre, 50, '\n');
    fflush(stdin);
    
    cout<<"Ingrese su direccion: ";
    cin.getline(estudiante.direccion, 50, '\n');
    fflush(stdin);
    
    cout<<"Ingrese telefono: ";
    cin.getline(estudiante.telefono, 11, '\n');
    fflush(stdin);
    
    cout<<"Ingresar semestre: ";
    cin>>estudiante.general[estudiante.posicion].semestre;
    fflush(stdin);
    
    cout<<"Ingrese el periodo academico (ejem: 2019-1): ";
    cin.getline(estudiante.general[estudiante.posicion].periodo, 7, '\n');
    fflush(stdin);
    
    cout<<"Promedio integral: ";
    cin>>estudiante.general[estudiante.posicion].promedio_integral;
    fflush(stdin);
    
    cout<<"Ingrese el numero de matarias cursadas: ";
    cin>>estudiante.general[estudiante.posicion].materias_cursadas;
    
    fwrite(&estudiante, tamest, 1,usuario);
    fclose(usuario);
    
    cout<<"Los datos del usuario se han guardado con exito :D "<<endl<<endl;
    
    cout<<"Por favir pulse ENTER... ";
  
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//funcion que imprime  los datos corrspondientes
void mostrar(){

Informacion_estudiante estudiante;
int tamest = sizeof(estudiante);
int i = 1; //esta variable lo que hace es mostrar el numero de estudiante al momento de imprimir
FILE *usuario;

system("cls");

    cout<<" Base de Datos Municipal               "<<endl;
     cout<<" Base de datos Estudiantes           "<<endl;
     cout<<" Estudiantes Ingresados hasta el momento: "<<endl<<endl;
 
    usuario = fopen("USUARIO.txt", "r");
   
    while(fread(&estudiante, tamest, 1, usuario) == 1){
    if(estudiante.estado == 1){   //solamente va a imprimir los estudiantes que tengan como estado 1 osea FUERA
    	
      cout<<"Estudiante numero : "<<i<<endl<<endl;
	  cout<<"Codigo: "<<estudiante.codigo<<endl;
      cout<<"Nombre: "<<estudiante.nombre<<endl;
      cout<<"Direccion: "<<estudiante.direccion<<endl;
      cout<<"Telefono: "<<estudiante.telefono<<endl;
      cout<<"Estado: "<<Estado_es[estudiante.estado];
      
      for(int j = 0; j <= estudiante.posicion; j++){
      	
      cout<<"\nSemestre : "<<estudiante.general[j].semestre<<endl;
      cout<<"Periodo: "<<estudiante.general[j].periodo<<endl;
      cout<<"Promedio Integral: "<<estudiante.general[j].promedio_integral<<endl;
      cout<<" Materias cusrsadas: "<<estudiante.general[j].materias_cursadas<<endl<<endl;
	  
	  }	  
	  cout<<endl;
	  i++; 
    }
} 

fclose(usuario);

}
///////////////////////////////////////////////////////////////////////////////////////////////////
//funcion  que se encarga de agregarotro periodo academico 
Datos llenar_periodo(){
Datos estudiante;

    fflush(stdin);
    cout<<"Ingresar semestre: ";
    cin>>estudiante.semestre;
    fflush(stdin);
    
    
    cout<<"Ingrese el periodo academico (ejem: 2019-1): ";
    cin.getline(estudiante.periodo, 7, '\n');
    fflush(stdin);
    
    
    cout<<"Promedio integral: ";
    cin>>estudiante.promedio_integral;
    fflush(stdin);
    
    
    cout<<"Ingrese el numero de matarias cursadas: ";
    cin>>estudiante.materias_cursadas;
   
   
    return estudiante;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// funcion encargada de la asignacion de periodos
void periodos(){
 
  system("cls");
  Informacion_estudiante estudiante;
  int tamest = sizeof(estudiante);
  char  codigo_aux[11];
  
     cout<<"		Base de Datos Municipal             "<<endl;
     cout<<" 		Base de datos Estudiantes           "<<endl;
     cout<<"			Agregar Periodo                 "<<endl<<endl;
 
  fflush(stdin);
  cout<<"Por favor ingrese el codigo del estudiante:";
  cin.getline(codigo_aux, 13, '\n');
 
  FILE  *aux;
  FILE  *usuario;
 
            usuario = fopen("USUARIO.txt", "r+");
            aux =  fopen("AUXILIAR.txt", "at+");
           
            while(fread(&estudiante,tamest, 1, usuario) == 1){
           
            if(strcmp(estudiante.codigo,codigo_aux) != 0){ fwrite(&estudiante, tamest, 1, aux);}
			
            if(strcmp(estudiante.codigo,codigo_aux) == 0){
            estudiante.posicion ++;
            estudiante.general[estudiante.posicion] = llenar_periodo();
            
              fwrite(&estudiante, tamest, 1,aux);}
         } 

        fclose(usuario);
        fclose(aux);
        remove("USUARIO.txt");
        rename("AUXILIAR.txt","USUARIO.txt");

        cout<<"Usuario modificado con exito!!!"<<endl;
        cout<<"Presione ENTER para continuar"<<endl;

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//En esta funcion se asigna el estado correspondiente segun el promedio de cada estudiante 
void asignar_estados(){
	
  system("cls");
  Informacion_estudiante estudiante;
  int tamest = sizeof(estudiante);
  float promedio = 0.0;	
  float sum = 0.0;
  
     cout<<"		Sistema Municipal de Datos     "<<endl;
     cout<<" 		Base de datos Estudiantes           "<<endl;
     cout<<"			Asignar Estados                 "<<endl<<endl;
     
     FILE  *aux;
     FILE  *usuario;
     
        usuario  = fopen("USUARIO.txt", "r+");
        aux  =  fopen("AUXILIAR.txt", "at+");
        
        while(fread(&estudiante,tamest,1,usuario) == 1){
        	
        	for(int i = 0; i <= estudiante.posicion; i++){
        		
             sum = sum + estudiante.general[i].promedio_integral;
			}
			
			promedio = sum/(estudiante.posicion + 1);
			cout<<sum<<endl;
			cout<<promedio<<endl<<endl;
			
			if(promedio < 2.5 ){ estudiante.estado = 1; }
			if(promedio >= 2.5 && promedio <= 2.9){ estudiante.estado = 2; }
			if(promedio >= 3.0) { estudiante.estado = 3; }
			
			promedio = 0;
			sum = 0;
			
			fwrite(&estudiante, tamest, 1, aux);
		}
		
		fclose(usuario);
		fclose(aux);
		remove("USUARIO.txt");
		rename("AUXILIAR.txt", "USUARIO.txt");
		
		cout<<"Todos los estudiantes han sido asignados con exito!!!"<<endl;
		cout<<"Presione ENTER para continuar"<<endl;	
	
	
}
////////////////////////////////////////////////////////////////////////////////////////
//funcion que reinicia el sistema
void formatear(){
   
  char decision[2];
  FILE *usuario;
  
   cout<<"Esta seguro que desea borrar todos los datos?"<<endl;
   fflush(stdin);
   cin.getline(decision, 2, '\n');
   
   for(int i = 0; i < 2; i++){ decision[i] = tolower(decision[i]);}
   
   if (strcmp(decision, "si") == 0)   //getchar recibe el valor (tiene reflejo en pantalla) tolower vuelve la letra en minuscula
      {
          usuario = fopen("USUARIO.txt","w");
          fclose(usuario);
      }

}
////////////////////////////////////////////////////////////////////////////////////
//Menu, funcion principal

int main(){

int opcion = 0; //se toma la opcion que desea el ususario


do{
	
	char codigo_aux[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};// inicializamos en 0  el codigo auxiliar para realizar la busqueda
	int si_esta = 0;// inicializamos en falso la variable que determinar si esta o no

    system("cls");
   
    cout<<"        Sistema Municipal de Datos             "<<endl;
    cout<<"         Base de datos Estudiantes           "<<endl<<endl<<endl;
   
    cout<<"1. Ingresar un estudiante al sistema. Se ingresan los datos de un estudiante, exceptuando el estado."<<endl;
    
    cout<<"2. Definir estado de los estudiantes. El sistema debe asignar a los estudiantes registrados, su estado asi: "<<endl;
    
    cout<<"   Si promedio integral menor a 2.5, estado FUERA"<<endl;
    
    cout<<"3. Mostrar toda la información de los estudiantes en estado FUERA registrados en el sistema"<<endl;
    cout<<"  Si promediointegral entre 2.5 y 2.9, estado PRUEBA"<<endl;
    cout<<"  Si promedio integral mayor o igual a 3.0, estado NORMAL"<<endl;
    
    cout<<"4. Agregar periodos academicos."<<endl;
    
    cout<<"5. Rescribir datos"<<endl;
    
    cout<<"6.salir"<<endl;
    
    cout<<"Opcion: ";cin>>opcion;


  switch(opcion){
 
  case 1:
  	
    fflush(stdin);
    cout<<"verificar si el codigo del estudiante ya existe: ";
    cin.getline(codigo_aux, 13, '\n' );

    si_esta = buscar(codigo_aux);
    
	if(si_esta == 0){ ingresar(); }
 
   getch();
   break;
   
   
  case 2:
 
   asignar_estados();
   
    getch();
    break;
   
  case 3:
 
    mostrar();
 
    getch();
    break;

  case 4:
  	
    fflush(stdin);
    cout<<"Se verifica si el codigo ya se encuentra en el sistema: ";
    cin.getline(codigo_aux, 13, '\n' );

    si_esta = buscar(codigo_aux);
    
	if(si_esta == 0){ periodos(); }
 
 getch();
 break;

  case 5:
  	
  formatear();
 
 getch();
 break;

  default:
 
  cout<<"\n\n El programa ha terminado :D"<<endl;
 
    getch();
    break;
 
  }
  }while(opcion != 6);



   return 0;
}


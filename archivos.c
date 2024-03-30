#include <stdio.h>
#include <stdlib.h>
//EJEMPLO BASCIO DE MANEJO DE ARCHIVOS CON REGISTROS (STRUCT)
//ESCRITO EN C, TENGA EN CUENTA ESTO PARA LA COMPILACIÓN
typedef struct r
    {   char nombre[20];
        int  edad;
    }   registro; //registro es el alias del tipo de dato r
    
    
int main()
{
     char c;
     registro reg;   //declaración de una variable del tipo struct A PARTIR DEL ALIAS DEL TIPO DE DATO
     int tamanoreg = sizeof (reg);	//calculo del tamaño de un registro
     FILE *pf;						//pf es un puntero a archivo
     int fin = 0;

//se intenta abrir un archivo existente, sino existe se crea y luego se cierra
   if (fopen("datos.dat", "r")== 0)		
     {    
	 	pf = fopen("datos.dat","w");
        fclose(pf);
     }

//si el usuario desea puede borrar el contenido del archivo   
   printf( "\nDesea inicializar el archivo? ");
   fflush(stdin);
   if (tolower (c = getchar()) == 's')
      {
          pf = fopen("datos.dat","w");
          fclose(pf);
      }
          
//se abre el archivo para introducirle datos (registros)          
      printf( "\nDesea ingresar datos? ");
	  fflush(stdin);
      if (tolower (c = getchar()) == 's')
        {     
          pf = fopen("datos.dat","a+");     
          while (!fin)
            {
           	   	fflush(stdin);
         		printf("\nIndique nombre:  ");
             	fflush(stdin);
             	gets(reg.nombre);
             	printf("\nIndique edad:    ");
				scanf("%d",&reg.edad);
             	fwrite(&reg, tamanoreg, 1, pf);
             	
            	printf( "\nDesea agregar otro? ");
            	if (tolower (c = getch()) != 's')
                	fin = 1;
            }   
          fclose(pf);
         }
         
// se muestra el contenido del archivo         
         printf("\nMostrar el archivo\n ");
         pf = fopen("datos.dat","r");
         fread(&reg, tamanoreg, 1, pf);
         while (! feof (pf))
            {
                  printf("\n\nNombre = %s", reg.nombre);
                  printf("\nEdad     = %d", reg.edad);
                  fread(&reg, tamanoreg, 1, pf);
            }
         fclose(pf);
     	getchar();
 }
 
 //INDAGUE, COMO FUNCIONA Y CUALES SON LOS PARAMETROS DE:
 //FOPEN(), FCLOSE(), FREAD(),FWRITE(), FSEEK(), FEOF()

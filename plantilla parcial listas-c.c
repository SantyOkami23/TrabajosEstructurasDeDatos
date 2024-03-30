#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct nodo {
	char id[12];
    char name[30];
    char celphone[11];
    char phone[11];
    int age;
    struct nodo *sig;
};

struct nodo *first=NULL;

void print()
{
    struct nodo *temp = first;
    printf("Contenido de la lista...\n");
    while (temp != NULL)
    {
    	printf("No ID: %s \n",temp->id);
        printf("Nombre: %s \n",temp->name);
        printf("Celular %s \n",temp->celphone);
        printf("Fijo: %s \n",temp->phone);
        printf("Edad: %i \n\n",temp->age);
        temp = temp->sig;
    }
    printf("\n\n");
}

int main()
{
    int option;
    
    do
    {
    system("cls");
    printf("||                            Menu                                 ||\n");
    printf("||                                                                 ||\n");
    printf("|| 1. Ingresar persona                                             ||\n");
    printf("|| 2. Imprimir todos los datos                                     ||\n");
    printf("|| 3. Salir                                                        ||\n");
    printf("||                                                                 ||\n");
	printf("\n\n             Inserte la opcion que desea ejecutar --->  ");
	fflush(stdin);
    scanf("%i",&option);
	system("cls");

    switch(option)
    {
    	case 1:

    		break;
    	case 2:
    		print();
    		break;
    	case 3:
			printf("El programa ha terminado\n");
    		printf("Hasta luego...\n\n");
    		break;
    	default:
    		printf("\nEl valor ingresado no esta entre las opciones dadas\n");
    		break;
	}
	system("pause");
    }
	while(option!=3);
    return 0;
}

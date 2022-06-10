#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
    int option = 0;
    int flag=0;//si el usuario carga o no el archivo, cambiar criterio de guardado
    int flagT;
    int flagB;
    int dataLoad=0;

    setbuf(stdout, NULL);

    LinkedList* listaPasajeros = ll_newLinkedList();
    do{
    	GetOption:
    	//print
		system("@cls||clear");
		 printf("\n");
		 printf("****************************************************************\n");
		 printf("\n");
		 printf("1: Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)\n");
		 printf("2: Cargar los datos de los pasajeros desde el archivo data.csv (modo binario)\n");
		 printf("3: Alta de pasajero\n");
		 printf("4: Modificar datos de pasajero\n");
		 printf("5: Baja de pasajero\n");
		 printf("6: Listar pasajeros\n");
		 printf("7: Ordenar pasajeros\n");
		 printf("8: Guardar los datos de los pasajeros en el archivo data.csv (modo texto)\n");
		 printf("9: Guardar los datos de los pasajeros en el archivo data.csv (modo binario)\n");
		 printf("10:Salir\n");
		 printf("\n");
		 printf("****************************************************************\n");
		 printf("\n");

		 Utn_getInt("",0,11,&option);

    	//getOption
    	//
        switch(option)
        {
            case 1:
                flag=controller_loadFromText("data.csv",listaPasajeros);
                flagT=flag;
                flagB=flag;
                dataLoad=flag;
                break;
            case 2:
            	flag=controller_loadFromBinary("data.bin",listaPasajeros);
            	flagT=flag;
            	flagB=flag;
            	dataLoad=flag;
            	break;
            case 3:
            	dataLoad=controller_addPassenger(listaPasajeros);
            	break;
            case 4:
            	if(dataLoad)
            	{
            		controller_editPassenger(listaPasajeros);
            	}
            	else
            	{
            		printf("Ingrese algun dato antes de continuar\n");
            	}
            	break;
            case 5:
            	if(dataLoad)
            	{
            		controller_removePassenger(listaPasajeros);
            	}
            	else
            	{
            	    printf("Ingrese algun dato antes de continuar\n");
            	}
            	break;
            case 6:
            	if(dataLoad)
            	{
            		controller_ListPassenger(listaPasajeros);
            	}
            	else
            	{
            	    printf("Ingrese algun dato antes de continuar\n");
            	}
            	break;
            case 7:
            	break;
            case 8:
            	flagT=controller_saveAsText("data.csv",listaPasajeros,flag);
            	break;
            case 9:
            	flagB=controller_saveAsBinary("data.bin",listaPasajeros,flag);
            	break;
            case 10:
            	option=0;
            	GetExit:
                system("@cls||clear");
                printf("Desea salir del programa?\nSe perderan los cambios que no hayan sido guardados\n");
                printf("\n");
                printf("1: Si\n");
                printf("2: No\n");
                Utn_getInt("",0,3,&option);
                switch(option)
                {
                case 1:
                	option=10;
                	freeAll(listaPasajeros);
                	break;
                case 2:
                	goto GetOption;
                	break;
                default:
                	goto GetExit;
                	break;
            	}
            	break;
            default:
            	break;
        }
        if(flagB==0 && flagT==0)
        {
        	flag=0;
        }
    }while(option != 10);
    return 0;
}


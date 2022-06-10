#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno=0;
	char auxId[8];
	char auxNombre[50];
	char auxApellido[50];
	char auxPrecio[20];
	char auxFlycode[10];
	char auxStatus[14];
	char auxType[16];
	Passenger* new;


	if (pFile!=NULL)
		{

			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxApellido,auxPrecio,auxFlycode,auxType,auxStatus);

			while(!feof(pFile))
			{
				fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxApellido,auxPrecio,auxFlycode,auxType,auxStatus);

				new=Passenger_newParametros(auxId,auxNombre,auxApellido,auxPrecio,auxFlycode,auxType,auxStatus);

				if(new!=NULL)
				{
					retorno=ll_add(pArrayListPassenger,new);
				}
				else{
					printf("\n");
					printf("Error, borre la lista y vuelva a intentarlo\n");
					break;
				}
			}
			setbuf(stdout, NULL);
		}
		else
		{
			printf("Error al abrir el archivo\n");
		}

    return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno=0;
	Passenger aux;
	Passenger* new;
	   if(pFile!=NULL)
		   {
			   while(!feof(pFile))
			   {
				   fread(&aux,sizeof(Passenger),1,pFile);

				   Passenger_printPassenger(&aux);

				  /* new=Passenger_NonStrNewParametros(aux);
				   if(new!=NULL)
				   {
					   retorno=ll_add(pArrayListPassenger,new);
				   }*/

			   }
		   }
	   else
	   {
		   printf("Error en Lectura en Binario\n");
	   }

    return retorno;
}

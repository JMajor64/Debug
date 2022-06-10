#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "parser.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	FILE * pFile;

	pFile = fopen (path, "r");
	parser_PassengerFromText(pFile,pArrayListPassenger);

	fclose(pFile);

    return 1;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE * pFile;

	pFile=fopen(path,"rb");
	parser_PassengerFromBinary(pFile,pArrayListPassenger);
	fclose(pFile);
    return 1;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int retorno=0;
	Passenger* new;
	Passenger aux;

	aux = Passenger_getFromUser();
	Passenger_setId(&aux,calculate_NewId(pArrayListPassenger));
	new=Passenger_NonStrNewParametros(aux);
	if(new!=NULL)
	{
		ll_add(pArrayListPassenger,new);
		retorno=1;
	}
    return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	Passenger* aux;
	int len;
	int idS;
	int valid=0;
	len=ll_len(pArrayListPassenger);

	while(valid==0)
	{
		valid=Utn_getInt("ingrese el Id del pasajero",0,len+1,&idS);
		if(valid==0)
		{
			printf("\n");
			printf("Error, ingrese un Id valido\n");
			printf("\n");
		}
	}

	aux=ll_get(pArrayListPassenger,idS-1);

	if(aux!=NULL)
	{
		Passenger_Modify(aux);
	}
	else{
		printf("Error, pasajero no encontrado\n");
		getch();
	}


    return 1;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	Passenger* aux;
	int len;
	int idS;
	int auxIndex;
	int valid=0;
	len=ll_len(pArrayListPassenger);

	while(valid==0)
	{
		valid=Utn_getInt("ingrese el Id del pasajero",0,len+1,&idS);
		if(valid==0)
		{
			printf("\n");
			printf("Error, ingrese un Id valido\n");
			printf("\n");
		}
	}
	aux=ll_get(pArrayListPassenger,idS-1);
	if(aux!=NULL)
	{
		auxIndex=ll_indexOf(pArrayListPassenger,aux);
		valid=Passenger_delete(aux);
		
		switch(valid)
		{
			case 1:
				ll_pop(pArrayListPassenger,auxIndex);
			break;

			case 2:
			break;
		}
	}
	
    return 1;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int len;
	int i;
	Passenger* aux;
	len=ll_len(pArrayListPassenger);
	system("@cls||clear");
	printf("Id\tNombre \t\t  Apellido \t  Precio \t  Flycode \t Tipo de pasajero \t Estado\n");
	for(i=0;i<len;i++)
	{
		aux=ll_get(pArrayListPassenger,i);
		if(aux!=NULL)
		{
			Passenger_printPassenger(aux);
		}
		else{
			printf("ERROR\n");
			getch();
		}
	}
	getch();
    return 1;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger,int flag)
{
	int retorno=0;
	FILE* pFile;
	if(flag==1)
	{
		pFile=fopen(path,"w");
	}else{
		pFile=fopen(path,"a");
	}if(pFile!=NULL)
	{
		int len;
				len=ll_len(pArrayListPassenger);
				if(len!=-1)
				{
					Passenger* aux;
					int auxId;
					char name[50];
					char lstname[50];
					float auxprice;
					char flycode[4];
					char auxTypeStr[16];
					char status[16];

					if(flag==1)
					{
						fprintf(pFile,"Id, Name, Lastname, Price, Flycode, typePassenger, StatusFlyght");
					}
					int i;
					for(i=0;i<len;i++)
					{
						aux=ll_get(pArrayListPassenger,i);

						Passenger_getId(aux,&auxId);
						Passenger_getNombre(aux,name);
						Passenger_getApellido(aux,lstname);
						Passenger_getCodigoVuelo(aux,flycode);
						GetTypeStr(aux,auxTypeStr);
						Passenger_getPrecio(aux,&auxprice);
						Passenger_getStatus(aux,status);

						fprintf(pFile,"%d,%s,%s,%.2f,%s,%s,%s",auxId,name,lstname,auxprice,flycode,auxTypeStr,status);
					}

				}

	}
	fclose(pFile);
    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger,int flag)
{
	int retorno=0;
	FILE* pFile;
	if(flag==1)
	{
		pFile=fopen(path,"w");
		printf("open W\n");
	}else{
		pFile=fopen(path,"a");
		printf("open A\n");
	}

	if(pFile!=NULL)
	{
		int len;
		len=ll_len(pArrayListPassenger);
		if(len>0)
		{
			Passenger* aux;

			int i;
			for(i=0;i<len;i++)
			{
				aux=ll_get(pArrayListPassenger,i);
				if(aux!=NULL)
				{
					Passenger_printPassenger(aux);
					fwrite(aux,sizeof(Passenger),1,pFile);
				}

			}

		}

	}
	else
	{
		printf("Error al guardar el archivo\n");
	}
	fclose(pFile);
    return retorno;
}



int calculate_NewId(LinkedList* pArrayListPassenger)
{
	int len;
	len=ll_len(pArrayListPassenger);
	if(len==-1)
	{
		len=0;
	}
	len++;
	return len;
}

int calulate_ForcedId(char* path)
{
	int retorno=-1;
	//abrir modo bin, pisar la lista en aux y calcular el ultimo id
	//Uso: salvar en texto/binario datos nuevos sin pisar los previos

	Passenger aux;
	FILE* pFile;

	pFile=fopen(path,"rb");
	if(pFile!=NULL)
	{
		while(!feof(pFile))
			{
				fread(&aux,sizeof(Passenger),1,pFile);
			}
		retorno=aux.id;
	}

	return retorno;
}

void freeAll(LinkedList* pArrayListPassenger)
{
	int len;
	int i;
	Passenger* aux;

	len=ll_len(pArrayListPassenger);
	for(i=0;i<len;i++)
	{
		aux=ll_get(pArrayListPassenger,i);
		if(aux!=NULL)
		{
			Passenger_free(aux);
		}
	}
	ll_clear(pArrayListPassenger);
	ll_deleteLinkedList(pArrayListPassenger);
}

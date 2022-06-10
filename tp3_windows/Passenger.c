#include "Passenger.h"
/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */
#define TAM 3
//print


Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* PrecioStr,char* flyCodeStr,char* tipoPasajeroStr,char* status)
{
	Passenger aux;
	Passenger* new;
		//convertir datos;
		aux.id=atoi(idStr);
		aux.precio=atof(PrecioStr);
		aux.tipoPasajero=TypePassenger(tipoPasajeroStr);
		strcpy(aux.nombre,nombreStr);
		strcpy(aux.apellido,apellidoStr);
		strcpy(aux.codigoVuelo,flyCodeStr);
		strcpy(aux.status,status);

		//introducir datos
		new=Passenger_NonStrNewParametros(aux);

	return new;
}

Passenger* Passenger_NonStrNewParametros(Passenger aux)
{
	Passenger* new;
	new=Passenger_new();
	if(new!=NULL)
	{
		Passenger_setId(new,aux.id);
		Passenger_setNombre(new,aux.nombre);
		Passenger_setApellido(new,aux.apellido);
		Passenger_setCodigoVuelo(new,aux.codigoVuelo);
		Passenger_setTipoPasajero(new,aux.tipoPasajero);
		Passenger_setPrecio(new,aux.precio);
		Passenger_setStatus(new,aux.status);
	}
	else{
		printf("Error, intente mas tarde\n");
	}
	return new;
}

int TypePassenger(char *typeStr)
{
	int typeInt=0;
	if(strcmp(typeStr,"FirstClass") == 0)
	{
		typeInt=1;
	}else
	{
		if(strcmp(typeStr,"ExecutiveClass") == 0)
		{
			typeInt=2;
		}
		else
		{
			if(strcmp(typeStr,"EconomyClass") == 0)
			{
				typeInt=3;
			}
		}
	}
	return typeInt;
}

void printType(int TypeInt)
{
	switch(TypeInt)
	{
	case 1:
		printf("Tipo: FirstClass\n");
		break;
	case 2:
		printf("Tipo: ExecutiveClass\n");
		break;
	case 3:
		printf("Tipo: EconomyClass\n");
		break;
	default:
		printf("Error, Tipo invalido\n");
		break;
	}
}

Passenger Passenger_getFromUser()
{
	Passenger aux;
	int auxStatus;
	int validate=0;


	while(validate==0){
		validate=Utn_getString("ingrese el Nombre",aux.nombre,sizeof(aux.nombre));
	}
	validate=0;

	while(validate==0){
		validate=Utn_getString("ingrese el Apellido",aux.apellido,sizeof(aux.apellido));
	}
	validate=0;

	while(validate==0){
		validate=Utn_getString("ingrese el codigo de vuelo (8 caracteres)",aux.codigoVuelo,sizeof(aux.codigoVuelo));
	}
	validate=0;

	while(validate==0){
	printf("Ingrese el tipo de pasajero: \n");
	printf("1:");
	printType(1);
	printf("2:");
	printType(2);
	printf("3:");
	printType(3);
	validate=Utn_getInt("",0,4,&aux.tipoPasajero);
	}
	validate=0;

	while(validate==0){
		validate=Utn_getFloat("ingrese el precio",0,9999999,&aux.precio);
	}
	validate=0;

	while(validate==0){
		validate=Utn_getInt("ingrese el Estado",0,3,&auxStatus);
		Passenger_GetStatusStr(auxStatus,aux.status);
	}

	return aux;
}

Passenger* Passenger_new()
{
	Passenger* new=(Passenger*) malloc(sizeof(Passenger));

	return new;
}

//SETERS

int Passenger_setId(Passenger* this,int id)
{
	int retorno=0;

	if(this!=NULL && id>0)
	{
		(*this).id=id;
		retorno=1;
	}

	return retorno;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno=0;
	if(this!=NULL && strlen(nombre)<sizeof((*this).nombre))
	{
			strcpy((*this).nombre,nombre);
			retorno=1;
	}

	return retorno;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno=0;
	if(this!=NULL && strlen(apellido)<sizeof((*this).apellido))
	{
			strcpy((*this).apellido,apellido);
			retorno=1;
	}

	return retorno;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno=0;

	if(this!=NULL && strlen(codigoVuelo)<sizeof((*this).codigoVuelo))
	{
			strcpy((*this).codigoVuelo,codigoVuelo);
			retorno=1;
	}

	return retorno;
}

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int retorno=0;

	if(this!=NULL && tipoPasajero < 4)
	{
		(*this).tipoPasajero=tipoPasajero;
		retorno=1;
	}

	return retorno;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int retorno=0;

	if(this!=NULL && precio > 1000)
	{
		(*this).precio=precio;
		retorno=1;
	}

	return retorno;
}

int Passenger_setStatus(Passenger* this,char* Status)
{
	int retorno=0;

	if(this!=NULL && strlen(Status)<sizeof((*this).status))
	{
			strcpy((*this).status,Status);
			retorno=1;
	}

	return retorno;
}

int Passenger_setIntType(Passenger* this,int type)
{
	int retorno=0;

	if(this!=NULL && type>0)
	{
		(*this).tipoPasajero=type;
		retorno=1;
	}

	return retorno;
}

//GETERS

int Passenger_getId(Passenger* this,int* id)
{
	int retorno=0;
	if(this!=NULL && id!=NULL)
	{
		*id=(*this).id;
		retorno=1;
	}
	return retorno;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno=0;
	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre,(*this).nombre);
		retorno=1;
	}
	return retorno;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno=0;
	if(this!=NULL && apellido!=NULL)
	{
		strcpy(apellido,(*this).apellido);
		retorno=1;
	}
	return retorno;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno=0;
	if(this!=NULL && codigoVuelo!=NULL)
	{
		strcpy(codigoVuelo,(*this).codigoVuelo);
		retorno=1;
	}
	return retorno;
}

int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int retorno=0;
	if(this!=NULL && tipoPasajero!=NULL)
	{
		*tipoPasajero=(*this).tipoPasajero;
		retorno=1;
	}
	return retorno;
}

int Passenger_getPrecio(Passenger* this,float* precio)
{
	int retorno=0;
	if(this!=NULL && precio!=NULL)
	{
		*precio=(*this).precio;
		retorno=1;
	}
	return retorno;
}

int Passenger_getStatus(Passenger* this,char* status)
{
	int retorno=0;
	if(this!=NULL && status!=NULL)
	{
		strcpy(status,(*this).status);
		retorno=1;
	}
	return retorno;
}

void GetTypeStr(Passenger* this,char* Type)
{
	switch(this->tipoPasajero)
	{
	case 1:
		strcpy(Type,"FirstClass");
		break;
	case 2:
		strcpy(Type,"ExecutiveClass");
		break;
	case 3:
		strcpy(Type,"EconomyClass");
		break;
	}
}

void Passenger_printPassenger(Passenger* aux)
{
	char auxType[16];
	GetTypeStr(aux,auxType);
	//printf("%-6d||%-16s %-12s\t||%-7.2f\t||%-6s\t||%-14s\t||%s\n",aux->id,aux->nombre,aux->apellido,aux->precio,aux->codigoVuelo,auxType,aux->status);
	printf("%s\n",aux->apellido);
}

void Passenger_GetStatusStr(int statusInt,char* StatusStr)
{
	switch(statusInt)
	{
	case 1:
		strcpy(StatusStr,"En Horario");
		break;
	case 2:
		strcpy(StatusStr,"Aterrizado");
		break;
	}
}

void Passenger_Modify(Passenger* aux)
{
	int  option;
	int valid;

	//////auxiliares////////
	char auxName[50];
	char auxLstName[50];
	char auxFlycode[10];
	float auxPrice;
	int auxInt;
	char auxStatus[11];
	///////////////////////
	do
	{
		valid=0;
		system("@cls||clear");

		printf("\n");
		printf("Vista previa del Pasajero:\n");
		printf("****************************************************************************\n");
		printf("\n");
		Passenger_printPassenger(aux);
		printf("\n");
		printf("****************************************************************************\n");
		printf("\n");
		printf("Ingrese el campo que desea modificar:\n");
		printf("1: Nombre\n");
		printf("2: Apellido\n");
		printf("3: Codigo de vuelo\n");
		printf("4: Precio\n");
		printf("5: Tipo de pasajero\n");
		printf("6: Estado de vuelo\n");
		printf("7: Salir\n");

		Utn_getInt("",0,8,&option);

		system("@cls||clear");

		switch(option)
		{
			case 1:

				while(valid==0)
				{
					valid=Utn_getString("Ingrese el nombre",auxName,sizeof(aux->nombre));
				}
				Passenger_setNombre(aux,auxName);
			break;
			case 2:

				while(valid==0)
				{
					valid=Utn_getString("Ingrese el apellido",auxLstName,sizeof(aux->apellido));
				}
				Passenger_setApellido(aux,auxLstName);
			break;
			case 3:
				while(valid==0)
				{
					valid = Utn_getString("Ingrese codigo de vuelo",auxFlycode,sizeof(aux->codigoVuelo));
				}
				Passenger_setCodigoVuelo(aux,auxFlycode);
			break;
			case 4:
				while(valid==0)
				{
					valid = Utn_getFloat("Ingrese el precio",0,9999999,&auxPrice);
				}
				Passenger_setPrecio(aux,auxPrice);
			break;
			case 5:

				while(valid==0)
				{
					printf("Ingrese el Tipo de pasajero\n");
					printf("1:");
					printType(1);
					printf("2:");
					printType(2);
					printf("3:");
					printType(3);
					valid = Utn_getInt(" ",0,4,&auxInt);
				}
				Passenger_setIntType(aux,auxInt);
				break;
			case 6:

				while(valid==0)
				{
					printf("Ingrese el Estado\n");
					printf("1: En Horario\n");
					printf("2: Aterrizado\n");
					valid = Utn_getInt("",0,3,&auxInt);
				}
				Passenger_GetStatusStr(auxInt,auxStatus);
				Passenger_setStatus(aux,auxStatus);

				break;
		}
	}while(option!=7);
			
}



int Passenger_delete(Passenger* delete)
{
	int  option;
	GetOption:
	system("@cls||clear");

	printf("\n");
	printf("Vista previa del Pasajero:\n");
	printf("****************************************************************************\n");
	printf("\n");
	Passenger_printPassenger(delete);
	printf("\n");
	printf("****************************************************************************\n");
	printf("\n");
	printf("Desea eliminar este pasajero?\n");
	printf("1: Si\n");
	printf("2: No\n");

	Utn_getInt("",0,3,&option);

	switch(option)
	{
		case 1:
			Passenger_free(delete);
			printf("Pasajero eliminado correctamente\n");
		break;
		case 2:
			printf("Pasajero no eliminado\n");
		break;
		default:
		goto GetOption;
		break;
	}

	return option;
}
 
 void Passenger_free(Passenger* delete)
 {
	free(delete);
 }

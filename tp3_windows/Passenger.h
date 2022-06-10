#include "utnlib.h"
#include <stdlib.h>
#include <stdio.h>
/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[10];
	int tipoPasajero;
	char status[16];

}Passenger;



Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* PrecioStr,char* flyCodeStr,char* tipoPasajeroStr,char* status);
int Passenger_delete(Passenger* delete);
void Passenger_free(Passenger* delete);

int TypePassenger(char *typeStr);
void printType(int TypeInt);

Passenger* Passenger_NonStrNewParametros(Passenger aux);
Passenger Passenger_getFromUser();

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setStatus(Passenger* this,char* Status);
int Passenger_getStatus(Passenger* this,char* status);

void GetTypeStr(Passenger* this,char* Type);

void Passenger_printPassenger(Passenger* aux);

void Passenger_Modify(Passenger* aux);

void Passenger_GetStatusStr(int statusInt,char* StatusStr);
int Passenger_setIntType(Passenger* this,int type);

#endif /* PASSENGER_H_ */

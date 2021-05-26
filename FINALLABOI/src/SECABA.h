/*
 * Concursantes.h
 *
 *  Created on: 21 may. 2021
 *      Author: ian
 */

#ifndef CONCURSANTES_H_
#define CONCURSANTES_H_
#ifndef eEmergencia_H_INCLUDED
#define eEmergencia_H_INCLUDED
#include "Funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM 100
typedef struct
{//char* idStr,char* DescripcionStr,char* dniStr,char* fechapresentacionStr,char*temapresentacionStr,char*puntaje
    int id;
    char descripcion[50];
    char domicilio[25];
    int recursos;
    int rubroId;
}eEmergencia;

eEmergencia* eEmergencia_new();
eEmergencia* eEmergencia_newParametros(char* ,char* ,char* ,char* ,char*);
void eEmergencia_delete();

int eEmergencia_setId(eEmergencia* this,int id); //(x)
int eEmergencia_getId(eEmergencia* this,int* id);//(x)

int eEmergencia_setDescripcion(eEmergencia* this,char* Descripcion); //(x)
int eEmergencia_getDescripcion(eEmergencia* this,char* Descripcion); //(x?)

int eEmergencia_setDomicilio(eEmergencia* this,char* Domicilio);
int eEmergencia_getDomicilio(eEmergencia* this,char* Domicilio);

int eEmergencia_getRecursos(eEmergencia* this,int* Recursos);
int eEmergencia_setRecursos(eEmergencia* this,int Recursos);

int eEmergencia_getRubroId(eEmergencia* this,int* rb);
int eEmergencia_setRubroId(eEmergencia* this,int rb);

int eEmergencia_CompareByName(eEmergencia* e1, eEmergencia* e2); //(x)
int eEmergencia_CompareById(eEmergencia* e1, eEmergencia* e2);   //(x)
int eEmergencia_CompareBySalary(eEmergencia* e1, eEmergencia* e2);//(x)
int eEmergencia_CompareByWorkingHours(eEmergencia* e1, eEmergencia* e2);//(x)

int ValidarInt(char[]); //(x)
int ValidarString(char []); //(x)

int criterioJurado(void*);

int MenosDe10(void* elemento);
void MostrarMayorPuntos(LinkedList* this);

int MayorNumeroLL(void* elemento,void* criterio);
int BuscarTresMayores(LinkedList* LaLista,int Tresmayores,int bandera);
int BuscarMayorNumero(LinkedList* LaLista);

int sorteador(void* elemento,void* elemento2);

int MayorNumeroLL2(void* elemento,void* criterio);
#endif // eEmergencia_H_INCLUDED




#endif /* CONCURSANTES_H_ */

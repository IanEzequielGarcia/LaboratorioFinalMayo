/*
 * Controller.h
 *
 *  Created on: 21 may. 2021
 *      Author: ian
 */
#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"
#include "SECABA.h"
#include "parser.h"
int controller_loadFromText(char* path , LinkedList* pArrayListeEmergencia);
int controller_loadFromBinary(char* path , LinkedList* pArrayListeEmergencia);
int controller_addeEmergencia(LinkedList* pArrayListeEmergencia);
int controller_editeEmergencia(LinkedList* pArrayListeEmergencia);
int controller_removeeEmergencia(LinkedList* pArrayListeEmergencia);
int controller_ListeEmergencia(LinkedList* pArrayListeEmergencia);
int controller_sorteEmergencia(LinkedList* pArrayListeEmergencia);
int controller_saveAsText(char* path , LinkedList* pArrayListeEmergencia);
int controller_saveAsBinary(char* path , LinkedList* pArrayListeEmergencia);


int controller_saveElementoAsText(char* path, eEmergencia* empleado);
void SaveEmergencia(void* voidIngresado);
void LlMenorQue10(LinkedList* this);

int BuscarMayorNumero(LinkedList* LaLista);
int TresMayores(LinkedList* LaLista);

void SaveeEmergenciaLL(LinkedList* this);

int OrderByDescripcion(eEmergencia* emergenciaUno,eEmergencia* emergenciaDos);

#endif /* CONTROLLER_H_ */

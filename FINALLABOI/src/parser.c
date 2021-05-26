/*
 * parser.c
 *
 *  Created on: 21 may. 2021
 *      Author: ian
 */
#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
#include "SECABA.h"
#include "parser.h"

int parser_eEmergenciaFromText(FILE* pFile, LinkedList* pArrayListeEmergencia)
{
    int cant;
    char id[12];
    char descripcion[32];
    char domicilio[32];
    char recursos[12];
    char rubroId[12];
    int sePudo=0;
    eEmergencia* eEmergenciaAux;
    do
    {
        cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,descripcion,domicilio,recursos,rubroId);
        if(cant==5)
        {
           if(!(eEmergenciaAux=eEmergencia_new()))
            {
                printf("No hay espacio!");
                break;
            }
            else
            {//(char* idStr,char* anioStr,char* descripcionStr,char* dniStr,char* fechapresentacionStr,char*temapresentacion,char*puntajeStr)
                /*for(i=7;i<sizeof(dni);i++)
                {
                    dni[i]='\0';
                }*/
                eEmergenciaAux=eEmergencia_newParametros(id,descripcion,domicilio,recursos,rubroId);
                if(eEmergenciaAux!=NULL)
                {
                    ll_add(pArrayListeEmergencia,eEmergenciaAux);
                    sePudo=1;
                }

            }
        }
    }while(!feof(pFile));
    fclose(pFile);
    return sePudo;

}

int parser_eEmergenciaFromBinary(FILE* pFile, LinkedList* pArrayListeEmergencia)
{
    int cant;
    char id[10];
    char descripcion[50];
    char domicilio[20];
    char recursos[25];
    char rubroId[25];
    int sePudo=0;
    eEmergencia* eEmergenciaAux;
    do
    {
        cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,descripcion,domicilio,recursos,rubroId);
        if(cant==5)
        {
           if(!(eEmergenciaAux=eEmergencia_new()))
            {
                printf("No hay espacio!");
                break;
            }
            else
            {//(char* idStr,char* anioStr,char* descripcionStr,char* dniStr,char* fechapresentacionStr,char*temapresentacion,char*puntajeStr)
                /*for(i=7;i<sizeof(dni);i++)
                {
                    dni[i]='\0';
                }*/
                eEmergenciaAux=eEmergencia_newParametros(id,descripcion,domicilio,recursos,rubroId);
                ll_add(pArrayListeEmergencia,eEmergenciaAux);
                sePudo=1;
            }
        }
    }while(!feof(pFile));
    fclose(pFile);
    return sePudo;

}



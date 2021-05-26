/*
 * Controller.c
 *
 *  Created on: 21 may. 2021
 *      Author: ian
 */
#include "Controller.h"

int controller_loadFromText(char* path, LinkedList* pArrayListeEmergencia)
{
    int sePudo=0;
    FILE* pArchivo;
    pArchivo=fopen(path,"r");

    if(pArchivo!=NULL)
    {
        if(parser_eEmergenciaFromText(pArchivo, pArrayListeEmergencia))
        {
           sePudo=1;
        }
    }


    return sePudo;
}
int controller_loadFromBinary(char* path, LinkedList* pArrayListeEmergencia)
{
    int sePudo=0;
    FILE* pArchivo;
    pArchivo=fopen(path,"rb");
    if(pArchivo!=NULL)
    {
        if(parser_eEmergenciaFromBinary(pArchivo, pArrayListeEmergencia))
        {
        	sePudo=1;
        }
    }

    return sePudo;
}

int controller_saveElementoAsText(char* path, eEmergencia* corredor)
{
    FILE* pAux;
    int devolver=0;
    pAux=fopen(path,"w");
    char nombre[64];
    int id;
    int puntaje;
    int tiempo;
    //int puntajeSR;
    //int promPuntaje;
    char tipo[20];

    if(pAux!=NULL)
    {
    	eEmergencia_getId(corredor,&id);
    	eEmergencia_getDescripcion(corredor,nombre);
    	eEmergencia_getDomicilio(corredor,tipo);
    	eEmergencia_getRecursos(corredor,&puntaje);
    	eEmergencia_getRubroId(corredor,&tiempo);


    //eEmergencia_getPromedioPuntaje(corredor,&promPuntaje);
        if(!feof(pAux))
        {
            if(corredor!=NULL)
            {
                fprintf(pAux,"%d,%s,%s,%d,%d\n",id,nombre,tipo,puntaje,tiempo);
                devolver=1;
            }
        }
    }
    fclose(pAux);
    return devolver;
}
int controller_removeeEmergencia(LinkedList* pArrayListeEmergencia)
{
    eEmergencia* aux=NULL;

    int index;
    int id;
    int sePudo=0;

    printf("Quien va a borrar?");
    scanf("%d",&index);
    index--;//hacerlo con getters
    id=index;
    aux=(eEmergencia*)ll_get(pArrayListeEmergencia,index);
    if(eEmergencia_getId(aux,&index))
    {
        ll_remove(pArrayListeEmergencia,id);
        ll_len(pArrayListeEmergencia);
        sePudo=1;
    }
    return sePudo;
}
int controller_ListeEmergencia(LinkedList* pArrayListeEmergencia)
{
    int len=0;
    int sePudo=0;

    eEmergencia* corredor=NULL;
    len=ll_len(pArrayListeEmergencia);

    char nombre[64];
    char tipo[64];
    int id;
    int puntaje;
    int tiempo;
    for(int i=0;i<len;i++)
    {
        corredor = (eEmergencia*) ll_get(pArrayListeEmergencia,i);

    	eEmergencia_getId(corredor,&id);
    	eEmergencia_getDescripcion(corredor,nombre);
    	eEmergencia_getDomicilio(corredor,tipo);
    	eEmergencia_getRecursos(corredor,&puntaje);
    	eEmergencia_getRubroId(corredor,&tiempo);

        printf("(%6d) %20s %20d %30s,%10d\n",id,nombre,puntaje,tipo,tiempo);
    }
    printf("\n");
    sePudo=1;

    return sePudo;
}

void SaveEmergencia(void* voidIngresado)
{
    eEmergencia* auxcorredor;
    auxcorredor=voidIngresado;
    int auxInt;
    char id[64],aux[32];

    eEmergencia_getId(auxcorredor,&auxInt);
    strcpy(id,"/home/ian/eclipse-workspace/FINALCFEBRERO/eEmergenciaes/");
    sprintf(aux,"%d",auxInt);
    strcat(id,aux);
    strcat(id,".csv");
    controller_saveElementoAsText(id,auxcorredor);

}
void SaveeEmergenciaLL(LinkedList* this)
{
	for(int i=0;i<ll_len(this);i++)
	{
	    SaveEmergencia(ll_get(this,i));
	}
}

int controller_saveAsText(char* path, LinkedList* pArrayListeEmergencia)
{
    eEmergencia* corredor=NULL;
    FILE* pAux;
    int len;
    int i=0;
    int aux;
    int devolver=0;
    pAux=fopen(path,"w");

    char tipo[35];
    char nombre[64];
    int id;
    int tiempo;
    int promedio;

    if(pAux!=NULL)
    {
        len=ll_len(pArrayListeEmergencia);
        aux=len-1;
        while(!feof(pAux))
        {
            corredor=eEmergencia_new();
            if(aux==i)
            {
            	eEmergencia_getId(corredor,&id);
            	eEmergencia_getDescripcion(corredor,nombre);
            	eEmergencia_getDomicilio(corredor,tipo);
            	eEmergencia_getRecursos(corredor,&promedio);
            	eEmergencia_getRubroId(corredor,&tiempo);
                fprintf(pAux,"%d,%s,%s,%d,%d",id,nombre,tipo,promedio,tiempo);
                //fprintf(pAux,"%d,%s,%d",id,nombre,puntaje);
                devolver=1;
                break;
            }
            else
            {
                corredor=(eEmergencia*) ll_get(pArrayListeEmergencia,i);
                corredor=(eEmergencia*) ll_get(pArrayListeEmergencia,i);
            	eEmergencia_getId(corredor,&id);
            	eEmergencia_getDescripcion(corredor,nombre);
            	eEmergencia_getDomicilio(corredor,tipo);
            	eEmergencia_getRecursos(corredor,&promedio);
            	eEmergencia_getRubroId(corredor,&tiempo);
                fprintf(pAux,"%d,%s,%s,%d,%d\n",id,nombre,tipo,promedio,tiempo);
                i++;
            }
        }
    }
    fclose(pAux);
    return devolver;
}
int BajaRecurso(eEmergencia* this)
{
	int auxInt;
	if(eEmergencia_getRubroId(this,&auxInt)==1)
	{
		auxInt=0;
		if(eEmergencia_getRecursos(this,&auxInt)<=15)
		{
			eEmergencia_setRecursos(this,auxInt-2);
		}
	}else if(eEmergencia_getRubroId(this,&auxInt)==4)
	{
		auxInt=0;
		if(eEmergencia_getRecursos(this,&auxInt)<=20)
		{
			eEmergencia_setRecursos(this,auxInt-1);
		}
	}
	return 0;
}
void MostrarParcial(LinkedList* this)
{
	int auxInt;
    char tipo[35];
    char nombre[64];
    int id;
    int tiempo;
    int promedio;
	eEmergencia* aux;
	for(int i=0;i<ll_len(this);i++)
	{
		aux=ll_get(this,i);
		if(aux!=NULL)
		{
			if(eEmergencia_getRecursos(aux,&auxInt)<=12)
			{
	        	eEmergencia_getId(aux,&id);
	        	eEmergencia_getDescripcion(aux,nombre);
	        	eEmergencia_getDomicilio(aux,tipo);
	        	eEmergencia_getRecursos(aux,&promedio);
	        	eEmergencia_getRubroId(aux,&tiempo);
	            printf("(%6d) %20s %20d %30s,%10d\n",id,nombre,tipo,promedio,tiempo);

			}
			if(eEmergencia_getRubroId(this,&auxInt)==4)
			{
	        	eEmergencia_getId(aux,&id);
	        	eEmergencia_getDescripcion(aux,nombre);
	        	eEmergencia_getDomicilio(aux,tipo);
	        	eEmergencia_getRecursos(aux,&promedio);
	        	eEmergencia_getRubroId(aux,&tiempo);
	            printf("(%6d) %20s %20d %30s,%10d\n",id,nombre,tipo,promedio,tiempo);
			}
		}

	}
}
void OrdenarListas(LinkedList* this)
{
	ll_sort(this,OrderByDescripcion,0);
}
int OrderByDescripcion(eEmergencia* emergenciaUno,eEmergencia* emergenciaDos)
{
    int auxInt=0;
    if(emergenciaUno!=NULL&&emergenciaDos!=NULL)
    {
    	if(strcmp(emergenciaUno->descripcion,emergenciaDos->descripcion))
    	{
    		auxInt=1;
    	}
    }
    return auxInt;
}
/*int controller_saveAsBinary(char* path, LinkedList* pArrayListeEmergencia)
{
    eEmergencia* corredor=NULL;
    FILE* pAux;
    int len;
    int i=0;
    int aux;
    int devolver=0;
    pAux=fopen(path,"wb");

    char tipo[9];
    char nombre[64];
    int id;
    int tiempo;
    int promedio;

    if(pAux!=NULL)
    {
        len=ll_len(pArrayListeEmergencia);
        aux=len-1;
        while(!feof(pAux))
        {
            corredor=eEmergencia_new();
            if(aux==i)
            {
                corredor=(eEmergencia*) ll_get(pArrayListeEmergencia,i);
            	eEmergencia_getId(corredor,&id);
            	eEmergencia_getDescripcion(corredor,nombre);
            	eEmergencia_getDomicilio(corredor,tipo);
            	eEmergencia_getRecursos(corredor,&puntaje);
            	eEmergencia_getRubroId(corredor,&tiempo);
                fprintf(pAux,"%d,%s,%s,%d,%d",id,nombre,tipo,promedio,tiempo);
                //fprintf(pAux,"%d,%s,%d",id,nombre,puntaje);
                devolver=1;
                break;
            }
            else
            {
                corredor=(eEmergencia*) ll_get(pArrayListeEmergencia,i);
                corredor=(eEmergencia*) ll_get(pArrayListeEmergencia,i);
            	eEmergencia_getId(corredor,&id);
            	eEmergencia_getDescripcion(corredor,nombre);
            	eEmergencia_getDomicilio(corredor,tipo);
            	eEmergencia_getRecursos(corredor,&puntaje);
            	eEmergencia_getRubroId(corredor,&tiempo);
                fprintf(pAux,"%d,%s,%s,%d,%d\n",id,nombre,tipo,promedio,tiempo);
                i++;
            }
        }
    }
    fclose(pAux);
    return devolver;
}
*/

//Punto 7
/*void LlMenorQue10(LinkedList* this)
{
	LinkedList* aux=ll_newLinkedList();
	void* elementoAux=NULL;
	if(aux!=NULL&&this!=NULL)
		for(int i=0;i<ll_len(this);i++)
		{
			elementoAux=ll_get(this,i);
			if(MenosDe10(elementoAux))
			{
				SaveeEmergencia(elementoAux);
			}
		}
}
//PUNTO 8
int BuscarMayorNumero(LinkedList* LaLista)
{
    eEmergencia* corredorAux=eEmergencia_new();
    int puntajePr;
    int criterio=0;
    int retorno=0;
    int len=ll_len(LaLista);
    if(LaLista!=NULL)
    {
        for(int i=0;i<len;i++)
        {
            corredorAux=(eEmergencia*)ll_get(LaLista,i);
            eEmergencia_getPuntaje(corredorAux,&puntajePr);
            if((corredorAux)!=NULL)
            {
                if(puntajePr>=criterio)
                {
                    criterio=puntajePr;
                    retorno = i;
                }
            }
        }
    }
    return retorno;
}
int TresMayores(LinkedList* LaLista)
{
    int retorno=0;
    LinkedList* listAux=(LinkedList*) ll_newLinkedList();
    listAux=LaLista;
    listAux=ll_filter(listAux,BuscarMayorNumero);
    controller_ListeEmergencia(listAux);
    SaveeEmergenciaLL(listAux);
    retorno = 1;
    free(listAux);
    return retorno;

}
*/
//PUNTO 10, TERMINAR
/*int FinalistasTerceraRonda(LinkedList* LaLista)
{
    int retorno=0;
    LinkedList* listAux=(LinkedList*) ll_newLinkedList();
    listAux=LaLista;
    listAux=ll_filter(listAux,BuscarMayorNumero);
    controller_ListeEmergencia(listAux);
    SaveeEmergenciaLL(listAux);
    retorno = 1;
    free(listAux);
    return retorno;

}*/
/*
int controller_addeEmergencia(LinkedList* pArrayListeEmergencia)//hacer funcion
{
    int len,i;
    char nombre[128];
    char anioStr[128];
    char dniStr[128];
    char fechapresentacionStr[128];
    char temaPresentacion[128];
    char horasTrabajadas[64];
    char puntajeStr[64];
    char id[64];
    int sePudo=0;
    eEmergencia* corredor[TAM];
    eEmergencia* aux;

    len=ll_len(pArrayListeEmergencia);
    i=len+1;
    sprintf(id, "%d", i);

    printf("Ingrese fechaNacimiento ");
    scanf("%[^\n]",anioStr);
    fflush(stdin);

    printf("Ingrese nombre ");
    fflush(stdin);
    scanf("%[^\n]",nombre);
    ValidarString(nombre);

    printf("Ingrese dniStr");
    scanf("%s",dniStr);
    ValidarInt(dniStr);

    printf("Ingrese fechapresentacionStr");
    scanf("%s",fechapresentacionStr);
    ValidarInt(fechapresentacionStr);

    printf("Ingrese temapresentacion");
    scanf("%s",temaPresentacion);
    ValidarString(temaPresentacion);

    printf("Ingrese puntajeStr");
    scanf("%s",puntajeStr);
    ValidarInt(puntajeStr);

    aux=eEmergencia_newParametros(id,anioStr,nombre,dniStr,fechapresentacionStr,temaPresentacion,puntajeStr);//(idStr, anioStr,char* nombreStr,char* dniStr,char* fechapresentacionStr,char*temapresentacion,char*puntajeStr)
    corredor[i]=aux;
    ll_add(pArrayListeEmergencia,corredor[i]);
    sePudo=1;
    return sePudo;
}
int controller_editeEmergencia(LinkedList* pArrayListeEmergencia)
{
    eEmergencia* aux=NULL;

    int sePudo=1;
    char auxString[64];
    int index;
    int opcion;
    int auxInt;

    printf("Que indice va a modificar? ");
    scanf("%d",&index);//verificar que existe primero
    index--;
    aux=(eEmergencia*)ll_get(pArrayListeEmergencia,index);
    if(eEmergencia_getId(aux,&index))
    {
        printf("Que quiere modificar?\n1.Nombre\n2.Sueldo\n3.Horas Trabajadas\n4.fechaPresentacion\n5.temapresentacion\n");
        scanf("%d",&opcion);

       	    int id;
			int anioNacimiento;
			char nombre[50];
			char dni[9];
			char fechaPresentacion[30];
			char temapresentacion[50];
			int puntajeRonda;
			int puntajeSegundaRonda;
			int promedioPuntaje;
			int puntajeTerceraRonda;

        switch(opcion)
        {
            case 1:
                printf("Ingrese nombre ");
                fflush(stdin);
                scanf("%[^\n]",auxString);
                ValidarString(auxString);
                eEmergencia_setNombre(aux,auxString);
                break;
            case 2:
                printf("Ingrese anio nacimiento ");
                fflush(stdin);
                scanf("%s",auxString);
                ValidarInt(auxString);
                auxInt=atoi(auxString);
                eEmergencia_setAnio(aux,auxInt);
                break;
            case 3:
                printf("Ingrese dni ");
                fflush(stdin);
                scanf("%s",auxString);
                ValidarInt(auxString);
                auxInt=atoi(auxString);
                eEmergencia_setDni(aux,auxInt);
                break;
            case 4:
                printf("Ingrese fechaPresentacion ");
                fflush(stdin);
                scanf("%s",auxString);
                ValidarString(auxString);
                eEmergencia_setFechaPresentacion(aux,auxString);
                break;
            case 5:
                printf("Ingrese TemaPresentacion ");
                fflush(stdin);
                scanf("%s",auxString);
                ValidarString(auxString);
                eEmergencia_setTemaPresentacion(aux,auxString);
                break;
        }

    }
    else
    {
        sePudo=0;
    }

    return sePudo;
}
*/
/*int controller_sorteEmergencia(LinkedList* pArrayListeEmergencia)
{
    int sePudo=0;//hacerle if a sort
    int opcion;
    printf("De que forma los quiere ordenar?\n1.Nombre(menor a mayor)\n2.id(menor a mayor)\n3.Salario(menor a mayor)\n4.Horas trabajadas(menor a mayor)\n");
    scanf("%d",&opcion);
    switch(opcion)
    {
        case 1:
            if(!(ll_sort(pArrayListeEmergencia,(void*)eEmergencia_CompareByName,1)))//1 menor a mayor 0 mayor a menor
            {
                printf("Ordenados por Nombre\n");
                controller_ListeEmergencia(pArrayListeEmergencia);
                sePudo=1;
            }
            break;
        case 2:

            if(!(ll_sort(pArrayListeEmergencia,(void*)eEmergencia_CompareById,1)))//1 menor a mayor 0 mayor a menor
            {
                printf("Ordenados por id\n");
                controller_ListeEmergencia(pArrayListeEmergencia);
                sePudo=1;
            }
            break;
        case 3:
            if(!(ll_sort(pArrayListeEmergencia,(void*)eEmergencia_CompareBySalary,1)))//1 menor a mayor 0 mayor a menor
            {
                printf("Ordenados por sueldo\n");
                controller_ListeEmergencia(pArrayListeEmergencia);
                sePudo=1;
            }
            break;
        case 4:
            if(!(ll_sort(pArrayListeEmergencia,(void*)eEmergencia_CompareByWorkingHours,1)))//1 menor a mayor 0 mayor a menor
            {
                printf("Ordenados por horas trabajadas\n");
                controller_ListeEmergencia(pArrayListeEmergencia);
                sePudo=1;
            }
            break;
    }
    return sePudo;
}*/



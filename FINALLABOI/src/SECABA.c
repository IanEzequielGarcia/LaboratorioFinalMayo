/*
 * Concursantes.c
 *
 *  Created on: 21 may. 2021
 *      Author: ian
 */
#include <stdlib.h>
#include "SECABA.h"
#include <string.h>
eEmergencia* eEmergencia_new()
{
    eEmergencia* nuevoEmpleado=NULL;
    nuevoEmpleado=(eEmergencia*)malloc(sizeof(eEmergencia));
   return nuevoEmpleado;
}
eEmergencia* eEmergencia_newParametros(char* idStr,char* nombreStr,char* tipoStr,char* promedioStr,char*RubroIdStr)
{
    eEmergencia* EmpleadoAux;
    EmpleadoAux=eEmergencia_new();
    if(EmpleadoAux!=NULL)
    {
        eEmergencia_setId(EmpleadoAux,atoi(idStr));
        eEmergencia_setDescripcion(EmpleadoAux,nombreStr);
        eEmergencia_setDomicilio(EmpleadoAux,tipoStr);
        eEmergencia_setRecursos(EmpleadoAux,atoi(promedioStr));
        eEmergencia_setRubroId(EmpleadoAux,atoi(RubroIdStr));
    }

    return EmpleadoAux;
}
int eEmergencia_getId(eEmergencia* this,int* id)
{
    int getteo=0;
    if(this!=NULL && id!=NULL)
    {
        *id=this->id;
        getteo = 1;
    }
    return getteo;
}

int eEmergencia_setId(eEmergencia* this,int id)
{
    int setteo=0;
    if(this!=NULL && id!=-1)
    {
        this->id=id;
        setteo = 1;
    }
    return setteo;
}
int eEmergencia_setDescripcion(eEmergencia* this,char* descripcion)
{
    int setteo=0;
    if(this!=NULL && *descripcion!='\0')
    {
        strcpy(this->descripcion,descripcion);
        setteo=1;
    }
    return setteo;
}
int eEmergencia_getDescripcion(eEmergencia* this,char* descripcion)
{
    int getteo=0;
    if(this!=NULL && descripcion!=NULL)
    {
        strcpy(descripcion,this->descripcion);
        getteo = 1;
    }
     return getteo;
}
int eEmergencia_setDomicilio(eEmergencia* this,char* domicilio)
{
    int setteo=0;
    if(this!=NULL && *domicilio!='\0')
    {
        strcpy(this->domicilio,domicilio);
        setteo=1;
    }
    return setteo;
}
int eEmergencia_getDomicilio(eEmergencia* this,char* domicilio)
{
    int getteo=0;
    if(this!=NULL && domicilio!=NULL)
    {
        strcpy(domicilio,this->domicilio);
        getteo = 1;
    }
     return getteo;
}
int eEmergencia_getRecursos(eEmergencia* this,int* recursos)
{
    int getteo=0;
    if(this!=NULL && recursos!=NULL)
    {
        *recursos=this->recursos;
        getteo = 1;
    }
    return getteo;
}

int eEmergencia_setRecursos(eEmergencia* this,int recursos)
{
    int setteo=0;
    if(this!=NULL && recursos!=-1)
    {
        this->recursos=recursos;
        setteo = 1;
    }
    return setteo;
}
int eEmergencia_getRubroId(eEmergencia* this,int* rb)
{
    int getteo=0;
    if(this!=NULL && rb!=NULL)
    {
        *rb=this->rubroId;
        getteo = 1;
    }
    return getteo;
}

int eEmergencia_setRubroId(eEmergencia* this,int rb)
{
    int setteo=0;
    if(this!=NULL && rb!=-1)
    {
        this->rubroId=rb;
        setteo = 1;
    }
    return setteo;
}

/*
int criterioJurado(void* elemento)
{
    eEmergencia* empleadoAux;
    empleadoAux= eEmergencia_new();
    int retorno=0;
    int puntajePr;
    int RubroId;
    ;
    if(empleadoAux!=NULL)
    {
        if(elemento!=NULL)
        {
            empleadoAux=elemento;

            eEmergencia_getProm(empleadoAux,&puntajePr);
            RubroId=(puntajePr*1.2);
            eEmergencia_setRubroId(empleadoAux,RubroId);

            elemento=empleadoAux;
            retorno=1;
        }
    }
    return retorno;
}*/
/*int MenosDe10(void* elemento)
{
    eEmergencia* empleadoAux;
    int puntajePrimera;
    int devuelto=0;
    empleadoAux=elemento;
    eEmergencia_getProm(empleadoAux,&puntajePrimera);
    if(10>puntajePrimera)
    {
        devuelto=1;
    }
    return devuelto;
}*/

/*void MostrarMayorPuntos(LinkedList* this)
{
    eEmergencia* auxEmpleado;
    int len=ll_len(this);
    char dni[15];
    for(int i=0;len>i;i++)
    {
        auxEmpleado=ll_get(this, i);
        eEmergencia_getDni(auxEmpleado,dni);
        strcat(dni,".csv");
        controller_saveElementoAsText(dni,auxEmpleado);
        //controller_saveAsText(dni,this);
    }

}*/
/*int eEmergencia_CompareByName(eEmergencia* empleadoUno,eEmergencia* empleadoDos)
{
    return strcmp(empleadoUno->nombre,empleadoDos->nombre);
}
int eEmergencia_CompareById(eEmergencia* empleadoUno,eEmergencia* empleadoDos)
{
    int compare=0;
    if(empleadoUno->id>empleadoDos->id)
    {
        compare=1;
    }
    else                                    //USAR GETTERS Y SETTERS
                                            //NO USAR ->
    {
        if(empleadoUno->id<empleadoDos->id)
        {
            compare=-1;
        }
    }
    return compare;
}
int eEmergencia_CompareBySalary(eEmergencia* empleadoUno,eEmergencia* empleadoDos)
{
    int compare=0;
    if(empleadoUno->sueldo>empleadoDos->sueldo)
    {
        compare=1;
    }
    else                                    //USAR GETTERS Y SETTERS
                                            //NO USAR ->
    {
        if(empleadoUno->sueldo<empleadoDos->sueldo)
        {
            compare=-1;
        }
    }
    return compare;
}
int eEmergencia_CompareByWorkingHours(eEmergencia* empleadoUno,eEmergencia* empleadoDos)
{
    int compare=0;
    if(empleadoUno->horasTrabajadas>empleadoDos->horasTrabajadas)
    {
        compare=1;
    }
    else                                    //USAR GETTERS Y SETTERS
                                            //NO USAR ->
    {
        if(empleadoUno->horasTrabajadas<empleadoDos->horasTrabajadas)
        {
            compare=-1;
        }
    }
    return compare;
}
int ValidarInt(char NumeroIngresado[])
{
    int i;
    int longitud;
    int resultado;
    longitud=strlen(NumeroIngresado);
    for(i=0;i<longitud;i++)
    {
       if(isdigit(NumeroIngresado[i])!=0)
       {
           resultado=1;
       }
       else
       {
           do
           {
            printf("Reingrese numero ingresado\n");
            scanf("%s",NumeroIngresado);
            resultado=ValidarInt(NumeroIngresado);
           }while(resultado!=1);
       }
    }
    return resultado;
}
int ValidarFloat(char NumeroIngresado[])
{
    int i;
    int longitud;
    int resultado;
    longitud=strlen(NumeroIngresado);
    for(i=0;i<longitud;i++)
    {
       if(isdigit(NumeroIngresado[i])!=0||NumeroIngresado[i]=='.')
       {
           resultado=1;
       }
       else
       {
           do
           {
            printf("Reingrese numero ingresado\n");
            scanf("%s",NumeroIngresado);
            resultado=ValidarInt(NumeroIngresado);
           }while(resultado!=1);
       }
    }
    return resultado;
}
int ValidarString(char StringIngresado[])
{
    int i;
    int longitud;
    int resultado;
    longitud=strlen(StringIngresado);
    for(i=0;i<longitud;i++)
    {
       if(isalpha(StringIngresado[i])!=0)
       {
           resultado=1;
       }
       else
       {
            do
            {
                printf("ReIngrese la palabra\n");
                fflush(stdin);
                scanf("%s",StringIngresado);
                resultado=ValidarString(StringIngresado);
            }while(resultado!=1);
       }
    }
    return resultado;
}
*/



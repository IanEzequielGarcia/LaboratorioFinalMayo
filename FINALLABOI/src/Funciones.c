/*
 * LinkedList.c
 *
 *  Created on: 26 may. 2021
 *      Author: ian
 */


/*
 * LinkedList.c
 *
 *  Created on: 21 may. 2021
 *      Author: ian
 */
#include "Funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this = NULL;
    this = (LinkedList*)malloc(sizeof(LinkedList));
    if(this!=NULL)
    {
    	this->size=0;
    	this->pFirstNode=NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
    	returnAux=this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNode=NULL;
	int len=ll_len(this);
	if(this!=NULL && nodeIndex>-1 &&nodeIndex<len)
	{
		pNode=this->pFirstNode;

		for(int i=0;i<nodeIndex;i++)
		{
			pNode=pNode->pNextNode;
		}

	}
	else
	{
		if(nodeIndex==0&&this!=NULL && nodeIndex>-1)
		{
			pNode=this->pFirstNode;
		}
	}
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)//REVISAR ADDNODE
{
	Node* pAuxNode=NULL;
	Node* pAntNode=NULL;
	Node* pSigNode=NULL;//HACER CON GETNODE
    int returnAux = -1;

    int len=ll_len(this);
    if(this!=NULL && nodeIndex>=0 && nodeIndex<=len)
    {
        pAuxNode=(Node*)malloc(sizeof(pAuxNode));
        if(pAuxNode!=NULL)
        {
			pAuxNode->pElement=pElement;
			pAuxNode->pNextNode=NULL;

    		if(nodeIndex==0)
    		{
    			pAuxNode->pNextNode=this->pFirstNode;
    			this->pFirstNode=pAuxNode;
    		}
			else
    		{
    			pAntNode=getNode(this,nodeIndex-1);
    			pAntNode->pNextNode=pAuxNode;
    		}
    		if((getNode(this,nodeIndex+1))!=NULL)
    		{
        		pSigNode=getNode(this,nodeIndex+1);
        		pAuxNode->pNextNode=pSigNode;
    		}
            this->size+=1;
    		returnAux=0;
        }


    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len=ll_len(this);
    if((addNode(this,len,pElement))==0)
		{
    		returnAux=0;
		}
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pAuxNode = NULL;
    pAuxNode=getNode(this, index);
    if(pAuxNode!=NULL)
    {
    	returnAux=pAuxNode->pElement;
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* AuxNode=NULL;
    if((getNode(this, index))!=NULL)
    {
    	AuxNode=getNode(this, index);
        AuxNode->pElement=pElement;
        returnAux=0;
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* OtronodeAux;
    Node* nodeAux;
    nodeAux=getNode(this,index);
    if(nodeAux!=NULL)
    {
    	if(index==0)
    	{
    		this->pFirstNode=nodeAux->pNextNode;
    		free(nodeAux);
    	}
    	else
    	{
    		OtronodeAux=getNode(this,index-1);
    		OtronodeAux->pNextNode=nodeAux->pNextNode;
    		free(nodeAux);
    	}
    	this->size--;
    	returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = 0;
    if(this!=NULL)
    {
        for(int i=0;i<ll_len(this);i++)
        {
        	if((ll_remove(this,i))==-1)
        	{
        		returnAux = -1;
        		break;
        	}
        }
    }else{
    	returnAux = -1;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
    	free(this);
    	returnAux=0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
	void* auxElement;
    int returnAux = -1;
    for(int i=0;i<ll_len(this);i++)
    {
    	auxElement=ll_get(this, i);
    	if(auxElement==pElement)
    	{
    		returnAux = i;
    	}
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        if((ll_len(this))>0)
        {
        	returnAux = 0;
        }else{
        	returnAux = 1;
        }
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL)
    {
    	returnAux=addNode(this,index,pElement);
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    void* elementAux = NULL;

    elementAux=ll_get(this,index);
    returnAux=elementAux;

    ll_remove(this,index);
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL)
    {
    	if((ll_indexOf(this,pElement))!=-1)
    	{
    		returnAux=1;
    	}else{
    		returnAux=0;
    	}
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
	void* pAux;
    int returnAux = -1;
    int len=ll_len(this2);
    if(this!=NULL&&this2!=NULL)
    {
    	if(len==0)
    	{
    		pAux=ll_get(this,0);
    		if((ll_contains(this2,pAux))==0)
			{
				returnAux = 0;
			}else{
				returnAux = 1;
			}
    	}
        for(int i=0;i<len;i++)
        {
        	pAux=ll_get(this,i);
        	if((ll_contains(this2,pAux))==0)
        	{
        		returnAux = 0;
        		break;
        	}
        	else
        	{
        		returnAux = 1;
        	}
        }
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    Node* auxNode;
    void* auxElemento;
    int len=ll_len(this);

    if(this!=NULL)
    {
    	if(from<0||from>len||from>=to||to>len)
    	{
    	}
    	else
    	{
    		cloneArray=ll_newLinkedList();
    		if(cloneArray!=NULL)
    		{
            	for(int i=from;i<to;i++)
            	{
            		auxNode=getNode(this,i);
            		auxElemento=auxNode->pElement;
            		addNode(cloneArray,i,auxElemento);
            	}
    		}
    	}
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
	int len=ll_len(this);
    LinkedList* cloneArray = NULL;
    cloneArray=ll_subList(this,0,len);
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    void* priElemento=NULL;
    void* segElemento=NULL;
    int len=ll_len(this);

    if(this!=NULL&&pFunc!=NULL)
    {
    	for(int i=0;i<len-1;i++)
    	{
    		for(int j=i+1;j<len;j++)
    		{
    			priElemento=ll_get(this,i);
    			segElemento=ll_get(this,j);

    			if(order==1&&pFunc(priElemento,segElemento)==1)
    			{
    				ll_set(this,i,segElemento);
    				ll_set(this,j,priElemento);
    			}
    			else if(order==0&&pFunc(priElemento,segElemento)==-1)
    			{

					ll_set(this,i,segElemento);
					ll_set(this,j,priElemento);
    			}
    			else if(order!=1&&order!=0)
    			{
    				break;
    			}
    			returnAux=0;
    		}
    	}

    }
    return returnAux;

}
int ll_map(LinkedList* this,int (*pFunc)(void*))
{//get elemento y mappea entre el elemento y la funcion y luego pregunta por criteo
    int devuelto=0;
    void* elementoAux;
    int len=ll_len(this);
    if(this!=NULL)
    {
        for(int i=0;i<len;i++)
        {
            elementoAux=ll_get(this,i);
            if((elementoAux)!=NULL)
            {
                devuelto=pFunc(elementoAux);
                ll_set(this,i,elementoAux);
            }
        }
    }
    return devuelto;
}
int ll_count(LinkedList* this, int (*fn)(void* element))
{
    int devuelto=0;
    int len=ll_len(this);
    void* elementoAux;
    if(this!=NULL)
    {
        for(int i=0;i<len;i++)
        {
            elementoAux=ll_get(this,i);
            if((elementoAux)!=NULL)
            {
                if(fn(elementoAux))
                {
                    devuelto++;
                }
            }
        }

    }
    return devuelto;
}
/*HACER CON LAS FUNCIONES DEL OTRO TP, CON UNA AUX LL, CON LA FUNC MAYOR NUMERO Y BORRANDO
 *UNA VEZ ENCONTRADO EL MAYORN, ASI LO PUDO REUSAR 3 VECES, DESPUES BORRAR LL AUX Y
 *GUARDAR EN LA OTRA LL*/
LinkedList* ll_filter(LinkedList* this, int (*fn)(LinkedList*))
{
    LinkedList* NuevaLL;
    NuevaLL=ll_newLinkedList();
    int intAux=-1;


    if(this!=NULL&&NuevaLL!=NULL)
    {
        for(int i=0;i<3;i++)
        {
			intAux=fn(this);
			if(intAux>=0)
			{
				ll_add(NuevaLL,ll_get(this,intAux));

				ll_pop(this,intAux);
				intAux=-1;
			}
       }
    }

    return NuevaLL;
}


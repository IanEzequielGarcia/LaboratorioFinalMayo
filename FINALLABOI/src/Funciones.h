/*
 * LinkedList.h
 *
 *  Created on: 21 may. 2021
 *      Author: ian
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#ifndef _Structs
#define _Structs
struct
{
    void* pElement;                 //puntero al elemento (persona, empleado, etc.)
    struct Node* pNextNode;         //puntero al prox nodo
}typedef Node;

struct
{
    Node* pFirstNode;
    int size;                       //cada vez que agrego o elimino un elemento size++/--
}typedef LinkedList;
#endif
// _Structs
//Publicas
LinkedList* ll_newLinkedList(void);
int ll_len(LinkedList* this);                                       //devuelve el valor del campo int size
int ll_add(LinkedList* this, void* pElement);
void* ll_get(LinkedList* this, int index);
int ll_set(LinkedList* this, int index,void* pElement);
int ll_remove(LinkedList* this,int index);
int ll_clear(LinkedList* this);
int ll_deleteLinkedList(LinkedList* this);
int ll_indexOf(LinkedList* this, void* pElement);
int ll_isEmpty(LinkedList* this);
int ll_push(LinkedList* this, int index, void* pElement);
void* ll_pop(LinkedList* this,int index);                           //elimina un elemento (los enlaces a ese elemento) y devuelve un puntero a ese elemento
int ll_contains(LinkedList* this, void* pElement);
int ll_containsAll(LinkedList* this,LinkedList* this2);
LinkedList* ll_subList(LinkedList* this,int from,int to);
LinkedList* ll_clone(LinkedList* this);
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);

int ll_map(LinkedList* lista,int (*pFunc)(void*));
int ll_count(LinkedList* this, int (*fn)(void* element));
LinkedList* ll_filter(LinkedList* this, int (*fn)(LinkedList*));



#endif /* FUNCIONES_H_ */

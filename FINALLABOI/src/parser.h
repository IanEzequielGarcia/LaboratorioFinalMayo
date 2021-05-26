/*
 * parser.h
 *
 *  Created on: 21 may. 2021
 *      Author: ian
 */

#ifndef PARSER_H_
#define PARSER_H_
#include "Funciones.h"
int parser_eCorredorFromText(FILE* pFile, LinkedList* pArrayListeCorredor);
int parser_eCorredorFromBinary(FILE* pFile , LinkedList* pArrayListeCorredor);



#endif /* PARSER_H_ */

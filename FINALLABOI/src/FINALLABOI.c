#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "Funciones.h"
#include "SECABA.h"
#include "Controller.h"
int main()
{
    int menu;
    LinkedList* miLista=NULL;
    char path[64];
    //char lista[4][25]={"BOMBEROS","DEFENSACIVIL","POLICIA","EMERGENCIAMEDICA"};
    /*
     * 1 - BOMBEROS
	2 - DEFENSA CIVIL
	3 - POLICIA
	4 - EMERGENCIA MEDICA
     */
    do
    {
        printf("Que quiere hacer?\n1.LEERARCHIVO\n2.Mostrar\n"
        		"3.Asignar tiempos\n4.Guardar en Archivo\n7.salir");


        scanf("%d",&menu);
        switch(menu)
        {
            case 1:
                miLista=(LinkedList*) ll_newLinkedList();
                printf("Que archivo quiere cargar?\n");
                fflush(stdin);
                //strcpy(path,"/home/ian/eclipse-workspace/FINALLABOI/");
                //scanf("%s",path);
                strcpy(path,"/home/ian/eclipse-workspace/FINALLABOI/Datos_LABO1.csv");
                if(!(controller_loadFromText(path, miLista)))
                {
                    printf("Error al leer el archivo");
                }
                break;
            case 2:
            	OrdenarListas(miLista);
                break;
            case 3:
                    if(!(controller_ListeEmergencia(miLista)))
                    {
                        printf("No se pudo mostrar la lista\n");
                    }
                break;
            case 4:
					//ll_map(miLista,criterioJurado);
					break;

			case 5:
					controller_saveAsText("mapeado.csv",miLista);
					break;
			case 6:
					MostrarParcial(miLista);
					break;
        }
    }while(menu!=7);
    return 0;
}

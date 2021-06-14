#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "biblioteca.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

//Alumno: Cano Gaston 1f

int main()
{
	setbuf(stdout, NULL);
    int option;


    LinkedList* miLista;

    miLista = ll_newLinkedList();

    do{
    	option = obtenerRango("1.Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n2.Cargar los datos de los empleados desde el archivo data.dat (modo binario).\n3.Alta de empleado\n4.Modificar datos de empleado\n5.Baja de empleado\n6.Listar empleados\n7.Ordenar empleados\n8.Guardar los datos de los empleados en el archivo data.csv (modo texto).\n9.Guardar los datos de los empleados en el archivo data.dat (modo binario).\n10.salir\nELIJA UNA OPCION:\n","Error ingrese solo numeros\n", 1, 10);
        switch(option)
        {
            case 1:
            	if(controller_loadFromText("data.csv", miLista))
            	{
            	  printf("Archivo se cargo exitosamente\n");
            	}
            	else
            	{
            		printf("No se encontro el archivo\n");
            	}
                break;
            case 2:
            	if(controller_loadFromBinary("data.dat",miLista))
				{
				  printf("Archivo se cargo exitosamente\n");
				}
				else
				{
					printf("No se encontro el archivo\n");
				}
            	break;
            case 3:
            	if(controller_addEmployee(miLista))
            	{
            		printf("Alta dada correctamente\n");
            	}
            	else
            	{
            		printf("No Hay espacio para mas empelados\n");
            	}
            	break;
            case 4:
            	switch(controller_editEmployee(miLista))
            	{
            	case -1:
            		printf("Lista esta vacia\n");
            		break;
            	case 0:
            		printf("No hay archivos cargados\n");
            		break;
            	case 1:
            		printf("Se modifico con exito\n");
            		break;
            	case 2:
            		printf("Se cancelo la modificacion\n");
            		break;
            	}
            	break;
            case 5:
            	switch(controller_removeEmployee(miLista))
            	{
            	case -1:
            		printf("Lista vacia\n");
            		break;
            	case 0:
            		printf("No se reconoce el ID\n");
            		break;
            	case 1:
            		printf("Se elimino con exito\n");
            		break;
            	case 2:
            		printf("Se cancelo la baja\n");
            		break;
            	}
            	break;
            case 6:
            	switch(controller_ListEmployee(miLista))
            	{
            	case 0:
            		printf("No hay nada para mostrar\n");
            		break;
            	case 1:
            		printf("     \tFIN DE LISTA\n\n");
            		break;
            	}
            	break;
            case 7:
            	switch(controller_sortEmployee(miLista))
            	{
				case 1:
					printf("Ordenado exitosamente por nombre de forma ascendente\n");
					break;
				case 2:
					printf("Ordenado exitosamente por nombre  de forma descendente\n");
					break;
				case 3:
					printf("Ordenado exitosamente por sueldo de forma ascendente\n");
					break;
				case 4:
					printf("Ordenado exitosamente por sueldo  de forma descendente\n");
					break;
            	}
            	break;
            case 8:
            	if(controller_saveAsText("data.csv", miLista))
            	{
            		printf("Se guardo exitosamente\n");
            	}
            	else
            	{
            		printf("El archivo no se guardo\n");
            	}
            	break;
            case 9:
            	if(controller_saveAsBinary("data.dat", miLista))
            	{
            		printf("Se guardo exitosamente\n");
            	}
            	else
            	{
            		printf("El archivo no pudo guardarse\n");
            	}
            	break;
            case 10:
            	printf("Fin del programa\n");
            	break;
        }
    }while(option != 10);

    return 0;
}


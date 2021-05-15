/*
 ============================================================================
 Name        : tp_laboratorio_2.c
 Author      : Cano Gaston division 1f
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "ArrayEmployees.h"
#include "Biblioteca.h"
#define MAX_STRUCT 1000 //maxima cantidad de ingresos

int main(void) {

	setbuf(stdout, NULL);
	int opcion;
	int criterio;
	int idIncrementarEmpleado;

	idIncrementarEmpleado = 2;//inicia en 2 debido al hardcodeo

	Employee empleados[MAX_STRUCT];

	initEmployees(empleados,MAX_STRUCT);//validar espacios del array
	addEmployees(empleados, MAX_STRUCT);//hardcodeo de 1 empleado

	do
	{
		opcion = Menu();//menu del usuario

		switch(opcion)
		{
		case 1:
			if(loadData(empleados, MAX_STRUCT, idIncrementarEmpleado))//carga de datos
			{
				idIncrementarEmpleado++;
				printf("Se cargo con  exito!\n");
			}
			else
			{
				printf("No hay espacio!\n");
			}
			break;
		case 2:
			switch(modification(empleados, MAX_STRUCT))//modificacion
			{
			 case -1:
			    printf("No se modifico el Empleado\n");
			    break;
			 case 0:
				printf("No hay registros de empleados\n");
				break;
			 case 1:
				 printf("Se  modifico con exito\n");
				 break;
			 case 2:
				 printf("Los id no coinciden\n");
				 break;
			}
			break;
		case 3:
			switch(removeEmployee(empleados,MAX_STRUCT))//baja de empleado
			{
			 case -1:
				printf("No se dio de baja el Empleado\n");
				break;
			 case 0:
				printf("No hay registros de empleados\n");
				break;
			 case 1:
				printf("Se dio de baja con exito\n");
				break;
			case 2:
				printf("Los id no coinciden\n");
				break;
			}
			break;
		case 4:

			 opcion = subMenu2();

			 switch(opcion)
			 {
			 	 case 1:
			 		 criterio = obtenerRango("1-ASCENDENTE\n2-DESCENDENTE\n","ERROR. ingrese solo numeros:\n", 1, 2);

			 		 switch(criterio)
			 		 {
			 		  case 1:
			 			 if(sortEmployees(empleados, MAX_STRUCT, criterio)==1)//ordenamiento
						 {
							 printf("Lista ordenada\n");
							 printEmployees(empleados, MAX_STRUCT);
						 }
						 else
						 {
							 printf("No hay registros de empleados\n");
						 }
			 			 break;
			 		  case 2:
			 			 if(sortEmployees(empleados, MAX_STRUCT, criterio)==1)//ordenamiento
						 {
							 printf("Lista ordenada\n");
							 printEmployees(empleados, MAX_STRUCT);
						 }
						 else
						 {
							 printf("No hay registros de empleados\n");
						 }
			 			  break;
			 		 }
			 		 break;
			 	 case 2:
			 		if(average(empleados,MAX_STRUCT)==1)//promedio
			 		{
			 			printf("Fin de informe\n");
			 		}
			 		else
			 		{
			 			printf("No hay registro de empleados\n");
			 		}
			 		break;
			 }
			break;
		case 5:
			printf("Fin del programa.\n");
			break;
		}

	}while(opcion!=5);

}

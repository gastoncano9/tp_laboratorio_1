#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{

	Employee* empleado;
	char nombre[50];
	char id[50];
	char sueldo[50];
	char horasTrabajadas[50];
	int leidos;
	int exito;
	exito = 0;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		 fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,sueldo,horasTrabajadas);

		 while(!feof(pFile))
		 {
			 leidos = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,sueldo,horasTrabajadas);
			 if(leidos == 4)
			 {
				 empleado = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
				 ll_add(pArrayListEmployee, empleado);
				 exito = 1;
			 }
			 if(feof(pFile))
			 {
				 break;
			 }
		 }
		 fclose(pFile);
		 exito = 1;
	}


    return exito;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee empleado;
	int entro;
	entro = 0;


	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		fread(&empleado,sizeof(Employee),1,pFile);

		while(!feof(pFile))
		{
			 Employee* pEmpleado = employee_new();
			 employee_setId(pEmpleado,empleado.id);
			 employee_setHorasTrabajadas(pEmpleado,empleado.horasTrabajadas);
			 employee_setNombre(pEmpleado,empleado.nombre);
			 employee_setSueldo(pEmpleado,empleado.sueldo);
			 fread(&empleado,sizeof(Employee),1,pFile);
			 ll_add(pArrayListEmployee,pEmpleado);
			 entro=1;
		}

		fclose(pFile);
	}

	return entro;
}

#include "Employee.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Employee* employee_new()
{
	Employee* listaEmpleados;

	listaEmpleados = (Employee*) calloc(sizeof(Employee),1);

	return listaEmpleados;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	Employee* listaEmpleados;

	listaEmpleados = employee_new();

	if(listaEmpleados != NULL)
	{
		if(idStr != NULL)
		{
			employee_setId(listaEmpleados,atoi(idStr));
		}
		if(horasTrabajadasStr != NULL)
		{
			employee_setHorasTrabajadas(listaEmpleados, atoi(horasTrabajadasStr));
		}
		if(nombreStr != NULL)
		{
			employee_setNombre(listaEmpleados, nombreStr);
		}
		if(sueldoStr != NULL)
		{
			employee_setSueldo(listaEmpleados, atoi(sueldoStr));
		}
	}

	return listaEmpleados;
}

int employee_setId(Employee* this,int id)
{
	int exito;

	exito = 0;

	if(this != NULL && id>0)
	{
		this->id = id;
		exito = 1;
	}

	return exito;
}

int employee_getId(Employee* this,int* id)
{
	int exito;
	exito = 0;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		exito = 1;
	}

	return exito;
}
int employee_setNombre(Employee* this,char* nombre)
{
	int exito;
	exito = 0;

	if(this != NULL)
	{
		strcpy(this->nombre,nombre);
		exito = 1;

	}

	return exito;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int exito;
	exito = 0;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);
		exito = 1;
	}

	return exito;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int exito;
	exito = 0;

	if(this != NULL && horasTrabajadas>0)
	{
		this->horasTrabajadas = horasTrabajadas;
		exito = 1;
	}

	return exito;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int exito;
	exito = 0;

	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		exito = 1;
	}

	return exito;
}
int employee_setSueldo(Employee* this,int sueldo)
{
	int exito;
	exito = 0;

	if(this != NULL && sueldo>0)
	{
		this->sueldo = sueldo;
		exito =1;
	}

	return exito;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
	int exito;
	exito = 0;

	if(this!= NULL && sueldo!= NULL)
	{
		*sueldo = this->sueldo;
		exito = 1;
	}

	return exito;
}
int compareByName(void* e1, void* e2)
{
	Employee* empleado1;
	Employee* empleado2;
	char nombreAux1[50];
	char nombreAux2[50];

	empleado1 = (Employee*)e1;
	empleado2 = (Employee*)e2;

	employee_getNombre(empleado1, nombreAux1);
	employee_getNombre(empleado2, nombreAux2);


	return strcmp(nombreAux1,nombreAux2);
}
int compareBySalary(void* e1, void* e2)
{
	int retorno;
	retorno = 0;
	Employee* empleado1;
	Employee* empleado2;
	int auxSueldo1;
	int auxSueldo2;

	empleado1 = (Employee*)e1;
	empleado2 = (Employee*)e2;

	employee_getSueldo(empleado1, &auxSueldo1);
	employee_getSueldo(empleado2, &auxSueldo2);

		if(auxSueldo1>auxSueldo2)
		{
			retorno = 1;
		}
		else
		{
			if(auxSueldo1<auxSueldo2)
			{
				retorno = 2;
			}
		}

	return retorno;
}
int searchId(LinkedList* pArrayListEmployee, int auxId)
{
	int retorno;
	int i;
	int len;
	int idEmpleado;
	Employee* empleado;
	retorno = -1;

	len = ll_len(pArrayListEmployee);

	if(pArrayListEmployee != NULL)
	{
		for(i=0;i<len;i++)
		{
			empleado = (Employee*)ll_get(pArrayListEmployee, i);
			idEmpleado = empleado->id;
			employee_getId(empleado, &idEmpleado);
			if(auxId==idEmpleado)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}
void employee_delete(Employee* this)
{
	  if(this!=NULL)
	  {
		  free(this);
	  }
}

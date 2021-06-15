#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "biblioteca.h"
#include "controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int exito;
    exito = 0;

    pFile = fopen(path,"r");

    if(path != NULL && pArrayListEmployee != NULL)
    {
        if(pFile!=NULL)
        {
            exito = parser_EmployeeFromText(pFile , pArrayListEmployee);
        }
    }

    return exito;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	  FILE* pFile;
	  int exito;
	  exito = 0;


	    if(path!=NULL && pArrayListEmployee!=NULL)
	    {
	        pFile= fopen(path,"rb");

	        if(pFile!=NULL)
	        {
	            exito = parser_EmployeeFromBinary(pFile , pArrayListEmployee);
	        }
	    }

	    return exito;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int exito;
	char horas[20];
	char sueldo[50];
	char nombre[50];
	char auxId[50];
	int id;

	Employee* empleado;
	exito = 0;

	if(pArrayListEmployee != NULL)
	{
		empleado = employee_new();

		if(empleado != NULL)
		{
			id = controller_readId(pArrayListEmployee, "id.dat")+1;
			employee_setId(empleado, id);
			itoa(id,auxId,10);
			Get_Char("Ingrese su nombre:\n", "Error ingrese solo letras para el nombre:\n", nombre);
			nombre[0] = toupper(nombre[0]);
			Get_CharConNumeros("Ingrese sus horas trabajadas:\n","Error ingrese solo numeros:\n",horas);
			Get_CharConNumeros("Ingrese su sueldo:\n","Error ingrese solo numeros:\n",sueldo);
			empleado = employee_newParametros(auxId, nombre, horas, sueldo);
			ll_add(pArrayListEmployee, empleado);
		}

		exito = 1;
	}

    return exito;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
   Employee* empleado;
   int exito;
   int auxId;
   int index;
   int opcion;
   int isEmpty;
   char nombre[50];
   char sueldo[50];
   char horas[50];
   exito = 0;

   if(pArrayListEmployee != NULL)
   {
	   isEmpty = ll_isEmpty(pArrayListEmployee);
	   if(isEmpty != 1)
	   {
		   controller_ListEmployee(pArrayListEmployee);
		   auxId = obtenerRango("Ingrese el ID del empleado que desea modificar:\n", "Error ingrese solo numeros\n", 1, 5000);
		   index = searchId(pArrayListEmployee, auxId);
	   }
	   else
	   {
		   exito = -1;
	   }

	   if(index != -1)
	   {
		   opcion = obtenerRango("Realmente desea modificar al empleado?\n1-SI\n2-NO\n", "Error ingresar solo numeros:\n", 1, 2);
		   empleado = (Employee*) ll_get(pArrayListEmployee, index);
		   printf("\nID \t\tNOMBRE \tHORAS \tSUELDO\n");
		   printf("%2d %18s %7d %7d\n",empleado->id,empleado->nombre,empleado->horasTrabajadas,empleado->sueldo);
		   if(opcion == 1)
		   {
			   opcion = obtenerRango("1-Modificar nombre\n2-Modificar sueldo\n3-Modificar horas Trabajadas\nElija una opcion:\n", "Error ingrese solo numeros\n", 1, 3);
			   empleado = (Employee*) ll_get(pArrayListEmployee, index);
			   switch(opcion)
			   {
			   case 1:
				   Get_Char("Ingrese nuevo nombre:\n", "Error al ingresar nombre\n", nombre);
				   nombre[0] = toupper(nombre[0]);
				   employee_setNombre(empleado, nombre);
				   exito = 1;
				   break;
			   case 2:
				   Get_CharConNumeros("Ingrese su sueldo:\n","Error ingrese solo numeros:\n",sueldo);
				   employee_setSueldo(empleado, atoi(sueldo));
				   exito = 1;
				   break;
			   case 3:
				   Get_CharConNumeros("Ingrese sus horas trabajadas:\n","Error ingrese solo numeros:\n",horas);
				   employee_setHorasTrabajadas(empleado, atoi(horas));
				   exito = 1;
				   break;
			   }
		   }
		   else
		   {
			   exito = 2;
		   }
	   }
   }


   return exito;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
   Employee* empleado;
   int retorno;
   int opcion;
   int auxId;
   int index;
   int isEmpty;

   retorno = 0;
   index = -1;

   if(pArrayListEmployee != NULL)
   {
	  isEmpty = ll_isEmpty(pArrayListEmployee);
	  if(isEmpty != 1)
	  {
		  controller_ListEmployee(pArrayListEmployee);
		  auxId = obtenerRango("ingrese el id de la persona que desea eliminar:\n", "Error ingrese solo numeros:\n", 1,5000);
		  index = searchId(pArrayListEmployee, auxId);
	  }
	  else
	  {
		  retorno = -1;
	  }

	  if(index!=-1)
	  {

		  empleado = (Employee*) ll_get(pArrayListEmployee, index);
		  opcion = obtenerRango("Realmente desea eliminar este empleado?\n1-SI\n2-NO\n","Error ingrese solo numeros\n", 1, 2);
		  printf("%d %s %d %d\n",empleado->id,empleado->nombre,empleado->horasTrabajadas,empleado->sueldo);

		  if(opcion==1)
		  {
			  ll_remove(pArrayListEmployee, index);
			  retorno = 1;
		  }
		  else
		  {
			  if(opcion==2)
			  {
				  retorno = 2;
			  }
		  }
	  }
   }


   return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{

    int i;
    int exito;
    int len;
    int auxId;
    int isEmpty;
    int auxHorasTrabajadas;
    int auxSueldo;
    char auxNombre[20];
    Employee* auxEmpleado;

    exito = 0;

    len = ll_len(pArrayListEmployee);
    isEmpty = ll_isEmpty(pArrayListEmployee);

    if(isEmpty != 1)
    {
    	if(len == 0)
    	{
    		 printf("\nID \t\tNOMBRE \tHORAS \tSUELDO\n\n");
    	}

        for(i=0;i<len;i++)
        {
            auxEmpleado = (Employee*)ll_get(pArrayListEmployee,i);
            employee_getId(auxEmpleado,&auxId);
            employee_getNombre(auxEmpleado,auxNombre);
            employee_getHorasTrabajadas(auxEmpleado,&auxHorasTrabajadas);
            employee_getSueldo(auxEmpleado,&auxSueldo);
            printf("%2d %18s %7d %7d\n\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
        }

        exito=1;
    }

    return exito;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
   int opcion;

   if(pArrayListEmployee != NULL)
   {
	   opcion = obtenerRango("1-Ordenar por nombre de forma ascendente\n2-Ordenar por nombre de forma descendente\n3-Ordenar por salario de forma ascendente\n4-Ordenar por salario de forma descendente\nELIJA UNA OPCION:\n", "Ingrese solo numeros:\n", 1, 4);

	   switch(opcion)
	   {
	   case 1:
		   ll_sort(pArrayListEmployee, compareByName, 1);
		   controller_ListEmployee(pArrayListEmployee);
		   break;
	   case 2:
		   ll_sort(pArrayListEmployee, compareByName, 0);
		   controller_ListEmployee(pArrayListEmployee);
		   break;
	   case 3:
		   ll_sort(pArrayListEmployee, compareBySalary, 1);
		   controller_ListEmployee(pArrayListEmployee);
		   break;
	   case 4:
		   ll_sort(pArrayListEmployee, compareBySalary, 0);
		   controller_ListEmployee(pArrayListEmployee);
		   break;
	   }
   }

   return opcion;

}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    Employee* empleado;
    int exito;
    int id;
    int i;
    int len;
    char nombre[50];
    int horas;
    int sueldo;
    exito = 0;

    pFile = fopen(path,"w");

    if(path != NULL && pArrayListEmployee != NULL)
    {
    	if(pFile != NULL)
    	{
			len = ll_len(pArrayListEmployee);
			fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");

			for(i=0;i<len;i++)
			{
				empleado = (Employee*) ll_get(pArrayListEmployee, i);
				employee_getId(empleado, &id);
				employee_getNombre(empleado, nombre);
				employee_getHorasTrabajadas(empleado, &horas);
				employee_getSueldo(empleado, &sueldo);
				fprintf(pFile,"%d,%s,%d,%d\n",id,nombre,horas,sueldo);
			}

			fclose(pFile);
			controller_writeId(pArrayListEmployee, "id.dat");
			exito = 1;
    	}
    }

    return exito;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	Employee* Empleado;
	int len;
	int exito;
	int i;
	exito = 1;

	    if(path!=NULL && pArrayListEmployee!=NULL)
	    {
	        pFile = fopen(path,"wb");

	        if(pFile!=NULL)
	        {
	            len=ll_len(pArrayListEmployee);

	            for(i=0;i<len;i++)
	            {
	                Empleado = (Employee*)ll_get(pArrayListEmployee,i);
	                fwrite(Empleado,sizeof(Employee),1,pFile);
	            }

	            fclose(pFile);
	        }

	        exito=1;
	    }

	 return exito;
}
int controller_writeId(LinkedList* pArrayListEmployee, char* path)
{
	int retorno;
	int i;
	int len;
	Employee* empleado;
	FILE* pFile;

	retorno = -1;

	if(path != NULL)
	{
		len = ll_len(pArrayListEmployee);

		pFile = fopen(path,"wb");

		if(pFile != NULL)
		{
			for(i=0;i<len;i++)
			{
				empleado = (Employee*) ll_get(pArrayListEmployee, i);
				retorno = empleado->id;
			}

			fwrite(&retorno,sizeof(int),1,pFile);
		}

		fclose(pFile);
	}


	return retorno;

}
int controller_readId(LinkedList* pArrayListEmployee, char* path)
{
	int retorno;
	int id;
	int isEmpty;
	FILE* pFile;

	retorno = -1;

		if(path != NULL)
		{
			pFile = fopen(path,"rb");

			if(pFile != NULL)
			{
				isEmpty = ll_isEmpty(pArrayListEmployee);
				if(isEmpty != 1)
				{
					fread(&id,sizeof(int),1,pFile);
					retorno = id;
				}
				else
				{
					retorno = 0;
				}
			}

			fclose(pFile);
		}


	return retorno;

}

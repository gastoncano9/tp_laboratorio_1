/*
 * Employee.c
 *
 *  Created on: 14 may. 2021
 *      Author: gaston cano
 */
#include "ArrayEmployees.h"
#include "Biblioteca.h"

void initEmployees(Employee array[], int tam)
{
	int i;

		for(i=0;i<tam;i++)
		{
			array[i].isEmpty = TRUE;
		}

}
void  addEmployees(Employee array[], int tam)
{

	int id[] = {1};
	char name [][TAM_TECLADO] = {"GASTON"};
	char lastName [][TAM_TECLADO] = {"CANO"};
	float salary[] = {125000};
	int sector[] = {4};


	int i;

	for(i=0;i<1;i++)
	{
		array[i].id = id[i];
		strcpy(array[i].name,name[i]);
		strcpy(array[i].lastName,lastName[i]);
		array[i].salary = salary[i];
		array[i].sector = sector[i];
		array[i].isEmpty = FALSE;
	}
}
int findEmployeeById(Employee array[], int tam, int id)
{
	int i;
	int retorno;

		retorno = TRUE;

			for(i=0;i<tam;i++)
			{
				if(array[i].id == id && array[i].isEmpty == FALSE)
				{
					retorno = i;
					break;
				}
			}

	return retorno;

}
int removeEmployee(Employee array[], int tam)
{

	int i;
	int auxiliar;
	int retorno;
	int pregunta;
	int index;

	retorno = 0;


		for(i=0;i<tam; i++)
		{
			if(array[i].isEmpty == FALSE)
			{
				printEmployees(array, tam);

				auxiliar = ObtenerNumeroInt("Ingrese el numero ID  dar de baja:\n","ERROR ingrese solo numeros:\n");

				if(findEmployeeById(array,tam,auxiliar)!=TRUE)
				{
					index = findEmployeeById(array, tam,auxiliar);

					pregunta = obtenerRango("Realmente desea eliminar?\n1-SI\n2-NO\n","Ingrese solo numeros:\n",1,2);

					if(pregunta==1)
					{
						array[index].isEmpty = TRUE;
						retorno = 1;
						break;
					}
					else
					{
						retorno = -1;
						break;
					}
				}
				else
				{
					retorno = 2;
					break;
				}
			}
		}

	return retorno;
}
int sortEmployees(Employee array[], int tam,int criterio)
{
	int retorno;
	int i;
	int j;

	retorno = 0;

	Employee aux;

	switch(criterio)
	{
	case 1:
		for(i=0;i<tam-1;i++)
		{
			for(j=i+1;j<tam;j++)
			{
				if(array[i].isEmpty == FALSE || array[j].isEmpty == FALSE)
				{
					retorno = 1;

					if(strcmp(array[i].lastName,array[j].lastName)>0)
					{
						aux = array[i];
						array[i] = array[j];
						array[j] = aux;
						retorno = 1;
					}

					if(strcmp(array[i].lastName,array[j].lastName)==0)
					{
						if(array[i].sector>array[j].sector)
						{
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
							retorno = 1;
						}
					}
				}
			}
		}
		break;
	case 2:
		for(i=0;i<tam-1;i++)
		{
			for(j=i+1;j<tam;j++)
			{
				if(array[i].isEmpty == FALSE || array[j].isEmpty == FALSE)
				{
					retorno = 1;

					if(strcmp(array[i].lastName,array[j].lastName)<0)
					{
						aux = array[i];
						array[i] = array[j];
						array[j] = aux;
						retorno = 1;
					}

					if(strcmp(array[i].lastName,array[j].lastName)==0)
					{
						if(array[i].sector<array[j].sector)
						{
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
							retorno = 1;
						}
					}
				}
			}
		}
		break;
	}


	return retorno;
}
int printEmployees(Employee array[], int tam)
{
	int i;
	int retorno;
	int contador;

	contador = 0;

	retorno = 0;

			for(i=0;i<tam;i++)
			{
				 if(array[i].isEmpty == FALSE)
				 {

					if(contador==0)
					{
						printf(" ID  NOMBRE APELLIDO SECTOR\n");
						contador++;
					}

					viewone(array[i]);
					retorno = 1;
				 }
			}

	return retorno;
}
int searchcaliber(Employee array[], int tam)
{
	int i;
	int indice;

		indice = -1;

			for(i=0; i<tam;i++)
			{
				if(array[i].isEmpty == TRUE)
				{
					indice = i;
					break;
				}
			}

		return indice;
}
Employee requestdata()
{
	Employee auxiliar;

	Get_Char("Ingrese su nombre:\n","ERROR.ingrese solo letras:\n", auxiliar.name);

	strupr(auxiliar.name);

	Get_Char("Ingrese su Apellido:\n","ERROR.ingrese solo letras:\n", auxiliar.lastName);

	strupr(auxiliar.lastName);

	auxiliar.salary = obtenerNumeroFloat("Ingrese el salario:\n","ERROR. ingrese solo numeros:\n");

	auxiliar.sector = ObtenerNumeroInt("Ingrese el sector:\n","ERROR. ingrese solo numeros:\n");

	auxiliar.isEmpty = FALSE;

	return auxiliar;
}
int loadData(Employee array[], int tam,int idIncremental)
{
	int i;
	int retorno;

		retorno = 0;

		i = searchcaliber(array, tam);

		if(i!=-1)
		{
			array[i] = requestdata();

			array[i].id = idIncremental;

			retorno = 1;
		}
		else
		{
			retorno = 0;
		}


		return retorno;
}
int modification(Employee array[], int tam)
{
	int i;
	int auxiliar;
	int retorno;
	int pregunta;
	int opcion;

	retorno = 0;

				for(i=0;i<tam; i++)
				{
					if(array[i].isEmpty == FALSE)
					{
						printEmployees(array, tam);

						auxiliar = ObtenerNumeroInt("Ingrese el numero ID a MODIFICAR:\n","ERROR ingrese solo numeros:\n");

						if(findEmployeeById(array,tam,auxiliar) != TRUE)
						{

							pregunta = obtenerRango("Realmente desea modificar?\n1-SI\n2-NO\n","Ingrese solo numeros:\n",1,2);

							if(pregunta==1)
							{
								opcion = subMenu();

								switch(opcion)
								{
								case 1:
									Get_Char("Ingrese su nombre:\n","ERROR.ingrese solo letras:\n", array[i].name);
									strupr(array[i].name);
									retorno = 1;
									break;
								case 2:
									Get_Char("Ingrese su Apellido:\n","ERROR.ingrese solo letras:\n", array[i].lastName);
									strupr(array[i].lastName);
									retorno = 1;
									break;
								case 3:
									array[i].salary = obtenerNumeroFloat("Ingrese el salario:\n","ERROR. ingrese solo numeros:\n");
									retorno = 1;
									break;
								case 4:
									array[i].sector = ObtenerNumeroInt("Ingrese el sector:\n","ERROR. ingrese solo numeros:\n");
									retorno = 1;
									break;
								}
								break;
							}
							else
							{
								retorno = -1;
								break;
							}
						}
						else
						{
							retorno = 2;
							break;
						}
					}

				}

			return retorno;
}
void viewone(Employee array)
{

	printf(" %2d %7s %6s %5d\n",array.id,array.name,array.lastName,array.sector);
}
int counterincrease(Employee array[],int tam)
{
	int i;
	int contador;

	contador = 0;

	for(i=0;i<tam;i++)
	{
		if(array[i].isEmpty == FALSE)
		{
			contador++;
		}
	}

	return contador;
}
float acumincrease(Employee array[],int tam)
{
	int i;
	float acumulador;

	acumulador = 0;

	for(i=0;i<tam;i++)
	{
		if(array[i].isEmpty == FALSE)
		{
			acumulador = acumulador + array[i].salary;
		}
	}

	return acumulador;
}
float calculateaverage(Employee array[],int tam)
{

	int i;
	float promedio;

	promedio = 0;

	for(i=0;i<tam;i++)
	{
		if(counterincrease(array, tam)>0)
		{
			promedio = acumincrease(array, tam) / counterincrease(array, tam);
		}

	}

	return promedio;
}
int viewaverage(Employee array[],int tam)
{
	int retorno;
	int contador;
	int i;

	retorno = 0;
	contador = 0;

	for(i=0;i<tam;i++)
	{
		if(array[i].isEmpty == FALSE && array[i].salary > calculateaverage(array, tam))
		{
			contador++;
		}
	}

	if(counterincrease(array, tam)!=0)
	{
		printf("El total de todos los salarios : %.3f\nel promedio es : %.3f\ncantidad de empleados que superan el promedio salarial :%d\n",
				acumincrease(array, tam),calculateaverage(array, tam),contador);
		retorno = 1;
	}

	return retorno;
}

int average(Employee array[],int tam)
{
	int retorno;

	counterincrease(array, tam);

	acumincrease(array, tam);

	calculateaverage(array, tam);

	retorno = viewaverage(array, tam);

	return retorno;
}

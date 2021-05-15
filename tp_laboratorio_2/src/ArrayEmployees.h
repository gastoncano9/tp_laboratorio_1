/*
 * Employee.h
 *
 *  Created on: 14 may. 2021
 *      Author: Gaston Cano
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#define TRUE -1
#define FALSE 0

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;

}Employee;

typedef struct
{
	int id;
	float acumulador;
	int contador;
	float promedio;

}eAuxiliar;
/**
 * @fn void initEmployees(Employee[], int)
 * @brief se valida todos los espacios disponibles en TRUE que su valor es -1
 *
 * @param
 * @param tam tamaño de la estructura
 */
void initEmployees(Employee [], int tam);
/**
 * @fn int searchcaliber(Employee[], int)
 * @brief se busca un espacio libre en el array
 *
 * @param
 * @param tam tamaño de la estructura
 * @return retorna -1 si no hay espacio y si lo hay devuelve el indice de donde hay el espacio
 */
int searchcaliber(Employee [], int tam);
/**
 * @fn void addEmployees(Employee[], int)
 * @brief hardcodeo de 1 empleado para testear el funcionamiento
 *
 * @param
 * @param tam tamaño de la estructura
 */
void addEmployees(Employee [], int tam);
/**
 * @fn int findEmployeeById(Employee[], int, int)
 * @brief se verifica que el id que se ingreso exista haciendo un match
 *
 * @param
 * @param tam tamaño de la estructura
 * @param id valor que se esta buscando
 * @return retorna TRUE si no existe el id y si existe retorna en que indice esta
 */
int findEmployeeById(Employee [], int tam, int id);
/**
 * @fn int removeEmployee(Employee[], int)
 * @brief si existe el id del usuario se le da una baja logica
 *
 * @param
 * @param tam tamaño de la estructura
 * @return retorna -1 si no se dio de baja 0 si no hay empleados 1 si se dio de baja con exito y 2 si los id no coinciden
 */
int removeEmployee(Employee [], int tam);
/**
 * @fn int sortEmployees(Employee[], int, int)
 * @brief se ordena los empleados mediante un swap ante igualdad de apellidos los ordena por sector
 *
 * @param
 * @param tam tamaño de la estructura
 * @param criterio criterio de ordenamiento
 * @return retorna 0 si no hay empleados y 1 si se ordeno
 */
int sortEmployees(Employee [], int tam,int criterio);
/**
 * @fn int printEmployees(Employee[], int)
 * @brief se muestran todos los empleados que esten estado FALSE
 *
 * @param
 * @param tam tamaño de la estructura
 * @return retorna 0 si no hay nada y 1 si lo hay
 */
int printEmployees(Employee [], int tam);
/**
 * @fn Employee requestdata()
 * @brief se pide los datos de la estructura
 *
 * @return retorna los datos
 */
Employee requestdata();
/**
 * @fn int loadData(Employee[], int, int)
 * @brief si hay espacio se podra cargar datos
 *
 * @param
 * @param tam tamaño de la estructura
 * @param idIncremental variable para el incremento del id
 * @return retorna 0 si no habia espacio y 1 si habia espacio para cargar los datos
 */
int loadData(Employee [], int tam,int idIncremental);
/**
 * @fn int modification(Employee[], int)
 * @brief si existe el id se podra modifcar lo que el usuario prefiera mediante un sub menu
 *
 * @param
 * @param tam tamaño de la estructura
 * @return retorna -1 sino se modifico 0 si no hay empleados 1 si se modifico con exito y 2 si los id no coinciden
 */
int modification(Employee [], int tam);
/**
 * @fn void viewone(Employee)
 * @brief se muestra los datos de la estructura empleados
 *
 * @param
 */
void viewone(Employee);
/**
 * @fn int counterincrease(Employee[], int)
 * @brief se cuenta la cantidad de empleados que hay
 *
 * @param
 * @param tam tamaño de la estructura
 * @return retorna 0 si no hay y sino devuelve la cantidad que hay
 */
int counterincrease(Employee [],int tam);
/**
 * @fn float acumincrease(Employee[], int)
 * @brief por cada empleado acumula los salarios
 *
 * @param
 * @param tam tam tamaño de la estructura
 * @return retorna 0 si no hay empleados y sino devuelve el total de los salarios
 */
float acumincrease(Employee [],int tam);
/**
 * @fn float calculateaverage(Employee[], int)
 * @brief se calcula el promedio de los salarios
 *
 * @param
 * @param tam tam tamaño de la estructura
 * @return retorna el promedio
 */
float calculateaverage(Employee [],int tam);
/**
 * @fn int viewaverage(Employee[], int)
 * @brief muestra el promedio, el total de los salarios y la cantidad de empleados que superan el promedio
 *
 * @param
 * @param tam tam tamaño de la estructura
 * @return retorna 0 si no hay empleados y 1 si hay promedio para mostrar
 */
int viewaverage(Employee [], int tam);
/**
 * @fn int average(Employee[], int)
 * @brief funcion para calcular el promedio
 *
 * @param array
 * @param tam tam tamaño de la estructura
 * @return retorna el valor de viewaverage 0 si no hay para mostrar 1 si ,si los hay
 */
int average(Employee array[],int tam);



#endif /* ARRAYEMPLOYEES_H_ */

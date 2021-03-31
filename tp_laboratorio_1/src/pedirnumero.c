/*
 * pedirentero.c
 *
 *  Created on: 25 mar. 2021
 *      Author: gaston cano
 */

/**
 * @fn float NumeroEntero(void)
 * @brief pedimos ingresar un numero y lo guardamos en la variable "ingreseUnNumero".
 *
 * @return se retorna un numero flotante.
 */

#include "pedirnumero.h"

float PedirNumero(void)
{
	float IngreseUnNumero;

	printf("ingrese un numero:");

	scanf("%f",&IngreseUnNumero);

	return IngreseUnNumero;
}

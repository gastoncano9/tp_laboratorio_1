/*
 * funcionsumar.c
 *
 *  Created on: 24 mar. 2021
 *      Author: gaston cano
 */
#include "funcionesdecalculo.h"

float Sumar(float numero1, float numero2)
{
	float resultado;

	resultado = numero1 + numero2;

	return resultado;
}

float Division(float numero1, float numero2)
{

	float resultado;

	resultado = numero1 / numero2;

	return resultado;
}

float Resta(float numero1, float numero2)
{
	float resultado;

	resultado = numero1 - numero2;

	return resultado;
}

float Multiplicar(float numero1, float numero2)
{
	float resultado;

	resultado = numero1 * numero2;

	return resultado;
}

double CalcularFactorial(double numero1)
{
	double resultado;
	int i;

	resultado = 1;

	for(i=1;i<=numero1;i++)
	{
		resultado = resultado * i;
	}


	return resultado;

}

double CalcularFactorial2(double numero2)
{
	double resultado;
	int i;

	resultado =1;

	for(i=1;i<=numero2;i++)
	{
		resultado = resultado * i;
	}

	return resultado;
}

double ValidacionFactorial(double numero1)
{
    int entero;
    double resultadoPrimerNumero;
    entero = numero1;
    if(numero1 - entero)
    {
        return 0;
    }
    else
    {
        resultadoPrimerNumero = CalcularFactorial(numero1);
        return resultadoPrimerNumero;
    }
}

double ValidacionFactorial2(double numero2)
{
    int entero;
    double resultadoPrimerNumero;
    entero = numero2;
    if(numero2 - entero)
    {
        return 0;
    }
    else
    {
        resultadoPrimerNumero = CalcularFactorial2(numero2);
        return resultadoPrimerNumero;
    }
}




/*
 * biblioteca.c
 *
 *  Created on: 7 abr. 2021
 *      Author: gaston cano
 */

#include "biblioteca.h"

int ValidarEntero(char ingresoTeclado[])
{
	int retorno;
	int i;

	retorno = 1;
	// pregunta si la cadena esta vacia
	if(strlen(ingresoTeclado)>0)
	{
		//recorro el ingreso del teclado para ver si son numeros
		for(i=0;i<strlen(ingresoTeclado);i++)
		{
			//validar el dato
			 if(isdigit(ingresoTeclado[i])==0)//si devuelve cero no es un numero
			 {
				 retorno = 0;
				 break;
			 }
		}
	}
	else
	{
		retorno = 0;
	}

	return retorno;
}

int ValidarFloat(char ingresoTeclado[])
{
	int retorno;
	int i;
	int contadorDeSigno;

	contadorDeSigno = 0;

		retorno = 1;
		// pregunta si la cadena esta vacia
		if(strlen(ingresoTeclado)>0)
		{
			//recorro el ingreso del teclado para ver si son numeros
			for(i=0;i<strlen(ingresoTeclado);i++)
			{
				//validar el dato
				if(ingresoTeclado[i]=='.' || ingresoTeclado[i]==','|| ingresoTeclado[i]=='-')
				{
					contadorDeSigno++;
				}
				else
				{
					 if(isdigit(ingresoTeclado[i])==0)//si devuelve cero no es un numero
					 {
						 retorno = 0;
						 break;
					 }
				}
			}

			if(contadorDeSigno>1)
			{
				retorno = 0;
			}
		}
		else
		{
			retorno = 0;
		}

		return retorno;
}

int ObtenerNumeroInt(char mensaje[], char mensajeError[])
{
	int retorno;
	char ingresoTeclado[TAM_TECLADO];

	printf("%s",mensaje);
	fflush(stdin);
	scanf("%[^\n]",ingresoTeclado);

	while( ValidarEntero(ingresoTeclado)==0)
	{
		printf("%s",mensajeError);
		fflush(stdin);
		scanf("%[^\n]",ingresoTeclado);
	}

	retorno = atoi(ingresoTeclado);

	return retorno;

}

int obtenerNumeroFloat(char mensaje[], char mensajeError[])
{
	int retorno;
	char ingresoTeclado[TAM_TECLADO];

	printf("%s",mensaje);
	fflush(stdin);
	scanf("%[^\n]",ingresoTeclado);

	while( ValidarFloat(ingresoTeclado)==0)
	{
		printf("%s",mensajeError);
		fflush(stdin);
		scanf("%[^\n]",ingresoTeclado);
	}

	retorno = atoi(ingresoTeclado);

	return retorno;
}

int obtenerRango(char mensaje[], char mensajeError[], int min,int max)
{
	int retorno;

	retorno = ObtenerNumeroInt(mensaje, mensajeError);

	while(retorno<min || retorno>max)
	{
		printf("Error. fuera de rango [min]=%d [max]=%d", min, max);

		retorno = ObtenerNumeroInt(mensaje, mensajeError);
	}

	return retorno;
}

int obtenerRangoFlotante(char mensaje[], char mensajeError[], int min,int max)
{

	int retorno;

	retorno = obtenerNumeroFloat(mensaje, mensajeError);

	while(retorno<min || retorno>max)
	{
		printf("Error. fuera de rango [min]=%d [max]=%d", min, max);

		retorno = obtenerNumeroFloat(mensaje, mensajeError);
	}

	return retorno;

}

int ValidarAlfaNumerico(char ingresoTeclado[])
{
	int i;
	int retorno;

	retorno = 1;

	if(strlen(ingresoTeclado)>0)
	{
		for(i=0;i<strlen(ingresoTeclado);i++)
		{
			if(ingresoTeclado[i] == ' ' || ingresoTeclado[i] == ',')
			{
				retorno = 1;
			}
			else
			{
				if(isalnum(ingresoTeclado[i])==0)
				{
					retorno = 0;
					break;
				}
			}
		}
	}
	else
	{
		retorno = 0;
	}


	return retorno;
}

int  obtenerAlfaNumerico(char mensaje[], char mensajeError[])
{
	char ingresoTeclado[TAM_TECLADO];
	int retorno;

	printf("%s",mensaje);
	fflush(stdin);
	scanf("%[^\n]",ingresoTeclado);

	while(ValidarAlfaNumerico(ingresoTeclado)==0)
	{
		printf("%s",mensajeError);
		fflush(stdin);
		scanf("%[^\n]",ingresoTeclado);
	}

	retorno = atoi(ingresoTeclado);

	return retorno;
}



/*
 * biblioteca.c
 *
 *  Created on: 7 abr. 2021
 *      Author: Gaston Cano
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
				if(ingresoTeclado[i]=='.' || ingresoTeclado[i]==',')
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
		printf("Error. fuera de rango [min]=%d [max]=%d\n", min, max);

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
int Menu()
{
	int opcion;

	opcion = ObtenerNumeroInt("1-ALTAS\n2-MODIFICAR\n3-BAJAS\n4-INFORMAR\n5-SALIR\nELIJA UNA OPCION:\n","ERROR. ingrese solo numeros\n");

	return opcion;
}
int Validate_Char(char ingresoTeclado[])
{

	int retorno;
	int i;

	retorno = 0;

	for(i=0;i<strlen(ingresoTeclado);i++)
	{
		if(strlen(ingresoTeclado))
		{
			if(isalpha(ingresoTeclado[i]))
			{
				retorno = 1;

				if(ingresoTeclado[i] == ' ')
				{
					retorno = 1;
				}
			}
			else
			{
				retorno = 0;
			}
		}
		else
		{
			retorno = 0;
			break;
		}
	}

	return retorno;
}

void Get_Char(char mensaje[],char mensajeError[],char ingresoTeclado[])
{
	printf("%s",mensaje);
	fflush(stdin);
	scanf("%[^\n]",ingresoTeclado);

	while(Validate_Char(ingresoTeclado)==0)
	{
		printf("%s",mensajeError);
		fflush(stdin);
		scanf("%[^\n]",ingresoTeclado);
	}
}
int subMenu()
{
	int opcion;

	opcion = ObtenerNumeroInt("1-MODIFICAR NOMBRE\n2-MODIFICAR APELLIDO\n3-MODIFICAR SALARIO\n4-MODIFICAR SECTOR\nELIJA UNA OPCION:\n","ERROR. ingrese solo numeros\n");

	return opcion;
}
int subMenu2()
{
	int opcion;

	opcion = ObtenerNumeroInt("1-ORDENAR POR APELLIDO\n2-PROMEDIO SALARIALES\nELIJA UNA OPCION:\n","ERROR. ingrese solo numeros\n");

	return opcion;
}

/*
 * biblioteca.h
 *
 *  Created on: 7 abr. 2021
 *      Author: gaston cano
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM_TECLADO 2000


//VALIDACIONES
int ValidarEntero(char ingresoTeclado[]);

int ValidarFloat(char ingresoTeclado[]);

int ValidarAlfaNumerico(char ingresoTeclado[]);

//OBTENER
int ObtenerNumeroInt(char mensaje[], char mensajeError[]);

int obtenerNumeroFloat(char mensaje[], char mensajeError[]);

int obtenerRango(char mensaje[], char mensajerror[], int min,int max);

int obtenerAlfaNumerico(char mensaje[], char mensajeError[]);

int obtenerRangoFlotante(char mensaje[], char mensajeError[], int min,int max);



#endif /* BIBLIOTECA_H_ */

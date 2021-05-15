/*
 * biblioteca.h
 *
 *  Created on: 7 abr. 2021
 *      Author: Gaston Cano
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM_TECLADO 2000


//VALIDACIONES
/**
 * @fn int ValidarEntero(char[])
 * @brief se valida que lo que ingresa el usuario sean solo numeros.
 *
 * @param ingresoTeclado
 * @return retorna 0 sino es numero y 1 si lo es.
 */
int ValidarEntero(char ingresoTeclado[]);
/**
 * @fn int ValidarFloat(char[])
 * @brief se valida que lo que ingresa el usuario sean solo numeros y que tambien puedan ser flotantes.
 *
 * @param ingresoTeclado
 * @return retorna 0 sino es numero y 1 si lo es.
 */
int ValidarFloat(char ingresoTeclado[]);
/**
 * @fn int ValidarAlfaNumerico(char[])
 * @brief valida que lo que ingresa el usuario sean caracteres alfanumericos.
 *
 * @param ingresoTeclado
 * @return devuelve 0 si ingresan un signo y 1 si son solo numeros y letras.
 */
int ValidarAlfaNumerico(char ingresoTeclado[]);

//OBTENER
/**
 * @fn int ObtenerNumeroInt(char[], char[])
 * @brief se le pide al usuario que ingrese numeros y se guarda en un scanf.
 *
 * @param mensaje
 * @param mensajeError
 * @return retorna a numero lo que ingreso el usuario.
 */
int ObtenerNumeroInt(char mensaje[], char mensajeError[]);
/**
 * @fn int obtenerNumeroFloat(char[], char[])
 * @brief se le pide al usuario lo que queremos que ingrese y se valida que fuese un numero.
 *
 * @param mensaje
 * @param mensajeError
 * @return retorna a numero lo que ingreso el usuario.
 */
int obtenerNumeroFloat(char mensaje[], char mensajeError[]);
/**
 * @fn int obtenerRango(char[], char[], int, int)
 * @brief le pediremos al usuario que ingrese un numero con un maximo y un minimo
 *
 * @param mensaje
 * @param mensajerror
 * @param min
 * @param max
 * @return retorna el numero validado
 */
int obtenerRango(char mensaje[], char mensajerror[], int min,int max);
/**
 * @fn int obtenerRangoFlotante(char[], char[], int, int)
 * @brief se pide al usuario lo que queremos que ingrese y se valida que sean numeros.tienen maximo y minimo
 *
 * @param mensaje
 * @param mensajeError
 * @param min
 * @param max
 * @return retorna los numeros validados
 */
int obtenerRangoFlotante(char mensaje[], char mensajeError[], int min,int max);
/**
 * @fn int Menu()
 * @brief Se muestra un menu al usuario.
 *
 * @return Retorna un valor entero elegido por el usuario
 */
int Menu();
/**
 * @fn int Validate_Char(char[])
 * @brief se valida que lo que ingresa sean solo letras
 *
 * @param
 * @return retorna 0 sino lo es y si son solo letras
 */
int Validate_Char(char []);
/**
 * @fn void Get_Char(char[], char[], char[])
 * @brief con la funcion validate_char pedimos ingresos y son validados
 *
 * @param
 * @param
 * @param
 */
void Get_Char(char [],char [],char []);
/**
 * @fn int subMenu()
 * @brief Se muestra un menu al usuario.
 *
 * @return Retorna un valor entero elegido por el usuario
 */
int subMenu();
/**
 * @fn int subMenu2()
 * @brief Se muestra un menu al usuario.
 *
 * @return Retorna un valor entero elegido por el usuario
 */
int subMenu2();

#endif /* BIBLIOTECA_H_ */

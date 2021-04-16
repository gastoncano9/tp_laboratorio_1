/*
 * funcionsumar.h
 *
 *  Created on: 24 mar. 2021
 *      Author: gaston cano
 */

#ifndef FUNCIONESDECALCULO_H_
#define FUNCIONESDECALCULO_H_
#include <stdio.h>

/**
 * @fn float Sumar(float, float)
 * @brief se suma las 2 variables flotantes ingresadas por el usuario en la funcion "pedirNumero.h".
 *
 * @param numero1 primer numero ingresado por el usuario.
 * @param numero2 segundo numero ingresado por el usuario.
 * @return retorna el valor de la suma.
 */
float Sumar(float numero1, float numero2);

/**
 * @fn float Division(float, float)
 * @brief se genera la division entre el numero 1 y el numero 2.
 *
 * @param numero1 primer numero ingresado por el usuario.
 * @param numero2 segundo numero ingresado por el usuario.
 *
 * @return retorna el valor de la division de numero1 y numero 2.
 */
float Division(float numero1, float numero2);

/**
 * @fn float Resta(float, float)
 * @brief es la resta de numero1 - numero2.
 *
 * @param numero1 primer numero ingresado por el usuario.
 * @param numero2 segundo numero ingresado por el usuario.
 * @return retorna el valor de la resta de las 2 variables antes mencionadas.
 */
float Resta(float numero1, float numero2);

/**
 * @fn float Multiplicar(float, float)
 * @brief es el producto del numero1 * el numero2
 *
 * @param numero1 primer numero ingresado por el usuario.
 * @param numero2 segundo numero ingresado por el usuario.
 * @return retorna el producto de dicha multiplicacion.
 */
float Multiplicar(float numero1, float numero2);

/**
 * @fn double CalcularFactorial(double)
 * @brief es el factorial del numero1.
 *
 * @param el numero ingresado por el usuario es ingresado a un ciclo for. dicho numero recorrera su antecesor hasta
 * llegar a su mismo valor o su menor. mientras este hace el recorrido en el bucle for, la variable i ira creciendo +1 cada
 * vuelta. es decir pasaria algo asi : (resultado = 1*1 ; resultado = 1*2 resultado = 2*3) mientras se ira multiplicando
 *  hasta el valor ingresado  y se ira guardando en la variable resultado.
 *
 * @return retorna el calculo del factorial del numero ingresado por el usuario.
 */
double CalcularFactorial(double numero1);

/**
 * @fn double CalcularFactorial(double)
 * @brief es el factorial del numero2.
 *
 * @param el numero ingresado por el usuario es ingresado a un ciclo for. dicho numero recorrera su antecesor hasta
 * llegar a su mismo valor o su menor. mientras este hace el recorrido en el bucle for, la variable i ira creciendo +1 cada
 * vuelta. es decir pasaria algo asi : (resultado = 1*1 ; resultado = 1*2 resultado = 2*3) mientras se ira multiplicando
 *  hasta el valor ingresado  y se ira guardando en la variable resultado.
 *
 * @return retorna el calculo del factorial del numero ingresado por el usuario.
 */
double CalcularFactorial(double numero2);

/**
 * @fn double ValidacionFactorial(double)
 * @brief se valida que solamente el calculo de un factorial sea con un numero entero y no con con coma o decimales.
 *
 * @param a la variable numero1 que esta declarada como double se la pasa a entero. teniendo asi su valor entero
 * y su valor con decimal. una vez ingresados al condicional if se le resta la parte entera al numero decimal.
 * si retorna 0 es que tiene decimales. sino se muestra el resultado del factorial de un numero entero.
 * @return retorna el resultado del factorial.
 */
double ValidacionFactorial(double numero1);

/**
 * @fn double ValidacionFactorial(double)
 * @brief se valida que solamente el calculo de un factorial sea con un numero entero y no con con coma o decimales.
 *
 * @param a la variable numero2 que esta declarada como double se la pasa a entero. teniendo asi su valor entero
 * y su valor con decimal. una vez ingresados al condicional if se le resta la parte entera al numero decimal.
 * si retorna 0 es que tiene decimales. sino se muestra el resultado del factorial de un numero entero.
 * @return retorna el resultado del factorial.
 */
double ValidacionFactorial2(double numero2);

#endif /* FUNCIONESDECALCULO_H_ */

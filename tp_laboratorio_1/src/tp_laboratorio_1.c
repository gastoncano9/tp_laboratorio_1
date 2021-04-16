/*
 ============================================================================
 Name        : tp_laboratorio_1.c
 Author      : Cano Gaston division 1f
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include "funcionesdecalculo.h"
#include "biblioteca.h"

int main(void) {


	int opcion;
	float numero1;
	float numero2;
	double numeroFactorial1;
	double numeroFactorial2;
	float resultadoSuma;
	float resultadoResta;
	float resultadoDivision;
	float resultadoMultiplicacion;
	double resultadoFactorial;
	double resultadoFactorial2;
	int banderaPrimero;
	int banderaSegundo;
	int banderaTercero;

	setbuf(stdout, NULL);


	banderaPrimero = 0;
	banderaSegundo = 0;
	banderaTercero = 0;



	do
	{
		if(banderaPrimero == 0)//Se utiliza para saber que es la priemra vez qaue se ingresan el operando.
		{
			printf("1.Ingresar 1er operando\n");
		}
		else //Si la bandera es distinta a cero significa que ya se ingreso el operando y se mostrara el valor cargado.
		{
			printf("1.Ingresar 1er operando (%.2f)\n",numero1);
		}
		if(banderaSegundo == 0)//Se utiliza para saber que es la priemra vez qaue se ingresan el operando.
		{
			printf("2.Ingresar 2do operando\n");
		}
		else//Si la bandera es distinta a cero significa que ya se ingreso el operando y se mostrara el valor cargado.
		{
			printf("2.Ingresar 2do operando (%.2f)\n",numero2);
		}

		printf("3.Calcular todas las operaciones\n");

		printf("4.Informar resultados\n");

		printf("5.Salir");

		opcion = obtenerRango("\nELIJA UNA OPCION:\n","ERROR ingrese solo numeros:\n", 1, 5);//Si en la opcion se pusiera un numero mayor a 5 o menor a 1 se le avisara al usuario,lo mismo si pusiera letras.

		switch(opcion)
		{
			case 1:
				if(banderaPrimero == 0)
				{
					numero1 = obtenerNumeroFloat("Ingrese el primer operando:\n", "ERROR. ingrese solo numeros:\n");
					numeroFactorial1 = numero1;
					banderaPrimero = 1;
				}
				else
				{
					numero1 = obtenerNumeroFloat("Ingrese el primer operando:\n", "ERROR. ingrese solo numeros:\n");
					numeroFactorial1 = numero1;
				}
				break;
			case 2:
				if(banderaSegundo == 0)
				{
					numero2 = obtenerNumeroFloat("Ingrese el segundo operando:\n", "ERROR. ingrese solo numeros:\n");
					numeroFactorial2 = numero2;
					banderaSegundo = 1;
				}
				else
				{
					numero2 = obtenerNumeroFloat("Ingrese el segundo operando:\n", "ERROR. ingrese solo numeros:\n");
					numeroFactorial2 = numero2;
				}

				break;
			case 3:
				if(banderaPrimero !=0 && banderaSegundo !=0)//Al menos que ambas banderas sean distintas a cero no se podra realizar los calculos.
				{
					resultadoSuma = Sumar(numero1,numero2);
					resultadoResta = Resta(numero1,numero2);
					resultadoDivision = Division(numero1,numero2);
					resultadoMultiplicacion = Multiplicar(numero1,numero2);
					resultadoFactorial = CalcularFactorial(numeroFactorial1);
					resultadoFactorial2 = CalcularFactorial(numeroFactorial2);
					banderaTercero = 1;//Bandera utilizada para saber que se realizaron los calculos.
				}
				else//Se informa que para calcular se deben ingresar ambos operandos.
				{
					printf("Para resolver la suma se debe ingresar los 2 operando\n");
					printf("Para resolver la resta se debe ingresar los 2 operando\n");
					printf("Para resolver la division se debe ingresar los 2 operando\n");
					printf("Para resolver la multiplicacion se debe ingresar los 2 operando\n");
					printf("Para resolver el factorial se debe ingresar los 2 operando\n");
				}



				break;
			case 4:
				if(banderaTercero == 0)//Si la bandera es cero es porque aun no se realizaron los calculos, por lo tanto no se deberian mostrar los resultados.
				{
					printf("Para mostrar los resultados debe primero calcularlos\n");
				}
				else if(banderaPrimero !=0 && banderaSegundo !=0)//Al ser la tercera bandera distinta a cero,luego se pregunta si se ingresaron los 2 operando para mostrar los resultados.
				{
					printf("El resultado de la suma es  : %.1f\n", resultadoSuma);
					printf("El resultado de la resta es : %.1f\n", resultadoResta);
					if((numero1 == 0 && numero2 == 0) || (numero1 !=0 && numero2 == 0))//Se valida que no se puede dividir por cero.
					{
						printf("No se puede dividir por cero \n");
					}
					else
					{
						printf("El resultado de la division es : %.3f\n", resultadoDivision);
					}
					printf("El resultado de la multiplicaciòn es : %.2f\n", resultadoMultiplicacion);
					if(numeroFactorial1<0)//Si el factorial es negativo no se puede calcular.
					{
						printf("Error, no se puede calcular el  primer factorial porque ingreso un numero negativo\n");
					}
					else if(ValidacionFactorial(numeroFactorial1) !=0)//Se valida que el factorial no tenga comas o puntos.
					{
						printf("El resultado del primer factorial es : %.0f\n",resultadoFactorial);
					}
					else
					{
						printf("Error no puede calcularse el  segundo factorial dado que ingreso un numero con decimal \n");
					}
					if(numeroFactorial2<0)//Si el factorial es negativo no se puede calcular.
					{
						printf("Error, no se puede calcular el segundo factorial porque ingreso un numero negativo\n");
					}
					else if(ValidacionFactorial(numeroFactorial2) !=0)//Se valida que el factorial no tenga comas o puntos.
					{
						printf("El resultado del segundo factorial es : %.0f\n",resultadoFactorial2);
					}
					else
					{
						printf("\nError no puede calcularse el factorial dado que ingreso un numero con decimales \n");
					}
				}
				else
				{
					printf("Para mostrar los resultados se deben ingresar ambos operandos\n");
				}
				if(banderaTercero == 1)//Una vez mostrado los resultados, se setean las banderas.
				{
					banderaPrimero = 0;
					banderaSegundo = 0;
					banderaTercero = 0;
				}
				break;
			case 5:
				printf("Fin del programa. Hasta pronto.\nAutor: Gastòn Cano division 1f UTN \n");
				break;
		}

	}while(opcion !=5);

}




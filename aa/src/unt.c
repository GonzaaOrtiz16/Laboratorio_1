/*
 * unt.c
 *
 *  Created on: 14 abr. 2022
 *      Author: Sergio
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"


int pedirEntero(char mensaje[])
{
	int numeroIngresado;

	printf(mensaje);
	fflush(stdin);
	scanf("%d",&numeroIngresado);

	return numeroIngresado;
}
void precioVuelos(int* precioLatam, int* precioAerolineas, int opcion2)
{
	if(precioLatam!=NULL && precioAerolineas!=NULL)//Verifica que las variables de los punteros esten declaradas y no rompa el programa
	{
		if(opcion2==1)
		{
			printf("---------------------------------- \n");
			*precioLatam = pedirEntero("Ingrese precio de vuelo por LATAM: $");
		}
		else
		{
			printf("---------------------------------- \n");
			*precioAerolineas= pedirEntero("Ingrese precio de vuelo por Aerolineas: $");
		}
	}
}

float aumentoDescuento(char operacion, int numero, int aumento)
{
	float resultado;

	if(operacion=='a')//Verifica que operacion quiere realizar 'a'=aumento, 'd'=descuento
	{
		resultado= (float)numero*(1+(float)aumento/100);
	}
	else
	{
		resultado= (float)numero*(1-(float)aumento/100);
	}
	return resultado;
}
float conversionMoneda(int valorMoneda, float valorMoneda2, int valorAConvertir)
{
	float resultado;

	resultado= (valorAConvertir*valorMoneda2)/valorMoneda;

	return resultado;

}
float division(int numero, int numero2)
{
	float resultado;

	if(numero2!=0)//Descarta la division por 0
	{
		resultado=numero/numero2;
	}
	else
	{
		printf("ERROR: No es posible realizar esta operacio (Math error)");
	}
	return resultado;
}
int diferenciaPrecio(int numero1, int numero2)
{
	int resultado;

	if(numero1>numero2)//comprueba que valor es mayor para que la diferencia no quede en negativo
	{
		resultado=numero1-numero2;
	}
	else
	{
		resultado=numero2-numero1;
	}
	return resultado;
}
int validacion(int numero, int minimo, int maximo)
{

	while(numero<minimo || numero>maximo)
	{
		numero=pedirEntero("ERROR: Ingrese una opcion valida: ");
		/*printf("ERROR: Ingrese una opcion valida: ");
		scanf("%d",&numero);*/
	}
	return numero;
}

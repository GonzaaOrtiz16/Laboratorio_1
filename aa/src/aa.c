/*
 ============================================================================
 Name        : aa.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void)
{
	setbuf(stdout, NULL);

	int opcion;
	int kilometros;
	int opcion2;
	int precioLatam;
	int precioAerolineas;
	float tarjetaDebitoLatam;
	float tarjetaDebitoAerolineas;
	float tarjetaCreditoLatam;
	float tarjetaCreditoAerolineas;
	float bitcoinLatam;
	float bitcoinAerolineas;
	float precioKilometroLatam;
	float precioKilometroAerolineas;
	int diferenciaDePrecio;
	int bandera;

	kilometros=0;
	precioLatam=0;
	precioAerolineas=0;

	do
	{
		printf("------SELECCIONE UNA OPCION------ \n");
		printf("1. Ingresar kilometros.\n");
		printf("2. Ingresar precio de vuelo.\n");
		printf("3. Calcular costos.\n");
		printf("4. Informar resultados.\n");
		printf("5. Carga forzada de datos. \n");
		printf("6. Salir. \n");
		printf("--------------------------------- \n");
		printf("La opcion seleccionada es:");
		fflush(stdin);
		scanf("%d", &opcion);



		switch(opcion)
		{
			case 1:
				printf("---------------------------------- \n");
				kilometros = pedirEntero("Ingrese cantidad de kilometros. \n");
			break;

			case 2:
				do
				{
					printf("---------------------------------- \n");
					printf("1. Ingresar el precio de LATAM. ($%d)\n", precioLatam);
					printf("2. Ingresar precio de Aerolineas. ($%d)\n", precioAerolineas);
					printf("3. Volver.\n");
					printf("---------------------------------- \n");
					scanf("%d", &opcion2);
					opcion2=validacion(opcion2, 1, 3);
					if(opcion2==1 || opcion2==2)
					{
						precioVuelos(&precioLatam, &precioAerolineas, opcion2);
					}
				}while(opcion2!=3);
			break;

			case 3:
				if(kilometros!=0 && precioLatam!=0 && precioAerolineas!=0)
				{
					printf("Calculando costos...\n");
					tarjetaDebitoLatam=aumentoDescuento( 'd', precioLatam, 10);
					tarjetaDebitoAerolineas=aumentoDescuento('d', precioAerolineas, 10);
					tarjetaCreditoLatam=aumentoDescuento('a', precioLatam, 25);
					tarjetaCreditoAerolineas=aumentoDescuento('a', precioAerolineas, 25);
					bitcoinLatam=conversionMoneda(4606954.55, 1, precioLatam);
					bitcoinAerolineas=conversionMoneda(4606954.55, 1, precioAerolineas);
					precioKilometroLatam=division(precioLatam, kilometros);
					precioKilometroAerolineas=division(precioAerolineas, kilometros);
					diferenciaDePrecio= diferenciaPrecio(precioLatam, precioAerolineas);
					bandera=1;
					printf("PROCESO REALIZADO CON EXITO.\n");
				}
				else
				{
					printf("ERROR: Todavia no se cargaron los datos necesarios para realizar esta operacion.\n");
				}
			break;

			case 4:
				if(bandera==1)
				{
					printf("---------------------------------- \n");
					printf("\nKilometros ingresados: %dkm \n\n", kilometros);
					printf("Precio latam: $%d\n", precioLatam);
					printf("	Precio con tarjeta de debito: $%.2f \n",tarjetaDebitoLatam);
					printf("	Precio con tarjeta de credito: $%.2f \n", tarjetaCreditoLatam);
					printf("	Precio pagando con bitcoin: %fBTC \n", bitcoinLatam);
					printf("	El precio por kilometro es: $%.2f \n", precioKilometroLatam);
					printf("Precio Aerolineas: $%d\n", precioAerolineas);
					printf("	Precio con tarjeta de debito: $%.2f \n",tarjetaDebitoAerolineas);
					printf("	Precio con tarjeta de credito: $%.2f \n", tarjetaCreditoAerolineas);
					printf("	Precio pagando con bitcoin: %fBTC \n", bitcoinAerolineas);
					printf("	El precio por kilometro es: $%.2f \n", precioKilometroAerolineas);
					printf("La diferencia de precio es: $%d\n",diferenciaDePrecio);
				}
				else
				{
					printf("ERROR: Todavia no se calcularon los costos. \n");
				}
			break;

			case 5:
				kilometros=7090;
				precioAerolineas=162965;
				precioLatam=159339;
				tarjetaDebitoLatam=aumentoDescuento( 'd', precioLatam, 10);
				tarjetaDebitoAerolineas=aumentoDescuento('d', precioAerolineas, 10);
				tarjetaCreditoLatam=aumentoDescuento('a', precioLatam, 25);
				tarjetaCreditoAerolineas=aumentoDescuento('a', precioAerolineas, 25);
				bitcoinLatam=conversionMoneda(4606954.55, 1, precioLatam);
				bitcoinAerolineas=conversionMoneda(4606954.55, 1, precioAerolineas);
				precioKilometroLatam=division(precioLatam, kilometros);
				precioKilometroAerolineas=division(precioAerolineas, kilometros);
				diferenciaDePrecio= diferenciaPrecio(precioLatam, precioAerolineas);
				printf("---------------------------------- \n");
				printf("\nKilometros ingresados: %dkm \n\n", kilometros);
				printf("Precio latam: $%d\n", precioLatam);
				printf("	Precio con tarjeta de debito: $%.2f \n",tarjetaDebitoLatam);
				printf("	Precio con tarjeta de credito: $%.2f \n", tarjetaCreditoLatam);
				printf("	Precio pagando con bitcoin: %fBTC \n", bitcoinLatam);
				printf("	El precio por kilometro es: $%.2f \n", precioKilometroLatam);
				printf("Precio Aerolineas: $%d\n", precioAerolineas);
				printf("	Precio con tarjeta de debito: $%.2f \n",tarjetaDebitoAerolineas);
				printf("	Precio con tarjeta de credito: $%.2f \n", tarjetaCreditoAerolineas);
				printf("	Precio pagando con bitcoin: %fBTC \n", bitcoinAerolineas);
				printf("	El precio por kilometro es: $%.2f \n", precioKilometroAerolineas);
				printf("La diferencia de precio es: $%d\n",diferenciaDePrecio);

			break;
			default:
				if(opcion>6)
				{


					printf("---------------------------------- \n");
					printf("ERROR: Ingrese una opcion valida\n");
					printf("---------------------------------- \n");
				}
			break;


		}

	}while(opcion!=6);

	printf("------- Gracias por confiar en nosotros :) ------- ");

	return EXIT_SUCCESS;
}

/*
 ============================================================================
 Name        : TrabajoPractico.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Tp2.h"
#define TAM 2000

int main(void)
{
	setbuf(stdout, NULL);
	int opcion;
	int index;
	int banderaAlta;

	banderaAlta=0;

	sPasajero listaPasajero[TAM];
	for(int i=0; i<TAM;i++)
	{
		listaPasajero[i].estado=0;
	}





	do
	{
		printf("1. ALTA\n");
		printf("2. MODIFICAR\n");
		printf("3. BAJA\n");
		printf("4. INFORMAR\n");
		printf("5. CARGA FORZADA\n");
		printf("6. SALIR\n");
		scanf("%d",&opcion);

		switch(opcion)
		{
		case 1:
			   index= cargarEnLista(listaPasajero, TAM);
			   switch(index)
				{
					case -1:
						printf("No hay espacio disponible\n");
					break;

					default:
						printf("\nLa carga se realizó con éxito en la posición %d\n", index);
						banderaAlta=1;
					break;
				}

			break;
		case 2:
			if(banderaAlta==0)
			{
				printf("\n ERROR \n");
				printf("Todavia no se ingreso ninguno pasajero");
			}
			else
			{
				modificar(listaPasajero, TAM);
			}

			break;
		case 3:
			if(banderaAlta==0)
			{
				printf("\n ERROR \n");
				printf("Todavia no se ingreso ninguno pasajero");
			}
			else
			{
				DarDeBaja(listaPasajero,TAM);
			}

			break;
		case 4:
			if(banderaAlta==0)
			{
				printf("\n ERROR \n");
				printf("Todavia no se ingreso ninguno pasajero");
			}
			else
			{
				mostrar(listaPasajero, TAM);
			}

			break;
		case 5:
			harcodear(listaPasajero,TAM);
			banderaAlta=1;
			break;
		case 6:
			printf("Adios :)");
			break;
		default:
			printf("ERROR: opcion incorrecta.\n");
			break;
		}

		}while(opcion!=6);

	return EXIT_SUCCESS;
}

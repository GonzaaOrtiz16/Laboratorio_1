/*
 * Tp2.c
 *
 *  Created on: 2 may. 2022
 *      Author: Pc Gonza
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Validaciones.h"
#include "Tp2.h"
#include "Inputs.h"
#define VACIO 0
#define LLENO 1
#define sizeTipoPasajero 4
#define sizeEstadoDeVuelo 3
#define sizeCodigoDeVuelo 5

static int idIncremental=999;
static sTipoPasajero listaTipoPasajero[sizeTipoPasajero]={{1,"Clase Economica"},
														{2,"Clase Economica Premium"},
														{3,"Clase Ejecutiva"},
														{4,"Primera Clase"}};

static sEstadoDeVuelo listaEstadoDeVuelo[sizeEstadoDeVuelo]={{1,"Activo"},
															{2,"Demorado"},
															{3,"Reprogramado"}};

static sCodigoDevuelo listaCodigoDeVuelo[sizeCodigoDeVuelo]={{"JAG504", "Iguazu(Aerolineas)",1},
															{"FHZ896", "Bariloche(LATAM)",2},
															{"UOM679", "Cordoba(Aerolineas)",1},
															{"EMG852", "Orlando(American Airlines)",1},
															{"CMA915", "Mendoza(Flybondi)",3}};

int generadorId()
{

	idIncremental++;

	return idIncremental;
}

sPasajero IngresarPasajero()
{
	sPasajero unPasajero;
	int auxiliar;
	auxiliar=-1;



	unPasajero.id=generadorId();

	PedirCadena(unPasajero.nombre, "Ingrese Nombre:\n");
	/*printf("Ingrese nombre: \n");
	scanf("%s",unPasajero.nombre);*/
	PedirCadena(unPasajero.apellido,"Ingrese Apellido: \n" );
	/*printf("Ingrese Apellido: \n");
	scanf("%s", unPasajero.apellido);*/
	unPasajero.precio=PedirFlotante("Ingrese precio: \n");
	/*printf("Ingrese precio: \n");
	fflush(stdin);
	scanf("%f",&unPasajero.precio);*/
	mostrarCodigoDeVuelo();
	//PedirCadena(unPasajero.codigoVuelo,"Ingrese codigo de vuelo:\n" );
	printf("Ingrese codigo de vuelo:\n");
	scanf("%s",unPasajero.codigoVuelo);
	//ValidarCodigoDeVuelo(unPasajero.codigoVuelo,unPasajero.codigoVuelo, listaCodigoDeVuelo, sizeCodigoDeVuelo);
	while(auxiliar==-1||auxiliar==1)
	{

		for(int i=0; i<sizeCodigoDeVuelo;i++)
		{

			auxiliar=strcmp(unPasajero.codigoVuelo,listaCodigoDeVuelo[i].codigoDeVuelo);
			if(auxiliar==0)
			{
				break;
			}

		}
		if(auxiliar==0)
		{

			break;
		}

			printf("____________________________________________________________________\n");
			printf("\nERROR!\n"
					"Ingrese un codigo de vuelo valido\n");
			printf("____________________________________________________________________\n");
			mostrarCodigoDeVuelo();

			printf("Ingrese codigo de vuelo:\n");
			scanf("%s",unPasajero.codigoVuelo);



	}


	mostrarTipoPasajero();
	unPasajero.idTipoPasajero=PedirEntero("Ingrese su tipo de pasasjero:");

	unPasajero.estado=LLENO;

	return unPasajero;

}

int buscarLibre(sPasajero lista[], int size)
{
	int index;
	index=-1;
	for(int i=0; i<size; i++)
	{
		if(lista[i].estado==VACIO)
		{
			index=i;
			break;
		}
	}

	return index;
}
int cargarEnLista(sPasajero lista[], int size)
{
	int index;

	index=buscarLibre(lista, size);

	if(index!=-1)
	{
		lista[index] = IngresarPasajero();
	}

	return index;
}

void mostrarTipoPasajero()
{
	for(int i=0; i<sizeTipoPasajero;i++)
	{
		printf("%d. %s\n",listaTipoPasajero[i].idTipoPasajero,
						listaTipoPasajero[i].descripcion);
	}
}
void mostrarCodigoDeVuelo()
{
	int index;
	char *titulo[]={"Codigo de vuelo","Destino","Estado de vuelo"};

	printf("%*s|| %*s|| %*s\n",-16, titulo[0],-26, titulo[1],-10, titulo[2]);
	printf("____________________________________________________________________\n");
	for(int i=0;i<sizeCodigoDeVuelo;i++)
	{
		index=CompararIdEstado(listaCodigoDeVuelo[i]);

		printf("%-16s|| %-26s|| %-5s\n",listaCodigoDeVuelo[i].codigoDeVuelo,
								listaCodigoDeVuelo[i].descripcion,
								listaEstadoDeVuelo[index].descripcion);
	}
}
int CompararIdEstado(sCodigoDevuelo lista)
{
	int index;

	for(int i=0; i<sizeEstadoDeVuelo;i++)
	{
		if(lista.idEstadoDeVuelo==listaEstadoDeVuelo[i].idEstadoDeVuelo)
		{
			index=i;
		}
	}
	return index;
}
void mostrarEstadoDeVuelo()
{
	for(int i=0;i<sizeEstadoDeVuelo; i++)
	{
		printf("%d. %s", listaEstadoDeVuelo[i].idEstadoDeVuelo,listaEstadoDeVuelo[i].descripcion);
	}

}
int buscarLlenos(sPasajero listaPasajeros[],int sizeListaPasajeros)
{
	int retorno;

	retorno=0;

	for(int i=0;i<sizeListaPasajeros;i++)
	{
		if(listaPasajeros[i].estado==LLENO)
		{
			retorno=1;
		}
	}
	return retorno;
}
void mostrarLista(sPasajero listaPasajeros[], int sizeListaPasajeros)
{
	int indexTipoPasajero;
	int indexCodigoVuelo;
	int indexEstado;
	int pasajeroLleno;

	pasajeroLleno=buscarLlenos(listaPasajeros, sizeListaPasajeros);

	if(pasajeroLleno==1)
	{
		char *titulo[]={"Numero de ID","Nombre","Apellido","Precio","Tipo de pasajero","Codigo de vuelo", "Destino", "Estado de vuelo"};
		printf("%-10s || %-10s || %-10s || %-10s || %-10s || %-10s || %-10s || %-10s \n",titulo[0],titulo[1],titulo[2],titulo[3],
																						titulo[4],titulo[5], titulo[6], titulo[7]);
		for(int i=0; i<sizeListaPasajeros;i++)
		{
			if(listaPasajeros[i].estado==LLENO)
			{
				indexTipoPasajero=BuscarTipoPasajero(listaPasajeros[i]);
				indexCodigoVuelo=BuscarCodigoDeVuelo(listaPasajeros[i]);
				indexEstado=CompararIdEstado(listaCodigoDeVuelo[indexCodigoVuelo]);
				MostrarUnPasajero(listaPasajeros[i], listaTipoPasajero[indexTipoPasajero], listaCodigoDeVuelo[indexCodigoVuelo],
								listaEstadoDeVuelo[indexEstado]);

			}

		}
	}
	else
	{
		printf("No hay ningun pasajero en lista.\n");
	}



}
void MostrarUnPasajero(sPasajero unPasajero, sTipoPasajero tipoPasajero, sCodigoDevuelo codigoDeVuelo, sEstadoDeVuelo estadoVuelo)
{
	printf("%-10d || %-10s || %-10s || %-10f || %-10s || %-10s || %-10s || %-10s\n",
															unPasajero.id, unPasajero.nombre, unPasajero.apellido,
															unPasajero.precio, tipoPasajero.descripcion,
															codigoDeVuelo.codigoDeVuelo, codigoDeVuelo.descripcion,
															estadoVuelo.descripcion);
}
int BuscarCodigoDeVuelo(sPasajero unPasajero)
{
	int index;
	int auxiliar;

		for(int i=0; i<sizeCodigoDeVuelo;i++)
		{
			auxiliar=strcmp(unPasajero.codigoVuelo,listaCodigoDeVuelo[i].codigoDeVuelo);
			if(auxiliar==0)
			{
				index=i;
				break;
			}

		}
	return index;
}
int BuscarTipoPasajero(sPasajero unPasajero)
{
	int index;
		for(int i=0;i<sizeTipoPasajero; i++)
		{
			if(unPasajero.idTipoPasajero==listaTipoPasajero[i].idTipoPasajero)
			{
				index=i;
				break;
			}
		}
	return index;
}
void modificar(sPasajero listaPasajeros[],int sizeListaPasajeros)
{
	int idIngresado;
	int indexId;
	int opcion;
	sPasajero auxiliar;
	char respuesta;

	mostrarLista(listaPasajeros, sizeListaPasajeros);
	printf("Ingrese id de persona que quiere modificar\n");
	scanf("%d",&idIngresado);
	indexId=BuscarPorId(listaPasajeros, sizeListaPasajeros, idIngresado);
	if(indexId==-1)
	{
		printf("\n ERROR \n");
		mostrarLista(listaPasajeros, sizeListaPasajeros);
		printf("Ingrese id de persona que quiere modificar.\n");
		scanf("%d",&idIngresado);
		indexId=BuscarPorId(listaPasajeros, sizeListaPasajeros, idIngresado);

	}
	else
	{
		printf("Usuario encontrado con exito.\n");
	}
	do
	{
		printf("Ingrese que desea modificar:\n");
		printf("1. Nombre [%s]\n",listaPasajeros[indexId].nombre);
		printf("2. Apellido [%s]\n",listaPasajeros[indexId].apellido);
		printf("3. Precio [%f]\n", listaPasajeros[indexId].precio);
		printf("4. Tipo de Pasajero [%s] \n",listaTipoPasajero[BuscarTipoPasajero(listaPasajeros[indexId])].descripcion);
		printf("5. Codigo de Vuelo [%s] \n",listaPasajeros[indexId].codigoVuelo);
		printf("6. Salir.");
		fflush(stdin);
		scanf("%d",&opcion);

		switch(opcion)
		{
			case 1:
				PedirCadena(auxiliar.nombre, "Ingrese Nombre:\n");
				respuesta=Confirmacion("¿Desea cambiar el nombre?\n");
				if(respuesta=='s')
				{
					strcpy(listaPasajeros[indexId].nombre,auxiliar.nombre);
					printf("Cambio de nombre realizado con exito.\n");
				}
				else
				{
					printf("Cancelacion exitosa.\n");
				}

			break;

			case 2:
				PedirCadena(auxiliar.apellido, "Ingrese apellio:\n");
				respuesta=Confirmacion("¿Desea cambiar apellido?\n");
				if(respuesta=='s')
				{
					strcpy(listaPasajeros[indexId].apellido,auxiliar.apellido);
					printf("Cambio de apellido realizado con exito.\n");
				}
				else
				{
					printf("Cancelacion exitosa.\n");
				}

			break;

			case 3:
				auxiliar.precio=PedirFlotante("Ingrese precio.\n");
				respuesta=Confirmacion("¿Desea cambiar precio?\n");
				if(respuesta=='s')
				{
					listaPasajeros[indexId].precio=auxiliar.precio;
					printf("Cambio de precio realizado con exito\n");
				}
				else
				{
					printf("Cancelacion exitosa.\n");
				}


			break;

			case 4:
				mostrarTipoPasajero();
				auxiliar.idTipoPasajero=PedirEntero("Ingrese tipo de pasajero.\n");
				respuesta=Confirmacion("¿Desea cambiar el tipo de pasajero?\n");
				if(respuesta=='s')
				{
					listaPasajeros[indexId].idTipoPasajero=auxiliar.idTipoPasajero;
					printf("Cambio de precio realizado con exito.\n");
				}
				else
				{
					printf("Cancelacion exitosa.\n");
				}

			break;

			case 5:
				mostrarCodigoDeVuelo();
				printf("Ingrese codigo de vuelo:\n");
				scanf("%s",auxiliar.codigoVuelo);
				respuesta=Confirmacion("¿Desea cambiar codigo de vuelo?\n");
				if(respuesta=='s')
				{
					strcpy(listaPasajeros[indexId].codigoVuelo,auxiliar.codigoVuelo);
					printf("Cambio de codigo de vuelo realizado con exito.\n");
				}
				else
				{
					printf("Cancelacion exitosa.\n");
				}

			break;

			case 6:
			break;

			default:
				printf("Opcion incorrecta.\n");
			break;
		}

	}while(opcion!=6);
}
int BuscarPorId(sPasajero listaPasajero[],int sizePasajeros, int idIngresado)
{
	int index;
	index=-1;

	for(int i=0;i<sizePasajeros;i++)
	{
		if(idIngresado==listaPasajero[i].id)
		{
			index=i;
			break;
		}
	}
	return index;
}
char Confirmacion(char mensaje[])
{
	char respuesta;

	printf(mensaje);
	scanf("%c",&respuesta);

	while(respuesta!='s'&& respuesta!='n')
	{
		printf("\n ERROR: Ingrese opcion correcta (s/n)\n");
		printf(mensaje);
		scanf("%c",&respuesta);
	}
	return respuesta;
}
void DarDeBaja(sPasajero listaPasajeros[], int sizeListaPasajeros)
{
	int indexId;
	int idIngresado;
	char respuesta;
	int pasajeroLleno;

	pasajeroLleno=buscarLlenos(listaPasajeros, sizeListaPasajeros);

	if(pasajeroLleno==1)
	{
		mostrarLista(listaPasajeros, sizeListaPasajeros);
		printf("Ingrese id de persona que quiere dar de baja.\n");
		scanf("%d",&idIngresado);
		indexId=BuscarPorId(listaPasajeros, sizeListaPasajeros, idIngresado);
		if(indexId==-1)
		{
			printf("\n ERROR \n");
			printf("Id ingresado incorrecto.\n");
			mostrarLista(listaPasajeros, sizeListaPasajeros);
			printf("Ingrese id de persona que quiere modificar");
			scanf("%d",&idIngresado);
			indexId=BuscarPorId(listaPasajeros, sizeListaPasajeros, idIngresado);

		}
		else
		{
			printf("Usuario encontrado con exito.\n");
		}

		mostrarDatosPasajero(listaPasajeros[indexId]);
		respuesta=Confirmacion("\n¿Desea eliminar el usurio selecionado?");
		if(respuesta=='s')
		{
			listaPasajeros[indexId].estado=VACIO;
			printf("Usuario eliminado con exito,\n");
		}
		else
		{
			printf("Operacion cancelada.\n");
		}

	}
	else
	{
		printf("No hay ningun pasajero cargado en lista.\n");
	}

}
void mostrarDatosPasajero(sPasajero unPasajero)
{
	printf("%d %s %s",unPasajero.id,unPasajero.nombre, unPasajero.apellido);
}
void mostrar(sPasajero listaPasajeros[], int sizeListaPasajeros)
{
	int opcion;
	int opcion2;
	int opcion3;

	do
	{
		printf("1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.\n");
		printf("2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.\n");
		printf("3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’\n");
		printf("4. Volver.");
		fflush(stdin);
		scanf("%d",&opcion);

		switch(opcion)
		{
			case 1:
				printf("1. Ordenar de forma ascendente.");
				printf("2. Ordenar de forma descendente");
				scanf("%d", &opcion2);
				OrdenarListaAlfabeticamente(listaPasajeros, sizeListaPasajeros, opcion2);
				mostrarLista(listaPasajeros, sizeListaPasajeros);
			break;

			case 2:
				PromediosPrecios(listaPasajeros, sizeListaPasajeros);
			break;

			case 3:
				printf("1. Ordenar de forma ascendente.");
				printf("2. Ordenar de forma descendente");
				scanf("%d",&opcion3);
				OrdenarPorCodigoDeVuelo(listaPasajeros, sizeListaPasajeros, opcion3);
				mostrarLista(listaPasajeros, sizeListaPasajeros);
				break;

			case 4:

				break;

			default:
				printf("Opcion incorrecta.\n");
				break;

		}
	}while(opcion!=4);
}
void PromediosPrecios(sPasajero listaPasajeros[], int sizeListaPasajeros)
{
	float acumulador;
	int contador;
	float promedio;

	acumulador=0;
	contador=0;

	for(int i=0;i<sizeListaPasajeros;i++)
	{
		if(listaPasajeros[i].estado==LLENO)
		{
			acumulador=acumulador+listaPasajeros[i].precio;
			contador++;
		}

	}
	promedio=acumulador/contador;
	printf("El total de ingresos es %f y el promedio es %f",acumulador,promedio);
}
void OrdenarListaAlfabeticamente(sPasajero listaPasajeros[], int sizeListaPasajeros, int opcion)
{


	if(opcion==1)
	{
		AlfabeticamenteAscendente(listaPasajeros, sizeListaPasajeros);

	}
	if(opcion==2)
	{
		AlfabeticamenteDescendente(listaPasajeros, sizeListaPasajeros);
	}


}
void AlfabeticamenteAscendente(sPasajero listaPasajeros[], int sizeListaPasajeros)
{
	sPasajero auxiliar;

	for(int i=0;i<sizeListaPasajeros; i++)
			{
				for(int j=i+1;j<sizeListaPasajeros;i++)
				{
					if((strcmp(listaPasajeros[i].apellido,listaPasajeros[j].apellido))>0)
					{
						auxiliar=listaPasajeros[i];
						listaPasajeros[i]=listaPasajeros[j];
						listaPasajeros[j]=auxiliar;
					}
					if((strcmp(listaPasajeros[i].apellido,listaPasajeros[j].apellido))==0)
					{
						if(listaPasajeros[i].idTipoPasajero>listaPasajeros[j].idTipoPasajero)
						{
							auxiliar=listaPasajeros[i];
							listaPasajeros[i]=listaPasajeros[j];
							listaPasajeros[j]=auxiliar;

						}
					}

				}
			}
}
void AlfabeticamenteDescendente(sPasajero listaPasajeros[], int sizeListaPasajeros)
{
	sPasajero auxiliar;

	for(int i=0;i<sizeListaPasajeros; i++)
	{
		for(int j=i+1;j<sizeListaPasajeros;i++)
		{
			if((strcmp(listaPasajeros[i].apellido,listaPasajeros[j].apellido))<0)
			{
				auxiliar=listaPasajeros[i];
				listaPasajeros[i]=listaPasajeros[j];
				listaPasajeros[j]=auxiliar;
			}
			if((strcmp(listaPasajeros[i].apellido,listaPasajeros[j].apellido))==0)
			{
				if(listaPasajeros[i].idTipoPasajero<listaPasajeros[j].idTipoPasajero)
				{
					auxiliar=listaPasajeros[i];
					listaPasajeros[i]=listaPasajeros[j];
					listaPasajeros[j]=auxiliar;

				}
			}

		}
	}
}
void OrdenarPorCodigoDeVuelo(sPasajero listaPasajeros[], int sizeListaPasajeros, int opcion)
{
	if(opcion==1)
		{
			codigoDeVueloAscendente(listaPasajeros, sizeListaPasajeros);

		}
		if(opcion==2)
		{
			codigoDeVueloDescendente(listaPasajeros, sizeListaPasajeros);
		}
}
void codigoDeVueloAscendente(sPasajero listaPasajeros[], int sizeListaPasajeros)
{
	sPasajero auxiliar;

		for(int i=0;i<sizeListaPasajeros; i++)
		{
			for(int j=i+1;j<sizeListaPasajeros;i++)
			{
				if((strcmp(listaPasajeros[i].codigoVuelo,listaPasajeros[j].codigoVuelo))>0)
				{
					auxiliar=listaPasajeros[i];
					listaPasajeros[i]=listaPasajeros[j];
					listaPasajeros[j]=auxiliar;
				}
			}
		}
}
void codigoDeVueloDescendente(sPasajero listaPasajeros[], int sizeListaPasajeros)
{
	sPasajero auxiliar;

	for(int i=0;i<sizeListaPasajeros; i++)
	{
		for(int j=i+1;j<sizeListaPasajeros;i++)
		{
			if((strcmp(listaPasajeros[i].codigoVuelo,listaPasajeros[j].codigoVuelo))<0)
			{
				auxiliar=listaPasajeros[i];
				listaPasajeros[i]=listaPasajeros[j];
				listaPasajeros[j]=auxiliar;
			}
		}
	}
}
void harcodear(sPasajero listaPasajeros[],int sizeListaPasajeros)
{
	sPasajero listaHarcodeo[5]={{generadorId(),"Gonzalo","Ortiz",14089,"JAG504",2,1 },
			{generadorId(),"Julieta","Giusti",50477, "FHZ896",3,2},
			{generadorId(),"Marisa","Videla", 3000, "UOM679",2,2},
			{generadorId(),"Sergio","Ortiz", 2304, "EMG852",1,1},
			{generadorId(),"Ronan", "Videla", 32340,"CMA915",3,1}};

	int index;
	for(int i=0;i<sizeListaPasajeros;i++)
	{
		index=buscarLibre(listaPasajeros, sizeListaPasajeros);
		if(index!=-1)
		{
			listaPasajeros[index]=listaHarcodeo[i];
			listaPasajeros[index].estado=LLENO;
		}
	}
}
/*char ConfirmarNumero(char mensaje[])
{
	char respuesta;

	printf(mensaje);
	scanf("%c",&respuesta);

	while(respuesta!='s'&& respuesta!='n')
	{
		printf("\n ERROR: Ingrese opcion correcta \n");
		printf(mensaje);
		scanf("%c",&respuesta);
	}
	return respuesta;

}*/





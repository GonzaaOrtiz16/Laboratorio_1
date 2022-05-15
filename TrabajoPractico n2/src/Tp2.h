/*
 * Tp2.h
 *
 *  Created on: 2 may. 2022
 *      Author: Pc Gonza
 */

#ifndef TP2_H_
#define TP2_H_

typedef struct
{
	int id;
	char nombre[51];
	char apellido[51];
	float precio;
	char codigoVuelo[10];
	int idTipoPasajero;
	int idEstadoVuelo;
	int estado;

}sPasajero;

typedef struct
{
	int idEstadoDeVuelo;
	char descripcion[20];

}sEstadoDeVuelo;

typedef struct
{
	int idTipoPasajero;
	char descripcion[50];

}sTipoPasajero;

typedef struct
{
	char codigoDeVuelo[10];
	char descripcion[50];
	char idEstadoDeVuelo;

}sCodigoDevuelo;

int cargarEnLista(sPasajero lista[], int size);
int buscarLibre(sPasajero lista[], int size);
sPasajero IngresarPasajero();
int generadorId();
void mostrarEstadoDeVuelo();
int CompararIdEstado(sCodigoDevuelo lista);
void mostrarCodigoDeVuelo();
void mostrarTipoPasajero();
void mostrarLista(sPasajero listaPasajeros[], int sizeListaPasajeros);
void MostrarUnPasajero(sPasajero unPasajero, sTipoPasajero tipoPasajero, sCodigoDevuelo codigoDeVuelo, sEstadoDeVuelo estadoVuelo);
int BuscarCodigoDeVuelo(sPasajero unPasajero);
int BuscarTipoPasajero(sPasajero unPasajero);
int BuscarPorId(sPasajero listaPasajero[],int sizePasajeros, int idIngresado);
char Confirmacion(char mensaje[]);
void mostrarDatosPasajero(sPasajero unPasajero);
void DarDeBaja(sPasajero listaPasajeros[], int sizeListaPasajeros);
void modificar(sPasajero listaPasajeros[],int sizeListaPasajeros);
void AlfabeticamenteDescendente(sPasajero listaPasajeros[], int sizeListaPasajeros);
void AlfabeticamenteAscendente(sPasajero listaPasajeros[], int sizeListaPasajeros);
void OrdenarListaAlfabeticamente(sPasajero listaPasajeros[], int sizeListaPasajeros, int opcion);
void AlfabeticamenteDescendente(sPasajero listaPasajeros[], int sizeListaPasajeros);
void AlfabeticamenteAscendente(sPasajero listaPasajeros[], int sizeListaPasajeros);
void OrdenarPorCodigoDeVuelo(sPasajero listaPasajeros[], int sizeListaPasajeros, int opcion);
void codigoDeVueloAscendente(sPasajero listaPasajeros[], int sizeListaPasajeros);
void codigoDeVueloDescendente(sPasajero listaPasajeros[], int sizeListaPasajeros);
void harcodear(sPasajero listaPasajeros[],int sizeListaPasajeros);
void mostrar(sPasajero listaPasajeros[], int sizeListaPasajeros);
void PromediosPrecios(sPasajero listaPasajeros[], int sizeListaPasajeros);






#endif /* TP2_H_ */

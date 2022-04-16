/*
 * utn.h
 *
 *  Created on: 14 abr. 2022
 *      Author: Sergio
 */

#ifndef UTN_H_
#define UTN_H_

void precioVuelos(int* , int* , int );
/// \ brief Llama a la funcion pedir entero y ese valor lo guarda en el espacio de memoria que elija el usuario
/// \ param Recibe dos espacios de memoria para guardar los valores ingresados y la opcion elegida por el usuario
/// \return No retorna ningun valor por return
int pedirEntero(char mensaje[]);
/// \ brief Sirve para pedir numeros enteros
/// \ param Recibe una cadena de caracteres para mostrar por pantalla
/// \return Retorna el valor ingresado por el usuario
float aumentoDescuento(char, int, int);
/// \ brief Reliza un aumento o descuento segun el char que reciba por parametro
/// \ param Recibe la un char para indicar la operacio a realizar, el numero al cual realizar la opercion y el porcentaje de descuento o aumento
/// \return Retorna el valor obtenido
float conversionMoneda(int, float, int);
/// \ brief Realiza una regla de 3 simple para convertir valores
/// \ param Recibe la cantidad que quiero convertir y la relacion entre los valores standar
/// \return Retorna el valor obtendo
float division(int, int);
/// \ brief Divide
/// \ param Los dos valores
/// \return El valor obtenido
int diferenciaPrecio(int, int);
/// \ brief Realiza una resta o diferencia (numero mas grande menos numero mas chico)
/// \ param Recibe los dos valores a relizar la diferencia
/// \return Retorna el valor obtenido
int validacion(int numero, int minimo, int maximo);
/// \ brief Realiza una validacion de lo que ingresa el usuario
/// \ param Recibe el valor que ingresa el usuario y entre que valores tiene que estar
/// \return Retorna el nuevo valor que ingresa el usuario


#endif /* UTN_H_ */

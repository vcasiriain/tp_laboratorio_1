#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define BITCOIN 4606954.55

/** \brief funcion de menu para mostrar y pedir datos
 */
void menu();

/*****VALIDACIONES*****/

/** \brief funcion para pedir kilometros
 *
 * \param recibe la cantidad km
 * \return float devuelve la cantidad de km
 *
 */
float validacionKilometros();

/** \brief funcion para pedir precio de Aerolineas Argentinas
 *
 * \param recibe el precio
 * \return float devuelve el precio
 *
 */
float validacionAA();

/** \brief funcion para pedir precio de Latam
 *
 * \param recibe el precio
 * \return float devuelve el precio
 *
 */
float validacionL();

/*****CALCULOS*****/

/** \brief funcion para hacer descuento con debito en Aerolineas Argentinas
 *
 * \param recibe el precio de Areolineas Argentinas
 * \return float devuelve el precio final con descuento
 *
 */
float descuentoDebAA(float precioAA);

/** \brief funcion para hacer descuento con debito en Aerolineas Argentinas
 *
 * \param recibe el precio de Areolineas Argentinas
 * \return float devuelve el precio final con descuento
 *
 */
float descuentoCredAA(float precioAA);

/** \brief funcion para hacer calcular precio en Aerolineas Argentinas pagando en bitcoin
 *
 * \param recibe el precio de Areolineas Argentinas
 * \return float devuelve el precio final en bitcoin
 *
 */
float bitcoinAA(float precioAA);

/** \brief funcion para calcular el precio por km de Aerolineas Argentinas
 *
 * \param recibe el precio de Areolineas Argentinas
 * \return float devuelve el precio por km
 *
 */
float precioXkmAA(float precioAA, float km);

/** \brief funcion para hacer descuento con debito de Latam
 *
 * \param recibe el precio de Latam
 * \return float devuelve el precio final con descuento
 *
 */
float descuentoDebL(float precioL);

/** \brief funcion para hacer descuento con credito de Latam
 *
 * \param recibe el precio de Latam
 * \return float devuelve el precio final con descuento
 *
 */
float descuentoCredL(float precioL);

/** \brief funcion para hacer calcular precio en Latam pagando en bitcoin
 *
 * \param recibe el precio de Latam
 * \return float devuelve el precio final en bitcoin
 *
 */
float bitcoinL(float precioL);

/** \brief funcion para calcular el precio por km de Latam
 *
 * \param recibe el precio de Latam
 * \return float devuelve el precio por km
 *
 */
float precioXkmL(float precioL, float km);

/** \brief funcion para hacer calcular la diferencia de precios
 *
 * \param recibe el precio de Areolineas Argentinas y Latam
 * \return float devuelve la diferencia de precio
 *
 */
float diferencia(float precioAA, float precioL);

/*****MOSTRAR RESULTADOS*****/

/** \brief funcion para mostrar los resultados
 *
 * \param toma los resultados
 * \return devuelve los resultados con mensajes
 *
 */

void mostrarResultados(float km,float precioAA,float finalDebitoAA,float finalCreditoAA,float finalBitcoinAA,float finalPrecioXkmAA,
                       float precioL,float finalDebitoL,float finalCreditoL,float finalBitcoinL,float finalPrecioXkmL,
                       float finalDiferencia);

#endif /* FUNCIONES_H_ */

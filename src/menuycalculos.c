#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funciones.h"
#define BITCOIN 4606954.55

/*****VALIDACIONES*****/

float validacionKilometros()
{
    float km = 0;

    printf("\nIngrese kilometros: ");
    fflush(stdin);
    scanf("%f", &km);

    while(!(km > 0))
    {
        printf("\nError. Ingrese kilometros nuevamente: ");
        fflush(stdin);
        scanf("%f", &km);
    }

    return km;
}
float validacionAA()
{
    float precioAA = 0;

    printf("\nIngrese precio Aerolineas Argentinas: ");
    fflush(stdin);
    scanf("%f", &precioAA);

    while(!(precioAA > 0))
    {
        printf("\nError. Ingrese precio Aerolineas Argentinas nuevamente: ");
        fflush(stdin);
        scanf("%f", &precioAA);
    }

    return precioAA;
}
float validacionL()
{
    float precioL = 0;

    printf("\nIngrese precio Latam: ");
    fflush(stdin);
    scanf("%f", &precioL);

    while(!(precioL > 0))
    {
        printf("\nError. Ingrese precio Latam nuevamente: ");
        fflush(stdin);
        scanf("%f", &precioL);
    }

    return precioL;
}

/*****CALCULOS*****/

float descuentoDebAA(float precioAA)
{
    float descuentoDebitoAA = 0;
    float finalDebitoAA = 0;

    descuentoDebitoAA = precioAA * 10 / 100;
    finalDebitoAA = precioAA - descuentoDebitoAA;

    return finalDebitoAA;
}
float descuentoCredAA(float precioAA)
{
    float descuentoCreditoAA = 0;
    float finalCreditoAA = 0;

    descuentoCreditoAA = precioAA * 25 / 100;
    finalCreditoAA = precioAA - descuentoCreditoAA;

    return finalCreditoAA;
}
float bitcoinAA(float precioAA)
{
    float finalBitcoinAA;

    finalBitcoinAA = precioAA / BITCOIN;

    return finalBitcoinAA;
}
float precioXkmAA(float precioAA, float km)
{
    float finalPrecioXkmAA = 0;

    finalPrecioXkmAA = precioAA / km;

    return finalPrecioXkmAA;
}
float descuentoDebL(float precioL)
{
    float descuentoDebitoL = 0;
    float finalDebitoL = 0;

    descuentoDebitoL = precioL * 10 / 100;
    finalDebitoL = precioL - descuentoDebitoL;

    return finalDebitoL;
}
float descuentoCredL(float precioL)
{
    float descuentoCreditoL = 0;
    float finalCreditoL = 0;

    descuentoCreditoL = precioL * 25 / 100;
    finalCreditoL = precioL - descuentoCreditoL;

    return finalCreditoL;
}
float bitcoinL(float precioL)
{
    float finalBitcoinL = 0;

    finalBitcoinL = precioL / BITCOIN;

    return finalBitcoinL;
}
float precioXkmL(float precioL, float km)
{
    float finalPrecioXkmL = 0;

    finalPrecioXkmL = precioL / km;

    return finalPrecioXkmL;
}
float diferencia(float precioAA, float precioL)
{
    float finalDiferencia = 0;

    if(precioAA > precioL)
    {
        finalDiferencia = precioAA - precioL;
    }
    else
    {
        finalDiferencia = precioL - precioAA;
    }

    return finalDiferencia;
}

/*****MOSTRAR RESULTADOS*****/

void mostrarResultados(float km,float precioAA,float finalDebitoAA,float finalCreditoAA,float finalBitcoinAA,float finalPrecioXkmAA,
                       float precioL,float finalDebitoL,float finalCreditoL,float finalBitcoinL,float finalPrecioXkmL,
                       float finalDiferencia)
{

    if(precioAA <= 0 || precioL <= 0 || km <= 0)
    {
        printf("\nNo se ingresaron todos los precios o km para calcular\n");
    }
    else
    {
        printf("\nKilometros ingresados: %.2f\n",km);

        printf("\nPrecio Aerolineas Argentinas: $%.2f\n",precioAA);

        printf("Precio con tarjeta de debito: $%.2f\n",finalDebitoAA);

        printf("Precio con tarjeta de credito: $%.2f\n",finalCreditoAA);

        printf("Precio pagando en bitcoin: $%f\n",finalBitcoinAA);

        printf("Precio por KM: $%.4f\n\n",finalPrecioXkmAA);

        printf("Precio Latam: $%.2f\n",precioL);

        printf("Precio con tarjeta de debito: $%.2f\n",finalDebitoL);

        printf("Precio con tarjeta de credito: $%.2f\n",finalCreditoL);

        printf("Precio pagando en bitcoin: $%f\n",finalBitcoinL);

        printf("Precio por KM: $%.4f\n",finalPrecioXkmL);

        printf("\nLa diferencia de precio es: $%.2f\n",finalDiferencia);
    }
}

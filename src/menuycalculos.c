#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funciones.h"
#define BITCOIN 4606954.55

void menu()
{
	char continuar = 'n';
	int opcion;

	float km;
	int flagKM = 0;

	float precioAA = 0;
	float precioL = 0;
    int flagV = 0;

	float finalDebitoAA;
    float finalCreditoAA;
	float finalBitcoinAA;
    float finalPrecioXkmAA;

    float finalDebitoL;
	float finalCreditoL;
	float finalBitcoinL;
	float finalPrecioXkmL;
	float finalDiferencia;

	int flagCalculos = 0;

	do
    {

        printf("\n||Menu de opciones||\n\n");
        printf("1. Ingresar kilometros (km = %.2f)\n",km);
        printf("2. Ingresar precio de vuelos (Aerolineas = %.2f, Latam = %.2f)\n",precioAA,precioL);
        printf("3. Calcular todos los costos\n");
        printf("4. Informar resultados\n");
        printf("5. Carga forzada de datos\n");
        printf("6. Salir\n");

		printf("\nIngrese una opcion: ");
        fflush(stdin);
		scanf("%d", &opcion);

		switch(opcion)
		{
            case 1:

                if(flagKM == 0)
                {
                    km = validacionKilometros();
                    flagKM = 1;
                }
                else
                {
                    printf("\nYa ingreso kilometros\n");
                    fflush(stdin);
                }
                system("pause");
                break;

            case 2:

                if(flagV == 0)
                {
                    precioAA = validacionAA();

                    precioL = validacionL();

                    flagV = 1;
                }
                else
                {
                    printf("\nYa ingreso precios de vuelos\n");
                    fflush(stdin);
                }
                system("pause");
                break;

            case 3:

                if(precioAA <= 0 || precioL <= 0 || km <= 0)
                {
                    printf("\nNo se ingresaron todos los precios o km para calcular\n");
                }
                else
                {
                    printf("\nCalculos realizados\n");
                }

                finalDebitoAA = descuentoDebAA(precioAA);

                finalCreditoAA = descuentoCredAA(precioAA);

                finalBitcoinAA = bitcoinAA(precioAA);

                finalPrecioXkmAA = precioXkmAA(precioAA, km);

                finalDebitoL = descuentoDebL(precioL);

                finalCreditoL = descuentoCredL(precioL);

                finalBitcoinL = bitcoinL(precioL);

                finalPrecioXkmL = precioXkmL(precioL, km);

                finalDiferencia = diferencia(precioAA, precioL);

                flagCalculos = 1;

                system("pause");
                break;

            case 4:

                if(precioAA <= 0 || precioL <= 0 || km <= 0)
                {
                    printf("\nNo se ingresaron todos los precios o km para calcular\n");
                }
                else
                {
                    if(flagCalculos == 0)
                    {
                        printf("\nNo realizo los calculos. Presione 3\n");
                    }
                    else
                    {
                        mostrarResultados(km,precioAA,finalDebitoAA,finalCreditoAA,finalBitcoinAA,finalPrecioXkmAA,precioL,finalDebitoL
                                          ,finalCreditoL,finalBitcoinL,finalPrecioXkmL,finalDiferencia);
                    }
                }

                system("pause");
                break;

            case 5:

                finalDebitoAA = descuentoDebAA(162965);

                finalCreditoAA = descuentoCredAA(162965);

                finalBitcoinAA = bitcoinAA(162965);

                finalPrecioXkmAA = precioXkmAA(162965, 7090);

                finalDebitoL = descuentoDebL(159339);

                finalCreditoL = descuentoCredL(159339);

                finalBitcoinL = bitcoinL(159339);

                finalPrecioXkmL = precioXkmL(159339, 7090);

                finalDiferencia = diferencia(162965, 159339);

                mostrarResultados(7090,162965,finalDebitoAA,finalCreditoAA,finalBitcoinAA,finalPrecioXkmAA,159339,finalDebitoL,finalCreditoL,
                                  finalBitcoinL,finalPrecioXkmL,finalDiferencia);

                system("pause");
                break;

            case 6:
                printf("\nDesea salir? s/n: ");
                fflush(stdin);
                scanf("%c", &continuar);
                break;

            default:
                fflush(stdin);
                printf("\nError. Ingrese una opcion valida\n");
                break;
		}
    }while(continuar == 'n');
}

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

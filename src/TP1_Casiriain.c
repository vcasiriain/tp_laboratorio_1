#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funciones.h"
#define BITCOIN 4606954.55

int main(void)
{
    setbuf(stdout, NULL);

	char continuar = 'n';
	int opcion;

	float km;
	int flagKM = 0;

	float precioAA;
	float precioL;
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
        printf("1. Ingresar kilometros\n");
        printf("2. Ingresar precio de vuelos\n");
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

	return EXIT_SUCCESS;
}

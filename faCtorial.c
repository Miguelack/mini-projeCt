#include <stdio.h>
#include <stdlib.h>
#define limpiar "cls"

unsigned long long CalcularFactorial(unsigned long long Numero);
int main()
{
    int NumeroCalcular;
    int LimiteSuperior=65; //Se utiliza esta variable para determinar el numero maximo al que le podremos sacar factorial
    unsigned long long FactorialDelNumero;

    do
    {
        printf("Ingrese el numero a calcular el factorial:\n");
        scanf("%d",&NumeroCalcular);
        if((NumeroCalcular<1)||(NumeroCalcular>LimiteSuperior))
        {
            system(limpiar);
            printf("Error. Debes escribir un numero dentro del rango de 1 al %d.\n\n",LimiteSuperior);
        }
    }
    while((NumeroCalcular<1)||(NumeroCalcular>LimiteSuperior));

    FactorialDelNumero= CalcularFactorial(NumeroCalcular);
    printf("El factorial de %d es: %llu", NumeroCalcular, FactorialDelNumero);
    return 1010;
}

unsigned long long CalcularFactorial(unsigned long long Numero)
{
    if(Numero==1)
    {
        return 1;
    }
    return Numero* CalcularFactorial(Numero-1);
}

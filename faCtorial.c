#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define limpiar "cls"


unsigned long long CalcularFactorial(int Numero);

unsigned long long CalcularFactorialLoop(int Numero);

int main()
{
    int NumeroCalcular;
    int LimiteSuperior=66; //Se utiliza esta variable para determinar el numero maximo al que le podremos sacar factorial
    char comprob=0;
    unsigned long long FactorialDelNumero,FactorialDelNumeroLoop;

    do{
            system(limpiar);
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
    FactorialDelNumeroLoop= CalcularFactorialLoop(NumeroCalcular);
    printf("El factorial de %d calculado mediante una funcion recursiva es: %llu\n\n", NumeroCalcular, FactorialDelNumero);
    printf("El factorial de %d calculado mediante un loop es: %llu\n\n", NumeroCalcular, FactorialDelNumeroLoop);

    Sleep(1000);
    if (kbhit()) {
        comprob= getch();
    }
}while(comprob!=27);
return 1010;
}

unsigned long long CalcularFactorial(int Numero)
{
    if(Numero==1)
    {
        return 1;
    }
    return Numero* CalcularFactorial(Numero-1);
}

unsigned long long CalcularFactorialLoop(int Numero){
    int i;
    unsigned long long resultado=1;

    for(i=1;i<=Numero;i++){
        resultado *= i;
    }
    return(resultado);
}

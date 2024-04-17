/*Diseñe un algoritmo recursivo que encuentre la suma de los enteros positivos pares desde un numero N hasta 2.
Si N es impar debe imprimir un mensaje de error el algoritmo. */

#include <stdio.h>
#include <stdlib.h>
#define limpiar "cls"

int ParesRecursivos(int numeroPar);

int main(){
int numeroCalcular;

do{
    printf("Ingrese un numero natural y par:\n");
    scanf("%d",&numeroCalcular);
    if(((numeroCalcular % 2)!= 0) || (numeroCalcular<0)){
        system(limpiar);
        printf("Error. Su numero debe ser natural y par.");
    }
}while(((numeroCalcular % 2)!=0) || (numeroCalcular<0));

printf("La suma de numeros pares de %d es:%d",numeroCalcular,ParesRecursivos(numeroCalcular));
}

int ParesRecursivos(int numeroPar){
    if(numeroPar==2){
        return 2;
    }
    return numeroPar + ParesRecursivos(numeroPar -2);
}

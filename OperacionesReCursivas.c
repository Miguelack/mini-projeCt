#include <stdio.h>
#include <stdlib.h>
#define limpiar "cls"

int Mayor(int Numero1, int Numero2);
int Menor(int Numero1, int Numero2);
int SumaRecursiva(int sumando, int sumador);
int RestaRecursiva(int restando, int restador);
int MultiplicacionRecursiva(int multiplicador, int multiplicando);
void BinarioRecursivo(int Decimal);
int PotenciaRecursiva(int base, int exponente);
int main(){
int numero_1,numero_2,numero_grande,numero_chiquito;


do{
printf("Ingrese un numero entero positivo:\n");
scanf("%d",&numero_1);
if(numero_1<0){
    system(limpiar);
    printf("Error. Debes ingresar un numero positivo\n\n");
}
}while(numero_1<0);

do{
printf("Ingrese un numero entero positivo:\n");
scanf("%d",&numero_2);
if(numero_2<0){
    system(limpiar);
    printf("Error. Debes ingresar un numero positivo\n\n");
}
}while(numero_2<0);

numero_grande=Mayor(numero_1,numero_2);
numero_chiquito=Menor(numero_1,numero_2);
printf("\n\nEl resultado de la suma es: %d",SumaRecursiva(numero_grande,numero_chiquito));
printf("\n\nEl resultado de la resta entre %d y %d es: %d",numero_grande,numero_chiquito,RestaRecursiva(numero_grande,numero_chiquito));
printf("\n\nEl resultado de la resta entre %d y %d es: %d",numero_chiquito,numero_grande,RestaRecursiva(numero_chiquito,numero_grande));
printf("\n\nEl resultado de la multiplicacion es: %d",MultiplicacionRecursiva(numero_grande,numero_chiquito));
printf("\n\nEl resultado de la potencia entre %d y %d es: %d",numero_grande,numero_chiquito,PotenciaRecursiva(numero_grande,numero_chiquito));
printf("\n\nEl resultado de la potencia entre %d y %d es: %d",numero_chiquito,numero_grande,PotenciaRecursiva(numero_chiquito,numero_grande));
printf("\n\nLa representacion binaria de %d es:",numero_grande);
BinarioRecursivo(numero_grande);
printf("\n\nLa representacion binaria de %d es:",numero_chiquito);
BinarioRecursivo(numero_chiquito);
}

int Mayor(int Numero1, int Numero2){
    if(Numero1>=Numero2){
        return Numero1;
    }else{
        return Numero2;
    }
}

int Menor(int Numero1, int Numero2){
    if(Numero1>=Numero2){
        return Numero2;
    }else{
        return Numero1;
    }
}
int SumaRecursiva(int sumando, int sumador){
    if(sumador==0){
        return sumando;
    }else{
        return SumaRecursiva(sumando+1,sumador-1);
    }
}

int RestaRecursiva(int restando, int restador){
    if(restador==0){
        return restando;
    }else{
        return RestaRecursiva(restando-1,restador-1);
    }
}

int MultiplicacionRecursiva(int multiplicador, int multiplicando){
    if(multiplicando==0){
        return 0;
    }else{
        return multiplicador + MultiplicacionRecursiva(multiplicador,multiplicando-1);
    }
}

int PotenciaRecursiva(int base, int exponente){
    if(exponente==0){
        return 1;
    }else{
        return base * PotenciaRecursiva(base,exponente-1);
    }
}

void BinarioRecursivo(int Decimal) {
    if ((Decimal / 2) != 0) {
        BinarioRecursivo(Decimal / 2);
    }
    printf("%d", Decimal % 2);
}

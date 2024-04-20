/*Desarrollar una operación recursiva que realice la suma de números binarios cuyos digitos se encuentran almacenados en un
arreglo . Sabiendo que se recorren los digitos de derecha a izquierda y se suman digito a digito cuidando el acarreo.
Dificultad extra personal: debe leerse el entero desde un archivo, debe transformarlo a binario y luego realizar la tarea.
El algoritmo NO puede utilizar arreglos ni libreria string*/

#include <stdio.h>
#define archivo_binario "SumaBinariaRecursiva.txt"

int BinarioRecursivo(int Decimal);
int SumaBinariaRecursiva(int numeroBinario1,int numeroBinario2, int acarreoDeSuma);

int main(){
FILE* archivoDecimales= fopen(archivo_binario,"r");
int numeroACalcular1=0, numeroACalcular2=0;

    if(archivoDecimales != NULL){
        fscanf(archivoDecimales,"%d",&numeroACalcular1);
        fscanf(archivoDecimales,"%d",&numeroACalcular2);
        fclose(archivoDecimales);
        printf("Variables extraidas del archivo exitosamente.\n\n\n");
    }else{
        fclose(archivoDecimales);
        printf("Error en el archivo. Verificar su contenido\n");
        return -5;
    }
printf("El primer numero entero que analizaremos es: %d\n",numeroACalcular1);
printf("El segundo numero entero que analizaremos es: %d\n",numeroACalcular2);

numeroACalcular1=BinarioRecursivo(numeroACalcular1);
numeroACalcular2=BinarioRecursivo(numeroACalcular2);

printf("\nEl equivalente binario del primer numero es: %d\n",numeroACalcular1);
printf("El equivalente binario del segundo numero es: %d\n\n",numeroACalcular2);
printf("La suma de ambos binarios es:%d",SumaBinariaRecursiva(numeroACalcular1,numeroACalcular2,0));
}

int BinarioRecursivo(int Decimal) {
    if (Decimal==0) {
        return 0;
    }else{
        return ((Decimal % 2) + 10 * BinarioRecursivo(Decimal/2));
    }
}

int SumaBinariaRecursiva(int numeroBinario1,int numeroBinario2, int acarreoDeSuma){
    if(numeroBinario1 == 0 && numeroBinario2 == 0 && acarreoDeSuma == 0){
        return 0;
    }else {
        int ultimoDigitoBinario1= numeroBinario1 %10;
        int ultimoDigitoBinario2= numeroBinario2 %10;
        int retornableUltimoDigitoBinario= (ultimoDigitoBinario1 + ultimoDigitoBinario2 + acarreoDeSuma) % 2;
            acarreoDeSuma= (ultimoDigitoBinario1 + ultimoDigitoBinario2 + acarreoDeSuma) / 2;

    return retornableUltimoDigitoBinario + 10 * SumaBinariaRecursiva(numeroBinario1/10, numeroBinario2/10, acarreoDeSuma);
}
}

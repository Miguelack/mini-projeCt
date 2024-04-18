/*Elabora una función recursiva que dado un arreglo de N enteros ordenado de manera ascendente y un entero M
retorne la posición de M en el arreglo. Si no lo encuentra en el arreglo la función debe retornar -1
Dificultad extra personal: El arreglo debe tomarse desde un archivo .txt con numeros impresos de manera aleatoria
+Recibir el arreglo de manera aleatoria
+Ordenarlo*/

#include <stdio.h>
#include <stdlib.h>
#define limpiar "cls"
#define archivo_enteros "ArchivoEnterosAleatorios.txt"
#define MAXARRAY 100

int LlenarArray(int Enteros[]);
void IntercambiarVariables(int* variableUno, int* variableDos);
int FragmentarArreglo(int Enteros[],int puntoBajo,int puntoAlto);
void QuickSort(int Enteros[], long int escalarBajo, long int escalarAlto);
void printArray(int arr[], int size);
int BuscarNumeroDentroDelArreglo(int Enteros[],int numeroABuscar,int inicializador);
int main(){
    int Enteros[MAXARRAY];
    int cantidadDeNumerosAlmacenados=0,numeroABuscar=0;

    cantidadDeNumerosAlmacenados= LlenarArray(Enteros);
    if(cantidadDeNumerosAlmacenados!=-6){
        printf("Archivo cargado de manera exitosa.\n\n");
    }else{
        printf("Error en el archivo. Verificar su contenido}n}n");
        return 0;
    }

    QuickSort(Enteros,0,cantidadDeNumerosAlmacenados-1);
    printArray(Enteros,cantidadDeNumerosAlmacenados);
    printf("Ingrese el numero a buscar en el arreglo:\n\n");
    scanf("%d",&numeroABuscar);
    if(BuscarNumeroDentroDelArreglo(Enteros,numeroABuscar,0)!= -58){
        printf("\nEl numero %d se encuentra en la casilla: %d\n\n",numeroABuscar,BuscarNumeroDentroDelArreglo(Enteros,numeroABuscar,0));
        return 0;
    }else{
        printf("\nEl numero %d no se encuentra dentro del arreglo.\n\n");
        return 0;
    }

}

int LlenarArray(int Enteros[]){
    int auxiliarAsignador=0,i=0;
    FILE* archivoEnteros;
    archivoEnteros=fopen(archivo_enteros,"r");

    if(archivoEnteros!= NULL){
        while(fscanf(archivoEnteros,"%d",&auxiliarAsignador)!= EOF){
            Enteros[i]= auxiliarAsignador;
            i=i+1;
        }
        return i;
        fclose(archivoEnteros);
        }else{
            fclose(archivoEnteros);
            return -6;
            }
}

void IntercambiarVariables(int* variableUno, int* variableDos){
    int auxiliarCambio= *variableUno;
    *variableUno= *variableDos;
    *variableDos= auxiliarCambio;
}

int FragmentarArreglo(int Enteros[],int puntoBajo,int puntoAlto){
    int pivoteArreglo= Enteros[puntoAlto];
    int iniciadorArreglo=(puntoBajo - 1);
    for(int i= puntoBajo; i<= puntoAlto-1; i++){
        if(Enteros[i]<= pivoteArreglo){
            iniciadorArreglo++;
            IntercambiarVariables(&Enteros[iniciadorArreglo],&Enteros[i]);
        }
    }

    IntercambiarVariables((&Enteros[iniciadorArreglo + 1]),&Enteros[puntoAlto]);
    return (iniciadorArreglo + 1);
}

void QuickSort(int Enteros[], long int escalarBajo, long int escalarAlto){
    if(escalarBajo<escalarAlto){
        long int promedioArreglo= FragmentarArreglo(Enteros,escalarBajo,escalarAlto);
        QuickSort(Enteros,escalarBajo,promedioArreglo-1);
        QuickSort(Enteros,promedioArreglo+1,escalarAlto);
    }
}

void printArray(int arr[], int size){
   int i;
   for (i=0; i < size; i++)
      printf("%d\n\n", arr[i]);
}
int BuscarNumeroDentroDelArreglo(int Enteros[],int numeroABuscar,int inicializador){
    if(Enteros[inicializador]== numeroABuscar){
        return inicializador;
    }else{
        if(Enteros[inicializador]>numeroABuscar){
            return -58;
        }else{
            return BuscarNumeroDentroDelArreglo(Enteros,numeroABuscar,inicializador + 1);
        }
    }
}

/*Elabora una función recursiva que dado un arreglo de N enteros ordenado de manera ascendente y un entero M
retorne la posición de M en el arreglo. Si no lo encuentra en el arreglo la función debe retornar -1
Elabora una funcion recursiva que dado un arreglo de n enteros ordenados calcule la suma de los digitos de cada entero
y determine cual suma de digitos es mayor . Debe hacerse la suma de digitos de manera recursiva
Elabora una funcion recursiva que dado un arreglo de N enteros calcule la suma de todos sus elementos
Dificultad extra personal: El arreglo debe tomarse desde un archivo .txt con numeros impresos de manera aleatoria
+Recibir el arreglo de manera aleatoria
+Ordenarlo*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define limpiar "cls"
#define archivo_enteros "ArchivoEnterosAleatorios.txt"
#define MAXARRAY 100000

int LlenarArray(int Enteros[]);
void IntercambiarVariables(int* variableUno, int* variableDos);
int FragmentarArreglo(int Enteros[],int puntoBajo,int puntoAlto);
void QuickSort(int Enteros[], long int escalarBajo, long int escalarAlto);

int BuscarNumeroDentroDelArreglo(int Enteros[],int numeroABuscar,int inicializador);

int SumarDigitos(int numeroSumar);
int Mayor(int Numero1, int Numero2);
void SumarDigitosDelArreglo(int Enteros[], int maximoArreglo);
int DeterminarMayorArreglo(int Enteros[], int longitudArreglo, int numeroMayorArreglo, int inicializador);

int SumarEnterosDelArreglo(int Enteros[], int longitudArreglo, int inicializador);

int main(){
   int Enteros[MAXARRAY];
    int cantidadDeNumerosAlmacenados=0,numeroABuscar=0;

    cantidadDeNumerosAlmacenados= LlenarArray(Enteros);
    if(cantidadDeNumerosAlmacenados!=-6){
        printf("Archivo cargado de manera exitosa.\n");
    }else{
        printf("Error en el archivo. Verificar su contenido\n");
        return 0;
    }

    QuickSort(Enteros,0,cantidadDeNumerosAlmacenados-1);
    printf("Arreglo ordenado de manera exitosa.\n\n");
    printf("Ingrese el numero a buscar en el arreglo: ");
    scanf("%d",&numeroABuscar);
    if(BuscarNumeroDentroDelArreglo(Enteros,numeroABuscar,0)!= -1){
        printf("\nEl numero %d se encuentra en la casilla: %d\n\n",numeroABuscar,BuscarNumeroDentroDelArreglo(Enteros,numeroABuscar,0));
    }else{
        printf("\nEl numero %d no se encuentra dentro del arreglo.\n\n");
    }
Sleep(3000);
printf("\nLa suma de enteros del arreglo es:%d\n\n",SumarEnterosDelArreglo(Enteros,cantidadDeNumerosAlmacenados,0));
Sleep(3000);
printf("Arreglo original:\t\tArreglo de digitos sumados:\n");
Sleep(1000);
SumarDigitosDelArreglo(Enteros,cantidadDeNumerosAlmacenados);
return 0;
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
        if(Enteros[inicializador]<numeroABuscar){
            return -1;
        }else{
            return BuscarNumeroDentroDelArreglo(Enteros,numeroABuscar,inicializador + 1);
        }
    }
}

int SumarDigitos(int numeroSumar){
    if(numeroSumar / 10 !=0){
        return ((numeroSumar % 10) + SumarDigitos(numeroSumar/10));
    }else{
        return numeroSumar;
    }
}

int Mayor(int Numero1, int Numero2){
    if(Numero1>=Numero2){
        return Numero1;
    }else{
        return Numero2;
    }
}

int DeterminarMayorArreglo(int Enteros[], int longitudArreglo, int numeroMayorArreglo, int inicializador){
    if(inicializador>=longitudArreglo){
        return numeroMayorArreglo;
    }else{
        if(numeroMayorArreglo >Mayor(Enteros[inicializador],Enteros[inicializador+1])){
            return DeterminarMayorArreglo(Enteros,longitudArreglo,numeroMayorArreglo,inicializador+1);
        }else{
            return DeterminarMayorArreglo(Enteros,longitudArreglo, Mayor(Enteros[inicializador],Enteros[inicializador+1]),inicializador+1);
        }
    }
}
void SumarDigitosDelArreglo(int Enteros[], int longitudArreglo){
    for(int i=0;i<=longitudArreglo-1;i++){
        Sleep(80);
        printf("%d\t\t\t\t",Enteros[i]);
        Enteros[i]=SumarDigitos(Enteros[i]);
        printf("%d\n\n",Enteros[i]);
    }
     printf("\nEl numero mayor de la suma de digitos del arreglo es: %d\n\n",DeterminarMayorArreglo(Enteros,longitudArreglo,Mayor(Enteros[0],Enteros[1]),0));
}

int SumarEnterosDelArreglo(int Enteros[], int longitudArreglo, int inicializador){
    if(inicializador== longitudArreglo){
        return 0;
    }else{
        return Enteros[inicializador] + SumarEnterosDelArreglo(Enteros, longitudArreglo, inicializador + 1);
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LIBROS 100

/*
VERSION 2.0
En el marco de una relación entre Vongo, un estudiante de artes diagnosticado con TOC, caracterizado por un fuerte apego al orden
y limpieza; y Sandra, su compañera de vida, conocida por un estilo de vida desorganizado y caótico, surge un reto especial. Juntos
han hecho una inversión en un librero que alberga un total de N cantidadad de volúmenes. Con el objetivo de preservar la tranquilidad,
Vongo ha establecido como requisito indispensable que todos sus libros sean dispuestos en un orden alfabético riguroso.

Sandra reconocida por su inteligencia y habilidades estratégicas, ha confiado en ti, programador, para crear un algoritmo innovador capaz
de organizar los libros en el librero de manera sistemática y alfabética. Tu tarea consiste en diseñar y desarrollar un programa recursivo
que, ante una lista de libros aplique un método eficaz para su ordenamiento, como añadido, Sandra te ha solicitado que cuentes el número de
operaciones que le toma al programa ordenar todos los libros y de esta forma... si el numero es muy alto poder argumentar en contra de Vongo.

Cosas añadidas más allá del enunciado:

E/S mediante archivos. Recibe un archivo de la n cantidad de libros con un máximo definido, el usuario no participa.

Mejoras ante la versión 1.0:
+a través de funciones con variables de tipo apuntador se pudo modificar el arreglo sin necesidad de utilizar arreglos auxiliares.

Bugs:

-EL archivo imprime cadenas vacías al asignarlo directamente, luego al final imprime ordenado el arreglo.

Falta por agregar: 

+contador de veces que cambia
*/
int llenarBiblioteca(char* pBiblioteca[]);
void LiberarMemoria(char* pBiblioteca[]);
void LlenarArchivo(char* pBiblioteca[]);
void intercambiarCadenas(char* palabraUno, char* palabraDos);
int DividirQuickSort(char* arr[], int inicializadorArreglo, int topeArreglo);
void QuickSort(char* arr[], int inicializadorArreglo, int topeArreglo);

int main(void) {
char* bibliotecaInicial[MAX_LIBROS]; //tuve que trabajarlo con un arreglo dinamico al no saber el long de los caracteres
int i;

for (i = 0; i < MAX_LIBROS; i++) {
    bibliotecaInicial[i] = (char*)malloc(MAX_LIBROS);
}

if (llenarBiblioteca(bibliotecaInicial) == 1) {
    printf("Biblioteca cargada de manera exitosa.\n");
    QuickSort(bibliotecaInicial,0,MAX_LIBROS-1); //-1 porque si el arreglo está lleno genera segmentation fault el apuntador max
    LlenarArchivo(bibliotecaInicial);
} else{
     printf("Error al cargar, verificar archivo.\n");
     return -13;
    }
}
int llenarBiblioteca(char* pBiblioteca[]) {
FILE* archivoLibros = fopen("libros.txt", "r");
int i = 0;

if (archivoLibros != NULL) {
    while (!feof(archivoLibros) && i < MAX_LIBROS) {
        fscanf(archivoLibros, "%s\n", pBiblioteca[i]);
        i++;
    }
    fclose(archivoLibros);
    return 1;
} else {
    return -12;
    }
}

void LiberarMemoria(char* pBiblioteca[]){
    int i;

    for(i=0;i<=MAX_LIBROS;i++){
        free(pBiblioteca[i]);
    }
}

void LlenarArchivo(char* pBiblioteca[]){
    FILE* archivoEscribir=fopen("libros_ordenados.txt","a+");
    int i=0;

    for(i;i< MAX_LIBROS;i++){
        fprintf(archivoEscribir,"%s\n",pBiblioteca[i]);
    }
fclose(archivoEscribir);
LiberarMemoria(pBiblioteca); //libere la memoria al final para evitar problemas de segmentacion o llenar la memoria de espacio innecesario
}

void intercambiarCadenas(char* palabraUno, char* palabraDos){
    char* auxiliarIntercambio=(char*)malloc(MAX_LIBROS);
    strcpy(auxiliarIntercambio,palabraUno);
    strcpy(palabraUno,palabraDos);
    strcpy(palabraDos,auxiliarIntercambio);
}

int DividirQuickSort(char* pBiblioteca[], int inicializadorArreglo, int topeArreglo){
    char* cabecera = pBiblioteca[topeArreglo];
    int i = inicializadorArreglo - 1;

    for (int j = inicializadorArreglo; j < topeArreglo; j++) {
        if (strcmp(pBiblioteca[j], cabecera) <= 0) {
            i++;
            intercambiarCadenas(pBiblioteca[i], pBiblioteca[j]);
        }
    }

    intercambiarCadenas(pBiblioteca[i + 1], pBiblioteca[topeArreglo]);
    return i + 1;
}

void QuickSort(char* pBiblioteca[], int inicializadorArreglo, int topeArreglo){
    if (inicializadorArreglo < topeArreglo) {
        int indiceArreglo = DividirQuickSort(pBiblioteca, inicializadorArreglo, topeArreglo);
        QuickSort(pBiblioteca, inicializadorArreglo, indiceArreglo - 1);
        QuickSort(pBiblioteca, indiceArreglo + 1, topeArreglo);
    }
}

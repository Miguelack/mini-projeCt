#include <stdio.h>
#include <stdlib.h>
#include "stackms.h"

#define TRUE 1
#define FALSE 0


void NewStack(STACK* stack){
    stack->top= NULL;
    stack->sizeOfStack=0;
}//Inicializará el stack

int IsEmpty(STACK stack){
    if((stack.top==NULL) && (stack.sizeOfStack==0)){
        return TRUE;//Devolverá un simple TRUE as 1 en caso que los datos sean iguales a una pila VACÍA, es decir como si la hubiese iniciado con NewStack
    }else{
        if((stack.top==NULL) && (stack.sizeOfStack!=0)){
            stack.sizeOfStack=0;
            return TRUE; //Devolverá un TRUE as 1 en caso que el apuntador hacia el inicio de la pila NO apunte a nada PERO el contador de la pila diga que hay contenido dentro, la funcion trabaja como su propio debugger en caso que la pila no funcione de manera correcta o haya una corrupción de datos
        }else{
            return FALSE;
        }
    }
}

NODE* NewNode(data inputData){
    NODE* newNode = (NODE*)malloc(sizeof(NODE));//Malloc debido al puntero indefinido al nuevo node sizeof
    newNode->nextToTop= NULL;//Apunta a vacío porque estoy creando un nuevo nodo a implementar, este nodo ahora será el tope de la pila entonces que apunte a vacío es esencial
    newNode->element= inputData; //el nodo tiene un solo parámetro de entrada que es el data hacia el campo element
}

void DeleteNode(NODE* nodeToDelete){
    nodeToDelete->nextToTop=NULL; //El día 27/06 creación de esta función aún no existe aún alguna razón para eliminar algo que no esté al tope de la pila, por lo tanto esta función solo tendrá una llamada en caso definido Pop eliminando el último elemento entrante. Recordatorio: A pesar que definí muy bien la creación del nodo as NULL al eliminarlo vuelvo a definirlo como NULL
    free(nodeToDelete);
}

void Push(STACK* stack, data inputData){
    NODE* nodeToPush= NewNode(inputData); //asignación del nuevo nodo, este nodo tendrá características del input y apunta hacia NULL en esta llamada
    /*Esta linea es esencial, a este punto stack->top apunta a la ÚLTIMA posición de la pila, esta última posición es la que evita la pérdida 
    del apuntado hacia ella*/
    nodeToPush->nextToTop= stack->top;
    /*Ahora, tanto stack->top como nodeToPush->nextToTop apuntan a LO MISMO, el apuntador de nodeToPush ahora guarda el enlace de la pila, en caso de ser una pila vacia y que este fuese su primer elemento sencillamente apuntaria a NULL sin conflictos, el if es innecesario en caso de estar vacia*/ 
    stack->top= nodeToPush; //finalmente, el apuntador del stack APUNTA hacia el ultimo elemento
    stack->sizeOfStack++;//incrementa el contador xd
}

void Pop(STACK* stack){
    if(stack->top!=NULL){
        NODE* delete= stack->top;//al nodo a borrar se le asigna A DONDE apunta NULL es decir el nodo termina apuntando al ultimo elemento de la lista
        stack->top=stack->top->nextToTop;//ahora el stack indexador APUNTA a la siguiente direccion del apuntado (quiza no sea la mejor practica pero debo me funciona por los momentos 29/06);
        DeleteNode(delete);//hace free en pocas palabras
        stack->sizeOfStack--;//decrementa el contador
    }
}

data DataFromTop(STACK* stack){
    if(stack->top!=NULL){
        return stack->top->element;
    }else{
       printf("La pila actual esta vacia\n"); //SE que es una malapraxis hacer printf dentro de la funcion PERO como DATA puede ser cualquier entrada(ya sea una struct, integer, etc) pues solo imprimo y ya
    }
}

void DeleteStack(STACK* stack){
    while(stack->top !=NULL){
        Pop(stack);
    }
    free(stack);
}

int GetSizeOfStack(STACK* stack){
    return stack->sizeOfStack;
}
#ifndef stackms_h
#define stackms_h

#include <stdio.h>
#include <stdlib.h>

typedef int data;

typedef struct node{
    data element;
    struct node* nextToTop;
}NODE;

typedef struct stack{
    NODE* top;
    int sizeOfStack;
}STACK;

void NewStack(STACK* stack);
int IsEmpty(STACK stack);
NODE* NewNode(data inputData);
void DeleteNode(NODE* nodeToDelete);
void Push(STACK* stack, data inputData);
void Pop(STACK* stack);
data DataFromTop(STACK* stack);
void DeleteStack(STACK* stack);
int GetSizeOfStack(STACK* stack);

#endif
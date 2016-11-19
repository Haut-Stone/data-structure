#include <cstdio>
#include <iostream>
using namespace std;

struct stackRecord;
typedef int elementType;
typedef struct stackRecord *stack;

int isEmpty(stack S);
int isFull(stack S);
stack createStack(int maxElements);
void Disposestack(stack S);
void makeEmpty(stack S);
elementType top(stack S);
void pop(stack S);
elementType topAndPop(stack S);

#define emptyToS -1
#define minStackSize 5

struct stackRecord
{
	int capacity;
	int topOfStack;
	elementType *array;
};

stack createStack(int maxElements)
{
	stack S;
	if(maxElements < minStackSize){
		Error("stack size too small");
	}
	S = malloc(sizeof(struct stackRecord));
	if(S == NULL){
		FatalError("out of space!!\n");
	}
	S->array = malloc(sizeof(elementType)*maxElements);
	if(S->array == NULL){
		FatalError("out of space");
	}
	S->capacity = maxElements;
	makeEmpty(S);
	return S;
}

void Disposestack(stack S)
{
	if(S != NULL){
		free(S->array);
		free(S);
	}
}

int isEmpty(stack S)
{
	return S->topOfStack == emptyToS;
}

void makeEmpty(stack S)
{
	S->topOfStack = emptyToS;
}

void push(elementType X, stack S)
{
	if(isFull(S)){
		Error("Full stack");
	}else{
		S->array[++S->topOfStack] = X;
	}
}

elementType top(stack S)
{
	if(!isEmpty(S)){
		return S->array[S->topOfStack];
	}
	Error("empty stack");
	return 0;
}

void pop(stack S)
{
	if(isEmpty(S)){
		Error("empty stack");
	}else{
		S->topOfStack--;
	}
}

elementType topAndPop(stack S)
{
	if(!isEmpty(S)){
		return S->array[S->topOfStack--];
		Error("empty stack");
		return 0;
	}
}
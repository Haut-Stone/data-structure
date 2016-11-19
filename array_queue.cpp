#include <cstdio>
#include <iostream>
using namespace std;

struct queueRecord;
typedef int elementType
typedef struct queueRecord *queue;

int isEmpty(queue Q);
int isFuLL(queue Q);
int cresteQueue(int maxElement);
void disposeQueue(queue Q);
void makeEmpty(queue Q);
void enqueue(queue Q, elementType X);
elementType front(queue Q);
void dequeue(queue Q);
elementType frontAndDequeue(queue Q);

#define minQueueSize 5

struct QueueRecord
{
	int capacity;
	int front;
	int rear;
	int size;
	elementType *array;
};

int isEmpty(queue Q)
{
	return Q->size == 0;
}

void makeEmpty(queue Q)
{
	Q->size = 0;
	Q->front = 1;
	Q->rear = 0;
}

static int Succ(int value, queue Q)
{
	if(++value == Q->capacity)
		value = 0;
	return value;
}

void enqueue(elementType X, queue Q)
{
	if(isFuLL(Q)){
		Error("Full queue");
	}else{
		Q->size++;
		Q->Rear = Succ(Q->rear, Q);
		Q->array[Q->Rear] = X;
	}
}

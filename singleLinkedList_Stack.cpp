#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

struct Node;
typedef int elementType;
typedef struct Node *ptrToNode;
typedef ptrToNode stack;

int isEmpty(stack S);
stack createdStack(void);
void disposeStack(stack S);
void makeEmpty(stack S);
void push(elementType X, stack S);
elementType top(stack S);
void pop(stack S);

struct Node {
  elementType element;
  ptrToNode next;
};

int isEmpty(stack S) { return S->next == NULL; }

stack createdStack(void) {
  stack S;
  S = (ptrToNode)malloc(sizeof(struct Node));
  if (S == NULL) {
    printf("Out of space!!");
  }
  S->next = NULL;
  makeEmpty(S);
  return S;
}

void makeEmpty(stack S) {
  if (S == NULL) {
    printf("Must use CreatStack first");
  } else {
    while (!isEmpty(S)) {
      pop(S);
    }
  }
}

void push(elementType X, stack S) {
  ptrToNode tmpCell;
  tmpCell = (ptrToNode)malloc(sizeof(struct Node));
  if (tmpCell == NULL) {
    printf("out of space!!");
  } else {
    tmpCell->element = X;
    tmpCell->next = S->next;
    S->next = tmpCell;
  }
}

elementType top(stack S) {
  if (!isEmpty(S)) {
    return S->next->element;
  }
  printf("Empty stack");
  return 0;
}

void pop(stack S) {
  ptrToNode FirstCell;
  if (isEmpty(S)) {
    printf("Empty stack");
  } else {
    FirstCell = S->next;
    S->next = FirstCell->next;
    free(FirstCell);
  }
}

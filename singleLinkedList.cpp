#include <iostream>
using namespace std;

struct Node;
typedef int  ElementType;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty(List L);
int IsLast(Position p, List L);
int IsEmpty(List L);
Position Find(ElementType X, List L);
void Delete(ElementType X, List L);
Position FindPrevious(ElementType X, List L);
void Insert(ElementType X, List L, Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);

struct Node
{
    ElementType Element;
    Position Next;
};

int IsEmpty(List L){
    return L->Next == NULL;
}

int IsLast(Position P, List L){
    return P->Next == NULL;
}

Position Find(ElementType X, List L){
    Position P;
    P = L->Next;
    while( P != NULL && P->Element != X){ //如果没有怎么办？
        P = P->Next;
    }
    return P;
}

void Delete(ElementType X, List L){
    Position P, tmpcell;
    P = FindPrevious(X, L);
    if(!IsLast(P,L)){
        tmpcell = P->Next;
        P->Next = tmpcell->Next;
        free(tmpcell);
    }
    
}

Position FindPrevious(ElementType X, List L){
    Position P;
    P = L;
    while(P->Next != NULL && P->Next->Element != X){
        P = P->Next;
    }
    return P;
}

void Insert(ElementType X, List L, Position P){
    Position tmpCell;
    tmpCell = (Position)malloc(sizeof(struct Node));
    if(tmpCell == NULL){
        printf("out of space");
    }else{
        tmpCell->Element = X;
        tmpCell->Next = P->Next;
        P->Next = tmpCell;
    }
}

void DeleteList(List L){
    Position P,tmp;
    P = L->Next;
    L->Next == NULL;
    while(P->Next != NULL){
        tmp = P->Next;
        free(P);
        P = tmp;
    }
}

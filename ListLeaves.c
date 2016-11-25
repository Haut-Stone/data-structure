#include <stdio.h>  
#include <stdlib.h>  
  
#define MaxTree 10  
  
typedef struct TreeNode{  
    int number;  
    int left;  
    int right;  
} BinTree;  
BinTree T[MaxTree];  
  
typedef struct QNode{  
    int Data[MaxTree];  
    int rear;  
    int front;  
}QNode, *Queue;  
  
Queue CreatQueue();  
void AddQ(Queue PtrQ, int item);  
int DeleteQ(Queue PtrQ);  
int IsEmpty(Queue PtrQ);  
  
int BuildTree(BinTree T[]);  
void LevelorderTraversal(int root);  
  
int main(int argc, char const *argv[])  
{  
    int Root;  
    Root = BuildTree(T);  
    LevelorderTraversal(Root);  
    return 0;  
}  
  
Queue CreatQueue()  
{  
    Queue Q = (Queue)malloc(sizeof(QNode));  
    Q->front = Q->rear = 0;  
    return Q;  
}  
  
void AddQ(Queue PtrQ, int item)  
{  
    if((PtrQ->rear+1) % MaxTree == PtrQ->front){  
        printf("Queue is full\n");  
        return;  
    }  
    PtrQ->rear = (PtrQ->rear+1) % MaxTree;  
    PtrQ->Data[PtrQ->rear] = item;  
}  
  
int DeleteQ(Queue PtrQ)  
{  
    if(PtrQ->front == PtrQ->rear){  
        printf("Queue is empty\n");  
        return -1;  
    } else {  
        PtrQ->front = (PtrQ->front+1) % MaxTree;  
        return PtrQ->Data[PtrQ->front];  
    }  
}  
  
int IsEmpty(Queue PtrQ)  
{  
    if(PtrQ->front == PtrQ->rear)  
        return 0;  
    else  
        return 1;  
}  
  
int BuildTree(BinTree T[])  
{  
    int N, i, root = -1;  
    // freopen("test.txt", "r", stdin);  
    scanf("%d\n", &N);  
    char cl, cr;  
    if(N){  
        int check[MaxTree];  
        for (i = 0; i < N; ++i){  
            check[i] = 1;  
        }  
        for (i = 0; i < N; ++i){  
            scanf("%c %c\n", &cl, &cr);  
            T[i].number = i;    //结点序号  
            if(cl != '-'){  
                T[i].left = cl - '0';  
                check[T[i].left] = 0;  
            }  
            else  
                T[i].left = -1;  
            if(cr != '-'){  
                T[i].right = cr - '0';  
                check[T[i].right] = 0;  
            }  
            else  
                T[i].right = -1;  
        }  
        for (i = 0; i < N; ++i){  
            if(check[i])  
                root = i;  
        }  
    }  
    return root;  
}  
  
void LevelorderTraversal(int ROOT)  
{   
    Queue Q;   
    int temp, flag = 1;  
    int root = ROOT;   
    if(root == -1)  
        return; /* 若是空树则直接返回 */  
    Q = CreatQueue(); /* 创建空队列Q */  
    int rear = 0, front = 0;  
    AddQ(Q, root);  
    rear++;  
    while (rear - front) {  
        root = DeleteQ( Q );  
        front++;  
        if(T[root].left == -1 && T[root].right == -1){  
            if(flag){  
                flag = 0;  
                printf("%d", T[root].number);  
            } else  
                printf(" %d", T[root].number);  
        } else {  
            if(T[root].left != -1){  
                AddQ(Q, T[root].left);  
                rear++;  
            }  
            if(T[root].right != -1){  
                AddQ(Q, T[root].right);  
                rear++;  
            }  
        }  
    }  
} 
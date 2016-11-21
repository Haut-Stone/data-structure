#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1001

typedef struct Node{
    int top;
    int cap;//栈的最大容量
    int data[MAX_SIZE];//栈中的数据
}*Stack;

void pop(Stack myStack);
void push(Stack myStack, int e);
Stack initStack(void);
int checkStack(int tmp[], int m, int n);

int main(int argc, char const *argv[])
{
    int m, n, k;//M (the maximum capacity of the stack), N (the length of push sequence), and K (the number of pop sequences to be checked).
    scanf("%d %d %d", &m, &n, &k);
    int *tmp = (int*)malloc(sizeof(int)*n);//申请临时空间
    for(; k>0;k--){
        for(int i=0;i<n;i++){//读入数据
            scanf("%d", tmp + i);
        }
        if(checkStack(tmp, m, n)){//判断是否符合要求😂。
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}

Stack initStack()
{
    Stack myStack = (Stack)malloc(sizeof(struct Node));
    myStack->cap = MAX_SIZE;
    myStack->top = -1;
    return myStack;
}

void push(Stack myStack, int e)
{
    if(myStack->top == myStack->cap - 1){//若栈满返回
        return;
    }
    myStack->top++;
    myStack->data[myStack->top] = e;
}

void pop(Stack myStack)
{
    if(myStack->top == -1){//如果栈空，则返回
        return;
    }
    myStack->top--;
}

int checkStack(int tmp[], int m, int n)
{
    Stack ps = initStack();//建立 栈结构
    push(ps, 0);//使top指向data[0]
    int idx = 0;
    int num = 1;
    while(idx < n){//核心
        while(ps->data[ps->top] < tmp[idx] && idx < n && ps->top < m){
            push(ps, num++);
        }
        if(ps->data[ps->top] == tmp[idx]){
            pop(ps);
            idx++;
        }else{
            return 0;
        }
    }
    return 1;
}


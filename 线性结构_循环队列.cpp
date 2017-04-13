/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-10 12:18:04
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-10 21:37:32
*/

//用循环队列来提高数组的空间的利用效率
//相比于用指针，直接引用的写法更佳利于集中注意力

#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
using namespace std;

#define INPUT_TEST freopen("in.txt", "r", stdin)
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOWW -2//提示这个已经定义过了

typedef int Status;
typedef int Elemtype;

const int N = 100;

typedef struct Node
{
	Elemtype a[N];
	int front;//队头
	int rear;//队尾
}Queue;


void initQueue(Queue &Q);//初始化循环队列
void destroyQueue();
void clearQueue();
bool isEmpty(Queue &Q);//判断栈是否是空的
int queueLength(Queue &Q);//返循环队列的长度
Elemtype getHead(Queue &Q);//取得队头元素
void enQueue(Queue &Q, Elemtype value);//入队一个元素
Elemtype deQueue(Queue &Q);//出队一个元素，并返回该元素的值



int main(void)
{
	Queue Q;
	initQueue(Q);
	enQueue(Q, 20);
	enQueue(Q, 10);
	deQueue(Q);
	printf("%d\n", Q.a[Q.front]);
    return 0;
}

void initQueue(Queue &Q)
{
	Q.front = 0;
	Q.rear = 0;
}

void enQueue(Queue &Q, Elemtype value)
{
	if((Q.rear + 1) % N == Q.front){//当栈满时报错
		cout<<"Queue is full"<<endl;
	}else{
		Q.a[Q.rear] = value;
		Q.rear = (Q.rear+1) % N;
	}
}

Elemtype deQueue(Queue &Q)
{
	Elemtype res;
	if(Q.rear == Q.front){//当栈空时报错
		cout<<"Queue is empty"<<endl;
	}else{
		res = Q.a[Q.front];
		Q.front = (Q.front+1) % N;
		return res;
	}
	return 0;
}

int queueLength(Queue &Q)
{
	if(Q.front < Q.rear){
		return Q.rear - Q.front;
	}else{
		return N - (Q.front - Q.rear);
	}
}

bool isEmpty(Queue &Q)
{
	if(Q.rear == Q.front){
		return true;
	}else{
		return false;
	}
}

Elemtype getHead(Queue &Q)
{
	return Q.a[Q.front];
}
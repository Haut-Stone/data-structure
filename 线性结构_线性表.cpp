/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-06 12:37:57
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-06 21:12:40
*/
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

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOWW -2//提示这个已经定义过了

typedef int Status;
typedef int Elemtype;
using namespace std;

const int N = 100;

typedef struct Node
{
	Elemtype a[N];
	int length; 
}List;

void initList(List *L);//初始化表,并输入相关数据
void ClearList(List *L);//将一个表重置
bool isEmpty(List *L);//返回一个表是不是空表
Elemtype getElement(List *L, int pos);//取得某一位置的元素
int locateElement(List *L, Elemtype value);//找到符合某一条件的首元素的位置
Elemtype priorElement(List *L, int pos);//返回上一个元素
Elemtype nextElement(List *L, int pos);//返回后一个元素
void insertElement(List *L, Elemtype value, int pos);//在表中第i个位置插入元素
Elemtype deleteElement(List *L, int pos);//删除表中某位置的元素,并返回该元素	
void displayTheList(List *L);//将表中的数据全部输出到屏幕上
void uniteTowList(List *La, List *Lb, List *Lc);//合并两个顺序表
void listTraverse();//遍历？---未完成

int main(void)
{
	List L;
	L.length = 0;
	initList(&L);

    return 0;
}


void initList(List *L)
{	
	int n;
	cout<<"请输入表的长度 n = ";
	cin>>n;
	L->length = n;
	cout<<"请输入表中的个元素"<<endl;
	for(int i=0;i<n;i++){
		cin>>L->a[i];
	}
}

void displayTheList(List *L)
{
	cout<<"表的长度是"<<L->length<<endl;
	for(int i=0;i<L->length;i++){
		cout<<L->a[i];
		if(i%10 == 0 && i != 0) cout<<endl;
	}
	cout<<endl;
}

void insertElement(List *L, Elemtype value, int pos)
{
	if(L->length == N) cout<<"ERROR"<<endl;
	if(pos<1 || pos>L->length+1){
		cout<<"ERROR"<<endl;
	}else{
		for(int j=L->length;j>pos-1;j--){
			L->a[j] = L->a[j-1];
		}
		L->a[pos-1] = value;
		L->length++;
	}
}

Elemtype deleteElement(List *L, int pos)
{
	if(L->length == 0 || pos<1 || pos>L->length) return ERROR;
	Elemtype returnValue = L->a[pos-1];
	for(int i=pos-1;i<L->length;i++){
		L->a[i] = L->a[i+1];
	}
	L->length--;
	return returnValue;
}

int locateElement(List *L, Elemtype value)
{
	int i=0;
	while(i<=L->length && L->a[i] != value){
		i++;
	}
	if(i<=L->length-1){
		return i+1;
	}else
		return ERROR;
}

void uniteTowList(List *La, List *Lb, List *Lc)
{
	int posA, posB, posC;
	posA = posB = posC = 0;
	Lc->length = La->length + Lb->length;
	while(posA<La->length && posB<Lb->length){
		if(La->a[posA] <= Lb->a[posB]){
			Lc->a[posC] = La->a[posA];
			posA++;
			posC++;
		}else{
			Lc->a[posC] = Lb->a[posB];
			posB++;
			posC++;
		}
	}
	while(posA < La->length){
		Lc->a[posC] = La->a[posA];
		posA++;
		posC++;
	}
	while(posB < Lb->length){
		Lc->a[posC] = Lb->a[posB];
		posB++;
		posC++;
	}
}

void ClearList(List *L)
{
	for(int i=0;i<L->length;i++){
		L->a[i] = 0;
	}
	L->length = 0;
}

bool isEmpty(List *L)
{
	if(L->length == 0){
		return true;
	}else{
		return false;
	}
}

Elemtype getElement(List *L, int pos)
{
	return L->a[pos-1];
}

Elemtype priorElement(List *L, int pos)
{
	return L->a[pos-2];
}

Elemtype nextElement(List *L, int pos)
{
	return L->a[pos];
}
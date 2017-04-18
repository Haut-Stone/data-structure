/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-06 12:37:57
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-13 20:41:34
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

#define OK 1
#define ERROR -1
#define INFEASIBLE -1
#define OVERFLOWW -2//提示这个已经定义过了
#define INPUT_TEST freopen("in.txt", "r", stdin)

typedef int Status;
typedef int Elemtype;
using namespace std;

const int N = 100;

typedef struct Node
{
	Elemtype a[N];//一个具有定长的表
	int length; 
}List;

bool isEmpty(List &L);//返回一个表是不是空表
int locateElement(List &L, Elemtype value);//找到符合某一条件的首元素的位置
Elemtype getElement(List &L, int pos);//取得某一位置的元素
Elemtype priorElement(List &L, int pos);//返回上一个元素
Elemtype nextElement(List &L, int pos);//返回后一个元素
Elemtype deleteElement(List &L, int pos);//删除表中某位置的元素,并返回该元素	
void initList(List &L);//初始化表,并输入相关数据
void ClearList(List &L);//将一个表重置
void insertElement(List &L, Elemtype value, int pos);//在表中第i个位置插入元素
void displayTheList(List &L);//将表中的数据全部输出到屏幕上
void uniteTowList(List &La, List &Lb, List &Lc);//合并两个顺序表

int main(void)
{
	INPUT_TEST;

	List L;
	
	initList(L);//初始化一个表
	displayTheList(L);

	printf("%d\n", getElement(L, 3));//获得位置3的数字
	printf("%d\n", priorElement(L, 3));
	printf("%d\n", nextElement(L, 3));	

	deleteElement(L, 3);//删除3处的数字
	displayTheList(L);
	int pos = locateElement(L, 8);//找道8的位置
	printf("%d\n", pos);

	insertElement(L, 124, 4);//插入一个数字
	displayTheList(L);

	if(!isEmpty(L)){
		ClearList(L);
	}

	displayTheList(L);

	//合并链表
	List La;
	List Lb;
	List Lc;
	initList(La);
	initList(Lb);

	displayTheList(La);
	displayTheList(Lb);

	uniteTowList(La, Lb, Lc);

	displayTheList(Lc);

    return 0;
}


void initList(List &L)
{	
	int n;
	L.length = 0;
	// cout<<"乖乖输入表的长度噢！ n = ";
	cin>>n;
		L.length = n;
		// cout<<"请逐个输入表中的元素,以空格隔开"<<endl;
		for(int i=0;i<n;i++){
			cin>>L.a[i];
		}
}

void displayTheList(List &L)
{
	cout<<"表的长度是"<<L.length<<endl;
	for(int i=0;i<L.length;i++){
		cout<<L.a[i]<<' ';
		if(i%10 == 0 && i != 0) cout<<endl;
	}
	cout<<endl;
}

void insertElement(List &L, Elemtype value, int pos)
{
	if(L.length == N) cout<<"不好意思满员了(╯‵□′)╯︵┻━┻"<<endl;//队满的话无法插入
	if(pos<1 || pos>L.length+1){
		cout<<"想插队就找个正确的位置好不"<<endl;
	}else{
		for(int i=L.length;i>pos-1;i--){
			L.a[i] = L.a[i-1];
		}
		L.a[pos-1] = value;
		L.length++;
	}
}

Elemtype deleteElement(List &L, int pos)
{
	if(L.length == 0 || pos<1 || pos>L.length) return ERROR;
	Elemtype returnValue = L.a[pos-1];
	for(int i=pos-1;i<L.length;i++){
		L.a[i] = L.a[i+1];
	}
	L.length--;
	return returnValue;
}

int locateElement(List &L, Elemtype value)
{
	for(int i=0;i<L.length;i++){
		if(L.a[i] == value) return i+1;
	}
	return ERROR;
}

void uniteTowList(List &La, List &Lb, List &Lc)
{
	int posA, posB, posC;
	posA = posB = posC = 0;
	Lc.length = La.length + Lb.length;
	while(posA<La.length && posB<Lb.length){
		if(La.a[posA] <= Lb.a[posB]){
			Lc.a[posC] = La.a[posA];
			posA++;
			posC++;
		}else{
			Lc.a[posC] = Lb.a[posB];
			posB++;
			posC++;
		}
	}
	while(posA < La.length){
		Lc.a[posC] = La.a[posA];
		posA++;
		posC++;
	}
	while(posB < Lb.length){
		Lc.a[posC] = Lb.a[posB];
		posB++;
		posC++;
	}
}

void ClearList(List &L)
{
	for(int i=0;i<L.length;i++){
		L.a[i] = 0;
	}
	L.length = 0;
}

bool isEmpty(List &L)
{
	return L.length == 0 ? true:false;
}

Elemtype getElement(List &L, int pos)
{
	if(pos>=1 && pos<=L.length){
		return L.a[pos-1];
	}else{
		return ERROR;
	}
	
}

Elemtype priorElement(List &L, int pos)
{
	if(pos>=2 && pos<=L.length){
		return L.a[pos-2];
	}else{
		return ERROR;
	}
}

Elemtype nextElement(List &L, int pos)
{
	if(pos>=1 && pos<L.length){
		return L.a[pos];
	}else{
		return ERROR;
	}
}
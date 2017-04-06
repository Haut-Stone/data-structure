/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-06 12:38:31
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-06 13:59:48
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
#define ERROR -1
#define INFEASIBLE -1
#define OVERFLOWW -2//提示这个已经定义过了

typedef int Status;
typedef int Elemtype;
using namespace std;

typedef struct Node
{
	Elemtype value;
	struct Node *next;
}ListNode;


void initList();//建立新表
void destroyList();//破坏一个表
void ClearList();//将一个表重置
void isEmpty();//返回一个表是不是空表
void listLength();//返回表的长度
Elemtype getElement(ListNode *L, int i);//取得某一位置的元素
void deleteValue(ListNode *L, Elemtype value);//删除值等于某个数的第一个节点
void locateElement();//找到符合某一条件的首元素的位置
void priorElement();//返回上一个元素
void nextElement();//返回后一个元素
void insertElement(ListNode *L, int i, Elemtype value);//在表中某位置前插入元素
Elemtype deleteElement(ListNode *L, int i);//删除表中某位置的元素,并返回该被删元素的值
void listTraverse();//遍历？
ListNode* mergeTowList(ListNode *La, ListNode *Lb);

int main(void)
{

    return 0;
}

Elemtype getElement(ListNode *L, int i)
{
	ListNode *temp;
	temp = L->next;
	int j=1;
	while(temp && j<i){
		temp = temp->next;
		j++;
	}
	if(!temp || j>i){//失败的情况
		return ERROR;
	}else{
		return temp->value;
	}
}

Elemtype deleteElement(ListNode *L, int i)
{
	ListNode *temp1, *temp2;
	Elemtype value;
	int j = 0;
	temp1 = L;
	while(temp1 && j<i-1){//由于链表的缘故，需要先找到被删元素的上一个元素。
		temp1 = temp1->next;
		j++;
	}
	if(!temp1 || j>i-1){
		return ERROR; 
	}else{
		temp2 = temp1->next;
		value = temp2->value;
		temp1->next = temp2->next;
		delete(temp2);
		return value;
	}
}

void deleteValue(ListNode *L, Elemtype value)
{	
	ListNode *temp1, *temp2;
	temp1 = L;
	while(temp1->next && temp1->next->value != value){
		temp1 = temp1->next;
	}
	if(!temp1->next){
		cout<<"can't find value"<<endl;
	}else{
		temp2 = temp1->next;
		temp1->next = temp2->next;
		delete(temp2);
	}
}

ListNode* mergeTowList(ListNode *La, ListNode *Lb)
{
	ListNode *Lc;
	ListNode *posA, *posB, *posC;
	Lc = La;//以a链为基础
	posC = La;
	posA = La->next;
	posB = Lb->next;
	while(posA != NULL && posB != NULL){
		if(posA->value <= posB->value){
			posC->next = posA;
			posC = posA;
			posA = posA->next;
		}else{
			posC->next = posB;
			posC = posB;
			posB = posB->next;
		}
	}
	if(posA != NULL){
		posC->next = posA;
	}else{
		posC->next = posB;
	}
	delete(Lb);
	return Lc;
}

void insertElement(ListNode *L, int i, Elemtype value)
{
	ListNode *temp, *solo;
	int j = 1;
	temp = L;
	while(temp != NULL && j<i){
		temp = temp->next;
		j++;
	}
	if(temp == NULL || j>i){
		cout<<"can't find this position"<<endl;
	}else{
		solo = new ListNode;
		solo->value = value;
		solo->next = temp->next;
		temp->next = solo;
	}
}

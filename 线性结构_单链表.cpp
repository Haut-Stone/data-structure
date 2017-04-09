/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-06 12:38:31
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-06 22:00:29
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



void initList(ListNode *L);//建立新表
void ClearList();//将一个表重置
bool isEmpty();//返回一个表是不是空表
void listLength();//返回表的长度
Elemtype getElement(ListNode *L, int i);//取得某一位置的元素
void deleteValue(ListNode *L, Elemtype value);//删除值等于某个数的第一个节点
void locateElement();//找到符合某一条件的首元素的位置
void priorElement();//返回上一个元素
void nextElement();//返回后一个元素
void insertElement(ListNode *L, int i, Elemtype value);//在表中某位置前插入元素
Elemtype deleteElement(ListNode *L, int i);//删除表中某位置的元素,并返回该被删元素的值
ListNode* mergeTowList(ListNode *La, ListNode *Lb);//合并两个链表
void displayList(ListNode *L);//输出链表的值
ListNode* reversalList(ListNode *L);//将链表逆置
void listTraverse();//遍历？

int main(void)
{
	ListNode *head;
	head = new ListNode;
	head->next = NULL;
	initList(head);
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

void initList(ListNode *L)
{
	int n;
	Elemtype value;
	cout<<"请输入初始化链表的长度 n =";
	cin>>n;
	ListNode *temp, *solo;
	temp = L;
	cout<<"请输入链表个节点的值,以空格隔开"<<endl;
	while(n--){
		cin>>value;
		solo = new ListNode;
		solo->value = value;
		solo->next = NULL;
		temp->next = solo;
		temp = solo;
	}
}

void displayList(ListNode *L)
{
	ListNode *now;
	now = L->next;
	if(isEmpty()){
		cout<<"这个表是空表"<<endl;;
	}else{
		while(now != NULL){
			cout<<now->value<<" ";
			now = now->next;
		}
		cout<<endl;
	}
}

ListNode* reversalList(ListNode *L)
{
	ListNode *prior, *next, *current;//用三个指针来反转链表
	prior = L;
	current = L->next;
	next = current->next;
	prior->next = NULL;
	while(next->next != NULL){
		current->next = prior;
		prior = current;
		current = next;
		next = next->next;
	}
	current->next = prior;
	next->next = current;
	return next;
}
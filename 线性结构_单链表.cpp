/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-06 12:38:31
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-13 21:37:42
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

typedef struct Node
{
	Elemtype value;
	struct Node *next;
}ListNode;


bool isEmpty(ListNode *L);//返回一个表是不是空表
void initList(ListNode *L);//建立新表
void ClearList(ListNode *L);//将一个表重置
int listLength(ListNode *L);//返回表的长度
void deleteValue(ListNode *L, Elemtype value);//删除值等于某个数的第一个节点
// void locateElement();//找到符合某一条件的首元素的位置
// void priorElement();//返回上一个元素
// void nextElement();//返回后一个元素
void insertElement(ListNode *L, int i, Elemtype value);//在表中某位置前插入元素
void displayList(ListNode *L);//输出链表的值
void reversalList(ListNode *L);//将链表逆置
Elemtype getElement(ListNode *L, int i);//取得某一位置的元素
Elemtype deleteElement(ListNode *L, int i);//删除表中某位置的元素,并返回该被删元素的值
ListNode* mergeTowList(ListNode *La, ListNode *Lb);//合并两个链表

int main(void)
{
	INPUT_TEST;

	ListNode *head;
	head = new ListNode;
	head->next = NULL;

	initList(head);
	cout<<"读入数据后"<<endl;
	displayList(head);
	deleteElement(head, 3);
	cout<<"删除一个数据后"<<endl;
	displayList(head);
	insertElement(head, 10, 5);
	cout<<"插入一个数据后"<<endl;
	displayList(head);
	deleteValue(head, 10);
	cout<<"删除第一个符合条件的数据后"<<endl;
	displayList(head);
	reversalList(head);
	cout<<"反转链表后"<<endl;
	displayList(head);
	cout<<"单链表的长度是"<<listLength(head)<<endl;
	ClearList(head);
	cout<<"清空链表后"<<endl;
	displayList(head);
	
	ListNode *headA, *headB, *headC;
	headA = new ListNode;
	headA->next = NULL;
	headB = new ListNode;
	headB->next = NULL;

	initList(headA);
	initList(headB);
	headC = mergeTowList(headA, headB);
	cout<<"合并两个链表后"<<endl;
	displayList(headC);
    return 0;
}

bool isEmpty(ListNode *L)
{
	ListNode *temp;
	temp = L->next;
	if(temp == NULL){
		return true;
	}else{
		return false;
	}
}

void initList(ListNode *L)
{
	int n;
	Elemtype value;
	// cout<<"请输入初始化链表的长度 n =";
	cin>>n;
	ListNode *temp, *solo;
	temp = L;
	// cout<<"请输入链表个节点的值,以空格隔开"<<endl;
	while(n--){
		cin>>value;
		solo = new ListNode;
		solo->value = value;
		solo->next = NULL;
		temp->next = solo;
		temp = solo;
	}
}

void ClearList(ListNode *L)
{
	while(L->next != NULL){
		deleteElement(L, 1);
	}
}

int listLength(ListNode *L)
{
	int ans = 0;
	ListNode *temp;
	temp = L->next;
	while(temp != NULL){
		ans++;
		temp = temp->next;
	}
	return ans;
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
		delete temp2;
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
	delete Lb;
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

void displayList(ListNode *L)
{
	ListNode *now;
	now = L->next;
	if(now == NULL){
		cout<<"这个表是空表"<<endl;;
	}else{
		while(now != NULL){
			cout<<now->value<<" ";
			now = now->next;
		}
		cout<<endl;
	}
}

void reversalList(ListNode *L)
{
	ListNode *prior, *next, *current;//用三个指针来反转链表
	prior = L;
	current = L->next;
	if(current == NULL) return;//没有元素时直接返回
	next = current->next;
	if(next == NULL) return;//只有一个元素时也直接返回
	prior->next = NULL;
	while(next->next != NULL){
		if(prior != L){
			current->next = prior;
		}else{
			current->next = NULL;
		}
		prior = current;
		current = next;
		next = next->next;
	}
	if(prior != L){
		current->next = prior;
	}else{
		current->next = NULL;
	}
	next->next = current;
	L->next = next;
}
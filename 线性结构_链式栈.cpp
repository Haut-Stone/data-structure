/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-06 21:27:16
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-22 22:08:48
*/
#include <algorithm>
#include <iostream>

using namespace std;

#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOWW -2//提示这个已经定义过了

typedef int Status;
typedef int Elemtype;
using namespace std;

typedef struct Node
{
	Elemtype value;
	struct Node *next;
}StackNode;

StackNode* initStack();//构造一个空栈
void createStack(StackNode *top);//初始化栈中数据
// void destroyStack();//销毁一个栈
// void clearStack();//将一个栈清空
bool isEmpty(StackNode *top);//判断是不是空栈
int stackLength(StackNode *top);//返回栈的长度
Elemtype getTop(StackNode *top);//取得栈的顶部元素
void push(StackNode *top, Elemtype value);//向栈中添加元素
Elemtype pop(StackNode *top);//从栈中抛出元素，并返回其值
void displayTheStack(StackNode *top);

int main(void)
{
	StackNode *top;
	top = initStack();
	createStack(top);
	push(top, 10);
	push(top, 30);
	push(top, 40);
	displayTheStack(top);
	pop(top);
	displayTheStack(top);
	int ans = stackLength(top);
	printf("栈中的元素个数为%d\n", ans);
    return 0;
}

StackNode* initStack()
{
	StackNode *top;
	top = new StackNode;
	top->next = NULL;

	return top;
}

void createStack(StackNode *top)
{
	StackNode *solo;;
	int n;
	cout<<"请输入初始化的元素个数 n = ";
	cin>>n;
	cout<<endl<<"请依次输入各元素"<<endl;
	for(int i=0;i<n;i++){
		solo = new StackNode;
		cin>>solo->value;
		solo->next = top->next;
		top->next = solo;
	}
}

void displayTheStack(StackNode *top)
{
	StackNode *temp;
	temp = top->next;
	if(isEmpty(top)){
		cout<<"这是一个空栈"<<endl;
	}else{
		while(temp != NULL){
			cout<<temp->value<<" ";
			temp = temp->next;
		}
		cout<<endl;
	}
}

void push(StackNode *top, Elemtype value)
{
	StackNode *temp;
	temp = new StackNode;
	temp->value = value;
	temp->next = top->next;
	top->next = temp;
}	

Elemtype pop(StackNode *top)
{
	StackNode *temp;
	Elemtype returnValue;
	if(isEmpty(top)){
		cout<<"这是一个空栈"<<endl;
	}else{
		temp = top->next;
		top->next = top->next->next;
		returnValue = temp->value;
		delete temp;
		return returnValue;
	}
	return -1;
}

bool isEmpty(StackNode *top)
{
	if(top->next == NULL){
		return true;
	}else{
		return false;
	}
}

Elemtype getTop(StackNode *top)
{
	return top->next->value;
}

int stackLength(StackNode *top)
{
	int cnt;
	StackNode *temp;
	if(isEmpty(top)){
		return 0;
	}else{
		temp = top->next;
		cnt = 0;
		while(temp!=NULL){
			cnt++;
			temp = temp->next;
		}
		return cnt;
	}
}
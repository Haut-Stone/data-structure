/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-06 12:37:57
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-06 13:41:05
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
}ListNode;

void initList();//建立新表
void destroyList();//破坏一个表
void ClearList();//将一个表重置
void isEmpty();//返回一个表是不是空表
void listLength();//返回表的长度
void getElement();//取得某一位置的元素
void locateElement();//找到符合某一条件的首元素的位置
void priorElement();//返回上一个元素
void nextElement();//返回后一个元素
void insertElement();//在表中某位置插入元素
void deleteElement();//删除表中某位置的元素
void listTraverse();//遍历？


int main(void)
{

    return 0;
}
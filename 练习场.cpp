/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-03-23 20:04:15
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-03-27 22:46:57
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOWW -2//提示这个已经定义过了
typedef int Status;
typedef int Elemtype;
using namespace std;

const int N = 1000;

#if 1

//线性表
typedef struct Node
{
    int a[N];
    int length;
}List;

void initList1(List &L);
void initList2(List *L);
void insert(int solo);
void deleteElement(int index);

int main(void)
{
    List SL;
    initList1(SL);
    printf("%d\n", SL.length);
    initList2(&SL);
    printf("%d\n", SL.length);
    return 0;
}

void initList1(List &L)
{
    L.length = 1;
}

void initList2(List *L)
{
    L->length = 2;
}

#endif
/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-18 13:14:35
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-06-07 20:20:31
*/

//链式前向星实现：（数据规模较小时速度比不上邻接矩阵）


#include <iostream>
using namespace std;

const int N = 200010;//之前要调成题目要求的大小

struct Node
{
	int next;
	int to;
	// int w;//有权值的话，这一句启用
}edge[N*10];

int head[N];
int cnt;
int beginX;

void add(int u, int v, int w)//存一条以u为起点,v为终点,w为边权值的有向边。
{
	// edge[cnt].w = w;
	edge[cnt].to = v;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}

void init()
{
	cnt = 0;
	memset(head, -1, sizeof(head));
	memset(edge, 0, sizeof(edge));
}

int main(void)
{
	int u = beginX;
	for(int i=head[u];~i;i=edge[i].next){
		// int v = edge[i].to;//语法糖
		// int w = edge[i].w;
	}
    return 0;
}
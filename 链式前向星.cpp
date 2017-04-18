/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-18 13:14:35
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-18 15:56:35
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
using namespace std;

#define INPUT_TEST freopen("in.txt", "r", stdin)

const int N = 100;//之前要调成题目要求的大小

struct Node
{
	int next;
	int to;
	int w;//有权值的话，这一句启用
}edges[N];

int head[N];
int cnt;
int beginX;

void add(int u, int v, int w)//存一条以u为起点,v为终点,w为边权值的有向边。
{
	edges[cnt].w = w;
	edges[cnt].to = v;
	edges[cnt].next = head[u];
	head[u] = cnt;
	cnt++;
}

int main(void)
{
	for(int i=head[beginX];~i;i=edges[i].next){
		//遍历过程
	}
    return 0;
}
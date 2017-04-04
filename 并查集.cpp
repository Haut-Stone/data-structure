/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-03-30 18:45:17
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-03-30 18:55:20
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

const int N = 1000;

int par[N];//父节点
int Irank[N];//秩

void init(int n)
{
	for(int i=0;i<n;i++){
		par[i] = i;
		Irank[i] = 0;
	}
}


int find(int x)
{	
	if(par[x] == x){
		return x;
	}else{
		return par[x] = find(par[x]);//在一次搜索后会优化，将连接直接连到根上。
	}
}

void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if(x == y) return;
	if(Irank[x] > Irank[y]){
		par[y] = x;
	}else{
		par[x] = y;
		if(Irank[y] == Irank[x]) Irank[y]++;
	}
}

int main(void)
{

    return 0;
}

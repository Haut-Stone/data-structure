/*
 * Created by ShiJiahuan(li) in haut.
 * for more please visit www.shallweitalk.com
 *
 * Copyright 2017 SJH. All rights reserved.
 *
 * @Author: Haut-Stone
 * @Date:   2017-06-21 16:18:49
 * @Last Modified by:   Haut-Stone
 * @Last Modified time: 2017-06-21 18:41:19
 */

//很有用的一个小函数
//

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
#define INPUT_TEST freopen("in.txt", "r", stdin)
using namespace std;

const int N = 17;

struct Node
{
	int weight;
	int parent;
	int lChild;
	int rChild;
	int flag;
	Node(){
		weight = 0;
		parent = 0;
		lChild = 0;
		rChild = 0;
		flag = 0;
	}
	Node(int W, int P, int L, int R, int F){
		weight = W;
		parent = P;
		lChild = L;
		rChild = R;
		flag = F;
	}
}huffmanNode[N];

void makeTree(int NodeId, int depth);

stack<string> format, temp;
string a = "|   ";
string b = "    ";

int main(void)
{
	huffmanNode[1] = Node(5, 9, 0, 0, 0);
	huffmanNode[2] = Node(29, 14, 0, 0, 0);
	huffmanNode[3] = Node(7, 10, 0, 0, 0);
	huffmanNode[4] = Node(8, 10, 0, 0, 0);
	huffmanNode[5] = Node(14, 12, 0, 0, 0);
	huffmanNode[6] = Node(23, 13, 0, 0, 0);
	huffmanNode[7] = Node(3, 9, 0, 0, 0);
	huffmanNode[8] = Node(11, 11, 0, 0, 0);
	huffmanNode[9] = Node(8, 11, 1, 7 ,0);
	huffmanNode[10] = Node(15, 12, 3, 4, 0);
	huffmanNode[11] = Node(19, 13, 8, 9, 0);
	huffmanNode[12] = Node(29, 14, 5, 10, 0);
	huffmanNode[13] = Node(42, 15, 6, 11, 0);
	huffmanNode[14] = Node(58, 15, 2, 12, 0);
	huffmanNode[15] = Node(100, 0, 13, 14, 0);
	makeTree(15, 0);
	return 0;
}



void makeTree(int NodeId, int depth)
{
	//输出栈中的元素
	string c;
	while(!format.empty()){
		c = format.top();
		format.pop();
		temp.push(c);
	}

	while(!temp.empty()){
		c = temp.top();
		cout<<c;
		temp.pop();
		format.push(c);
	}

	cout<<"+---"<<huffmanNode[NodeId].weight<<endl;

	//如果父节点有左儿子
	if(huffmanNode[huffmanNode[NodeId].parent].lChild != 0 && huffmanNode[huffmanNode[NodeId].parent].flag == 0){
		format.push(a);
		huffmanNode[huffmanNode[NodeId].parent].flag = 1;
	}else{
		format.push(b);
	}
	
	if(huffmanNode[NodeId].rChild != 0) makeTree(huffmanNode[NodeId].rChild, depth + 1);
	if(huffmanNode[NodeId].lChild != 0) makeTree(huffmanNode[NodeId].lChild, depth + 1);

	format.pop();
}
/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-05-16 16:25:36
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-16 16:53:47
*/

//输入数据的格式是 字母个数 + 每个字母的权值 
//生成哈夫曼编码的种类可能有多种，基本不影响一个字符串的编码的长度。最好的效果时应该尽量是一颗完全二叉树。

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

const int N = 100;
const int INF = 99999999;

int n;
int weight[N];
char huffmanCode[N][N];

struct Node
{
	int id;
	int weight;
	int parent;
	int lChild;
	int rChild;
	int vis;
}vexter[N];

void huffmanCoding();
void strToCode();
void codeToStr();

int main(void)
{
	INPUT_TEST;

	// printf("输入字母的个数: ");
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>weight[i];
	}
	huffmanCoding();
	char temp = 'a';
	for(int i=1;i<=n;i++){
		cout<<temp<<": "<<huffmanCode[i]<<endl;
		temp++;
	}
	return 0;
}

void huffmanCoding()
{
	memset(vexter, 0, sizeof(vexter));
	for(int i=1;i<=n;i++){
		vexter[i].weight = weight[i];
		vexter[i].id = i;
	}
	int m = n*2-1;
	
	//建树部分
	for(int k=n+1;k<=m;k++){
		int min1 = INF;
		int min2 = INF;
		int id1 = 0;
		int id2 = 0;
		for(int i=1;i<=k-1;i++){
			if(vexter[i].vis == 0){
				if(vexter[i].weight < min2){
					if(vexter[i].weight < min1){
						min2 = min1;
						id2 = id1;
						min1 = vexter[i].weight;
						id1 = i;
					}else{
						min2 = vexter[i].weight;
						id2 = i;
					}
				}
			}
		}
		vexter[id1].parent = k;
		vexter[id2].parent = k;
		vexter[id1].vis = 1;
		vexter[id2].vis = 1;
		vexter[k].lChild = id1;
		vexter[k].rChild = id2;
		vexter[k].id = k;
		vexter[k].weight = min1 + min2;
	}
	
	// for(int i=1;i<=m;i++){
	// 	cout<<vexter[i].weight<<vexter[i].parent<<vexter[i].lChild<<vexter[i].rChild<<vexter[i].id<<endl;
	// }
	
	//编码部分
	memset(huffmanCode, 0, sizeof(huffmanCode));
	char code[N];
	code[n-1] = '\0';
	for(int i=1;i<=n;i++){
		int start = n-1;
		int now = i;
		int father = vexter[i].parent;
		while(father != 0){
			if(vexter[father].lChild == now){
				code[--start] = '0';
			}else{
				code[--start] = '1';
			}
			now = father;
			father = vexter[father].parent;
		}
		strcpy(huffmanCode[i], &code[start]);
	}
}

void strToCode()
{

}

void codeToStr()
{

}

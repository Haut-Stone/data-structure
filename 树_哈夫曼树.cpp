/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-05-16 16:25:36
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-06-20 19:17:31
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
char inStr[N];
char inCode[N];
char huffmanCode[N][N];

struct Node
{
	int id;
	int weight;
	int parent;
	int lChild;
	int rChild;
	int vis;
}vertex[N];

void huffmanCoding();
void strToCode(char inStr[], int len);
void codeToStr(char inCode[], int len);
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
	printf("please input the string:\n");
	scanf("%s", inStr);
	int len = strlen(inStr);
	strToCode(inStr, len);
	printf("please input the Code:\n");
	scanf("%s", inCode);
	len = strlen(inCode);
	codeToStr(inCode, len);
	return 0;
}

void huffmanCoding()
{
	memset(vertex, 0, sizeof(vertex));
	for(int i=1;i<=n;i++){
		vertex[i].weight = weight[i];
		vertex[i].id = i;
	}
	int m = n*2-1;
	
	//建树部分
	for(int k=n+1;k<=m;k++){
		int min1 = INF;
		int min2 = INF;
		int id1 = 0;
		int id2 = 0;
		for(int i=1;i<=k-1;i++){
			if(vertex[i].vis == 0){
				if(vertex[i].weight < min2){
					if(vertex[i].weight < min1){
						min2 = min1;
						id2 = id1;
						min1 = vertex[i].weight;
						id1 = i;
					}else{
						min2 = vertex[i].weight;
						id2 = i;
					}
				}
			}
		}
		vertex[id1].parent = k;
		vertex[id2].parent = k;
		vertex[id1].vis = 1;
		vertex[id2].vis = 1;
		vertex[k].lChild = id1;
		vertex[k].rChild = id2;
		vertex[k].id = k;
		vertex[k].weight = min1 + min2;
	}
	
	// for(int i=1;i<=m;i++){
	// 	cout<<vertex[i].weight<<vertex[i].parent<<vertex[i].lChild<<vertex[i].rChild<<vertex[i].id<<endl;
	// }
	
	//编码部分
	memset(huffmanCode, 0, sizeof(huffmanCode));
	char code[N];
	code[n-1] = '\0';
	for(int i=1;i<=n;i++){
		int start = n-1;
		int now = i;
		int father = vertex[i].parent;
		while(father != 0){
			if(vertex[father].lChild == now){
				code[--start] = '0';
			}else{
				code[--start] = '1';
			}
			now = father;
			father = vertex[father].parent;
		}
		strcpy(huffmanCode[i], &code[start]);
	}
}

void strToCode(char inStr[], int len)
{
    for(int i=0;i<len;i++){
        printf("%s", huffmanCode[inStr[i] - 'a' + 1]);
    }
    printf("\n");
    return;
}

void codeToStr(char inCode[], int len)
{
    int mapLen;
    int first = 0;

    while(first < len){
        for(int i=1;i<=n;i++){
            mapLen = strlen(huffmanCode[i]);
            char temp[N];
            for(int i=0;i<mapLen;i++){
                temp[i] = inCode[first + i];
                temp[i+1] = '\0';
            }
            if(strcmp(temp, huffmanCode[i]) == 0){
                printf("%c",'a' + i - 1);
                first += mapLen;
                break;
            }
        }
    }
    printf("\n");
}


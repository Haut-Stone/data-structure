/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-06-10 19:45:20
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-06-10 20:24:33
*/

//这是数据结构的作业。没有实际的价值意义
//这里的哈希用的是取余数的方法 H(key) = key MOD 13

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
#define SUCCESS 1
#define FAILD -1
#define INPUT_TEST freopen("in.txt", "r", stdin)
using namespace std;

const int N = 100;
const int INF = -1;
const int HASH_TABLE_LENGTH = 16;
const int MOD = 13;

int hashTable[N];
int averageSearchLength;
int num;
int solo;

int iHash(int x)
{
	int index = x % MOD;
	if(hashTable[index] == INF){
		hashTable[index] = x;
	}else{
		int temp = 1;
		while(1){
			int tempIndex = (index + temp) % HASH_TABLE_LENGTH;
			temp++;
			if(temp > HASH_TABLE_LENGTH) return FAILD;
			if(hashTable[tempIndex] == INF){
				hashTable[tempIndex] = x;
				break;
			}
		}
	}
	return SUCCESS;
}

int iSearch(int x)
{
	int index = x % MOD;
	if(hashTable[index] != x){
		int temp = 1;
		while(1){
			int tempIndex = (index + temp) % HASH_TABLE_LENGTH;
			temp++;
			if(temp > HASH_TABLE_LENGTH) return FAILD;
			if(hashTable[tempIndex] == x){
				return tempIndex;
			}
		}
	}else{
		return index;
	}
}

int main(void)
{
	while(~scanf("%d", &num)){
		memset(hashTable, INF, sizeof(hashTable));
		for(int i=0;i<num;i++){
			scanf("%d", &solo);
			iHash(solo);
		}
		for(int i=1;i<=100;i++){
			int ans = iSearch(i);
			if(ans == FAILD){
				printf("表里面没有数字 :%d\n", i);
			}else{
				printf("数字 :%d 在表里的位置是: %d\n", i, ans);
			}
		}
	}
	return 0;
}
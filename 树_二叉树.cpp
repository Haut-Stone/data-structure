/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-05-16 16:25:36
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-30 20:58:16
*/


#include <iostream>
#include <cstdio>
#define ERROR -1
#define OK 1
using namespace std;

struct treeNode
{
	char value;
	struct treeNode* leftChild;
	struct treeNode* rightChild;
};

//根据先序遍历建立树。
int createTree(treeNode* &temp)
{
	char c;
	scanf("%c", &c);
	if(c == '*'){
	   temp = NULL;
	}else{
		temp = new treeNode;
		if(temp == NULL) return ERROR;
		temp->value = c;
		createTree(temp->leftChild);
		createTree(temp->rightChild);
	}
	cout<<"OK"<<endl;
	return OK;
}

void last(treeNode* &solo)
{
	if(solo == NULL){
		return;
	}else{
		last(solo->leftChild);
		last(solo->rightChild);
		printf("%c ", solo->value);
	}
	return;
}


void pre(treeNode* &solo)
{
	if(solo == NULL){
		return;
	}else{
		printf("%c ", solo->value);
		pre(solo->leftChild);
		pre(solo->rightChild);
	}
}

void mid(treeNode* &solo)
{
	if(solo == NULL){
		return;
	}else{
		mid(solo->leftChild);
		printf("%c ", solo->value);
		mid(solo->rightChild);
	}
}

int main()
{
	treeNode* root;
	createTree(root);
	pre(root);
	mid(root);
	last(root);
}

//
// main.c
// stack
// Created by ShiJiahuan on 11/11/2016.
// copyright © 2016 ShiJiahuan.All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000
#define nil NULL

typedef struct {
	char elem[MAXSIZE];
	int top;
}Stack;

Stack S;

void initStack(){
	S.top = -1;
}

void push(char x){
	if(S.top >= MAXSIZE){
		printf("OverFlow\n");
		return;
	}
	S.top++;
	S.elem[S.top] = x;
}

void pop(){
	if(S.top == -1){
		printf("UnderFlow\n");
		return;
	}
	S.top--;
}

void printStark(){
	if(S.top == -1){
		printf(" No element here\n");
		return;
	}
	for (int i = 0; i < S.top; ++i)
	{
		printf("%c", S.elem[i]);
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	char str[MAXSIZE];
	fgets(str,MAXSIZE,stdin);
	initStack();

	for (int i = 0; i < MAXSIZE; ++i)
	{
		if(str[i] == '#'){
			pop();
		}else if (str[i] == '@')
		{
			initStack();
		}else if (str[i] == '\0')
		{
			break;
			/* code */
		}else{
			push(str[i]);
		}
	}
	printStark();
	return 0;
}
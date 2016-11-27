//
// main.c
// judgeTheSameTree
// Created by ShiJiahuan on 11/27/2016.
// Copyright ©️ 2016 ShiJiahuan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode{
    int value;
    struct treeNode *left;
    struct treeNode *right;
    int flag;
}treeNode, *tree;

tree makeTree(int N);
tree makeNewTreeNode(int tmp);
tree insertTreeNode(tree T, int tmp);

int judge(tree T, int N);
int checkNode(tree T, int tmp);
void resetFlag(tree T);
void freeTree(tree T);

int main(int argc, char const *argv[])
{
    int N, L;
    tree T = NULL;
    
    scanf("%d", &N);
    while(N){
        scanf("%d", &L);
        T = makeTree(N);
        for(int i=0;i<L;i++){
            if(judge(T, N)){
                printf("Yes\n");
            }else{
                printf("No\n");
            }
            resetFlag(T);
        }
        freeTree(T);
        scanf("%d", &N);
    }
    return 0;
}

tree makeTree(int N)
{
    tree T;
    int tmp;
    
    scanf("%d", &tmp);
    T = makeNewTreeNode(tmp);
    for(int i=1;i<N;i++){
        scanf("%d", &tmp);
        T = insertTreeNode(T, tmp);
    }
    return T;
}

tree makeNewTreeNode(int tmp)
{
    tree T;
    T = (tree)malloc(sizeof(treeNode));
    T->value = tmp;
    T->right = T->left = NULL;
    T->flag = 0;
    return T;
}

tree insertTreeNode(tree T, int tmp)
{
    if(!T){
        T = makeNewTreeNode(tmp);
    }else{
        if(tmp > T->value){
            T->right = insertTreeNode(T->right, tmp);
        }else{
            T->left = insertTreeNode(T->left, tmp);
        }
    }
    return T;
}

int judge(tree T, int N)
{
    int tmp, book = 0;
    scanf("%d", &tmp);
    if(tmp != T->value){
        book = 1;
    }else{
        T->flag = 1;
    }
    for(int i=1;i<N;i++){
        scanf("%d", &tmp);
        if((!book) && (!checkNode(T, tmp))) book = 1;
    }
    return !book;
}

int checkNode(tree T, int tmp)
{
    if(T->flag){
        if(tmp > T->value){
            return  checkNode(T->right, tmp);
        }else if(tmp < T->value){
            return  checkNode(T->left, tmp);
        }else{
            return 0;
        }
    }else{
        if(tmp == T->value){
            T->flag = 1;
            return 1;
        }else{
            return 0;
        }
    }
}

void resetFlag(tree T)
{
    if(T->left) resetFlag(T->left);
    if(T->right) resetFlag(T->right);
    T->flag = 0;
}

void freeTree(tree T)
{
    if(T->left) freeTree(T->left);
    if(T->right) freeTree(T->right);
    free(T);
}
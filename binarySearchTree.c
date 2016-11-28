
//
//  main.c
//  Binary Search Tree
//
//  Created by Jack Lee on 2016/11/28.
//  Copyright © 2016年 SJH. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node *left;
    struct Node *right;
} *Root, *SingleTreeNode;

Root makeTree(int N);
Root insertNode(SingleTreeNode treeNode, int temp);
SingleTreeNode makeNewNode(int temp);

int main()
{
    int N;
    Root tree1;
    
    scanf("%d", &N);
    tree1 = makeTree(N);
    
    return 0;
}

Root makeTree(int N)
{
    int temp;
    Root tree;
    
    scanf("%d", &temp);
    tree = makeNewNode(temp);//建立根节点
    for(int i=1;i<N;i++){
        scanf("%d", &temp);
        tree = insertNode(tree, temp);//逐一插入子节点
    }
    return tree;
}

Root insertNode(SingleTreeNode treeNode, int temp)
{
    if(!treeNode){
        treeNode = makeNewNode(temp);//当达到树顶时，递归达到基准条件
    }else{
        if(temp > treeNode->value){
            treeNode->right = insertNode(treeNode->right, temp);//递归右子树
        }else{
            treeNode->left = insertNode(treeNode->left, temp);//递归左子树
        }
    }
    return treeNode;
}

//建立新的节点
SingleTreeNode makeNewNode(int temp)
{
    SingleTreeNode node;
    node = (SingleTreeNode)malloc(sizeof(struct Node));
    node->value = temp;
    node->left = node->right = NULL;
    return node;
}
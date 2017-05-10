#include<iostream>
#include<cstdio>
#define ERROR -1
#define OK 1
using namespace std;

const int N = 100;

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
        //cout<<endl;
        return;
    }else{
        last(solo->leftChild);
        last(solo->rightChild);
        printf("%c ", solo->value);
    }
    return;
}

int main()
{
    treeNode* root;
    createTree(root);
    last(root);
}

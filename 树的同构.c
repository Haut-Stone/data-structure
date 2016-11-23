#include <stdio.h>
#define MaxTree 10

typedef struct treeNode{
    char element;
    int left;
    int right;
}BinTree;
BinTree T1[MaxTree], T2[MaxTree];

int BuildTree(BinTree T[]);
int Isomorphic(int root1, int root2);

int main(int argc, char const *argv[])
{
    int root1, root2;
    root1 = BuildTree(T1);
    root2 = BuildTree(T2);
    if(Isomorphic(root1, root2)){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}

int BuildTree(BinTree T[])
{
    int N;
    scanf("%d" , &N);
    char cl, cr;
    int check[MaxTree] = {1};
    for(int i=0;i<N;i++){
        scanf("%c %c %c", &T[i].element, &cl, &cr);
        if(cl != '-'){
            T[i].left = cl - '0';
            check[T[i].left] = 0;
        }else{
            T[i].left = -1;
        }
        if(cr != '-'){
            T[i].right = cr - '0';
            check[T[i].right] = 0;
        }else{
            T[i].right = -1;
        }
    }
    for(int i=0;i<N;i++){
        if(check[i]){
            return i;
        }
    }
    return 0;
}

int Isomorphic(int root1, int root2)
{
    if(root1 == -1 && root2 == -1){
        return 1;
    }
    if((root1 != -1 && root2 == -1) || (root1 == -1 && root2 != -1)){
        return 0;
    }else{
        if(T1[root1].element != T2[root2].element)
            return 0;
        if(T1[root1].left == -1 && T2[root2].left == -1)
            return Isomorphic(T1[root1].right, T2[root2].right);
        if(T1[root1].left != -1 && T2[root2].left != -1 && T1[T1[root1].left].element == T2[T2[root2].left].element)
            return ( Isomorphic(T1[root1].left, T2[root2].left) && Isomorphic(T1[root1].right, T2[root2].right) );
        if((T1[root1].left != -1 && T2[root2].left == -1) || (T1[root1].left == -1 && T2[root2].left != -1))
            return ( Isomorphic(T1[root1].left, T2[root2].right) && Isomorphic(T1[root1].right, T2[root2].left) );
    }
    return 0;
}
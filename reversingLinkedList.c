#include <stdio.h>


#define MAX_SIZE 100001


typedef struct node{
    int address;
    int data;
    int next_address;
    struct node * next;
} Node;


Node * ListReverse(Node * L, int k);
void PrintList(Node * L);


int main(int argc, char const *argv[])
{
    int first_address;//首地址
    int temp_address;//临时变量，输入的时候用
    int n = 0;//节点数 N
    int k = 0;//反转子链表的长度K
    int num = 0;//链表建好之后的链表节点数
    int Data[MAX_SIZE];//存data值 节点位置作为索引值
    int Next_address[MAX_SIZE];//存next_address值 节点位置为索引
    int i = 0;
    scanf("%d %d %d", &first_address, &n, &k);
    Node a[n+1];
    a[0].next_address = first_address;
    for(; i < n; i++){
        scanf("%d", &temp_address);
        scanf("%d %d", &Data[temp_address], &Next_address[temp_address]);
    }
    i = 1;
    while(1){
        if(a[i-1].next_address == -1){
            a[i-1].next = NULL;
            num = i - 1;
            break;
        }
        a[i].address = a[i-1].next_address;
        a[i].data = Data[a[i].address];
        a[i].next_address = Next_address[a[i].address];
        a[i-1].next = a + i;
        i++;
    }
    
    
    Node *p = a;
    Node *rp = NULL;//rp:反转链表函数的返回值
    if(k <= num){
        for (int i = 0; i < (num/k); i++){
            rp = ListReverse(p, k);
            p->next = rp;
            p->next_address = rp->address;
            for (int j = 0; j < k; j++){
                p = p->next;//使p指向下一段需要反转的子链表的头结点（第一个节点的前一个节点）
            }
        }
    }
    PrintList(a);
    return 0;
}


Node * ListReverse(Node * L, int k)
{
    int count = 1;
    Node * current, * pnext, * prev;
    current = L->next;//定义当前结点 current，初始值为首元结点，current = L->next;
    pnext = current->next;//定义当前结点的后继结点 pnext， pnext = current->next;
    while(count < k){
        prev = pnext->next;//定义新节点 prev，它是 pnext的后继结点，prev = pnext->next;
        pnext->next = current;//把pnext的后继指向current, pnext->next = current;
        pnext->next_address = current->address;
        current = pnext;//此时，pnext 实际上已经到了 current 前一位成为新的current，所以这个时候 current 结点实际上成为新的 pnext，current = pnext;
        pnext = prev;//而新的 pnext 就是 prev，pnext = prev;
        count++;
    }
    L->next->next = pnext;//使反转后的最后一个节点指向下一段子链表的第一个节点
    if(pnext != NULL){
        L->next->next_address = pnext->address;
    }else{
        L->next->next_address = -1;
    }
    return current;
}


void PrintList(Node * L)
{
    Node * P = L;
    while(P->next != NULL){
        P = P->next;
        if(P->next_address == -1)
            printf("%.5d %d %d\n", P->address, P->data, P->next_address);//格式输出，%.5意味着如果一个整数不足5位，输出时前面补0 如：22，输出：00022
        else
            printf("%.5d %d %.5d\n", P->address, P->data, P->next_address);
    }
}
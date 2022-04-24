//思路：设置伴随指针prep，保证和p相距k
//注意：表长小于k
#include<stdio.h>
#include<stdlib.h>
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define OVERFLOW   -2
typedef int Status;
typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;
Status CreatLinkList(LinkList &L){
    LinkList cur = NULL, p = NULL;
    L = (LNode *)malloc(sizeof(LNode));
    if(!L)exit(OVERFLOW);
    L->next = NULL;
    p = L;
    while(1){
        ElemType mid = 0;
        scanf("%d", &mid);
        if(mid < 0)
            break;
        cur = (LNode *)malloc(sizeof(LNode));
        if(!cur)exit(OVERFLOW);
        cur->next = NULL;
        cur->data = mid;
        getchar();
        p->next = cur;
        p = p->next;
    }
    return OK;
}
int main (){
    int k = 0, cou = 0;
    LinkList L = NULL, q = NULL, preq = NULL;
    scanf("%d", &k);
    if(CreatLinkList(L) != OK){
        return ERROR;
    }
    q = L->next;
    while(q){
        q = q->next;
        cou++;
        if(cou == k){
            preq = L->next;
            break;
        }
    }
    if(preq == NULL)
        printf("NULL");
    else{
        while(q){
            q = q->next;
            preq = preq->next;
        }
        printf("%d", preq->data);
    }
    return 0;
}
/*
//思路：设置伴随指针prep，保证和p相距k，在建表的同时这设置指针偏移，优点：够快，缺点：封装性不好
//注意：表长小于k
#include<stdio.h>
#include<stdlib.h>
#define OVERFLOW -1
#define ERROR 0
typedef int Elemtype;
typedef struct LNode{
    Elemtype data;
    struct LNode *next;
}LNode,*LinkList;
int main(){
    LinkList L,p,cur,rear;
    int k,len=0;
    scanf("%d",&k);
    if(k<=0)return ERROR;
    L=(LNode *)malloc(sizeof(LNode));
    if(!L)exit(OVERFLOW);
    L->next=NULL;
    rear=p=L;
    while(1){
        cur=(LNode *)malloc(sizeof(LNode));
        if(!cur)exit(OVERFLOW);
        cur->next=NULL;
        scanf("%d",&(cur->data));
        if(len>k-1){//p比rear少下移k-1次
            p=p->next;
        }
        if(cur->data<0)break;
        rear->next=cur;
        rear=cur;
        ++len;
    }
    if(p->next==L->next){//不存在倒数第k个位置
        printf("NULL");
        return 0;
    }
    printf("%d",p->data);
    return 0;
}
*/

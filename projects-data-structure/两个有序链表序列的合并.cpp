//˼·��������ֱ��ǰ����������ͬʱ�Ƚϣ�С������L3��ֱ����һ����Ϊ�գ��ٽ�ʣ�µ�Ԫ�����ӵ�L3����
//ע�⣺Ԫ����ȵ����,������Ϊ��
#include<stdio.h>
#include<stdlib.h>
#define OVERFLOW -1
#define OK 1
typedef int Status;
typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode* next;
}LNode,*LinkList;
Status CreateList_L(LinkList &L){//&���ñ���
    LinkList curPtr,rearPtr;
    L=(LNode *)malloc(sizeof(LNode));
    if(!L)exit(OVERFLOW);
    L->next=NULL;
    curPtr=(LNode *)malloc(sizeof(LNode));
    if(!curPtr)exit(OVERFLOW);
    rearPtr=L;
    scanf("%d",&curPtr->data);
    while(-1!=curPtr->data){
        curPtr->next=NULL;
        rearPtr->next=curPtr;
        rearPtr=curPtr;
        curPtr=(LNode *)malloc(sizeof(LNode));
        if(!curPtr)exit(OVERFLOW);
        scanf("%d",&curPtr->data);
    }
    if(-1==curPtr->data){
        free(curPtr);
        rearPtr=NULL;
    }
    return OK;
}
Status PrintList_L(LinkList &L){
    LNode *p=L->next;
    if(p==NULL)
        printf("NULL");
    while(p){
        if(p->next==NULL)
            printf("%d",p->data);
        else
            printf("%d ",p->data);
        p=p->next;
    }
    return OK;
}
Status MergeList_L(LinkList &L1,LinkList &L2,LinkList &L3){
    LinkList p1=L1->next,p2=L2->next,p3=L3;
    while(p1&&p2){
        if(p1->data<=p2->data){
            p3->next=p1;
            p3=p1;
            p1=p1->next;
        }
        else{
            p3->next=p2;
            p3=p2;
            p2=p2->next;
        }
    }
    if(p1)
        p3->next=p1;
    else if(p2)
        p3->next=p2;//���������Ϊ����L3����ֵ
}
int main(){
    LinkList L1,L2,L3;
    if(CreateList_L(L1)!=OK)
        printf("FALSE");
    if(CreateList_L(L2)!=OK)
        printf("FALSE");
    L3=(LNode *)malloc(sizeof(LNode));
    if(!L3)exit(OVERFLOW);
    L3->next=NULL;
    MergeList_L(L1,L2,L3);
    PrintList_L(L3);
    return 0;
}

//�⺯��ͷ�ļ�����
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

//����״̬�붨��
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE -1
#define OVERFLOW   -2

typedef int  Status;
typedef int  ElemType; //�������Ա��е�Ԫ�ؾ�Ϊ����

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

Status ListCreate_L(LinkList &L,int n)
{
    LNode *rearPtr,*curPtr;   //һ��βָ�룬һ��ָ���½ڵ��ָ��
    L=(LNode*)malloc(sizeof (LNode));
    if(!L)exit(OVERFLOW);
    L->next=NULL;               //�Ƚ���һ����ͷ���ĵ�����
    rearPtr=L;  //��ʼʱͷ���Ϊβ�ڵ�,rearPtrָ��β�ͽڵ�
    for (int i=1;i<=n;i++){  //ÿ��ѭ��������һ���½ڵ㣬�����½ڵ�ƴ��β�ڵ��
        curPtr=(LNode*)malloc(sizeof(LNode));//�����½��
        if(!curPtr)exit(OVERFLOW);
        scanf("%d",&curPtr->data);//����Ԫ��ֵ
        curPtr->next=NULL;  //���һ���ڵ��next����
        rearPtr->next=curPtr;
        rearPtr=curPtr;
    }
    return OK;
}
void ListReverse_L(LinkList &L);
void ListPrint_L(LinkList &L){
//���������
    LNode *p=L->next;  //pָ���һ��Ԫ�ؽ��
    while(p!=NULL)
    {
          if(p->next!=NULL)
               printf("%d ",p->data);
          else
               printf("%d",p->data);
          p=p->next;
    }
}
int main()
{
    LinkList L;
    int n;
    scanf("%d",&n);
    if(ListCreate_L(L,n)!= OK) {
          printf("����ʧ�ܣ�����\n");
          return -1;
    }
    ListReverse_L(L);
    ListPrint_L(L);
    return 0;
}

//˼·��ͷ�巨����ԭ��ĵ�һ��Ԫ��next���գ��Ժ��ÿһ��Ԫ�ص���������L�ĺ���
//ע�⣺�ձ��ֻ��һ��Ԫ��
void ListReverse_L(LinkList &L){

    if(!L||!L->next)
        exit(FALSE);
    LinkList p=L->next,q=p->next;
    p->next=NULL;
    while(q){
        L->next=q;
        q=q->next;
        L->next->next=p;
        p=L->next;
    }
}

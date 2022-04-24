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
#define NULL        0

typedef int  Status;
typedef int  ElemType; //�������Ա��е�Ԫ�ؾ�Ϊ����

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

//����������
Status ListCreate_L(LinkList &L,int n)
{
    LNode *rearPtr,*curPtr;
    L=(LNode*)malloc(sizeof (LNode));
    if(!L)exit(OVERFLOW);
    L->next=NULL;
    rearPtr=L;
    for (int i=1;i<=n;i++){
        curPtr=(LNode*)malloc(sizeof(LNode));
        if(!curPtr)exit(OVERFLOW);
        scanf("%d",&curPtr->data);
        curPtr->next=NULL;
        rearPtr->next=curPtr;
        rearPtr=curPtr;
    }
    return OK;
}
//�����������
void ListPrint_L(LinkList L)
{
	LNode *p=L->next;
	if(!p){
	    printf("�ձ�");
	    return;
	}
	while(p!=NULL)
	{
       if(p->next!=NULL)
           printf("%d ",p->data);
       else
           printf("%d",p->data);
   	   p=p->next;
	}
}
//��������Ҫʵ�ֵĺ���������
void ListLocateAndDel_L(LinkList L, ElemType x);

int main()
{
    LinkList L;
    int n;
    int x;
    scanf("%d",&n);  //����������Ԫ�ظ���
    if(ListCreate_L(L,n)!= OK) {
          printf("����ʧ�ܣ�����\n");
          return -1;
    }
   scanf("%d",&x); //���������Ԫ��
   ListLocateAndDel_L(L,x);
   ListPrint_L(L);
   return 0;
}

//˼·������һ�飬��¼���һ��Ŀ��Ԫ��ǰһ��Ԫ�ص�λ�ã�֮��ֱ��ɾ��
//ע�⣺Ҫɾ�����ǵ�һ��Ԫ�غ����һ��Ԫ�ص����,free
void ListLocateAndDel_L(LinkList L, ElemType x){
    LinkList p=L->next;//��һ��Ԫ�ص�λ��
    LinkList curq=NULL,q=NULL,q1;//q��¼��Ҫɾ��Ԫ�ص�ǰһ��Ԫ�ص�λ��,q1=q->next
    int cou=0;
    while(p){
        ++cou;
        if(p&&p->data==x){
            q=curq;
            if(cou==1)
                q=L;
        }
        curq=p;
        p=p->next;
    }
    if(!q)
        return;
    q1=q->next;
    q->next=q1->next;
    free(q1);
}

//库函数头文件包含
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

//函数状态码定义
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE -1
#define OVERFLOW   -2
#define NULL        0

typedef int  Status;
typedef int  ElemType; //假设线性表中的元素均为整型

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

//链表创建函数
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
//链表输出函数
void ListPrint_L(LinkList L)
{
	LNode *p=L->next;
	if(!p){
	    printf("空表");
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
//下面是需要实现的函数的声明
void ListLocateAndDel_L(LinkList L, ElemType x);

int main()
{
    LinkList L;
    int n;
    int x;
    scanf("%d",&n);  //输入链表中元素个数
    if(ListCreate_L(L,n)!= OK) {
          printf("表创建失败！！！\n");
          return -1;
    }
   scanf("%d",&x); //输入待查找元素
   ListLocateAndDel_L(L,x);
   ListPrint_L(L);
   return 0;
}

//思路：遍历一遍，记录最后一个目标元素前一个元素的位置，之后直接删除
//注意：要删除的是第一个元素和最后一个元素的情况,free
void ListLocateAndDel_L(LinkList L, ElemType x){
    LinkList p=L->next;//第一个元素的位置
    LinkList curq=NULL,q=NULL,q1;//q记录需要删除元素的前一个元素的位置,q1=q->next
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

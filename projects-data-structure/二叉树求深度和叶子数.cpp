//ͷ�ļ�����
#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>

//����״̬�붨��
#define TRUE       1
#define FALSE      0
#define OK         1
#define ERROR      0
#define OVERFLOW   -1
#define INFEASIBLE -2
typedef int Status;

//��������洢�ṹ����
typedef int TElemType;
typedef struct BiTNode{
    TElemType data;
    struct BiTNode  *lchild, *rchild;
} BiTNode, *BiTree;

//��������������㣬���������������
//���õݹ��˼�봴��
//�ݹ�߽磺������δ����أ�ֱ������0��
//�ݹ��ϵ���ǿ����Ĵ������⣬���Թ��Ϊ�ȴ������ڵ㣬������������ֵ���ٴ�������������󴴽������������������ݹ鼴����ɴ�����

Status CreateBiTree(BiTree &T){
   TElemType e;
   scanf("%d",&e);
   if(e==0)T=NULL;
   else{
     T=(BiTree)malloc(sizeof(BiTNode));
     if(!T)exit(OVERFLOW);
     T->data=e;
     CreateBiTree(T->lchild);
     CreateBiTree(T->rchild);
   }
   return OK;
}

//��������Ҫʵ�ֵĺ���������
int GetDepthOfBiTree ( BiTree T);
int LeafCount(BiTree T);
//������������
int main()
{
   BiTree T;
   int depth, numberOfLeaves;
   CreateBiTree(T);
   depth= GetDepthOfBiTree(T);
   numberOfLeaves=LeafCount(T);
   printf("%d %d\n",depth,numberOfLeaves);
}

//˼·���ݹ鵽�������Ϊ0���������Ϊ��������������������+1
//ע�⣺��ȱ����Ķ���
int GetDepthOfBiTree ( BiTree T){
    static int depth = 0;
    int ldepth = 0, rdepth = 0;
    if(!T){
        depth = 0;
    }
    else{
        ldepth = GetDepthOfBiTree(T->lchild);
        rdepth = GetDepthOfBiTree(T->rchild);
        if(ldepth > rdepth){//��������������
            depth = ldepth + 1;
        }
        else{//��������������
            depth = rdepth + 1;
        }
    }
    return depth;
}

//˼·�����������������һ���ڵ㣬����ڵ�
int LeafCount (BiTree T){
    static int num = 0;
    int lnum = 0, rnum = 0;
    if(!T){
        num = 0;
    }
    else if(!T->lchild && !T->rchild){
        num = 1;
    }
    else{
        if(T->lchild)
            lnum = LeafCount(T->lchild);
        if(T->rchild)
            rnum = LeafCount(T->rchild);
        num = lnum + rnum;
    }
    return num;
}

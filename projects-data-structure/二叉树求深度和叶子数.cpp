//头文件包含
#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>

//函数状态码定义
#define TRUE       1
#define FALSE      0
#define OK         1
#define ERROR      0
#define OVERFLOW   -1
#define INFEASIBLE -2
typedef int Status;

//二叉链表存储结构定义
typedef int TElemType;
typedef struct BiTNode{
    TElemType data;
    struct BiTNode  *lchild, *rchild;
} BiTNode, *BiTree;

//创建二叉树各结点，输入零代表创建空树
//采用递归的思想创建
//递归边界：空树如何创建呢：直接输入0；
//递归关系：非空树的创建问题，可以归结为先创建根节点，输入其数据域值；再创建左子树；最后创建右子树。左右子树递归即可完成创建！

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

//下面是需要实现的函数的声明
int GetDepthOfBiTree ( BiTree T);
int LeafCount(BiTree T);
//下面是主函数
int main()
{
   BiTree T;
   int depth, numberOfLeaves;
   CreateBiTree(T);
   depth= GetDepthOfBiTree(T);
   numberOfLeaves=LeafCount(T);
   printf("%d %d\n",depth,numberOfLeaves);
}

//思路：递归到空树深度为0，树的深度为左子树或右子树最大深度+1
//注意：深度变量的定义
int GetDepthOfBiTree ( BiTree T){
    static int depth = 0;
    int ldepth = 0, rdepth = 0;
    if(!T){
        depth = 0;
    }
    else{
        ldepth = GetDepthOfBiTree(T->lchild);
        rdepth = GetDepthOfBiTree(T->rchild);
        if(ldepth > rdepth){//左子树是最大深度
            depth = ldepth + 1;
        }
        else{//右子树是最大深度
            depth = rdepth + 1;
        }
    }
    return depth;
}

//思路：三种情况，空树，一个节点，多个节点
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

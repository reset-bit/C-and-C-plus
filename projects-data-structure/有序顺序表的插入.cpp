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
typedef int  Status;
//顺序表的存储结构定义
#define LIST_INIT_SIZE  100
#define LISTINCREMENT   10
typedef int ElemType;  //假设线性表中的元素均为整型
typedef struct{
    ElemType* elem;   //存储空间基地址
    int length;       //表中元素的个数
    int listsize;     //表容量大小
}SqList;    //顺序表类型定义
//函数声明
Status ListInsert_SortedSq(SqList &L, ElemType e);
//顺序表初始化函数
Status InitList_Sq(SqList &L)
{
    //开辟一段空间
    L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    //检测开辟是否成功
    if(!L.elem){
        exit(OVERFLOW);
    }
    //赋值
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}
//顺序表输出函数
void ListPrint_Sq(SqList L)
{
    ElemType *p = L.elem;//遍历元素用的指针
    for(int i = 0; i < L.length; ++i){
        if(i == L.length - 1){
            printf("%d", *(p+i));
        }
        else{
            printf("%d ", *(p+i));
        }
    }
}
int main()
{
    //声明一个顺序表
    SqList L;
    //初始化顺序表
    InitList_Sq(L);
    int number = 0;
    ElemType e;
     scanf("%d", &number);//插入数据的个数
    for(int i = 0; i < number; ++i)
    {
        scanf("%d", &e);//输入数据
        ListInsert_SortedSq(L, e);
    }
    ListPrint_Sq(L);
    return  0;
}
//思路：将待插入元素从后向前比较，若待插入元素大直接插入，若小则向前重复操作并将已比较过的元素后移，用指针！！
//注意：扩容，表长，取值取到首元素
Status ListInsert_SortedSq(SqList &L, ElemType e){
    int *p;
    if(L.listsize==L.length)//表长和储存空间相等，意味着空间已满，需重新分配
{
        L.elem=(ElemType*)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
        if(!L.elem)exit(OVERFLOW);
        L.listsize+=LISTINCREMENT;
    }
    p=L.elem+L.length-1;
    for(;p!=NULL && e<*p;--p){
        *(p+1)=*p;
    }
    if(e>=*p||NULL==p)
        *(p+1)=e;
    L.length++;
    return OK;
}




/*思路：将插入数据与最后一个元素进行比较，若小则向前进行重复操作且已比较过的元素后移，若大则直接插入
//注意：等于的情况,扩容的情况
Status ListInsert_SortedSq(SqList &L, ElemType e){
    int i=1,p=0;//i用于扩容，p用于比较元素
    while(L.length==L.listsize){
        L.elem=(ElemType *)realloc(L.elem,(LIST_INIT_SIZE+i*LISTINCREMENT)*sizeof(ElemType));
        if(!L.elem)
            exit(OVERFLOW);
        L.listsize=LIST_INIT_SIZE+i*LISTINCREMENT;
        ++i;
    }
    if(L.length==0){//只有1个元素的情况
        *L.elem=e;
        ++L.length;
        return OK;
    }
    for(;p<L.length;++p){
        if(e>=*(L.elem+L.length-1-p)){
            if(p==0){//e插入在最后的情况
                *(L.elem+L.length)=e;
                break;
            }
            else{//e插入在中间的情况
                *(L.elem+L.length-p)=e;
                break;
            }
        }
        if(e<*(L.elem+L.length-1-p)){//e需要向前移动的情况
            *(L.elem+L.length-p)=*(L.elem+L.length-1-p);
        }
        if(p==L.length-1){//e移动到第一个元素的情况
            *L.elem=e;
            break;
        }
    }
    ++L.length;
    return OK;
}
*/

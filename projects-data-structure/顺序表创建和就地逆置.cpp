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

Status ListCreate_Sq(SqList &L);
void ListReverse_Sq(SqList &L);

int main() {
    SqList L;
    ElemType *p;

    if(ListCreate_Sq(L)!= OK) {
        printf("ListCreate_Sq: 创建失败！！！\n");
        return -1;
    }
    if(L.length){
        for(p=L.elem;p<L.elem+L.length-1;++p){
            printf("%d ",*p);
        }
        printf("%d\n",*p);
    }

    ListReverse_Sq(L);

    if(L.length){
        for(p=L.elem;p<L.elem+L.length-1;++p){
            printf("%d ",*p);
        }
        printf("%d",*p);
    }
    return 0;
}

//思路：顺序表初始化并赋初值
//注意：输入元素个数大于表长需扩容。
Status ListCreate_Sq(SqList &L){
    int i,listlength;//i用于判断扩容时要扩几次
    scanf("%d",&listlength);
    L.elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    L.listsize=LIST_INIT_SIZE;
    L.length=0;
    for(i=1;L.listsize<listlength;++i){//判断扩容
        L.elem=(ElemType *)realloc(L.elem,(LIST_INIT_SIZE+i*LISTINCREMENT)*sizeof(ElemType));
        L.listsize=LIST_INIT_SIZE+i*LISTINCREMENT;
    }
    if(!L.elem)
        exit(OVERFLOW);
    for(;L.length<listlength;L.length++){
        scanf("%d",L.elem+L.length);
    }
    return OK;
}
//思路：利用第三变量交换两元素位置，分为奇数情况和偶数情况
void ListReverse_Sq(SqList &L){
    int p,q;//p用于交换两个元素的位置（中间量临时存储），q用于交换元素时计数
    if(L.length%2==0)
        q=L.length/2;
    else
        q=(L.length-1)/2;
    while(q>=0){
        p=*(L.elem+q-1);//q和length表示位序，要-1
        *(L.elem+q-1)=*(L.elem+L.length-q);//L.elem+L.length-q即L.elem+L.length-1-(q-1)
        *(L.elem+L.length-q)=p;
        --q;
    }
}

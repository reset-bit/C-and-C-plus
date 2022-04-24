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
Status ListInsert_Sq(SqList &L, int pos, ElemType e);
Status ListDelete_Sq(SqList &L, int pos, ElemType &e);
int ListLocate_Sq(SqList L, ElemType e);
void ListPrint_Sq(SqList L);
//结构初始化与销毁操作
Status InitList_Sq(SqList &L){
  //初始化L为一个空的有序顺序表
    L.elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!L.elem)exit(OVERFLOW);
    L.listsize=LIST_INIT_SIZE;
    L.length=0;
    return OK;
}
int main() {
    SqList L;
    if(InitList_Sq(L)!= OK) {
        printf("InitList_Sq: 初始化失败！！！\n");
        return -1;
    }
    for(int i = 1; i <= 10; ++ i)
        ListInsert_Sq(L, i, i);

    int operationNumber;  //操作次数
    scanf("%d", &operationNumber);

    while(operationNumber != 0) {
        int operationType;  //操作种类
        scanf("%d", & operationType);

        if(operationType == 1) {  //增加操作
            int pos, elem;
            scanf("%d%d", &pos, &elem);
            ListInsert_Sq(L, pos, elem);
        } else if(operationType == 2) {  //删除操作
             int pos; ElemType elem;
             scanf("%d", &pos);
             ListDelete_Sq(L, pos, elem);
             printf("%d\n", elem);
        } else if(operationType == 3) {  //查找定位操作
            ElemType elem;
            scanf("%d", &elem);
            int pos = ListLocate_Sq(L, elem);
            if(pos >= 1 && pos <= L.length)
                printf("%d\n", pos);
            else
                printf("NOT FIND!\n");
        } else if(operationType == 4) {  //输出操作
            ListPrint_Sq(L);
        }
       operationNumber--;
    }
    return 0;
}

/*ListInsert_Sq思路：加元素至L->elem+pos-1，后继元素后移，表长+1，考虑溢出风险*/
Status ListInsert_Sq(SqList &L,int pos,ElemType e){
    int i;
    if(L.length==L.listsize){
        L.elem=(ElemType*)realloc(L.elem,(LIST_INIT_SIZE+LISTINCREMENT)*sizeof(L));
        if(!L.elem)
            exit(OVERFLOW);
        L.listsize+=LISTINCREMENT;
    }
    for(i=L.length;i>pos-1;i--){//由大到小
        *(L.elem+i)=*(L.elem+i-1);
    }
    *(L.elem+pos-1)=e;
    L.length++;
    return OK;
}

/*ListDelete_Sq思路：找到需要删除的元素位置，记录元素，后继元素前移,表长-1*/
Status ListDelete_Sq(SqList &L,int pos ,ElemType &e){
    int i;
    int elemdelete=*(L.elem+pos-1);
    e=elemdelete;
    for(i=pos;i<=L.length;i++){
        *(L.elem+i-1)=*(L.elem+i);
    }
    L.length--;
    return OK;
}

/*ListLocate_Sq思路：依次比较，记录第一次位置，未找到返回0*/
int ListLocate_Sq(SqList L,ElemType e){
    int i;
    int elemlocate=0;
    for(i=0;i<=L.length;i++){
        if(*(L.elem+i)==e)
        {
            elemlocate=i+1;
            break;
        }
    }
    return elemlocate;
}

/*ListPrint_Sq思路：找到首元素地址，指针遍历*/
void ListPrint_Sq(SqList L){
    int *p=NULL;
    for(p=L.elem;p<=(L.elem+L.length-1);p++){
        printf("%d",*p);
        if(p<(L.elem+L.length-1))
            printf(" ");
    }
}

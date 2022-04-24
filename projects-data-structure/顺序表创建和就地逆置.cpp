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

//˳���Ĵ洢�ṹ����
#define LIST_INIT_SIZE  100
#define LISTINCREMENT   10
typedef int ElemType;  //�������Ա��е�Ԫ�ؾ�Ϊ����
typedef struct{
    ElemType* elem;   //�洢�ռ����ַ
    int length;       //����Ԫ�صĸ���
    int listsize;     //��������С
}SqList;    //˳������Ͷ���

Status ListCreate_Sq(SqList &L);
void ListReverse_Sq(SqList &L);

int main() {
    SqList L;
    ElemType *p;

    if(ListCreate_Sq(L)!= OK) {
        printf("ListCreate_Sq: ����ʧ�ܣ�����\n");
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

//˼·��˳����ʼ��������ֵ
//ע�⣺����Ԫ�ظ������ڱ������ݡ�
Status ListCreate_Sq(SqList &L){
    int i,listlength;//i�����ж�����ʱҪ������
    scanf("%d",&listlength);
    L.elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    L.listsize=LIST_INIT_SIZE;
    L.length=0;
    for(i=1;L.listsize<listlength;++i){//�ж�����
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
//˼·�����õ�������������Ԫ��λ�ã���Ϊ���������ż�����
void ListReverse_Sq(SqList &L){
    int p,q;//p���ڽ�������Ԫ�ص�λ�ã��м�����ʱ�洢����q���ڽ���Ԫ��ʱ����
    if(L.length%2==0)
        q=L.length/2;
    else
        q=(L.length-1)/2;
    while(q>=0){
        p=*(L.elem+q-1);//q��length��ʾλ��Ҫ-1
        *(L.elem+q-1)=*(L.elem+L.length-q);//L.elem+L.length-q��L.elem+L.length-1-(q-1)
        *(L.elem+L.length-q)=p;
        --q;
    }
}

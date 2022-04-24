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
//��������
Status ListInsert_SortedSq(SqList &L, ElemType e);
//˳����ʼ������
Status InitList_Sq(SqList &L)
{
    //����һ�οռ�
    L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    //��⿪���Ƿ�ɹ�
    if(!L.elem){
        exit(OVERFLOW);
    }
    //��ֵ
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}
//˳����������
void ListPrint_Sq(SqList L)
{
    ElemType *p = L.elem;//����Ԫ���õ�ָ��
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
    //����һ��˳���
    SqList L;
    //��ʼ��˳���
    InitList_Sq(L);
    int number = 0;
    ElemType e;
     scanf("%d", &number);//�������ݵĸ���
    for(int i = 0; i < number; ++i)
    {
        scanf("%d", &e);//��������
        ListInsert_SortedSq(L, e);
    }
    ListPrint_Sq(L);
    return  0;
}
//˼·����������Ԫ�شӺ���ǰ�Ƚϣ���������Ԫ�ش�ֱ�Ӳ��룬��С����ǰ�ظ����������ѱȽϹ���Ԫ�غ��ƣ���ָ�룡��
//ע�⣺���ݣ�����ȡֵȡ����Ԫ��
Status ListInsert_SortedSq(SqList &L, ElemType e){
    int *p;
    if(L.listsize==L.length)//���ʹ���ռ���ȣ���ζ�ſռ������������·���
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




/*˼·�����������������һ��Ԫ�ؽ��бȽϣ���С����ǰ�����ظ��������ѱȽϹ���Ԫ�غ��ƣ�������ֱ�Ӳ���
//ע�⣺���ڵ����,���ݵ����
Status ListInsert_SortedSq(SqList &L, ElemType e){
    int i=1,p=0;//i�������ݣ�p���ڱȽ�Ԫ��
    while(L.length==L.listsize){
        L.elem=(ElemType *)realloc(L.elem,(LIST_INIT_SIZE+i*LISTINCREMENT)*sizeof(ElemType));
        if(!L.elem)
            exit(OVERFLOW);
        L.listsize=LIST_INIT_SIZE+i*LISTINCREMENT;
        ++i;
    }
    if(L.length==0){//ֻ��1��Ԫ�ص����
        *L.elem=e;
        ++L.length;
        return OK;
    }
    for(;p<L.length;++p){
        if(e>=*(L.elem+L.length-1-p)){
            if(p==0){//e�������������
                *(L.elem+L.length)=e;
                break;
            }
            else{//e�������м�����
                *(L.elem+L.length-p)=e;
                break;
            }
        }
        if(e<*(L.elem+L.length-1-p)){//e��Ҫ��ǰ�ƶ������
            *(L.elem+L.length-p)=*(L.elem+L.length-1-p);
        }
        if(p==L.length-1){//e�ƶ�����һ��Ԫ�ص����
            *L.elem=e;
            break;
        }
    }
    ++L.length;
    return OK;
}
*/

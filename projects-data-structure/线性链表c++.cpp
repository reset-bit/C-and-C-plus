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
Status ListInsert_Sq(SqList &L, int pos, ElemType e);
Status ListDelete_Sq(SqList &L, int pos, ElemType &e);
int ListLocate_Sq(SqList L, ElemType e);
void ListPrint_Sq(SqList L);
//�ṹ��ʼ�������ٲ���
Status InitList_Sq(SqList &L){
  //��ʼ��LΪһ���յ�����˳���
    L.elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!L.elem)exit(OVERFLOW);
    L.listsize=LIST_INIT_SIZE;
    L.length=0;
    return OK;
}
int main() {
    SqList L;
    if(InitList_Sq(L)!= OK) {
        printf("InitList_Sq: ��ʼ��ʧ�ܣ�����\n");
        return -1;
    }
    for(int i = 1; i <= 10; ++ i)
        ListInsert_Sq(L, i, i);

    int operationNumber;  //��������
    scanf("%d", &operationNumber);

    while(operationNumber != 0) {
        int operationType;  //��������
        scanf("%d", & operationType);

        if(operationType == 1) {  //���Ӳ���
            int pos, elem;
            scanf("%d%d", &pos, &elem);
            ListInsert_Sq(L, pos, elem);
        } else if(operationType == 2) {  //ɾ������
             int pos; ElemType elem;
             scanf("%d", &pos);
             ListDelete_Sq(L, pos, elem);
             printf("%d\n", elem);
        } else if(operationType == 3) {  //���Ҷ�λ����
            ElemType elem;
            scanf("%d", &elem);
            int pos = ListLocate_Sq(L, elem);
            if(pos >= 1 && pos <= L.length)
                printf("%d\n", pos);
            else
                printf("NOT FIND!\n");
        } else if(operationType == 4) {  //�������
            ListPrint_Sq(L);
        }
       operationNumber--;
    }
    return 0;
}

/*ListInsert_Sq˼·����Ԫ����L->elem+pos-1�����Ԫ�غ��ƣ���+1�������������*/
Status ListInsert_Sq(SqList &L,int pos,ElemType e){
    int i;
    if(L.length==L.listsize){
        L.elem=(ElemType*)realloc(L.elem,(LIST_INIT_SIZE+LISTINCREMENT)*sizeof(L));
        if(!L.elem)
            exit(OVERFLOW);
        L.listsize+=LISTINCREMENT;
    }
    for(i=L.length;i>pos-1;i--){//�ɴ�С
        *(L.elem+i)=*(L.elem+i-1);
    }
    *(L.elem+pos-1)=e;
    L.length++;
    return OK;
}

/*ListDelete_Sq˼·���ҵ���Ҫɾ����Ԫ��λ�ã���¼Ԫ�أ����Ԫ��ǰ��,��-1*/
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

/*ListLocate_Sq˼·�����αȽϣ���¼��һ��λ�ã�δ�ҵ�����0*/
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

/*ListPrint_Sq˼·���ҵ���Ԫ�ص�ַ��ָ�����*/
void ListPrint_Sq(SqList L){
    int *p=NULL;
    for(p=L.elem;p<=(L.elem+L.length-1);p++){
        printf("%d",*p);
        if(p<(L.elem+L.length-1))
            printf(" ");
    }
}

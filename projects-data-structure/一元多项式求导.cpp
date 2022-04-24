//˼·���ṹ��洢ϵ����ָ�������������󵼷���
//ע�⣺ָ��Ϊ0
#include<stdio.h>
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define OVERFLOW   -2
typedef int  Status;
typedef struct LNode{
    int coef;//ϵ��
    int expn;//ָ��
    struct LNode *next;
}LNode, *LinkList;
Status CreatLinkList(LinkList &L){
    LinkList cur = NULL, p = NULL;
    char c = '\0';
    L = (LNode *)malloc(sizeof(LNode));
    if(!L)exit(OVERFLOW);
    L->next = NULL;
    p = L;
    while(c != '\n'){
        cur = (LNode *)malloc(sizeof(LNode));
        if(!cur)exit(OVERFLOW);
        cur->next = NULL;
        scanf("%d %d", &cur->coef, &cur->expn);
        c = getchar();
        p->next = cur;
        p = p->next;
    }
    return OK;
}
int main (){
    LinkList L = NULL, q = NULL;
    if(CreatLinkList(L) != OK){
        return ERROR;
    }
    q = L->next;
    while(q){
        if(q->expn == 0){//ָ��Ϊ0
            if(L->next->expn == q->expn && q->next == NULL){//ȫ���ǳ���
                printf("0");
            }
            q = q->next;
            continue;
        }
        if(q->coef == 0){//ϵ��Ϊ0
            q = q->next;
            continue;
        }
        printf("%d %d", q->coef * q->expn, q->expn - 1);
        if(q->next && q->next->expn!=0)
            printf(" ");
        q = q->next;
    }
    return 0;
}

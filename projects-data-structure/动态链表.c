/*���������ڽ���һ����̬�����洢ѧ���ɼ���num=0ʱ��������*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
struct stud_node {
     int    num;
     char   name[20];
     int    score;
     struct stud_node *next;
};
struct stud_node *head, *tail;
void input();
int main()
{
    struct stud_node *p;
    head = tail = NULL;
    input();
    for ( p = head; p != NULL; p = p->next )
        printf("%d %s %d\n", p->num, p->name, p->score);
    return 0;
}

/*˼·����̬�����ڴ棬||��һ��Ԫ�ص�ָ��ָ����һ��Ԫ�أ���ǰָ��ָ����һ��Ԫ��||�������������ж�num�Ƿ�Ϊ0*/
void input (){
    char str[20];
    struct stud_node *initial;
    head=(struct stud_node *)malloc(sizeof(struct stud_node));
    initial=tail=head;//��ǳ�ʼλ��

    if(!head)
        exit("OVERFLOW");

    printf("please input information of students:\n");
    scanf("%d",&head->num);
    while(head->num!=0){
        scanf("%s%d",str,&head->score);
        strcpy(head->name,str);

        tail->next=head;
        tail=head;

        head=(struct stud_node *)malloc(sizeof (struct stud_node));
        printf("please input information of students:\n");
        scanf("%d",&head->num);
        if(!head->num)//����ֹ�����
        {
            tail->next=NULL;//���һ��Ԫ��ָ�����
            head=initial;
            break;
        }
    }
    if(!head->num)//��ʼΪ0
        printf("You did not enter data for student information!");
        head=tail=NULL;
}

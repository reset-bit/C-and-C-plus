/*本程序用于建立一个动态链表，存储学生成绩，num=0时结束输入*/
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

/*思路：动态分配内存，||上一个元素的指针指向下一个元素，当前指针指向下一个元素||以令其连续。判断num是否为0*/
void input (){
    char str[20];
    struct stud_node *initial;
    head=(struct stud_node *)malloc(sizeof(struct stud_node));
    initial=tail=head;//标记初始位置

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
        if(!head->num)//对终止的情况
        {
            tail->next=NULL;//最后一个元素指针清空
            head=initial;
            break;
        }
    }
    if(!head->num)//初始为0
        printf("You did not enter data for student information!");
        head=tail=NULL;
}

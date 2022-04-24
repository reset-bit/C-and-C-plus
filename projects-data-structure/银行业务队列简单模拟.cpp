//思路：数组存储顾客，构造两个空队列,分别if判断奇偶入队，while+if语句，先a后b，且a出队2之后b出队1，不考虑时间间隔，先存再出
//注意：没有顾客，有一方队列先为空，输出格式，假满
#include<stdio.h>
#include<stdlib.h>
#define OVERFLOW -1
#define OK 0
#define ERROR -2
typedef int Status;
typedef int QElemType;
typedef struct {
    QElemType * base;
    int front;
    int rear;
}SqQueue;
int num = 1;
Status InitQueue (SqQueue &Q){
    Q.base = (QElemType * ) malloc ((num + 1) * sizeof (QElemType));//防假满多给1个空间
    if (! Q.base) exit (OVERFLOW);
    Q.front = Q.rear = 0;
    return OK;
}
int DeQueue (SqQueue &Q){
	int e;//带回值
	e = Q.base[Q.front];
    Q.front = (Q.front + 1) % (num + 1);
    return e;
}
int IsQueue (SqQueue Q){
	int i = 0;
	if(Q.front == Q.rear);//i判断队列空或满
	else{
		++i;
	}
	return i;
}
int main(){
    scanf ("%d", & num);
    int con [1000];
    SqQueue A, B;
    InitQueue (A);InitQueue (B);
    for(int i = 0; i < num; ++i){
        scanf("%d", con + i);
        if (con [i] % 2 != 0){//奇数入A
            *(A.base + A.rear) = con [i];
            A.rear = (A.rear + 1) % (num + 1);
        }
        else{//偶数入B
            *(B.base + B.rear) = con [i];
            B.rear = (B.rear + 1) % (num + 1);
        }
    }//for
	int i = 0;//i判断是否为第一个输出元素
    while(IsQueue(A) || IsQueue(B)){//AB有一个不为空时循环
		if(IsQueue(A)){
			if(i == 0){
				printf("%d",DeQueue(A));
				++i;
			}
			else{
				printf(" %d",DeQueue(A));
			}
		}//if-A1
		if(IsQueue(A)){
			printf(" %d",DeQueue(A));
		}//if-A2
		if(IsQueue(B)){
			if(i == 0){//A为空时，否则B总是在A之后（因为本题忽略顾客到来时间）
				printf("%d",DeQueue(B));
			}
			else{
				printf(" %d",DeQueue(B));
			}
		}//if-B
    }//while
    return 0;
}

//˼·������洢�˿ͣ����������ն���,�ֱ�if�ж���ż��ӣ�while+if��䣬��a��b����a����2֮��b����1��������ʱ�������ȴ��ٳ�
//ע�⣺û�й˿ͣ���һ��������Ϊ�գ������ʽ������
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
    Q.base = (QElemType * ) malloc ((num + 1) * sizeof (QElemType));//���������1���ռ�
    if (! Q.base) exit (OVERFLOW);
    Q.front = Q.rear = 0;
    return OK;
}
int DeQueue (SqQueue &Q){
	int e;//����ֵ
	e = Q.base[Q.front];
    Q.front = (Q.front + 1) % (num + 1);
    return e;
}
int IsQueue (SqQueue Q){
	int i = 0;
	if(Q.front == Q.rear);//i�ж϶��пջ���
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
        if (con [i] % 2 != 0){//������A
            *(A.base + A.rear) = con [i];
            A.rear = (A.rear + 1) % (num + 1);
        }
        else{//ż����B
            *(B.base + B.rear) = con [i];
            B.rear = (B.rear + 1) % (num + 1);
        }
    }//for
	int i = 0;//i�ж��Ƿ�Ϊ��һ�����Ԫ��
    while(IsQueue(A) || IsQueue(B)){//AB��һ����Ϊ��ʱѭ��
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
			if(i == 0){//AΪ��ʱ������B������A֮����Ϊ������Թ˿͵���ʱ�䣩
				printf("%d",DeQueue(B));
			}
			else{
				printf(" %d",DeQueue(B));
			}
		}//if-B
    }//while
    return 0;
}

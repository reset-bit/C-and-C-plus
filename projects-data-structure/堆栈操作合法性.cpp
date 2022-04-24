//˼·��ָ�����+malloc n���������Ϊ100�Ŀռ䣬������󳤶�Ϊm��ջ��s��ջ������ջ��������;ÿ����һ��x���Ե�s����s����;
//����ջ����Ϊ0����
//ע�⣺����ͻ��з������
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define OVERFLOW -1
#define ERROR 0
#define OK 1
#define NO -2
typedef int Status;
typedef struct Stack{
    int Stacksize;
    char *top;
    char *base;
}SqStack;
Status InitStack(SqStack &S,int m){
    S.base=(char *)malloc(m*sizeof(char));
    if(!S.base)exit(OVERFLOW);
    S.top=S.base;
    S.Stacksize=m;
    return OK;
}
Status Push(SqStack &S,char e){
    if(S.top-S.base==S.Stacksize){//����������ջ��
        printf("NO");
        return NO;
    }
    *S.top++=e;
    return OK;
}
Status Pop(SqStack &S){
    if(S.top==S.base){//��Ϊ��ջ���Ե���
        printf("NO");
        return NO;
    }
    --S.top;
    return OK;
}
int main(){
    int n,m;//n�Ǵ������еĸ�����m��ջ���������,i�����ж����ջ�Ƿ�Ϊ��
    SqStack S;int i;
    scanf("%d%d",&n,&m);
    getchar();//�̵�scanf��β�Ļس�
    if(m>50)return ERROR;
    for(int j=0;j<n;++j){
        char *p;
        p=(char *)malloc(100*sizeof(char));//100����������
        if(!p)exit(OVERFLOW);
        InitStack(S,m);
        fgets(p,100,stdin);
        if(*p!='S'&&*p!='X'){//��ֱ���ǻس������
            --j;//j����
            continue;
        }
        for(i=0;*(p+i)=='S'||*(p+i)=='X';++i){
            if(*(p+i)=='S')
                 if(Push(S,'S')==NO)
                    break;
            if(*(p+i)=='X')
                if(Pop(S)==NO)
                    break;
        }//��ÿ����������for
        if(*(p+i)!='S'&&*(p+i)!='X'&&S.base==S.top)
            printf("YES");
        else if(*(p+i)!='S'&&*(p+i)!='X'&&S.base!=S.top)//���ջ��Ϊ0
            printf("NO");
        free(p);p=NULL;
        if(j!=n-1)
            printf("\n");
    }//�Դ������и���for
    return 0;
}

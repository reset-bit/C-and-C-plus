//思路：指针遍历+malloc n个最大容量为100的空间，建立最大长度为m的栈，s入栈，大于栈容量报错;每读到一个x便试弹s，无s报错;
//最终栈长不为0报错
//注意：报错和换行符的情况
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
    if(S.top-S.base==S.Stacksize){//插入量大于栈长
        printf("NO");
        return NO;
    }
    *S.top++=e;
    return OK;
}
Status Pop(SqStack &S){
    if(S.top==S.base){//已为空栈但仍弹出
        printf("NO");
        return NO;
    }
    --S.top;
    return OK;
}
int main(){
    int n,m;//n是待测序列的个数，m是栈的最大容量,i用于判断最后栈是否为空
    SqStack S;int i;
    scanf("%d%d",&n,&m);
    getchar();//吞掉scanf结尾的回车
    if(m>50)return ERROR;
    for(int j=0;j<n;++j){
        char *p;
        p=(char *)malloc(100*sizeof(char));//100是最大操作数
        if(!p)exit(OVERFLOW);
        InitStack(S,m);
        fgets(p,100,stdin);
        if(*p!='S'&&*p!='X'){//对直接是回车的情况
            --j;//j不变
            continue;
        }
        for(i=0;*(p+i)=='S'||*(p+i)=='X';++i){
            if(*(p+i)=='S')
                 if(Push(S,'S')==NO)
                    break;
            if(*(p+i)=='X')
                if(Pop(S)==NO)
                    break;
        }//对每个待测序列for
        if(*(p+i)!='S'&&*(p+i)!='X'&&S.base==S.top)
            printf("YES");
        else if(*(p+i)!='S'&&*(p+i)!='X'&&S.base!=S.top)//最后栈不为0
            printf("NO");
        free(p);p=NULL;
        if(j!=n-1)
            printf("\n");
    }//对待测序列个数for
    return 0;
}

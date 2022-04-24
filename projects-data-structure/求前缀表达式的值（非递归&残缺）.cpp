//思路：将前缀表达式入栈存储，并新建数栈，前缀表达式栈出（从右向左操作表达式）
//swtich判断，是运算符就pop两个数栈元素

//仅适用于个位正数加减乘，除法分母为0无法判断，负数也无法判断，且类c实现代码冗余度高，非递归实现！！

//递归实现要从左向右

//注意：pop异常报错，最后前缀表达式栈只剩一个，如何将多位字符转化成相应数字
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define OK 0
#define ERROR -1
typedef int Status;
typedef char ElemType;
typedef struct SqStack{
    ElemType * base;
    ElemType * top;
    int stacksize;
}SqStack;
Status Push (SqStack &S, ElemType e){
    *S.top = e;
	S.top++;
    return OK;
}
Status Pop (SqStack &S, ElemType &e){
    if(S.base == S.top)
        return ERROR;
    S.top--;
	e = *S.top;
    return OK;
}
int main(){
    SqStack prefix;//表达式栈
	char e = 0;//e传递出入栈值
	char *p = NULL;
	double num1 = 0.0, num2 = 0.0, mid = 0.0;//mid类型转换中间量
	struct SqStack1{
		double *base;
		double *top;
		int stacksize;
	};
	struct SqStack1 num;
    prefix.base = (ElemType *) malloc (sizeof(ElemType));
    prefix.top = prefix.base;
    prefix.stacksize = 30;
    num.base = (double *) malloc (sizeof(double));
    num.top = num.base;
    num.stacksize = 30;
    while(1){//循环+辅助变量入栈
        scanf("%c", &e);//输入空格或回车对scanf+循环没有影响
		if(e == '\n')
			break;
        Push(prefix, e);
    }

	//入栈结束，开始出栈读取

	int cou = 0;//cou判断是多位数字或者字符 还是一位运算符或数字
    while(prefix.top != prefix.base){
		do{
			++cou;
			Pop(prefix, e);
			if(prefix.top == prefix.base){//表达式栈空，抵消循环外的--
				prefix.top++;
				break;
			}//if
		}while(*(prefix.top-1) != ' ');//下一位不是空格，就循环
		prefix.top--;//空格跳过一位
		if(cou == 1){
			if(e == '+' || e == '-' || e == '*' || e == '/'){
				num1 = *(--num.top); num2 = *(--num.top);
				switch(e){
					case '+' :	num1 =num1 + num2;//数栈出2
								*num.top = num1 ;//运算后入栈
								if(num.top != num.base)
									num.top++;//如果数栈只有两个元素，加和之后只保留一个元素
								break;
					case '-' :	num1 = num1 - num2;
								*num.top = num1 ;
								if(num.top != num.base)
									num.top++;
								break;
					case '*' :	num1 = num1 * num2;
								*num.top = num1 ;
								if(num.top != num.base)
									num.top++;
								break;
					case '/' :	num1 = num1 / num2;
								*num.top = num1 ;
								if(num.top != num.base)
									num.top++;
								break;
				}//switch
			}//if
			else{//单个数字
				mid = atof(&e);//atof字符转浮点型，入数栈
				*num.top++ = mid;
			}
			cou = 0;
		}//if
		else if(cou > 1){//多位数字直接入栈
			mid = atof(prefix.top + cou);//从前向后开始进行多位数字的转换,bug:不能转换负数
			while(cou > 1){
				--cou;
				p = prefix.top + cou;
				mid = atof(p);//mid = mid * 10 + atof(p);
			}
			*num.top++ = mid;
			cou = 0;
		}
    }
    printf("%.1f\n", *(num.top));
    return 0;
}

//˼·����ǰ׺���ʽ��ջ�洢�����½���ջ��ǰ׺���ʽջ������������������ʽ��
//swtich�жϣ����������pop������ջԪ��

//�������ڸ�λ�����Ӽ��ˣ�������ĸΪ0�޷��жϣ�����Ҳ�޷��жϣ�����cʵ�ִ�������ȸߣ��ǵݹ�ʵ�֣���

//�ݹ�ʵ��Ҫ��������

//ע�⣺pop�쳣�������ǰ׺���ʽջֻʣһ������ν���λ�ַ�ת������Ӧ����
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
    SqStack prefix;//���ʽջ
	char e = 0;//e���ݳ���ջֵ
	char *p = NULL;
	double num1 = 0.0, num2 = 0.0, mid = 0.0;//mid����ת���м���
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
    while(1){//ѭ��+����������ջ
        scanf("%c", &e);//����ո��س���scanf+ѭ��û��Ӱ��
		if(e == '\n')
			break;
        Push(prefix, e);
    }

	//��ջ��������ʼ��ջ��ȡ

	int cou = 0;//cou�ж��Ƕ�λ���ֻ����ַ� ����һλ�����������
    while(prefix.top != prefix.base){
		do{
			++cou;
			Pop(prefix, e);
			if(prefix.top == prefix.base){//���ʽջ�գ�����ѭ�����--
				prefix.top++;
				break;
			}//if
		}while(*(prefix.top-1) != ' ');//��һλ���ǿո񣬾�ѭ��
		prefix.top--;//�ո�����һλ
		if(cou == 1){
			if(e == '+' || e == '-' || e == '*' || e == '/'){
				num1 = *(--num.top); num2 = *(--num.top);
				switch(e){
					case '+' :	num1 =num1 + num2;//��ջ��2
								*num.top = num1 ;//�������ջ
								if(num.top != num.base)
									num.top++;//�����ջֻ������Ԫ�أ��Ӻ�֮��ֻ����һ��Ԫ��
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
			else{//��������
				mid = atof(&e);//atof�ַ�ת�����ͣ�����ջ
				*num.top++ = mid;
			}
			cou = 0;
		}//if
		else if(cou > 1){//��λ����ֱ����ջ
			mid = atof(prefix.top + cou);//��ǰ���ʼ���ж�λ���ֵ�ת��,bug:����ת������
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

#include <stdio.h>
#include <stdlib.h>
typedef int datatype;
datatype **na(const int m,const int n) /*����һ��m��n�е�datatype�������飬�����׵�ַ���������ʧ���򷵻�NULL*/
{
	int i;
	datatype **a=(datatype**)malloc(sizeof(datatype *)*m);
	if (!a) 
		return NULL;
	else
	for (i = 0; i<m; i++)
	{
		a[i]=(datatype*)malloc(sizeof(datatype)*n);
		if (!a[i])
			return NULL;
	}
	return a;
}
void dela(datatype **a,const int m) /*ɾ����na()���������Ĳ�����m��Ԫ�صĶ�ά����a*/
{
	int i;
	for (i = 0; i<m; i++)
	free(a[i]);
	free(a);
}
int main(void)
{
	datatype **dta=na(3,2); /*����һ��3��2�е�datatype����*/
	int i,j;
	if (!dta) /*�������ʧ�ܣ������������Ϣ����������*/
	{ 
	fprintf(stderr,"MEMORY ERROR\n");
	return -1;
	}
	else
	{
	for (i=0; i<3; i++) 
	{ /*ʹ�øղŴ����Ķ�ά����*/
		for (j=0; j<2; j++) 
		{
			dta[i][j]=i*j;
			printf("%d ",dta[i][j]);
		}
		putchar('\n');
	}
}
	dela(dta,3); /*��̬����������Ҫ�ֶ�ɾ��*/
	return 0;
}
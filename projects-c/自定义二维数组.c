#include <stdio.h>
#include <stdlib.h>
typedef int datatype;
datatype **na(const int m,const int n) /*创建一个m行n列的datatype类型数组，返回首地址，如果创建失败则返回NULL*/
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
void dela(datatype **a,const int m) /*删除用na()函数创建的并且有m行元素的二维数组a*/
{
	int i;
	for (i = 0; i<m; i++)
	free(a[i]);
	free(a);
}
int main(void)
{
	datatype **dta=na(3,2); /*创建一个3行2列的datatype数组*/
	int i,j;
	if (!dta) /*如果创建失败，则输出错误信息并结束程序*/
	{ 
	fprintf(stderr,"MEMORY ERROR\n");
	return -1;
	}
	else
	{
	for (i=0; i<3; i++) 
	{ /*使用刚才创建的二维数组*/
		for (j=0; j<2; j++) 
		{
			dta[i][j]=i*j;
			printf("%d ",dta[i][j]);
		}
		putchar('\n');
	}
}
	dela(dta,3); /*动态创建的数组要手动删除*/
	return 0;
}
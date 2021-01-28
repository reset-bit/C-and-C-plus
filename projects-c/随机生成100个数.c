#include<time.h>
#include<stdlib.h>
#include<stdio.h>
void main()
{
	int a[100],i;
	srand((unsigned)time(NULL)); //用当前系统时间设置种子
	
	printf("随即初始化数组的100个数(范围是0~100):\n");
	for(i=0;i<100;i++)
	{
		a[i]=rand()%101;    //用rand函数生成0-100的随机数，并赋值给数组a[i]
		printf("%4d",a[i]);
		if((i+1)%10==0&&i!=0)//每10个数换一次行
			printf("\n");
	}
}
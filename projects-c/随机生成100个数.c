#include<time.h>
#include<stdlib.h>
#include<stdio.h>
void main()
{
	int a[100],i;
	srand((unsigned)time(NULL)); //�õ�ǰϵͳʱ����������
	
	printf("�漴��ʼ�������100����(��Χ��0~100):\n");
	for(i=0;i<100;i++)
	{
		a[i]=rand()%101;    //��rand��������0-100�������������ֵ������a[i]
		printf("%4d",a[i]);
		if((i+1)%10==0&&i!=0)//ÿ10������һ����
			printf("\n");
	}
}
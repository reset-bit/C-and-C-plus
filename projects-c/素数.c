/*�������������1��100���е�����*/
/*2��n-1�Բ�����������*/
#include<stdio.h>

/*Ч����ߵ������жϷ�*/

int judge(int n){
	int i = 3;
	if(n == 2)
		return 0;//yes
	else if(n % 2 == 0 || n == 1)
		return 1;//no
	else{
		for(i = 3; i <= (int)sqrt((double)n); i += 2){//ÿ��+2
			if(n % i == 0)
				return 1;
		}
	}
	return 0;
}
void main(){
	int n;
	scanf("%d",&n);
	if(judge(n) == 0)
		printf("yes\n");
	else
		printf("no\n");
}
/*
void main()
{
	int i,a,b;
	for(i=2;i<100;i++)
	{
		for(a=2;a<i;a++)
		{
			b=i%a;//��b=0,֤�������������������������������
			if(b==0)
				break;
		}
		if(a==i)
			printf("%d\t",i);
	}
}*/

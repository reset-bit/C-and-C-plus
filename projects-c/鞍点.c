/*本程序用于求二维数组的鞍点。鞍点：在某位置上的元素同行最大，同列最小。可能没有鞍点。*/
//思路：找出一行中的最大值、最大值对应某列中的最小值，判断行标是否相等
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int a[10][10],i,j,n=10,m=10,min,max;
	int a1,a2,a3=0,w,q,sum=0;//a1用于定住列；a2用于定住行；a3用于定住已定列中最小值的行；w用于用户选择	
	printf("请选择操作方式：1.系统生成2.用户输入\n");
	scanf("%d",&w);
	switch(w)
	{
	case 1:
		srand((unsigned)time(NULL));	
		for(i=0;i<10;i++)
		{
			for(j=0;j<10;j++)
			{
				a[i][j]=rand()%101;
				printf("%4d",a[i][j]);					
			}
			printf("\n");			
		}
			break;
	case 2:
		printf("请输入二维数组的行列数：\n");
		scanf("%d%d",&n,&m);
		printf("请输入二维数组的数据：（每输入一个数换一次行）\n");
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				scanf("%d",&a[i][j]);
		printf("您输入的数组是：\n");
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
				printf("%4d",a[i][j]);
			printf("\n");
		}
	}
		for(i=0;i<n;i++)
		{				
			max=a[i][0];//放在循环内，每次只和第一个相比
			for(j=1;j<m;j++)//保持同行最大
			{
				if(max<a[i][j])
				{
					max=a[i][j];
					a1=j;//标记列
					a2=i;//标记行，并以此标记列
				}
			}
			//printf("第%d行的最大值在第%d列\n",a2+1,a1+1);
			min=a[0][a1];
			for(q=1;q<n;q++)//求出a1列的最小值,记录a3=q
			{
				if(min>a[q][a1])
				{
					min=a[q][a1];
					a3=q;
				}
			}
			//printf("第%d列的最小值在第%d列\n",a1+1,a3+1);		
		if(a3==a2)
			printf("该二维数组的鞍点是：%d，位于第%d行第%d列。\n",a[a2][a1],a2+1,a1+1);
		else
			sum=sum+1;
		if(sum==n)//n次循环都没有鞍点
			printf("没有鞍点\n");	
		}
		return 0;
}

//switch语句中case即使向下顺延也会携带进入时的值
//注意定义最大（小）值的位置，放在循环内会一直和同一个数（定义的第一个数）相比较，不会求得最大（小）
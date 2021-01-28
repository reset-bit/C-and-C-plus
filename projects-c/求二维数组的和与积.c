/*本程序用于求两个矩阵的和与积,本程序有错*/
#include<iostream>//cout输出函数头文件
#include<stdio.h>
void And(int a[][256],int b[][256],int n,int m)//定义And子函数，求两个矩阵相加
{
	int i,j;
	cout<<"两矩阵相加为:"<<endl;
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			cout<<a[i][j]+b[i][j]<<" ";
		}
		cout<<endl;
	}
}/*
void Minu(int a[][256],int b[][256],int n,int m,int l)//定义Minu子函数,求两个矩阵相乘
{
	int i,j,temp=0,k;
	cout<<"两矩阵相乘为:"<<endl;
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			temp=0;
			for(k=0;k<l;k++)
			temp+=a[i][k]*b[k][j];
			cout<<temp<<" ";
		}
		cout<<endl;
	}
}*/
void main()
{
	int a[256][256],b[256][256],c[256][256],n1,m1,n2,m2;
	int i,j;
	cout<<"请输入第一个矩阵的行数和列数:"<<endl;//cout输出函数
	cin>>n1>>m1;                                //cin输入函数
	cout<<"请输入第一个矩阵数据:"<<endl;
	for (i=0;i<n1;i++)
		for (j=0;j<m1;j++)
		{
			cin>>a[i][j];
		}
	cout<<"请输入第二个矩阵的行数和列数:"<<endl;
	cin>>n2>>m2;
	cout<<"请输入第二个矩阵数据:"<<endl;
	for (i=0;i<n2;i++)
		for (j=0;j<m2;j++)
		{
			cin>>b[i][j];
		}
	if (n1==n2&&m1==m2)
	{
		And(a,b,n1,m1);
	}
	else cout<<"这两个矩阵不能做加法"<<endl;
/*	if (n2==m1)
	{
		Minu(a,b,n1,m2,n2);
	}
	else cout<<"这两个矩阵不能做乘法"<<endl;*/
}
/*��������������������ĺ����,�������д�*/
#include<iostream>//cout�������ͷ�ļ�
#include<stdio.h>
void And(int a[][256],int b[][256],int n,int m)//����And�Ӻ������������������
{
	int i,j;
	cout<<"���������Ϊ:"<<endl;
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			cout<<a[i][j]+b[i][j]<<" ";
		}
		cout<<endl;
	}
}/*
void Minu(int a[][256],int b[][256],int n,int m,int l)//����Minu�Ӻ���,�������������
{
	int i,j,temp=0,k;
	cout<<"���������Ϊ:"<<endl;
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
	cout<<"�������һ�����������������:"<<endl;//cout�������
	cin>>n1>>m1;                                //cin���뺯��
	cout<<"�������һ����������:"<<endl;
	for (i=0;i<n1;i++)
		for (j=0;j<m1;j++)
		{
			cin>>a[i][j];
		}
	cout<<"������ڶ������������������:"<<endl;
	cin>>n2>>m2;
	cout<<"������ڶ�����������:"<<endl;
	for (i=0;i<n2;i++)
		for (j=0;j<m2;j++)
		{
			cin>>b[i][j];
		}
	if (n1==n2&&m1==m2)
	{
		And(a,b,n1,m1);
	}
	else cout<<"���������������ӷ�"<<endl;
/*	if (n2==m1)
	{
		Minu(a,b,n1,m2,n2);
	}
	else cout<<"���������������˷�"<<endl;*/
}
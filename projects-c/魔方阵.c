/*
��νN��ħ������һ��N*N�ķ�����Ԫ����1��N^2��ɣ��ҷ���ÿ��ÿ���Լ��Խ��ߵ�Ԫ�غ���ȡ�������ħ����
8 1 6
3 5 7
4 9 2
ħ����Ĺ������£�
   ��1��N*N�� �������������¹�����:
      (1) 1�ڵ�һ���м�һ�У�
      (2) ÿһ������ŵ��б�ǰһ������������һ��������һ�����ϵ����׷���5��4����һ�У���һ�У���
      (3) �����һ�����ڵ�һ�У�����һ���������һ�У�������һ��
      (4) �����һ���������һ�У�����һ�����ڵ�һ�У�������һ��
      (5) �������������ȷ����λ���Ѿ�����������һ�����ڵ�һ�е�N�У�����һ����������һ���������·���
*/
//!!������ά�����ָ���ʾ�ǳ�������!!
#include<stdio.h>
#include<stdlib.h>
int main()
{
   int n = 0,num = 0,*a=NULL;
   while(scanf("%d",&n) != EOF){//һ��������
        int row=0,column=0;
        num=n*n;
        a=(int *)malloc(num*sizeof(int));
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                *(a+i*n+j)=0;
        for(int i=1;i<=num;++i){
            if(i==1){
                *(a+0*n+n/2)=i;
                row=0;
                column=n/2;
                continue;
            }
            if(row==0&&column==n-1){//��һ�����ڵ�һ�е�N��
                *(a+(++row)*n+column)=i;
                continue;
            }
            if(row==0){//��һ�����ڵ�һ��
                if(*(a+(n-1)*n+(column+1))==0){
                    *(a+(n-1)*n+(++column))=i;
                    row=n-1;
                }
                else{
                    *(a+(++row)*n+column)=i;
                }
                continue;
            }
            else if(column==n-1){//��һ���������һ��
                if(*(a+(row-1)*n+0)==0){
                    *(a+(--row)*n+0)=i;
                    column=0;
                }
                else{
                    *(a+(++row)*n+column)=i;
                }
                continue;
            }
            if(*(a+(row-1)*n+(column+1))==0){
                *(a+(--row)*n+(++column))=i;
            }
            else{
                *(a+(++row)*n+column)=i;
            }
        }
        for(int i=0;i<n;++i){
            int j=0;
            for(j=0;j<n-1;++j){
                printf("%d ",*(a+i*n+j));
            }
            printf("%d\n",*(a+i*n+j));
        }
        printf("\n");
   }
   return 0;
}

/*���������ڴ�ӡn<14���������*/
/*n=7:
               1
             1   1
           1   2   1
         1   3   3   1
       1   4   6   4   1
     1   5  10  10   5   1
   1   6  15  20  15   6   1
*/
#include<stdio.h>
#include<stdlib.h>
void main()
{
	int *a=NULL;
	int i,j,n;
	while(scanf("%d",&n)!=EOF){
        a=(int *)malloc(n*n*sizeof(int));
        for(i=0;i<n;i++)
        {
            *(a+i*n+0)=1;
            *(a+i*n+i)=1;//�������1
        }
        for(i=2;i<n;i++)//�ӵ����п�ʼ
        {
            for(j=1;j<i;j++)//�ӵڶ��п�ʼ
                *(a+i*n+j)=*(a+(i-1)*n+(j-1))+*(a+(i-1)*n+j);//a[2][1]����2��=a[1][0]����1��+a[1][1]����1��
        }
        for(i=0;i<n;i++)
        {
            int k=0;
            for(k=0;k<2*(n-i-1);++k)
                printf(" ");
            for(j=0;j<i+1;j++)
            {
                printf("%4d",*(a+i*n+j));
            }
            printf("\n");//��i���ʱ����
        }
        printf("\n");
	}
}

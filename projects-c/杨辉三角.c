/*本程序用于打印n<14的杨辉三角*/
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
            *(a+i*n+i)=1;//将两侧归1
        }
        for(i=2;i<n;i++)//从第三行开始
        {
            for(j=1;j<i;j++)//从第二列开始
                *(a+i*n+j)=*(a+(i-1)*n+(j-1))+*(a+(i-1)*n+j);//a[2][1]（即2）=a[1][0]（即1）+a[1][1]（即1）
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
            printf("\n");//当i变的时候换行
        }
        printf("\n");
	}
}

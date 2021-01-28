/*
所谓N阶魔方阵，是一个N*N的方阵，其元素由1到N^2组成，且方阵每行每列以及对角线的元素和相等。如三阶魔方阵：
8 1 6
3 5 7
4 9 2
魔方阵的规律如下：
   从1～N*N的 各个数依次如下规则存放:
      (1) 1在第一行中间一列；
      (2) 每一个数存放的行比前一个数的行数减一，列数加一（如上的三阶方阵5在4的上一行，后一列）；
      (3) 如果上一个数在第一行，则下一个数在最后一行，列数加一；
      (4) 如果上一个数在最后一列，则下一个数在第一列，行数减一；
      (5) 如果按上述规则确定的位置已经有数，或上一个数在第一行第N列，则下一个数放在上一个数的正下方。
*/
//!!对理解二维数组的指针表示非常有意义!!
#include<stdio.h>
#include<stdlib.h>
int main()
{
   int n = 0,num = 0,*a=NULL;
   while(scanf("%d",&n) != EOF){//一定是奇数
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
            if(row==0&&column==n-1){//上一个数在第一行第N列
                *(a+(++row)*n+column)=i;
                continue;
            }
            if(row==0){//上一个数在第一行
                if(*(a+(n-1)*n+(column+1))==0){
                    *(a+(n-1)*n+(++column))=i;
                    row=n-1;
                }
                else{
                    *(a+(++row)*n+column)=i;
                }
                continue;
            }
            else if(column==n-1){//上一个数在最后一列
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

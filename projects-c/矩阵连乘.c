//OJ��ҵ8-1  problemC
//���������ǹؼ�
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 100
int main(void)
{
     int i,j,k,row1,col1,row2,col2,flagenter=0,flagscanfs1=0;
     int matrix1[M][M]={0},matrix2[M][M]={0},matrix[M][M]={0};
     while(1){
        if(flagscanfs1==0){//Ҫ����
            scanf("%d %d",&row1,&col1);
            if(row1==0&&col1==0)
                break;
             for(i=0;i<row1;i++){
                 for(j=0;j<col1;j++){
                     scanf("%d",&matrix1[i][j]);
                 }
             }
        }

        scanf("%d%d",&row2,&col2);
        if(row2==0&&col2==0)
            break;
        for(i=0;i<row2;i++){
            for(j=0;j<col2;j++){
                scanf("%d",&matrix2[i][j]);
            }
        }
        if(flagenter==1){//ÿ�����������֮����һ�����зָ�����
            printf("\n");
            flagenter=0;
        }

        if(col1!=row2){
            flagscanfs1=0;//��ʱs1Ҫ����
            printf("Not satisfied the definition of matrix multiplication!\n");
        }
        else{
            for(i=0;i<row1;i++){//���
                for(j=0;j<col2;j++){
                    for(k=0;k<col1;k++){
                        matrix[i][j]+=matrix1[i][k]*matrix2[k][j];
                    }
                }
            }//for
            for(i=0;i<row1;i++){//���
                for(j=0;j<col2-1;j++){
                    printf("%d ",matrix[i][j]);
                    matrix1[i][j]=matrix[i][j];
                }
                printf("%d",matrix[i][j]);
                matrix1[i][j]=matrix[i][j];
                printf("\n");
            }//for
            flagscanfs1=1;//��������s1
            flagenter++;

            memset(matrix,0,sizeof(matrix));
        }//else
     }//while
     return 0;
 }

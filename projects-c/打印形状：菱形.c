/*
ע��������������ã�������������ά������ϵ���������������ѭ����1--->n
�������ڿ������Σ�����״��
�������Ҵ������£���������һ����n/2  (n+1)/2  (n-1)/2�й�
���²���һ��һ�����i�йأ����²�����n�й�
https://wenku.baidu.com/view/7850bd13f18583d04964596c.html
*/
#include<stdio.h>
int main()
{
    int n = 0, i = 0, j = 0;
    while(scanf("%d", &n) != EOF){
        for(i = 1; i <= (n + 1) / 2; ++i){
            for(j = 1; j <= n; ++j){
                if(j == (n + 1) / 2 - i + 1|| j == (n - 1) / 2 + i){
                    printf("*");
                    if(j == (n - 1) / 2 + i)
                        break;
                }
                else
                    printf(" ");
            }
            printf("\n");
        }//for
        for(i = 1; i <= (n - 1) / 2; ++i){
            for(j = 1; j <= n; ++j){
                if(j == i + 1 || j == n - i){
                    printf("*");
                    if(j == n - i)
                        break;
                }
                else
                    printf(" ");
            }
            printf("\n");
        }
        printf("\n");
    }//while
    return 0;
}

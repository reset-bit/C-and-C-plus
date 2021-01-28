/*
注意基本方法的运用，将菱形输出与二维数组联系起来，但并非外层循环从1--->n
仅适用于空心菱形（仅形状）
从左至右从上至下，上两部分一般与n/2  (n+1)/2  (n-1)/2有关
左下部分一般一般仅与i有关，右下部分与n有关
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

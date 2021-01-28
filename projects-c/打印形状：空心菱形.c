/*输入为一个奇数n，1<n<50。输出一个n层的空心菱形*/
#include<stdio.h>
#include<math.h>
int print_graphic(int n)
{
    int i, j;
    for(i = -(n - 1) / 2; i <= (n - 1) / 2; i++){//-5--->5行
		for(j =- (n - 1) / 2; j <= (n - 1) / 2; j++)//-5---->5列
			if((abs(i) + abs(j)) >= (n - 1) / 2)//abs求绝对值
				printf("*");
			else
				printf(" ");
		printf("\n");
    }
}
int main()
{
    int num;
    scanf("%d", &num);
    print_graphic(num);
    return 0;
}

/*
冗余代码

#include<stdio.h>
//思路：菱形分上下两部分，空格数奇数变化
//在每一行分为3部分，空格前，空格，空格后，其中空格前后星花数对称
//第一行与最后一行单独处理
int print_graphic(int n){
	int  j = 0, k = 1;//k记录空格数
	for(j = 0; j < n; ++j){//max*=11
		int a = 0;//单次循环变量
		if(j == 0 || j == n - 1){
			for(a = 0; a < n; ++a){
				printf("*");
			}
		}
		else{
			if(j < (n + 1) / 2){//5
				for(a = 0; a < ((n + 1) / 2) - j; ++a){
					printf("*");
				}

				for(a = 0; a < k; ++a){
					printf(" ");
				}
				k += 2;
					
				for(a = 0; a < ((n + 1) / 2) - j; ++a){
					printf("*");
				}
			}
			else{
				if(j == 6)
					k -= 4;
				for(a = 0; a < j - n / 2 + 1; ++a){//6-5+1
					printf("*");
				}

				for(a = 0; a < k; ++a){
					printf(" ");
				}
				k -= 2;//7--5--3--1--0
					
				for(a = 0; a < j - n / 2 + 1; ++a){
					printf("*");
				}
			}//else
		}//else
		printf("\n");
	}//for
}
int main()
{
    int num;
    scanf("%d", &num);
    print_graphic(num);
    return 0;
}
*/



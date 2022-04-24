//全排列回溯套路试点
#include<stdio.h>
#define OK 0
typedef int Status;
int num[10], judge[10];
void Fullpermutation(int position, int n){
	if(position <= n){
		for(int i = 1; i <= n; ++i){
			if(!judge[i]){//判断数组从1开始遍历，是从没有使用过的第一个数开始的
				num[position] = i;
				judge[i] = 1;
				Fullpermutation(position+1, n);
				judge[i] = 0;//返回的时候顺便把最后一位标记可访问,如果是position则当长度第一次达到n
									//之后会将最后一位标记可访问，for再循环会重新读值且输出，judge失去作用
									//且会与之前读取的值重复，如132,133
									//i这里代表下标，其实就是该数字是否可访问，judge[i]保证没有重复值即133
			}
		}//for
	}//if
	else{//数组大于n才意味着要输出
        for(int i = 1; i <= n; ++i){
			printf("%d", num[i]);
		}
		printf("\n");
	}
}
int main(){
	int n = 0;
	judge[0] = 0;
	scanf("%d", &n);
	Fullpermutation(1, n);
	return 0;
}



/*
//回溯（优化的枚举，对可能的条件进行枚举，深度优先）套路：

子函数{
	if(不满足递归条件)
		for（）{
			if（不满足回溯条件）{
				相应操作
				子函数递归
			}
		}
	else
		满足条件，返回或输出
}


//思路：最小递归单元是1位，数字由小到大，每一位作相同判断。数组存储符合条件的数，另设辅助数组（可访问标记1）保证不重复
//注意：数组是全局变量，初值先赋0
#include<stdio.h>
int num[11],jud[11];//从1开始使用
void FullPermutation(int x, int n){//全排列(带输出)
    for(int i = 1; i <= n; ++i){
        if(!jud[i]){//为0进入，表示i此时没被用过，num中不会出现重复值
            jud[i] = 1;
            num[x] = i;
            if(x == n){//数组长度够才输出
                for(int j = 1; j <= n; ++j){//从1到n
                    printf("%d", *(num + j));
                }
                printf("\n");
            }
            else{
                FullPermutation(x + 1, n);//对下一位进行相同的num赋值
            }
            jud[i] = 0;//每次小循环之后重新赋0，如：得1--之后开始2--的操作
        }//if
    }//for
}
int main(){
    int n;
    jud[0] = 1;//保证剩下的数全为0，可访问
    scanf("%d", &n);
    if(n > 0){
        FullPermutation(1, n);
    }
    return 0;
}
*/
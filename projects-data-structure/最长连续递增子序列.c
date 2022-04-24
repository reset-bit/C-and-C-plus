//思路：表从前向后遍历，遇到第一个比前一个元素小的说明不再为递增子序列，需要纪录此时最大递增子序列的长度和元素的位置，重复比较之后
//得出最大递增子序列长度和元素位置，输出
//注意：n=1,n=100000,最后一个元素的处理，两个决定新表是否更新的最大递增子序列长度的比较,更新值放在哪！！！
#include<stdio.h>
#include<stdlib.h>
int main(){
    int numcount = 0;
    int curlen = 0, max = 0, maxPosi = 0;
    scanf("%d", &numcount);
    int *arr = malloc(numcount * sizeof(int));
    for(int i = 0; i < numcount; ++i){
        scanf("%d", arr + i);
    }
    for(int i = 0; i < numcount; ++i){
        if(*(arr + i) < *(arr + i + 1))
            ++curlen;
        else{
            if(curlen > max){
                max = curlen;
                maxPosi = i;
            }
            curlen = 0;
        }
    }
    for(int *p = arr + maxPosi - max; p < arr + maxPosi; ++p)
        printf("%d ", *(p));
    printf("%d", *(arr + maxPosi));
    return 0;
}

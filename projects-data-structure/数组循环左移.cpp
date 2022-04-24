//思路：左侧0-m-1就地逆置，右侧m-n-1就地逆置，整个数组就地逆置
#include<stdio.h>
void inversion(int a[], int num1, int num2){
    int len = (num2 - num1) / 2;
    while(len>=0){
        int mid = a[num1 + len];
        a[num1 + len] = a[num2 - len];
        a[num2 - len] = mid;
        len--;
    }
}
int main(){
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);
    int num[n];
    for(int i = 0; i < n; ++i){
        scanf("%d", num + i);
    }
    if(m >= n)
        m = m % n;//!!!
    if(m > 0){//m=0特殊
        inversion(num, 0, m - 1);
        inversion(num, m, n - 1);
        inversion(num, 0, n - 1);
    }
    int i = 0;
    for(; i < n - 1; ++i){
        printf("%d ", num[i]);
    }
    printf("%d", num[i]);
}

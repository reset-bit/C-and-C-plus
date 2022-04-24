/*
每次选择最小（大）的放到最前（后）面
*/
//selectionsort
#include<stdio.h>
#include<stdlib.h>
int selectionsort(int a[], int n){
    for(int i = 1; i < n; ++i){//排n-1次序
        int min = i;//假设第一个最小
        for(int j = i; j <= n; ++j){//从当前位置到最后一个位置，遍历找最小
            if(a[j] < a[min])
                min = j;
        }
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}
int main(){
	int n = 0, *a = NULL;
	scanf("%d", &n);
	a = (int *)malloc((n + 1) * sizeof(int));
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
	}
	selectionsort(a, n);
	for(int i = 1; i <= n; ++i){
		if(i == 1)
			printf("%d", a[i]);
		else
			printf(" %d", a[i]);
	}
	return 0;
}

/*
一直分原始序列，直到两个只有一个元素的序列为止，之后进行合并（后返时进行合并）
*/
//mergesort
#include<stdio.h>
#include<stdlib.h>
#define OVERFLOW -1
void merge(int a[], int _low, int _mid, int _high){
    int n1 = _mid - _low + 1, n2 = _high - _mid, k1 = 0, k2 = 0;
    int *l = NULL, *r = NULL;
    l = (int *)malloc(n1 * sizeof(int));//0号用
    if(!l)exit(OVERFLOW);
    r = (int *)malloc(n2 * sizeof(int));
    if(!r)exit(OVERFLOW);
    for(int i = 0; i < n1; ++i){
        l[i] = a[_low + i];
    }
    for(int i = 0; i < n2; ++i){
        r[i] = a[_mid + i + 1];//+1注意
    }
    int i = _low;           //!! i范围注意 !!    以下为标准merge
    while(k1 < n1 && k2 < n2){
        if(l[k1] <= r[k2]){
            a[i++] = l[k1++];
        }
        else{
            a[i++] = r[k2++];
        }
    }
    while(k1 < n1){
        a[i++] = l[k1++];
    }
    while(k2 < n2){
        a[i++] = r[k2++];
    }
    free(l); free(r);
    l = r = NULL;
}
void mergesort(int a[], int low, int high){//利用递归
    if(low < high){
        int mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}
int main(){
	int n = 0, *a = NULL;
	scanf("%d", &n);
	a = (int *)malloc((n + 1) * sizeof(int));
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
	}
	mergesort(a, 1, n);
	for(int i = 1; i <= n; ++i){
		if(i == 1)
			printf("%d", a[i]);
		else
			printf(" %d", a[i]);
	}
	return 0;
}

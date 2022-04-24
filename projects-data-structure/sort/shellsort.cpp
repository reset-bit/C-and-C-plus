/*
设置增量序列，每次减小直到最后一次到1
每一次将记录分为若干子序列，对各子序列分别进行直接插入排序
增量序列：一般以折半的方式选取
*/
//shellsort
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void shellinsert(int a[], int n, int dk){
    for(int i = dk + 1; i <= n; ++i){//从第dk+1个元素开始在子序列内进行直接插入排序
        if(a[i] < a[i - dk]){
            a[0] = a[i];
            int j = 0;
            for(j = i - dk; j > 0 && a[j] > a[0]; j -= dk){//把a[j]>a[0]条件放在循环条件上，放在循环内会导致重复值（本身关系即为只要有比其小的就不移动）
                a[j + dk] = a[j];
            }
            a[j + dk] = a[0];
        }
    }
}
void shellsort(int a[], int n){//对数表示法(log2:logx/log2)
    int *dlta = NULL, m = n, len = log(n) / log(2);
    dlta = (int *)malloc(len * sizeof(int));
    for(int i = 0; i < len; ++i){
        dlta[i] = m / 2;
        m /= 2;
    }
    for(int k = 0; k < len; ++k){
        shellinsert(a, n, dlta[k]);
    }
}
int main(){
	int n = 0, *a = NULL;
	scanf("%d", &n);
	a = (int *)malloc((n + 1) * sizeof(int));
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
	}
	shellsort(a, n);
	for(int i = 1; i <= n; ++i){
		if(i == 1)
			printf("%d", a[i]);
		else
			printf(" %d", a[i]);
	}
	return 0;
}

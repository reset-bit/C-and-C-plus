/*
有序块在前，无序块在后，利用递归思想先排好前n-1个
无序块从前向后，有序块从后向前遍历。直到定位到第一个大于等于待插入元素的记录左侧，插入即可
适用于：基本有序/n值较小时
*/
//insertionsort
#include<stdio.h>
void insertionsort (int a[], int n){//非递归实现
    for(int i = 2; i <= n; ++i){
        if(a[i] < a[i - 1]){
            a[0] = a[i];
            int j = 0;
            for(j = i - 1;a[j] > a[0]; --j){
                a[j + 1] = a[j];
            }
            a[j + 1] = a[0];//a[j]是第一个小于等于带插入元素的值，为了保证稳定性插在a[j+1]的左边
        }//if
    }//for
}
int main(){
	int n = 0, *a = NULL;
	scanf("%d", &n);
	a = (int *)malloc((n + 1) * sizeof(int));
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
	}
	insertionsort(a, n);
	for(int i = 1; i <= n; ++i){
		if(i == 1)
			printf("%d", a[i]);
		else
			printf(" %d", a[i]);
	}
	return 0;
}

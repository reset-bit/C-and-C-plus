/*
右向左：不比枢纽小high才向前（要找小的）；左向右：不比枢纽大low才向后（要找大的）
有很多实现的方法，如（选区最左端为枢纽）
①从左向右遍历，小的从左向右放，大的从右向左放----浪费空间
②high指最大，low指最小
从右向左遍历，遇到第一个比枢纽小的就搬到枢纽原来的位置，会空出一个位置
从左向右遍历，将第一个比枢纽大的元素填入空出来的位置
直到low=high，将pivot搬到该处
*/
/*改进的快排：
1.取left/right/(left+right)\2中关键字居中的那一个
2.随机化枢纽（对具有大量相等元素的数据，更可以将相等元素均匀的分入两个区间）
*/
//quicksort
#include<stdio.h>
#include<stdlib.h>
int partition(int a[], int low, int high){//返回枢纽新位置
	a[0] = a[low];
	while(low < high){
		while(low < high && a[high] >= a[0])//low < high 保证条件完备！
			high--;
		a[low] = a[high];
		while(low < high && a[low] <= a[0])
			low++;
		a[high] = a[low];
	}//此时low是pivot待填入位置
	a[low] = a[0];
	return low;
}
void quicksort(int a[], int pivot,  int right){//pivot枢轴,right右端边界
	if(pivot < right){
		int q = partition(a, pivot, right);
		quicksort(a, pivot, q - 1);//左侧快速排序
		quicksort(a, q + 1, right);//右侧快速排序
	}

}
int main(){
	int n = 0, *a = NULL;
	scanf("%d", &n);
	a = (int *)malloc((n + 1) * sizeof(int));
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
	}
	quicksort(a, 1, n);
	for(int i = 1; i <= n; ++i){
		if(i == 1)
			printf("%d", a[i]);
		else
			printf(" %d", a[i]);
	}
	return 0;
}
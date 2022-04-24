/*
�����۰������С����ʱ�䣬����˼·ͬinsertionsort
�۰룺high/low/mid��ֱ����λ����һ���ȴ�����Ԫ�ش��λ�ã����뼴��
*/
//bininsertionsort
#include<stdio.h>
#include<stdlib.h>
void bininsertionsort(int a[], int n){
    for(int i = 2; i <= n; ++i){//���Ǵӵڶ�����¼��ʼ����
        int high = i - 1, low = 1;
        while(low <= high){//������Ч
            int mid = (high + low) / 2;
            if(a[i] > a[mid])
                low = mid + 1;
            else if (a[i] < a[mid])
                high = mid - 1;
        }
        a[0] = a[i];
        for(int j = i - 1; j >= high + 1; --j){
            a[j + 1] = a[j];
        }
        a[high + 1] = a[0];//��ʱhigh�ǵ�һ��С�ڵ��ڴ�����Ԫ�ص�ֵ
    }
}
int main(){
	int n = 0, *a = NULL;
	scanf("%d", &n);
	a = (int *)malloc((n + 1) * sizeof(int));
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
	}
	bininsertionsort(a, n);
	for(int i = 1; i <= n; ++i){
		if(i == 1)
			printf("%d", a[i]);
		else
			printf(" %d", a[i]);
	}
	return 0;
}

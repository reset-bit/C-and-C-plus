/*
ÿ��ѡ����С���󣩵ķŵ���ǰ������
*/
//selectionsort
#include<stdio.h>
#include<stdlib.h>
int selectionsort(int a[], int n){
    for(int i = 1; i < n; ++i){//��n-1����
        int min = i;//�����һ����С
        for(int j = i; j <= n; ++j){//�ӵ�ǰλ�õ����һ��λ�ã���������С
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

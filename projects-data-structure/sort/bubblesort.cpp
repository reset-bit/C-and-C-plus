/*
�Ƚ�������Ԫ�أ�СԪ����������Ԫ���³�
��1����Ϊ���򣬴ӵ�2����ʼ
*/
//bubblesort
#include<stdio.h>
#include<stdlib.h>
void bubblesort(int a[], int n){
    for(int i = 1; i < n; ++i){//��������
        for(int j = 1; j <= n - i;++j){//ÿ�˱ȽϵĴ���
            if(a[j] > a[j + 1]){
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
int main(){
	int n = 0, *a = NULL;
	scanf("%d", &n);
	a = (int *)malloc((n + 1) * sizeof(int));
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
	}
	bubblesort(a, n);
	for(int i = 1; i <= n; ++i){
		if(i == 1)
			printf("%d", a[i]);
		else
			printf(" %d", a[i]);
	}
	return 0;
}

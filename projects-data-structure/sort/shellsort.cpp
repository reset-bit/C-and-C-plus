/*
�����������У�ÿ�μ�Сֱ�����һ�ε�1
ÿһ�ν���¼��Ϊ���������У��Ը������зֱ����ֱ�Ӳ�������
�������У�һ�����۰�ķ�ʽѡȡ
*/
//shellsort
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void shellinsert(int a[], int n, int dk){
    for(int i = dk + 1; i <= n; ++i){//�ӵ�dk+1��Ԫ�ؿ�ʼ���������ڽ���ֱ�Ӳ�������
        if(a[i] < a[i - dk]){
            a[0] = a[i];
            int j = 0;
            for(j = i - dk; j > 0 && a[j] > a[0]; j -= dk){//��a[j]>a[0]��������ѭ�������ϣ�����ѭ���ڻᵼ���ظ�ֵ�������ϵ��ΪֻҪ�б���С�ľͲ��ƶ���
                a[j + dk] = a[j];
            }
            a[j + dk] = a[0];
        }
    }
}
void shellsort(int a[], int n){//������ʾ��(log2:logx/log2)
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

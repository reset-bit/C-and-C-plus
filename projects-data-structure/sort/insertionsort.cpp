/*
�������ǰ��������ں����õݹ�˼�����ź�ǰn-1��
������ǰ��������Ӻ���ǰ������ֱ����λ����һ�����ڵ��ڴ�����Ԫ�صļ�¼��࣬���뼴��
�����ڣ���������/nֵ��Сʱ
*/
//insertionsort
#include<stdio.h>
void insertionsort (int a[], int n){//�ǵݹ�ʵ��
    for(int i = 2; i <= n; ++i){
        if(a[i] < a[i - 1]){
            a[0] = a[i];
            int j = 0;
            for(j = i - 1;a[j] > a[0]; --j){
                a[j + 1] = a[j];
            }
            a[j + 1] = a[0];//a[j]�ǵ�һ��С�ڵ��ڴ�����Ԫ�ص�ֵ��Ϊ�˱�֤�ȶ��Բ���a[j+1]�����
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

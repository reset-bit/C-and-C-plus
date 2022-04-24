/*
��Ϊ��ʼ�󶥶Ѻ�ɸѡ������
��ʼ�󶥶ѣ���Ȼ�����νṹ����ʵ��Ϊ���ԣ���ɸѡ������󶥶Ѽ���
ɸѡ������֮����бȽϣ�֮����˫�ױȽϣ���Ҫʱ������ֱ��ÿ���ڵ㶼���ں���
����ע�ⷶΧ��ѡȡ��
*/
//heapsort
#include<stdio.h>
#include<stdlib.h>
void heapadjust(int a[], int head, int tail){//ɸѡ
    int lchild = 2 * head, rchild = 2 * head + 1, bigchild = 0;
    a[0] = a[head];//���ݴ�ʱ����
    while(lchild <= tail){//������Ч����֤�к��Ӿ���
        if(rchild <= tail && a[lchild] < a[rchild])
            bigchild = rchild;
        else
            bigchild = lchild;//�Һ��ӿ���û��
        if(a[0] >= a[bigchild])//ɸѡ���
            break;
        else{
            a[head] = a[bigchild];
            head = bigchild;//��������
            lchild = 2 * head;
            rchild = 2 * head + 1;
        }
        a[head] = a[0];//��ʱhead�Ѿ��Ǻ�����
    }
}
void heapsort(int a[], int n){
    for(int i = n / 2; i > 0; --i){//��ʼ�󶥶�,�ӵ�һ����Ҷ�ӽ�㿪ʼ���ʶѶ��ı�
        heapadjust(a, i, n);
    }
    for(int i = 1; i < n; ++i){//
        int temp = a[1];//�����Ѷ��Ͷ�β���Ѷ�����a[1]
        a[1] = a[n - i + 1];
        a[n - i + 1] = temp;
        heapadjust(a, 1, n - i);//�Ӻ���ǰ�����ҳ���ĺ��ԣ��ʶ�β�ı䣬�Ӻ��Ե�ǰһ����ʼ
    }
}
int main(){
	int n = 0, *a = NULL;
	scanf("%d", &n);
	a = (int *)malloc((n + 1) * sizeof(int));
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
	}
	heapsort(a, n);
	for(int i = 1; i <= n; ++i){
		if(i == 1)
			printf("%d", a[i]);
		else
			printf(" %d", a[i]);
	}
	return 0;
}

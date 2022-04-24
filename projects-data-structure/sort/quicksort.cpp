/*
�����󣺲�����ŦСhigh����ǰ��Ҫ��С�ģ��������ң�������Ŧ��low�����Ҫ�Ҵ�ģ�
�кܶ�ʵ�ֵķ������磨ѡ�������Ϊ��Ŧ��
�ٴ������ұ�����С�Ĵ������ҷţ���Ĵ��������----�˷ѿռ�
��highָ���lowָ��С
�������������������һ������ŦС�ľͰᵽ��Ŧԭ����λ�ã���ճ�һ��λ��
�������ұ���������һ������Ŧ���Ԫ������ճ�����λ��
ֱ��low=high����pivot�ᵽ�ô�
*/
/*�Ľ��Ŀ��ţ�
1.ȡleft/right/(left+right)\2�йؼ��־��е���һ��
2.�������Ŧ���Ծ��д������Ԫ�ص����ݣ������Խ����Ԫ�ؾ��ȵķ����������䣩
*/
//quicksort
#include<stdio.h>
#include<stdlib.h>
int partition(int a[], int low, int high){//������Ŧ��λ��
	a[0] = a[low];
	while(low < high){
		while(low < high && a[high] >= a[0])//low < high ��֤�����걸��
			high--;
		a[low] = a[high];
		while(low < high && a[low] <= a[0])
			low++;
		a[high] = a[low];
	}//��ʱlow��pivot������λ��
	a[low] = a[0];
	return low;
}
void quicksort(int a[], int pivot,  int right){//pivot����,right�Ҷ˱߽�
	if(pivot < right){
		int q = partition(a, pivot, right);
		quicksort(a, pivot, q - 1);//����������
		quicksort(a, q + 1, right);//�Ҳ��������
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
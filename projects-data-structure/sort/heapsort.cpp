/*
分为初始大顶堆和筛选两部分
初始大顶堆：虽然是树形结构但是实际为线性，故筛选至满足大顶堆即可
筛选：孩子之间进行比较，之后与双亲比较，必要时互换，直到每个节点都大于孩子
其中注意范围的选取！
*/
//heapsort
#include<stdio.h>
#include<stdlib.h>
void heapadjust(int a[], int head, int tail){//筛选
    int lchild = 2 * head, rchild = 2 * head + 1, bigchild = 0;
    a[0] = a[head];//备份此时顶堆
    while(lchild <= tail){//区间有效，保证有孩子就行
        if(rchild <= tail && a[lchild] < a[rchild])
            bigchild = rchild;
        else
            bigchild = lchild;//右孩子可能没有
        if(a[0] >= a[bigchild])//筛选完成
            break;
        else{
            a[head] = a[bigchild];
            head = bigchild;//向下延伸
            lchild = 2 * head;
            rchild = 2 * head + 1;
        }
        a[head] = a[0];//此时head已经是孩子了
    }
}
void heapsort(int a[], int n){
    for(int i = n / 2; i > 0; --i){//初始大顶堆,从第一个非叶子结点开始，故堆顶改变
        heapadjust(a, i, n);
    }
    for(int i = 1; i < n; ++i){//
        int temp = a[1];//交换堆顶和堆尾，堆顶总是a[1]
        a[1] = a[n - i + 1];
        a[n - i + 1] = temp;
        heapadjust(a, 1, n - i);//从后向前，先找出大的忽略，故堆尾改变，从忽略的前一个开始
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

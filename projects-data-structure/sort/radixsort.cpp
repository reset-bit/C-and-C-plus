/*
由低位到高位进行桶排序，可能要用到队列
*/
//radixsort（3位数）
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10//每位数据取值范围0~9共计10
#define NUM 3 //每个数据由三位数字组成
typedef struct {
	int front;
	int rear;
} Queue;
//定义“桶”
Queue queue[N];
typedef struct {
	int data;
	int next;
}List;
//获取一个整数的位数
int get_figure_num(int number){
	int temp = number;
	int count = 0;
	while(temp > 10) {
		count++;
		temp /= 10;
	}
	count++;
	return count;
}
//按位提取数字
int extract_number(int number, int num) {
	int temp;
	switch(num) {
	case 0:
		temp = number -(number/10)*10;
		break;
	case 1:
		temp = number%100/10;
		break;
	case 2:
		temp = number/100;
		break;
	default:
		;
	}
	return temp;
}
//按某位数字将数据分配到相应桶中
void distribute_by_certain_num(List list[], int n, int head, int certain_num){
	int temp;
	for(int i = head; i != -1; i = list[i].next) {
		temp = extract_number(list[i].data, certain_num);
		if(-1 == queue[temp].front) {
			queue[temp].front = i;
			queue[temp].rear = i;
		}
		else {
			list[queue[temp].rear].next = i;
			queue[temp].rear = i;//注释1：更改队列尾指针
		}
	}
}
//将桶中的数据按队列的顺序收集
int collect_by_queue(List list[], int n) {
	int head = 0;
    int p = 0;
	int j = 0;
	while(-1 == queue[j].front) {
		j++;
	}
	head = queue[j].front;
	p = queue[j].rear;
	for(int i = j + 1; i < n; ++i) {
		if(queue[i].front != -1) {
			list[p].next = queue[i].front;
			p = queue[i].rear;
		}
	}
	list[p].next = -1;
	//注释2：***清空队列***非常重要的步骤！
	for(int i = 0; i < N; ++i) {
		queue[i].front = -1;
		queue[i].rear = -1;
	}

	return head;
}
void radix_sort(List list[], int n) {
	int head = 0;
	for(int i = 0; i < N; ++i) {
		queue[i].front = -1;
		queue[i].rear = -1;
	}
	for(int i = 0; i < NUM; ++i) {
		distribute_by_certain_num(list, n, head, i);
		head = collect_by_queue(list, n);
	}
	for(int i = head; i != -1; i = list[i].next) {
		printf("%5d", list[i].data);
	}
	printf("\n");
}
int main() {
	List list[10];
	for(int i = 0; i < 10; ++i) {
		list[i].data = rand() % 900 + 100 - i;//随机生成3位随机数
		if(i < 9) {
			list[i].next = i + 1;
		}
		else {
			list[i].next = -1;
		}
	}
	radix_sort(list, 10);
	return 0;
}

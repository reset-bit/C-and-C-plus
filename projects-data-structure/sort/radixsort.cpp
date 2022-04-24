/*
�ɵ�λ����λ����Ͱ���򣬿���Ҫ�õ�����
*/
//radixsort��3λ����
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10//ÿλ����ȡֵ��Χ0~9����10
#define NUM 3 //ÿ����������λ�������
typedef struct {
	int front;
	int rear;
} Queue;
//���塰Ͱ��
Queue queue[N];
typedef struct {
	int data;
	int next;
}List;
//��ȡһ��������λ��
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
//��λ��ȡ����
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
//��ĳλ���ֽ����ݷ��䵽��ӦͰ��
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
			queue[temp].rear = i;//ע��1�����Ķ���βָ��
		}
	}
}
//��Ͱ�е����ݰ����е�˳���ռ�
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
	//ע��2��***��ն���***�ǳ���Ҫ�Ĳ��裡
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
		list[i].data = rand() % 900 + 100 - i;//�������3λ�����
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

#include<stdio.h>
//��֪λ��
int main(){
    int x,i,num = 0,a[100]= {0};
    printf("������һ����:\n");
    scanf("%d", &x);
    printf("�ɸ�λ����λ�������:\n");
    while(x){//�ɵ�λ����λ����˳���������
        a[num] = x % 10;
        num++;
        x /= 10;
    }
    for(i = num - 1; i >= 0; i--){ //�ɸ�λ����λ�����������
        printf("%d\n",a[i]);
    }
    return 0;
}
//֪λ��
//#include <stdio.h>
//int main(){
//	int x,i,k,a[3] = {0};
//	printf("������һ����:\n");
//	scanf("%d",&x);
//	printf("�ɸ�λ����λ�������:\n");
//	for(i = 0,k = 1000;k >= 10;i++){//�ɸ�λ����λ����˳����������
//		a[i] = (x % k) / (k / 10);
//		k /= 10;
//	}
//	for(i = 0;i < 3;i++){//�ɸߵ���λ˳���������
//		printf("%d\n",a[i]);
//	}
//	return 0;
//}

#include<stdio.h>
//不知位数
int main(){
    int x,i,num = 0,a[100]= {0};
    printf("请输入一个数:\n");
    scanf("%d", &x);
    printf("由高位到低位依次输出:\n");
    while(x){//由低位到高位依次顺序存入数组
        a[num] = x % 10;
        num++;
        x /= 10;
    }
    for(i = num - 1; i >= 0; i--){ //由高位到低位逆序输出数组
        printf("%d\n",a[i]);
    }
    return 0;
}
//知位数
//#include <stdio.h>
//int main(){
//	int x,i,k,a[3] = {0};
//	printf("请输入一个数:\n");
//	scanf("%d",&x);
//	printf("由高位到低位依次输出:\n");
//	for(i = 0,k = 1000;k >= 10;i++){//由高位到低位依次顺序输入数组
//		a[i] = (x % k) / (k / 10);
//		k /= 10;
//	}
//	for(i = 0;i < 3;i++){//由高到低位顺序输出数组
//		printf("%d\n",a[i]);
//	}
//	return 0;
//}

/*����Ϊһ������n��1<n<50�����һ��n��Ŀ�������*/
#include<stdio.h>
#include<math.h>
int print_graphic(int n)
{
    int i, j;
    for(i = -(n - 1) / 2; i <= (n - 1) / 2; i++){//-5--->5��
		for(j =- (n - 1) / 2; j <= (n - 1) / 2; j++)//-5---->5��
			if((abs(i) + abs(j)) >= (n - 1) / 2)//abs�����ֵ
				printf("*");
			else
				printf(" ");
		printf("\n");
    }
}
int main()
{
    int num;
    scanf("%d", &num);
    print_graphic(num);
    return 0;
}

/*
�������

#include<stdio.h>
//˼·�����η����������֣��ո��������仯
//��ÿһ�з�Ϊ3���֣��ո�ǰ���ո񣬿ո�����пո�ǰ���ǻ����Գ�
//��һ�������һ�е�������
int print_graphic(int n){
	int  j = 0, k = 1;//k��¼�ո���
	for(j = 0; j < n; ++j){//max*=11
		int a = 0;//����ѭ������
		if(j == 0 || j == n - 1){
			for(a = 0; a < n; ++a){
				printf("*");
			}
		}
		else{
			if(j < (n + 1) / 2){//5
				for(a = 0; a < ((n + 1) / 2) - j; ++a){
					printf("*");
				}

				for(a = 0; a < k; ++a){
					printf(" ");
				}
				k += 2;
					
				for(a = 0; a < ((n + 1) / 2) - j; ++a){
					printf("*");
				}
			}
			else{
				if(j == 6)
					k -= 4;
				for(a = 0; a < j - n / 2 + 1; ++a){//6-5+1
					printf("*");
				}

				for(a = 0; a < k; ++a){
					printf(" ");
				}
				k -= 2;//7--5--3--1--0
					
				for(a = 0; a < j - n / 2 + 1; ++a){
					printf("*");
				}
			}//else
		}//else
		printf("\n");
	}//for
}
int main()
{
    int num;
    scanf("%d", &num);
    print_graphic(num);
    return 0;
}
*/



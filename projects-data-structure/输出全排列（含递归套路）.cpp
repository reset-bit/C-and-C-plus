//ȫ���л�����·�Ե�
#include<stdio.h>
#define OK 0
typedef int Status;
int num[10], judge[10];
void Fullpermutation(int position, int n){
	if(position <= n){
		for(int i = 1; i <= n; ++i){
			if(!judge[i]){//�ж������1��ʼ�������Ǵ�û��ʹ�ù��ĵ�һ������ʼ��
				num[position] = i;
				judge[i] = 1;
				Fullpermutation(position+1, n);
				judge[i] = 0;//���ص�ʱ��˳������һλ��ǿɷ���,�����position�򵱳��ȵ�һ�δﵽn
									//֮��Ὣ���һλ��ǿɷ��ʣ�for��ѭ�������¶�ֵ�������judgeʧȥ����
									//�һ���֮ǰ��ȡ��ֵ�ظ�����132,133
									//i��������±꣬��ʵ���Ǹ������Ƿ�ɷ��ʣ�judge[i]��֤û���ظ�ֵ��133
			}
		}//for
	}//if
	else{//�������n����ζ��Ҫ���
        for(int i = 1; i <= n; ++i){
			printf("%d", num[i]);
		}
		printf("\n");
	}
}
int main(){
	int n = 0;
	judge[0] = 0;
	scanf("%d", &n);
	Fullpermutation(1, n);
	return 0;
}



/*
//���ݣ��Ż���ö�٣��Կ��ܵ���������ö�٣�������ȣ���·��

�Ӻ���{
	if(������ݹ�����)
		for����{
			if�����������������{
				��Ӧ����
				�Ӻ����ݹ�
			}
		}
	else
		�������������ػ����
}


//˼·����С�ݹ鵥Ԫ��1λ��������С����ÿһλ����ͬ�жϡ�����洢�����������������踨�����飨�ɷ��ʱ��1����֤���ظ�
//ע�⣺������ȫ�ֱ�������ֵ�ȸ�0
#include<stdio.h>
int num[11],jud[11];//��1��ʼʹ��
void FullPermutation(int x, int n){//ȫ����(�����)
    for(int i = 1; i <= n; ++i){
        if(!jud[i]){//Ϊ0���룬��ʾi��ʱû���ù���num�в�������ظ�ֵ
            jud[i] = 1;
            num[x] = i;
            if(x == n){//���鳤�ȹ������
                for(int j = 1; j <= n; ++j){//��1��n
                    printf("%d", *(num + j));
                }
                printf("\n");
            }
            else{
                FullPermutation(x + 1, n);//����һλ������ͬ��num��ֵ
            }
            jud[i] = 0;//ÿ��Сѭ��֮�����¸�0���磺��1--֮��ʼ2--�Ĳ���
        }//if
    }//for
}
int main(){
    int n;
    jud[0] = 1;//��֤ʣ�µ���ȫΪ0���ɷ���
    scanf("%d", &n);
    if(n > 0){
        FullPermutation(1, n);
    }
    return 0;
}
*/
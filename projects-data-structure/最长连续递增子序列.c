//˼·�����ǰ��������������һ����ǰһ��Ԫ��С��˵������Ϊ���������У���Ҫ��¼��ʱ�����������еĳ��Ⱥ�Ԫ�ص�λ�ã��ظ��Ƚ�֮��
//�ó������������г��Ⱥ�Ԫ��λ�ã����
//ע�⣺n=1,n=100000,���һ��Ԫ�صĴ������������±��Ƿ���µ������������г��ȵıȽ�,����ֵ�����ģ�����
#include<stdio.h>
#include<stdlib.h>
int main(){
    int numcount = 0;
    int curlen = 0, max = 0, maxPosi = 0;
    scanf("%d", &numcount);
    int *arr = malloc(numcount * sizeof(int));
    for(int i = 0; i < numcount; ++i){
        scanf("%d", arr + i);
    }
    for(int i = 0; i < numcount; ++i){
        if(*(arr + i) < *(arr + i + 1))
            ++curlen;
        else{
            if(curlen > max){
                max = curlen;
                maxPosi = i;
            }
            curlen = 0;
        }
    }
    for(int *p = arr + maxPosi - max; p < arr + maxPosi; ++p)
        printf("%d ", *(p));
    printf("%d", *(arr + maxPosi));
    return 0;
}

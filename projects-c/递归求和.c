#include<stdio.h>
int numsum(int k,int sum){
    static int cou=0;
    int cur=0;
    scanf("%d",&cur);
    cou++;
    if(cou==k){
        sum=cur;
        return sum;
    }
    sum=cur+numsum(k,sum);
    return sum;
}
int main(){
    int k=0,sum=0;
    scanf("%d",&k);
    sum=numsum(k,sum);
    printf("%d",sum);
    return 0;
}

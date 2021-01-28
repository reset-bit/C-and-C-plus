#include<stdio.h>
void hanoi(int n, int a, int b, int c){
    if(n == 1)
        printf("   plate %d : from %d to %d\n", n, a, c);
    else{
        hanoi(n - 1, a, c, b);
        printf("   plate %d : from %d to %d\n", n, a, c);
        hanoi(n - 1, b, a, c);
    }
}
int main(){
    int i = 0, n = 0, n1 = 0, n2 = 0, n3 = 0;
    while(scanf("%d %d %d %d", &n, &n1, &n2, &n3) != EOF){
        //n1为第一个盘子，n2为中间盘，n3为目标盘
        printf("case %d :\n", ++i);
        hanoi(n, n1, n2, n3);
        printf("\n");
    }
    return 0;
}

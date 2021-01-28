//1+9999--->4
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char x[100],y[100];
    while(scanf("%s %s",x,y) != EOF){
        int lengx = strlen(x);
        int lengy = strlen(y);
        int i,j,cou = 0,temp = 0,plus = 0;
        for(i = lengx - 1, j = lengy - 1; i >= 0 || j >= 0; i--,j--){
            if(i >= 0)
                temp += x[i] - '0';
            if(j >= 0)
                temp += y[j] - '0';
            if(temp + plus >= 10){
                plus = 1;
                cou++;
            }
            else
                plus = 0;
            temp = 0;
        }
        printf("%d\n",cou);
    }
    return 0;
}

#include<stdio.h>
int main(){
    int i,s,r[5],n;//n存次数
    char a[100001],*p;
    float f[5];//存比率
    n=0;
    while ( gets(a) ){
        n++; p=a;//p操作次数
        for ( i=0;i<5;i++ )
            r[i]=0;
        s=0;
        while ( *p ){
            if ( ((*p)>='a' && (*p)<='z') || ((*p)>='A' && (*p)<='Z') ){
                s++;//总字母数
                switch ( *p ){
                    case 'a':
                    case 'A': r[0]++; break;
                    case 'e':
                    case 'E': r[1]++; break;
                    case 'i':
                    case 'I': r[2]++; break;
                    case 'o':
                    case 'O': r[3]++; break;
                    case 'u':
                    case 'U': r[4]++; break;
                }
            }
            p++;
        }//while
        for ( i=0;i<5;i++ ){
            f[i]=r[i];
            f[i]/=s;
        }
        printf("case %d :\n",n);
        i=0;
        printf("A : %7.4f%%\n",f[i++]*100);
        printf("E : %7.4f%%\n",f[i++]*100);
        printf("I : %7.4f%%\n",f[i++]*100);
        printf("O : %7.4f%%\n",f[i++]*100);
        printf("U : %7.4f%%\n",f[i]*100);
        printf("\n");
    }
}

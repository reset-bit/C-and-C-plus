#include <stdio.h>
void PrintN(long n);

int main()
{
    PrintN(65092);
    return 0;
}


void PrintN(long N){
    if(N==1){
        printf("1");
        return;
    }
    else
        PrintN(N-1);
    printf("%d",N);
}

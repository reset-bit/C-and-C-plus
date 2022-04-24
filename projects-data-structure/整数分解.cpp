#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <climits>
#include <functional>
using namespace std;
#define LL long long
const int INF=0x3f3f3f3f;
int n,a[10009],cnt=0;
void dfs(int k,int sum,int p)
{
    if(sum==n)
    {
        printf("%d=%d",n,a[0]);
        for(int i=1;i<p;i++)
            printf("+%d",a[i]);
        cnt++;
        if(cnt==4) printf("\n"),cnt=0;
        else if(p==1) printf("\n");
        else printf(";");
        return ;
    }
    for(int i=k;i<=n;i++)
    {
        if(sum+i<=n)
        {
            a[p]=i;
            dfs(i,sum+i,p+1);
        }
        else break;
    }
}

int main()
{
    while(~scanf("%d",&n))
    {
        cnt=0;
        dfs(1,0,0);
    }
    return 0;
}

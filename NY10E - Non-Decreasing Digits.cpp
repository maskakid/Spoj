#include<bits/stdc++.h>
#define LL long long int
using namespace std;

int n,cnt=0;
LL dp[11][70];
LL ans[70];

void rec(int res,int prev, int deep)
{
    if(deep==n)
        cnt++;
    if(deep>n)  return;
    for(int i=0; i<10; i++)
    {
        if(deep<n and prev<=i)
            rec(res*10+i,i,deep+1);
    }
    return;
}

void rec1()
{
    for(int i=0; i<10; i++)
        dp[i][1]=1;
    for(int i=0; i<10; i++)
        for(int j=2; j<65; j++)
            for(int k=0; k<=i; k++)
                dp[i][j]+=dp[k][j-1];

    int k=1;
    for(int len=1; len<65; len++)
    {
        LL cnt=0;
        for(int i=0; i<10; i++)
            cnt+=dp[i][len];
        ans[k]=cnt,k++;
    }
    return;
}

int main()
{
    rec1();
    int t,cas=1,x;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&x,&n);
        printf("%d %lld\n",cas++,ans[n]);
    }
    return 0;
}

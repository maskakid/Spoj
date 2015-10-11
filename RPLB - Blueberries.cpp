/*
    Author      : Akid (CSE'11,CUET)

    Problem Type: dp,knapsack
*/

#include<bits/stdc++.h>
using namespace std;

int n,k;
int dp[1010][1010];
int A[1010];

int rec(int limit, int i)
{
    if(i>=n)  return 0;
    if(dp[i][limit]!=-1)   return  dp[i][limit];

    int p1=0,p2=0;
    if(limit+A[i]<=k)
    p1= A[i] + rec(limit+A[i], i+2);
    p2=rec(limit, i+1);
    return dp[i][limit]=max(p1,p2);
}

int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        for(int i=0; i<n; i++)  scanf("%d",&A[i]);
        memset(dp,-1,sizeof(dp));
        printf("Scenario #%d: %d\n",cas++,rec(0,0));
    }
    return 0;
}

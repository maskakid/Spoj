/*
    Author      : Akid (CSE'11,CUET)

    Resources   : http://www.geeksforgeeks.org/total-number-of-non-decreasing-numbers-with-n-digits/
*/

#include<bits/stdc++.h>
#define LL long long int
using namespace std;

int n,x;
LL dp[11][70];
LL ans[70];

void rec()
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
    rec();
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&x,&n);
        printf("%d %lld\n",cas++,ans[n]);
    }
    return 0;
}

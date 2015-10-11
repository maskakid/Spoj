/*
    Author      : Akid (CSE'11,CUET)

    Problem Type: dp
*/

//110 --->>1{(1)(10)}

#include<bits/stdc++.h>
#define LL long long int
using namespace std;

int len;
LL dp[5010][30];
string str;

LL rec(int ind, LL res)
{
    if(res<1 or res>26)   return 0LL;
    if(ind>=len )  return 1LL;

    if(dp[ind][res]!=-1)   return dp[ind][res];

    LL p1=rec(ind+1, str[ind]-'0');

    LL x=0;
    if(ind+1<len and str[ind]!='0')
    x=(str[ind]-'0')*10LL+(str[ind+1]-'0');

    LL p2=rec(ind+2,x);

    return dp[ind][res]=(p1+p2);
}

int main()
{
    while(cin>>str)
    {
        if(str=="0")    return 0;
        len=str.size();
        memset(dp,-1,sizeof(dp));
        printf("%lld\n",rec(0,1));
    }
    return 0;
}

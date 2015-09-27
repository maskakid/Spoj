/*
    Author: Akid (CSE'11,CUET)

    Relation: 2*(n*(n+1)/2)+(n*(n-1)/2)
    warning: the output requests for
    (number of cards needed to make n levels) mod 1000007,
    not number of cards needed to make (n mod 1000007) levels.
    Take long long int in place of int.
*/

#include<bits/stdc++.h>
#define LL long long int
#define mod 1000007
using namespace std;

int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        LL n;
        scanf("%lld",&n);
        LL ans=n*(n+1);
        n--;
        LL ans1=(n*(n+1))/2;
        printf("%lld\n",(ans+ans1)%mod);
    }
    return 0;
}

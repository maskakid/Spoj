#include<bits/stdc++.h>
#define LL unsigned long long int
LL n,t;
int main()
{
    scanf("%llu",&t);
    while(t--)
    {
        scanf("%llu",&n);
        printf("%llu\n",((n*(n+2)*(2*n+1))/8));
    }
    return 0;
}

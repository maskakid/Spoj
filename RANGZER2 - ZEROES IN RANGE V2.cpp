/*
    Author      : Akid (CSE'11,CUET)

    Resources   : http://stackoverflow.com/questions/11891984/count-the-number-of-occurrences-of-0s-in-integers-from-1-to-n
*/

#include<bits/stdc++.h>
#define LL unsigned long long int
using namespace std;

LL a,b;

LL popcount(LL n)
{
    LL cnt=0;
    while(n)
    {
        cnt+=(n%10==0);
        n/=10;
    }
    return cnt;
}

LL _count(LL n)
{
    if(n==0) return 0;
    if(n<=10) return 1;

    LL k=n/10,r=n%10;
    LL cnt=k+10*(_count(k)-1);
    if(r>0) cnt+= r*popcount(k)+1;
    return cnt;
}

int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%llu %llu",&a, &b);
        printf("%llu\n",_count(b+1)-_count(a));
    }
    return 0;
}



/*
    Author: Akid (CSE'11,CUET)

    problem-id: : PROOT - Primitive Root
    problem-link: http://www.spoj.com/problems/PROOT/
    problem-type: math,implementation
    Resources   : http://goo.gl/6tM87H
                  https://en.wikipedia.org/wiki/Primitive_root_modulo_n
*/

#include<bits/stdc++.h>
#define _max 10000000+10
#define LL long long int
using namespace std;

template<class T> inline T bigmod(T a, T b, T c)
{
    LL res=1;
    while(b>0)
    {
        if(b&1) res=(res*a)%c;
        a=(a*a)%c;
        b>>=1;
    }
    return (T)res;
}

int A[_max /32];
int prime[_max], indx;
vector<LL> vc;

void sieve()
{
    int sqr=sqrt(_max);
    for(int i=3; i<=sqr; i+=2)
    {
        if( (A[i/32] & (1<<(i%32)) )==0)
        {
            for(int j=i*i ; j<_max; j+=2*i)
                A[j/32]|=(1<<(j%32));
        }
    }

    prime[indx++]=2;
    for(int i=3; i<_max;i+=2)
    if((A[i/32] & (1<<(i%32)))==0)
    prime[indx++]=i;
}

void factor(LL n)
{
    for(int i=0 ;i<indx and prime[i]<=sqrt(n); i++)
    {
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)  n=n/prime[i];
            vc.push_back(prime[i]);
        }
    }
    if(n>1) vc.push_back(n);
    return;
}

int main()
{
    sieve();
    LL n,q;

    while(scanf("%lld %lld",&n,&q) and (n>0 and q>0))
    {
        factor(n-1);
        while(q--)
        {
            LL r;
            bool ok=true;
            scanf("%lld",&r);
            for(int i=0;i<vc.size();i++)
            if(bigmod(r,(n-1)/vc[i] , n) ==1)
            {
                ok=false;
                break;
            }
            printf(ok ? "YES\n" : "NO\n");
        }
        vc.clear();
    }
    return 0;
}

/* Notes:
	1. Find did k is primitive root of n or not

	2. If n is prime then Phi(n) = n - 1 (it is guarantee), let Phi(n) = phi

	3. Here n is prime so Euler phi is not needed

	4. Then factorized Phi, here f vector contain the prime factor of phi

	5. Now for all prime factor of phi if (k ^ (phi / prime_i)) % n == 1
	then k is not a primitive root of n

	6. If the above condition does not happen then we can say k is primitive root of n

	7. If n is prime it must have one or more primitive root

	8. If n is not prime then it is not guarantee that there is a primitive root of n

	9. If a number n have primitive root (n may prime or not)

	it must have Phi(Phi(n)) number of distinct root

	10.Such as number of primitive root of n = Phi(Phi(n))

	11.If a number have primitive root
	then multiplication of primitive root mod n = 1, (exception n = 3)

	12.Such that (multiplication of all primitive root of n) % n = 1, (exception n = 3)
*/

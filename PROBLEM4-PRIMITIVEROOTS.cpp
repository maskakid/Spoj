/*
    Author: Akid (CSE'11,CUET)

    problem-id: : PROBLEM4 - PRIMITIVEROOTS
    problem-link: http://www.spoj.com/problems/PROBLEM4/
    problem-type: math,implementation
    Resources   : http://goo.gl/6tM87H
                  https://en.wikipedia.org/wiki/Primitive_root_modulo_n
*/

#include<bits/stdc++.h>
#define _max 100010
#define LL long long int
using namespace std;

int A[_max];
vector<int>v;
void sieve()
{
    for(int i=4; i<_max; i+=2)    A[i]=1;
    for(int i=3; i<=sqrt(_max); i+=2)
        if(A[i]==0)
            for(int j=2*i; j<_max; j+=i)A[j]=1;
    for(int i=2;i<_max;i++)
    if(A[i]==0) v.push_back(i);
}

int main()
{
    sieve();

    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        if(A[n]==1) printf("%d:NOTPRIME\n",cas++);
        else if(A[n]==0 and n==3) printf("%d:2\n",cas++);
        else if(A[n]==0 and n>3) printf("%d:1\n",cas++);
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


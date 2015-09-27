/*
    Author: Akid (CSE'11,CUET)

    Relation: 3*(n*(n+1)/2)
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        printf("Case #%d: %d\n",cas++,3*((n*(n+1))/2));
    }
    return 0;
}

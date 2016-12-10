#include <bits/stdc++.h>
using namespace std;
long long nzero(long long n)
{
    long long c= 0;
    for (long long i=5; n/i>=1; i *= 5)
          c += n/i;
    return c;
}
int main()
{
    int a, b;
    cin>>a>>b;
    long long l = 1, h = 9223372036854775807;
    while(l<=h)
    {
        long long mid = (l+h)/2;
        if (nzero(mid) < a)
        {
            l = mid+1;
        }
        else h = mid-1;
    }
    long long l1 = l, h1 = 9223372036854775807;
    while(l1<=h1)
    {
        long long mid = (l1+h1)/2;
        if (nzero(mid) <= b)
        {
            l1 = mid+1;
        }
        else h1 = mid-1;
    }
    long long ans = l1 - l;
    cout<<ans<<"\n";
    return 0;
}

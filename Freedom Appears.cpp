#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll xk, yk, zk;
int N;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
set < pair <int, pair <int,int> > > ss;
int main()
{
    cin>>xk>>yk>>zk;
    cin>>N;
    ll xx, yy, zz, gg;
    for (int i = 0 ; i < N; i++)
    {
        cin>>xx>>yy>>zz;
        xx = xx - xk; yy = yy - yk; zz = zz - zk;
        gg = abs(gcd(xx, gcd(yy,zz)));
        ss.insert(make_pair(xx/gg, make_pair(yy/gg, zz/gg)));
    }
    cout<<ss.size()<<"\n";
}

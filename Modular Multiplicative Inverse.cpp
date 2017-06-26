#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
//Extended Euclid
//if (d%c != 0) no solution
//x = x0 + (b/d)n, y = y0 - (a/d)n
ll x, y, d;
ll N, M;
void extendedeuclid(ll a, ll b, ll &x, ll &y, ll &d)
{
    if (b==0) {x = 1; y = 0; d = a; return;}
    extendedeuclid(b,a%b, x, y, d);
    ll x1 = y;
    ll y1 = x - (a/b)*y;
    x = x1;
    y = y1;
}
int main() {
    cin>>N>>M;
    extendedeuclid(M, N, x, y, d);
    cout<<(y + M) % M<<"\n";
}

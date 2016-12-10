#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
const int MAXN = 200010*4;
typedef long long ll;
ll node[MAXN];
ll lazy[MAXN];
ll M, N, Q;
ll A[MAXN];
ll pow (ll n, ll k)
{
    if (k == 0)
        return 1;
    if (k == 1)
        return n;
    if (k % 2 == 0)
        return pow(n*n%M, k/2)%M;
    return n*pow(n*n%M, k/2)%M;
}
void buildtree(int stidx, int L, int R)
{
    if (L==R)
    {
        node[stidx] = pow(A[L], M);
        return;
    }
    int le = 2 * stidx, ri = le + 1, mid = (L + R) / 2;
    buildtree(le, L, mid);
    buildtree(ri, mid+1, R);
    ll p1 = node[le], p2 = node[ri];
    node[stidx] = (p1 + p2) % M;
}
void rangeupdate(int stidx, int L, int R, int ql, int qr, ll val)
{
    if (lazy[stidx]!=0)
    {
        node[stidx] = (node[stidx] + (R-L+1) * lazy[stidx]) % M;
        if (L!=R)
        {
            lazy[stidx*2] += lazy[stidx];
            lazy[stidx*2+1] += lazy[stidx];
        }
        lazy[stidx] = 0;
    }
    if (L>R || L > qr || R < ql)
        return;
    if (L >= ql && R <= qr)
    {
        node[stidx] = (node[stidx] + (R-L + 1) * val)%M;
        if (L!=R)
        {
            lazy[stidx*2] += val;
            lazy[stidx*2+1] += val;
        }
        return;
    }
    int mid = (L+R)/2;
    rangeupdate(stidx*2,L,mid,ql,qr,val);
    rangeupdate(stidx*2+1,mid+1,R,ql,qr,val);
    node[stidx] = (node[stidx*2] + node[stidx*2+1])%M;
}
ll rangequery(int stidx, int L, int R, int ql, int qr)
{
    if (lazy[stidx]!=0)
    {
        node[stidx] = (node[stidx] + (R-L+1) * lazy[stidx]) % M;
        if (L!=R)
        {
            lazy[stidx*2] += lazy[stidx];
            lazy[stidx*2+1] += lazy[stidx];
        }
        lazy[stidx] = 0;
    }
    if (L>R || L > qr || R < ql)
        return 0;
    if (L >= ql && R <= qr)
        return (node[stidx])%M;
    int mid = (L+R)/2;
        return (rangequery(stidx*2,L,mid,ql,qr) + rangequery(stidx*2+1,mid+1,R,ql,qr)) % M;
}
int main()
{
    scanf("%lld%lld%lld", &M, &N, &Q);
    for (int i = 0 ; i < N; i++)
        scanf("%lld", &A[i]);
    buildtree(1,0,N-1);
    for (int i = 0 ; i < Q; i++)
    {
        ll arg, l, r, x;
        scanf("%lld%lld%lld", &arg, &l, &r);
        l--; r--;
        if (arg==1)
        {
            scanf("%lld", &x);
            rangeupdate(1,0,N-1,l,r,pow(x,M));
        }
        else
            printf("%lld\n", rangequery(1,0,N-1,l,r));
    }
}

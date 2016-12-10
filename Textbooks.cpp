#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
int N;
const int MAXN = 7*500000;
int node[MAXN];
int lazy[MAXN];
int ms[MAXN];
unordered_map <int, int> mx, xm, ym;
void rangeupdate(int stidx, int L, int R, int ql, int qr, int val)
{
    if (lazy[stidx]!=0) // need updating
    {
        //update current segment as everything is within range
        node[stidx] = lazy[stidx]; // if solving RMQ and alike don't multiply (R-L+1)
        //if it is not a leaf node, we need to update lazy value for the children
        if (L!=R)
        {
            lazy[stidx*2] = lazy[stidx];
            lazy[stidx*2+1] = lazy[stidx];
        }
        //finish updating for current idx
        lazy[stidx] = 0;
    }
    //out of range
    if (L>R || L > qr || R < ql)
        return;
    //Current segment is fully in update range. Use lazy propagation
    if (L >= ql && R <= qr)
    {
        node[stidx] = val;
        //if it is not a leaf node, we need to update lazy value for the children
        if (L!=R)
        {
            lazy[stidx*2] = val;
            lazy[stidx*2+1] = val;
        }
        return;
    }
    //if not, recur for children and use result to update
    int mid = (L+R)/2;
    rangeupdate(stidx*2,L,mid,ql,qr,val);
    rangeupdate(stidx*2+1,mid+1,R,ql,qr,val);
    node[stidx] = max(node[stidx*2],node[stidx*2+1]);
}
// use this when using lazy propagation
int rangequery(int stidx, int L, int R, int ql, int qr)
{
    if (lazy[stidx]!=0) // need updating
    {
        //update current segment as everything is within range
        node[stidx] = lazy[stidx]; // if solving RMQ and alike don't multiply (R-L+1)
        //if it is not a leaf node, we need to update lazy value for the children
        if (L!=R)
        {
            lazy[stidx*2] = lazy[stidx];
            lazy[stidx*2+1] = lazy[stidx];
        }
        //finish updating for current idx
        lazy[stidx] = 0;
    }
    //out of range
    if (L>R || L > qr || R < ql)
        return -1;
    //Complete in range
    if (L >= ql && R <= qr)
        return node[stidx];
    //else do it the old way
    int mid = (L+R)/2;
    return max(rangequery(stidx*2,L,mid,ql,qr) , rangequery(stidx*2+1,mid+1,R,ql,qr));
}
struct block
{
    int s, l, w;
} all[500010], cur;
vector <int> ycord;
set <int> xcord;
int xtot = 0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for (int i = 0; i < N; i++)
    {
        cin>>all[i].s>>all[i].l>>all[i].w;
        xcord.insert(all[i].s); xcord.insert(all[i].s+all[i].l);
    }
    for (int i : xcord)
    {
        mx[i] = xtot;
        xm[xtot++] = i;
    }
    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
        cur = all[i];
        int xl = mx[cur.s], xr = mx[cur.s + cur.l]-1;
        int mh = rangequery(1,0,xtot-1, xl, xr);
        ans = (ans - 1LL*cur.l*cur.w% MOD + MOD) % MOD;
        rangeupdate(1,0,xtot-1,xl,xr,mh+cur.w);
    }
    //cout<<ans<<endl;
    for (int i = 1; i < xtot; i++)
    {
        //cout<<"INDEX IS between "<<xm[i-1]<<" and "<<xm[i]<<endl;
        int mh = rangequery(1,0,xtot-1, i-1, i-1);
            ans = (ans + (1LL*mh * (xm[i]-xm[i-1]))%MOD) % MOD;
        //cout<<1LL*mh * (xm[i]-xm[i-1])<<endl;
    }
    cout<<ans%MOD<<"\n";
}

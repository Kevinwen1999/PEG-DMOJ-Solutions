#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int MAXN = 30010 * 4;
int node[MAXN];
int N, Q;
int A[MAXN];
int lazy[MAXN];
void buildtree(int stidx, int L, int R)
{
    if (L==R)
    {
        //assign value to node[stidx];
        node[stidx] = A[L];
        return;
    }
    int le = 2 * stidx, ri = le + 1, mid = (L + R) / 2;
    buildtree(le, L, mid);
    buildtree(ri, mid+1, R);
    int p1 = node[le], p2 = node[ri];
    //assign value to node[stidx];
    node[stidx] = min(p1,p2);
}
void rangeupdate(int stidx, int L, int R, int ql, int qr, int val)
{
    if (lazy[stidx]!=0) // need updating
    {
        //update current segment as everything is within range
        node[stidx] = max(0, node[stidx] + lazy[stidx]);
        //if it is not a leaf node, we need to update lazy value for the children
        if (L!=R)
        {
            lazy[stidx*2] += lazy[stidx];
            lazy[stidx*2+1] += lazy[stidx];
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
        node[stidx] = max(0, node[stidx] + val);
        //if it is not a leaf node, we need to update lazy value for the children
        if (L!=R)
        {
            lazy[stidx*2] += val;
            lazy[stidx*2+1] += val;
        }
        return;
    }
    //if not, recur for children and use result to update
    int mid = (L+R)/2;
    rangeupdate(stidx*2,L,mid,ql,qr,val);
    rangeupdate(stidx*2+1,mid+1,R,ql,qr,val);
    node[stidx] = min (node[stidx*2], node[stidx*2+1]);
}
// use this when using lazy propagation
int rangequery(int stidx, int L, int R, int ql, int qr)
{
    if (lazy[stidx]!=0) // need updating
    {
        //update current segment as everything is within range
        node[stidx] = max(0, node[stidx] + lazy[stidx]);
        //if it is not a leaf node, we need to update lazy value for the children
        if (L!=R)
        {
            lazy[stidx*2] += lazy[stidx];
            lazy[stidx*2+1] += lazy[stidx];
        }
        //finish updating for current idx
        lazy[stidx] = 0;
    }
    //out of range
    if (L>R || L > qr || R < ql)
        return INF;
    //Complete in range
    if (L >= ql && R <= qr)
        return node[stidx];
    //else do it the old way
    int mid = (L+R)/2;
    return min(rangequery(stidx*2,L,mid,ql,qr),rangequery(stidx*2+1,mid+1,R,ql,qr));
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>Q;
    for (int i = 0 ; i < N; i++)
        cin>>A[i];
    buildtree(1,0,N-1);
    for (int i = 0, v, a, b; i < Q; i++)
    {
        cin>>a>>b>>v;
        a--; b--;
        rangeupdate(1,0,N-1,a,b,-v);
        cout<<rangequery(1,0,N-1,a,b)<<" "<<rangequery(1,0,N-1,0,N-1)<<"\n";
    }
}

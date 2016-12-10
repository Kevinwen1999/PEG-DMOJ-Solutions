#include <bits/stdc++.h>
#define MAXN 4*1050000
using namespace std;
int N, M;
struct person
{
    int ma, va;
};
person node[MAXN];
int all[MAXN];
int cnt[MAXN];
void buildtree(int stidx, int L, int R)
{
    if (L==R)
    {
        node[stidx].ma = all[L];
        node[stidx].va = L;
        return;
    }
    int mid = (L+R)/2;
    buildtree(stidx*2,L,mid);
    buildtree(stidx*2+1,mid+1,R);
    if (node[stidx*2].ma > node[stidx*2+1].ma)
    {
        node[stidx].ma = node[stidx*2].ma;
        node[stidx].va = node[stidx*2].va;
        cnt[node[stidx].va]++;
    }
    else
    {
        node[stidx].ma = node[stidx*2+1].ma;
        node[stidx].va = node[stidx*2+1].va;
        cnt[node[stidx].va]++;
    }
}
void update(int stidx, int L, int R, int idx, int val)
{
    if (L==R)
    {
        node[stidx].ma = val;
        cnt[node[stidx].va]=0;
        return;
    }
    cnt[node[stidx].va]--;
    int mid = (L+R) / 2;
    if (idx<=mid)
        update(stidx*2, L, mid, idx, val);
    else
        update(stidx*2+1, mid+1, R, idx, val);
    if (node[stidx*2].ma > node[stidx*2+1].ma)
    {
        node[stidx].ma = node[stidx*2].ma;
        node[stidx].va = node[stidx*2].va;
        cnt[node[stidx].va]++;
    }
    else
    {
        node[stidx].ma = node[stidx*2+1].ma;
        node[stidx].va = node[stidx*2+1].va;
        cnt[node[stidx].va]++;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    N = pow(2,N);
    for (int i = 0; i < N; i++)
    {
        cin>>all[i];
    }
    buildtree(1,0,N-1);
    for (int i= 0; i < M; i++)
    {
        char op; cin>>op;
        if (op=='R')
        {
            int id, v;
            cin>>id>>v; id--;
            update(1,0,N-1,id,v);
        }
        else if (op=='W')
        {
            cout<<node[1].va + 1<<"\n";
        }
        else
        {
            int id; cin>>id; id--;
            cout<<cnt[id]<<"\n";
        }
    }
}

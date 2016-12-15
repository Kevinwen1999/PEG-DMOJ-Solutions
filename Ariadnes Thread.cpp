#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;
vector <int> adj[MAXN];
int N, Q;
long long idx = 0;
long long H[MAXN*2], E[MAXN*4], l[MAXN*4], node[MAXN*6],depth[MAXN*2];
set <long long> occ[MAXN];
void buildtree(int stidx, int L, int R)
{
    if (L==R)
    {
        node[stidx] = L;//assign value to node[stidx];
        return;
    }
    buildtree(2*stidx, L, (L+R)/2);
    buildtree(2*stidx + 1, (L+R)/2 + 1, R);
    node[stidx] = (l[node[2*stidx]] < l[node[2*stidx+1]])? node[2*stidx]: node[2*stidx+1];//assign value to node[stidx];
}
//call query(1,0,N-1,i,j);
long long query(int stidx, int L, int R, int i, int j) // i and j are the given range
{
    if (i > R || j < L) return -1; //out of range
    if (L >= i && R <= j) return node[stidx];
    long long p1 = query(2*stidx, L, (L+R)/2, i,j);
    long long p2 = query(2*stidx + 1, (L+R)/2 + 1, R, i,j);
    if (p1==-1) return p2;
    if (p2==-1) return p1;
    return (l[p1] < l[p2])? p1 : p2;//base on  the calculation, same as in buildtree;
}
void dfs(int cur, int dep, int pa)
{
    occ[cur].insert(idx);
    depth[cur] = dep;
    H[cur] = min(idx, H[cur]);
    E[idx] = cur;
    l[idx++] = dep;
    for (auto v : adj[cur])
    {
        if (v==pa) continue;
        dfs(v, dep+1, cur);
        occ[cur].insert(idx);
        E[idx] = cur;
        l[idx++] = dep;
    }
}
void init()
{
    memset(H,0x3f,sizeof H);
    memset(l,0x3f,sizeof l);
    dfs(0,0,-1);
    buildtree(1,0,idx-1);
}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for (int i = 0, a, b; i < N; i++)
    {
        cin>>a;
        for (int j = 0; j < a; j++)
        {
            cin>>b;
            adj[i].push_back(--b);
        }
    }
    init();
    cin>>Q;
    long long lca, fa, fb, ans, sum;
    set<long long>::iterator it;
    for (int i = 0, a, b; i < Q; i++)
    {
        cin>>a>>b; a--, b--;
        fa = H[a], fb = H[b];
        if (fa==fb)
        {
            cout<<"0\n";
            continue;
        }
        if (fa > fb) swap(fa,fb);
        lca = E[query(1,0,idx-1,fa,fb)];
        if (H[a] < H[b])
        {
            ans = H[b]-H[lca]-(depth[a]-depth[lca]);
            cout<<ans<<"\n";
        }
        else
        {
            it = occ[lca].lower_bound(H[a]);
            if (*it==H[a]) sum = 0;
            else
            {
                sum = *it; it--; sum -= *it;
            }
            ans = H[b]-H[lca] + sum -(depth[a]-depth[lca]);
            cout<<ans<<"\n";
        }
    }
}

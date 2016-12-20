#include <bits/stdc++.h>
#define MAXN 300010
using namespace std;
int N;
vector <int> adj[MAXN];
int pa[MAXN];
int p[MAXN], rnk[MAXN];
int same[MAXN];
struct query
{
    char op;
    int v, w, ans;
}cq;
vector <query> all;
int node[8*MAXN], l[2*MAXN], E[2*MAXN], H[MAXN], depth[MAXN], idx;
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
    depth[cur] = dep;
    H[cur] = idx; // position of current node in E array
    E[idx] = cur; // sequence of visiting
    l[idx++] = dep; // depth of each node visit
    for (int i = 0; i < adj[cur].size(); i++)
    {
        int v = adj[cur][i];
        if (v==pa) continue;
        dfs(v, dep+1, cur);
        E[idx] = cur;
        l[idx++] = dep;
    }
}
int main()
{
    cin>>N;
    memset(same,-1,sizeof same);
    same[0] = 0;
    pa[0] = 0;
    for (int i = 1; i <=N; i++)
    {
        cin>>cq.op>>cq.v;
        if (cq.op=='a')
        {
            adj[same[cq.v]].push_back(i);
            pa[i] = same[cq.v];
        }
        else if (cq.op=='b')
        {
            cq.ans = same[cq.v];
            same[i] = pa[cq.ans];
        }
        else
        {
            cin>>cq.w;
            same[i] = same[cq.v];
            cq.w = same[cq.w];
        }
        all.push_back(cq);
        if (same[i]==-1) same[i] = i;
    }
    dfs(0,0,-1);
    buildtree(1,0,idx-1);
    for (auto i : all)
    {
        if (i.op=='b')
            cout<<i.ans<<"\n";
        else if (i.op=='c')
        {
            int a = same[i.v], b = same[i.w];
            int fa = H[a], fb = H[b];
            if (fa > fb) swap(fa,fb);
            int lca = E[query(1,0,idx-1,fa,fb)];
            cout<<depth[lca]<<"\n";
        }
    }
    //for (int i = 0; i <= N; i++)
        //cout<<same[i]<<" ";
}

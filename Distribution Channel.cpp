#include <bits/stdc++.h>

#define MAXN 50001
#define INF 0x3f3f3f3f
using namespace std;
vector < pair <int, pair <int,int> > > EdgeList, rem;
vector < pair <int,int> > adj[50010];
int node[6*MAXN], l[2*MAXN], euler[2*MAXN], H[MAXN], idx;
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
int query(int stidx, int L, int R, int i, int j) // i and j are the given range
{
    if (i > R || j < L) return -1; //out of range
    if (L >= i && R <= j) return node[stidx];
    long long p1 = query(2*stidx, L, (L+R)/2, i,j);
    long long p2 = query(2*stidx + 1, (L+R)/2 + 1, R, i,j);
    if (p1==-1) return p2;
    if (p2==-1) return p1;
    return (l[p1] < l[p2])? p1 : p2;//base on  the calculation, same as in buildtree;
}
void dfs(int cur, int dep, int p)
{
    H[cur] = idx; // position of current node in E array
    euler[idx] = cur; // sequence of visiting
    l[idx++] = dep; // depth of each node visit
    for (int i = 0; i < adj[cur].size(); i++)
    {
        int v = adj[cur][i].first;
        if (v==p) continue;
        dfs(v, dep+1, cur);
        euler[idx] = cur;
        l[idx++] = dep;
    }
}
//---------------------------------------------------------------------------------------------------------------
int sz[MAXN], pa[MAXN], depth[MAXN];
void dfs1(int cur, int pre, int d)
{
    sz[cur] = 1; pa[cur] = pre; depth[cur] = d;
    for (auto i : adj[cur])
    {
        if (i.first==pre) continue;
        dfs1(i.first, cur, d+1);
        sz[cur] += sz[i.first];
    }
}
int nedge, nchain, chainid[MAXN], chaintop[MAXN], segpos[MAXN];
int base[MAXN];
void hld (int cur, int weight)
{
    if (chaintop[nchain]==-1) // if starting a new heavy edge set new chain top as current node
        chaintop[nchain] = cur;
    chainid[cur] = nchain;
    segpos[cur] = nedge;
    base[nedge++] = weight;
    int heavychild = -1, heavyweight;
    for (auto i : adj[cur])
    {
        if (i.first==pa[cur]) continue;
        if (heavychild==-1 || sz[i.first] > sz[heavychild])
        {
            heavychild = i.first; heavyweight = i.second;
        }
    }
    // if heavy child is found, extend heavy chain
    if (heavychild!=-1)
        hld(heavychild, heavyweight);
    // for all other child start a new heavy chain
    for (auto i : adj[cur])
    {
        if (i.first==pa[cur]) continue;
        if (i.first==heavychild) continue;
        nchain++;
        hld(i.first, i.second);
    }
}
int segtree[6*MAXN];
int buildST(int L, int R, int ti)
{
    if (L==R)
    {
        return segtree[ti] = base[L];
    }
    return segtree[ti] = max(buildST(L, (L+R)/2, ti<<1), buildST((L+R)/2+1, R, ti<<1|1));
}
int RMQ(int L, int R, int le, int re, int ti)
{
    if (L>=le && R<=re)
        return segtree[ti];
    if (le>R || re<L)
        return -1;
    return max(RMQ(L, (L+R)/2, le, re, ti<<1), RMQ((L+R)/2+1, R, le, re, ti<<1|1));
}
int maxedge(int u, int v)
{
    int chainu, chainv = chainid[v], ans = 0;
    while (true)
    {
        //cout<<u<<"\n";
        chainu = chainid[u];
        if (chainu==chainv) // two node on same chain
        {
            if (u!=v)
                ans = max(ans, RMQ(0, nedge-1, segpos[v]+1, segpos[u], 1));
            break;
        }
        else
        {
            ans = max(ans, RMQ(0,nedge-1,segpos[chaintop[chainu]], segpos[u],1));
            u = pa[chaintop[chainu]];
        }
    }
    return ans;
}
//---------------------------------------------------------------------------------------------------------------
class UnionFind
{
    private:
        vector < int > p;
        vector <int> rankx;
    public:
        UnionFind(int N) { rankx.assign(N+1, 0); p.assign(N+1, 0); for (int i = 0; i < N+1; i++) p[i] = i; }
        void init(int N) { rankx.assign(N+1, 0); p.assign(N+1, 0); for (int i = 0; i < N+1; i++) p[i] = i; }
        int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
        bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
        void unionSet(int i, int j)
        {
            if (!isSameSet(i,j))
            {
                int x = findSet(i), y = findSet(j);
                if (rankx[x] > rankx[y])
                    p[y] = x;
                else
                {
                    p[x] = y;
                    if (rankx[x] == rankx[y])
                        rankx[y]++;
                }
            }
        }
};
int main()
{
    int E, V;
    scanf("%d%d",&V,&E);
    long long mst_cost = 0;
    for (int i = 0 ; i < E ; i++)
    {
        int u,v,w;
        scanf("%d %d %d", &u,&v,&w);
        EdgeList.push_back(make_pair(w,make_pair(u,v)));
    }
    vector < pair <int, pair <int,int> > > flags;
    sort (EdgeList.begin(),EdgeList.end());
    UnionFind UF(V);
    pair <int, pair <int, int > > frontt;
    //Kruskal
    for (int i = 0 ; i < E; i++)
    {
        frontt = EdgeList[i];
        if (!UF.isSameSet(frontt.second.first, frontt.second.second))
        {
            //cout<<frontt.second.first<<" "<<frontt.second.second<<"\n";
            mst_cost+=frontt.first;
            UF.unionSet(frontt.second.first, frontt.second.second);
            adj[frontt.second.first].push_back({frontt.second.second, frontt.first});
            adj[frontt.second.second].push_back({frontt.second.first, frontt.first});
        }
        else
        {
            rem.push_back(frontt);
        }
    }
    //LCA
    dfs(1,0,-1);
    buildtree(1,0,idx-1);
    long long sb = INF;
    //HLD
    dfs1(1,-2,0);
    memset(chaintop,-1,sizeof chaintop);
    hld(1,-1);
    buildST(0,nedge-1, 1);
    for (int i = 0; i < rem.size(); i++)
    {
        frontt = rem[i];
        //cout<<frontt.second.first<<" "<<frontt.second.second<<"\n";
        int v1 = frontt.second.first, v2 = frontt.second.second;
        if (H[v1] > H[v2]) swap(v1,v2);
        int c = query(1,0,idx-1, H[v1], H[v2]);
        int lca = euler[c];
        //cout<<v1<<" "<<lca<<"wew\n";
        int m1 = maxedge(v1, lca), m2 = maxedge(v2, lca);
        int m3 = max(m1, m2);
        if (frontt.first-m3>0)
            sb = min(sb, mst_cost-m3+frontt.first);
    }
    if (sb==INF||V-1>E) cout<<-1;
    else cout<<sb;
}

#include <bits/stdc++.h>
using namespace std;

int N, S;
vector <int> adj[5001];
bool visited[5001];
bool v[5001];
int parent[5001];
struct node
{
    int id, d;
    node(int a, int b)
    {
        id = a; d = b;
    }
};
bool cmp (const node &a, const node &b)
{
    return a.d > b.d;
}
vector <node> nodes;
void dfsr(int cur, int dd)
{
    nodes[cur].d = dd++;
    for (int i = 0, next; i < adj[cur].size(); i++)
    {
        next = adj[cur][i];
        if (next!=parent[cur])
        {
            parent[next] = cur;
            dfsr(next, dd);
        }
    }
}
void visit(int cur, int s)
{
    if (s==-1) return;
    visited[cur] = true;
    v[cur] = true;
    for (int i = 0, next ; i < adj[cur].size(); i++)
    {
        next = adj[cur][i];
        if (!v[next])//if (next != parent[cur]) does not work because you can go up to the parents
            visit(next, s-1);
    }
}
int fur(int cur, int s)
{
    if (s == 0)
        return cur;
    else
        return fur(parent[cur], s-1);
}
int sneed(int s)
{
    memset(visited, 0, sizeof visited);
    int cnt = 0, f;
    for (int i = 0; i < N; i++)
    {
        if (!visited[nodes[i].id])
        {
            memset(v,0,sizeof v);
            f = fur(nodes[i].id, s);
            visit(f, s);
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    cin>>N>>S;
    for (int i = 0 ; i < N; i++)
        nodes.push_back(node(i,0));
    for (int i = 0, a, b; i < N-1; i++)
    {
        cin>>a>>b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfsr(0, 1);
    sort(nodes.begin(), nodes.end(), cmp);
    int l = 0, r = 5000, mid;
    while (l <= r)
    {
        mid = l + (r-l) / 2;
        if (sneed(mid) <= S)
        {
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout<<l<<"\n";
}

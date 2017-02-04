#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;
int c[MAXN];
vector <int> adj[MAXN];
vector <pair <int,int> > orii;
int dfs(int cur, int pa, int color)
{
    c[cur] = color;
    for (int i : adj[cur])
    {
        if (i!=pa)
            dfs (i, cur, !color);
    }
}
int N;
int main()
{
    cin>>N;
    for (int i = 0; i < N-1; i++)
    {
        int a, b; cin>>a>>b;
        orii.push_back({a,b});
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,-1,0);
    for (auto i : orii)
    {
        cout<<c[i.first]<<"\n";
    }
}

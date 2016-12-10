#include <bits/stdc++.h>
using namespace std ;
int N,a,b;
int sum, l, r;
vector <int> adj[400001];
long long level[400001], nlevel[400001], diameter, ndiameter;
bool visited[400001];
set <int> S;
void dfs(int cur)
{
    visited[cur] = true;
    level[cur] = 0; nlevel[cur] = 1;
    for (int i = 0 ; i < (int)adj[cur].size(); i++)
    {
        int next = adj[cur][i];
        if (visited[next]) continue;
        dfs(next);
        if (level[cur]+level[next] + 1 > diameter)
        {
            diameter = level[cur]+level[next] + 1;
            ndiameter = nlevel[cur] * nlevel[next];
        }
        else if (level[cur]+level[next] + 1 == diameter)
        {
            ndiameter += nlevel[cur] * nlevel[next];
        }
        if (level[cur] < level[next] + 1)
        {
            level[cur] = level[next] + 1;
            nlevel[cur] = nlevel[next];
        }
        else if (level[cur] == level[next] + 1)
        {
            nlevel[cur] += nlevel[next];
        }
    }
}
int main()
{
    scanf("%d", &N);
    for (int i = 0 ;i < N-1; i++)
    {
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    printf("%lld %lld", diameter+1, ndiameter);
}

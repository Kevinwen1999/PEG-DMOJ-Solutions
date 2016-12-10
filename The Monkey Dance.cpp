#include <bits/stdc++.h>
using namespace std;
// GCD and LCM
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }
int N;
vector <int> adj[110];
bool visited[110];
int dfs(int cur, int dist)
{
    if (visited[cur]) return dist;
    visited[cur] = true;
    for (int i = 0; i < adj[cur].size(); i++)
    {
        return dfs(adj[cur][i], dist+1);
    }
}
int main()
{
    while (scanf("%d", &N) == 1 && N)
    {
        memset(visited, 0, sizeof visited);
        for (int i = 0; i < 110; i++)
            adj[i].clear();
        for (int i = 0; i < N; i++)
        {
            int a, b;
            cin>>a>>b;
            adj[a].push_back(b);
        }
        int l = 1;
        for (int i = 1; i <= N; i++)
        {
            if (!visited[i])
            {
                l = lcm(l, dfs(i,0));
            }
        }
        printf("%d\n", l);
    }
}

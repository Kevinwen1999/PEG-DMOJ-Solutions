#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 100001;
int dp[MAXN];
vector <int> biton[32];
vector <int> adj[MAXN];
bool visited[MAXN];
int N;
vector <int> topo;
void dfs(int cur)
{
    visited[cur] = true;
    for (int i = 0 ; i < adj[cur].size(); i++)
        if (!visited[adj[cur][i]])
            dfs(adj[cur][i]);
    topo.push_back(cur);
}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for (int i = 0; i < N; i++)
    {
        int cur;
        cin>>cur;
        for (int j = 0 ; j < 32; j++)
        {
            if ((cur & (1<<j)) > 0)
                biton[j].push_back(i);
        }
    }
    for (int i = 0; i < 32; i++)
        for (int j = 1 ; j < biton[i].size(); j++)
        {
            adj[biton[i][j-1]].push_back(biton[i][j]);
        }
    for (int i = 0 ; i < N; i++)
    {
        if (!visited[i])
            dfs(i);
    }
    for (int i = 0 ; i < topo.size(); i++)
    {
        int cur = topo[i];
        int maxx = 0;
        for (int j = 0 ; j < adj[cur].size(); j++)
            maxx = max(maxx, dp[adj[cur][j]]);
        dp[cur] = maxx + 1;
    }
    int ans = 0;
    for (int i = 0 ; i < N; i++)
        ans = max(ans, dp[i]);
    cout<<ans;
}


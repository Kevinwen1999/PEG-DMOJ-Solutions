#include <bits/stdc++.h>
using namespace std;
int N;
vector <int> adj[50005];
int sz[50005];
vector <int> ans;
int dfs_size(int cur, int par)
{
    sz[cur] = 1;
    for (int i = 0,nxt; i< adj[cur].size(); i++)
    {
        nxt = adj[cur][i];
        if (nxt==par) continue;
        sz[cur] +=dfs_size(nxt,cur);
    }
    return sz[cur];
}
void dfs(int cur, int par, int min, int max)
{
    ans.push_back(min);
    for (int i = 0,nxt ; i <adj[cur].size(); i++)
    {
        nxt = adj[cur][i];
        if (nxt==par) continue;
        dfs(nxt, cur, max-sz[nxt]+1, max);
        max-=sz[nxt];
    }
}
int main()
{
    cin>>N;
    for (int i = 0 ,k,nxt; i < N; i++)
    {
        cin>>k;
        for (int j = 0 ; j < k; j++)
        {
            cin>>nxt; nxt-=1;
            adj[i].push_back(nxt);
            adj[nxt].push_back(i);
        }
    }
    dfs_size(0,-1);
    dfs(0,-1,1,N);
    for (int i = 0 ; i < ans.size(); i++)
        cout<<ans[i]<<" ";
    cout<<"\n";
}

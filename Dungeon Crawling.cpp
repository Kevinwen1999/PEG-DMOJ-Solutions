#include <bits/stdc++.h>
#define MAXN 300010
#define MOD 1000000007
using namespace std;

int indegree[MAXN], outdegree[MAXN];
vector <int> adj[MAXN];

int N, M;
int ways[MAXN], dist[MAXN];
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for (int i = 0, a, b; i < M; i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        outdegree[a]++; indegree[b]++;
    }
    queue <int> buff;
    for (int i = 0; i < N; i++)
    {
        if (!indegree[i])
        {
            dist[i] = 1; ways[i] = 1;
            buff.push(i);
        }
    }
    while (!buff.empty())
    {
        int cur = buff.front();
        buff.pop();
        for (int i : adj[cur])
        {
            if (!dist[i])
            {
                dist[i] = dist[cur]+1;
                buff.push(i);
            }
            ways[i] += ways[cur];
            ways[i]%=MOD;
        }
    }
    vector <int> ans;
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        if (!outdegree[i])
        {
            sum += ways[i];
            sum%=MOD;
            ans.push_back(dist[i]);
        }
    }
    cout<<sum<<"\n";
    for (int i : ans)
        cout<<i<<" ";
}

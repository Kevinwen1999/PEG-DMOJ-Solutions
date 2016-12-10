#include <bits/stdc++.h>
#define MX 1000010
#define ll long long
using namespace std;
int N;
vector <pair <int,int> > adj[MX];
bool v[MX];
ll sum[MX], num[MX];
void dfs(int cur, int pa)
{
    sum[cur] = 0; num[cur] = 1;
    for (auto i : adj[cur])
    {
        if (i.first==pa) continue;
        if (!v[i.first]) dfs(i.first, cur);
        sum[cur] += abs(num[i.first] - (N-num[i.first])) * i.second + sum[i.first];
        num[cur] += num[i.first];
    }
}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for (int i = 0, a, b, c; i < N-1; i++)
    {
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    dfs(1,-1);
    cout<<sum[1]<<"\n";
}

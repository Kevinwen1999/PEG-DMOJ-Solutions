#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int N, M;
map <pair <int,int> , long long>m;
vector <pair <int,long long> > adj[100010];
bool in[100010], out[100010];
unsigned long long sum[100010], paths[100010];
bool v[100010];
vector <int> ts;
void dfs(int u)
{
    v[u] = true;
    for (auto i : adj[u])
    {
        if (!v[i.first])
            dfs(i.first);
    }
    ts.push_back(u);
}
int main()
{
    cin>>N>>M;
    for (int i = 0, a, b; i < M; i++)
    {
        cin>>a>>b;
        pair <int,int> c = {a,b};
        if (!m.count(c))
        {
            out[a]=1; in[b]=1;
            m[c] = 1;
        }
        else
        {
            m[c]++;
        }
    }
    for (auto i : m)
    {
        int a = i.first.first, b = i.first.second;
        long long c = i.second;
        adj[a].push_back({b,c});
    }
    long long ans = 0;
    for (int i = 1; i <= N; i++)
    {
        if (!v[i])
            dfs(i);
    }
    reverse(ts.begin(), ts.end());
    for (int i : ts)
    {
        if (!in[i])
        {
            sum[i] = 0; paths[i] = 1;
        }
        //if (paths[i] < 0) cout<<paths[i]<<" ";
        for (auto j : adj[i])
        {
            sum[j.first] = (sum[j.first]%MOD + ((sum[i]+paths[i])%MOD)*(j.second % MOD)) % MOD;
            paths[j.first] += 1LL*paths[i]*j.second%MOD;
            paths[j.first]%=MOD;
        }
        if (!out[i])
        {
            ans = (ans%MOD + sum[i]%MOD)%MOD;
        }
    }
    cout<<ans<<"\n";
}

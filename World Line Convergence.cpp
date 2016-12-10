#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
const int MAXN = 200010;
long long bit[MAXN];
vector <int> adj[MAXN];
map <int, int> order;
int N, root;
void update(int x, long long v)
{
    for (; x <= N; x+=(x&-x))
        bit[x]= (bit[x] + v) % MOD;
}
long long query(int x)
{
    long long sum = 0;
    for (; x > 0; x-=(x&-x))
        sum = (sum + bit[x]) % MOD;
    return sum;
}
void dfs(int cur, int par)
{
    long long notinsubt = query(order[cur]);
    for (int next : adj[cur])
    {
        if (next == par) continue;
        dfs(next, cur);
    }
    update(order[cur], query(order[cur]) + 1 - notinsubt);
}
int main()
{
    cin>>N;
    for (int i = 1 ; i <= N; i++)
    {
        int next; cin>>next;
        if (next == 0) root = i;
        else
        {
            adj[i].push_back(next);
            adj[next].push_back(i);
        }
    }
    for (int i = 1 ; i <= N; i++)
    {
        int cur; cin>>cur;
        order[cur] = i;
    }
    dfs(root, -1);
    long long ans;
    for (int i = 1; i <= N; i++)
    {
        ans = (query(order[i]) - query(order[i]-1)+ MOD) % MOD;
        cout<<ans<<" ";
    }
    return 0;
}

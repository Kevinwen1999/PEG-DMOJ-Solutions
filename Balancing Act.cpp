#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std ;
int N,a,b;
vector <int> adj[20010];
int curmin = 9999999,curind,balance;
inline int min(int a, int b) {return a<b?a:b;}
inline int max(int a, int b) {return a>b?a:b;}
int dp[20010], parent[20010];
void dfs(int node1, int node2)
{
    dp[node1] = 1;
    parent[node1] = node2;
    for (int i = 0 ; i < (int)adj[node1].size(); i++)
    {
        int v = adj[node1][i];
        if (v!=node2)
        {
            dfs(v,node1);
            dp[node1]+= dp[v];
        }
    }
}

void check(int node)
{
    balance = -1;
    for (int i = 0 ; i < (int) adj[node].size(); i++)
    {
        int v = adj[node][i];
        if (v!=parent[node])
            balance = max(balance,dp[v]);
    }
    balance = max(balance, N-dp[node]);
    if (balance < curmin)
    {
        curmin = balance;
        curind = node;
    }
}
int main()
{
    cin>>N;
    for (int i = 0 ;i < N-1; i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,-1);
    for (int i = 1; i <= N; i++)
        check(i);
    cout<<curind<<" "<<curmin<<endl;
}

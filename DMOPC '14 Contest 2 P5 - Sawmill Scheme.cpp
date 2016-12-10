#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
using namespace std;
int N, M, sz,nextx;
vector <int> adj[1000001];
double dp[1000001], cur,after;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for (int i = 0, a, b; i < M; i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
    }
    dp[1] = 1.0;
    for (int i = 1 ; i <= N; i++)
    {
        cur = dp[i];
        sz = (int)adj[i].size();
        if (sz==0)
        {
            continue;
        }
        after = cur / sz;
        for (int j = 0 ; j < sz; j++)
        {
            nextx = adj[i][j];
            dp[nextx]+=after;
        }
    }
    cout<<fixed;
    cout<<setprecision(9);
    for (int i = 1 ; i <= N; i++)
    {
        sz = (int)adj[i].size();
        if (sz==0)
        {
            cout<<dp[i]<<"\n";
        }
    }

}

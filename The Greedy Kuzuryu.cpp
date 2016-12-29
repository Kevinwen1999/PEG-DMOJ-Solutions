#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
inline int min(int a, int b, int c) {return min(a,min(b,c));}
vector < pair <int,int> > adj[310];
bool visited[310];
// dp[i][j][k] : i rep the current node id (root of current sub tree),
// j rep how many node of the largest head is inside this sub tree,
// k rep whether the root node is of the largest head or not (1 rep largest head, 0 rep other heads)
// the reason why we only care about the largest head is because tree is bipartite
// therefore only the largest head can alter the result
int dp[310][310][2];
int tsize[310];
int N, M, K;
int dfs(int cur)
{
    visited[cur] = true;
    tsize[cur] = 1;
    for (auto i : adj[cur])
    {
        if (!visited[i.first])
        {
            tsize[cur] += dfs(i.first);
        }
    }
    return tsize[cur];
}
void recur(int cur)
{
    visited[cur] = true;
    dp[cur][1][1] = dp[cur][0][0] = 0;
    int tmp[310][2];
    for (pair <int,int> i : adj[cur])
    {
        if (!visited[i.first])
            recur(i.first);
        memcpy(tmp, dp[cur], sizeof tmp);
        memset(dp[cur],0x3f,sizeof dp[cur]);
        for (int j = K; j >= 0; j--)
        {
            for (int l = j-1; l >= 0; l--)
            {
                // current root node is eaten by largest head
                dp[cur][j][1] = min(dp[cur][j][1], tmp[j-l][1]+dp[i.first][l][1]+i.second, tmp[j-l][1]+dp[i.first][l][0]);
            }
            for (int l = j; l >= 0; l--)
            {
                // current root node is not eaten by largest head
                // notice that we only add edge weight when M==2, because tree is bipartite graph
                dp[cur][j][0] = min(dp[cur][j][0], tmp[j-l][0]+dp[i.first][l][0]+(int)(M==2)*i.second, tmp[j-l][0]+dp[i.first][l][1]);
            }
        }
    }
}
int main()
{
    cin>>N>>M>>K;
    for (int i = 0, a, b, c; i < N-1; i++)
    {
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    if (N-K<M-1)
    {
        cout<<"-1\n"; return 0;
    }
    //dfs(1);
    //memset(visited,0,sizeof visited);
    memset(dp,0x3f,sizeof dp);
    recur(1);
    cout<<dp[1][K][1]<<"\n";
}

#include <bits/stdc++.h>
using namespace std;
int N, M;
const int MAXN = 100010;
int med[MAXN];
int pen[MAXN];
long long dp[MAXN][2];
long long maxmed(int cur, int choice)
{
    if (dp[cur][choice]!=-1) return dp[cur][choice];
    if (cur>N) return 0;
    if (choice)
    {
        return dp[cur][choice] = max(maxmed(cur+1,0) + med[cur] ,maxmed(cur+1,1));
    }
    else
    {
        return dp[cur][choice] = max(maxmed(cur+1,0) + med[cur] ,maxmed(cur+1,1) + pen[cur-1]) - pen[cur-1];
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for (int i = 1; i <= N; i++)
        cin>>med[i];
    cin>>M;
    for (int i = 0, a, w; i < M; i++)
    {
        cin>>a>>w;
        pen[a] = w;
    }
    memset(dp,-1,sizeof dp);
    cout<<maxmed(1,0);
}

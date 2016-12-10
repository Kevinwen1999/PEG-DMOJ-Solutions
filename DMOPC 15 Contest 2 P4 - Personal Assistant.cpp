#include <bits/stdc++.h>
using namespace std;
long long R[100010],L[100010],H[100010],N;
long long dp[100010];
long long dfs(int cur)
{
    if (cur >= N) return 0;
    if (dp[cur]!=-1) return dp[cur];
    int next; bool hasleft = false;
    int l = cur + 1, h = N -1, mid;
    while (l <= h)
    {
        mid = l + (h-l) / 2;
        if (R[mid] < R[cur] + L[cur])
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    next = l;
    if (next == N) return dp[cur] = max(dfs(cur+1), H[cur]);
    else
    {
        return dp[cur] = max(dp[cur], max(dfs(cur+1), dfs(next) + H[cur]));
    }
}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for (int i = 0 ; i < N; i++)
    {
        cin>>R[i]>>L[i]>>H[i];
    }
    memset(dp,-1,sizeof dp);
    cout<<dfs(0);
}

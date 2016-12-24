#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int N;
int w[20], t[20];
int dp[1<<15][17][17];
int recur (int cur, int mask, int last_waiter, int last_time)
{
    // cur is not needed in dp state because mask, last_waiter and last_time are enough for defining the state
    if (dp[mask][last_waiter][last_time]!=-1) return dp[mask][last_waiter][last_time];
    if (mask==(1<<N)-1) return 0;
    int ans = INF;
    for (int i = 0; i < N; i++)
    {
        if (!(mask & (1<<i)))
        {
            if (w[cur]+t[i+1] >= w[last_waiter] + t[last_time])
            {
                ans = min(ans, max(w[cur]+t[i+1]-t[last_time]-w[last_waiter], recur(cur+1, mask | (1<<i), cur, i+1)));
            }
            else
            {
                ans = min(ans, max(t[last_time]-w[last_waiter], recur(cur+1, mask | (1<<i), last_waiter, last_time)));
            }
        }
    }
    return dp[mask][last_waiter][last_time] = ans;

}
int main()
{
    cin>>N;
    for (int i = 1; i <=N; i++)
        cin>>w[i];
    for (int i = 1; i <=N; i++)
        cin>>t[i];
    memset(dp,-1,sizeof dp);
    cout<<recur(1,0,0,0)<<"\n";
}

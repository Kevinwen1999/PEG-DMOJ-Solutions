#include <bits/stdc++.h>
#define MAXN 101
#define INF 0x3f3f3f3f
using namespace std;
int N, D;
int sec[MAXN], pitchs[MAXN];
vector <vector <int> > hashs;
vector <int> cr;
int tot = 0;
void recur (int d)
{
    if (d==D)
    {
        for (int i = 0; i < D-1; i++)
            if (cr[i+1] <= cr[i])
                return;
        tot++;
        hashs.push_back(cr);
        return;
    }
    for (int i = 1; i<= 12; i++)
    {
        cr.push_back(i);
        recur (d+1);
        cr.pop_back();
    }
}
double dp[101][20800];
double dfs(int cur, int st)
{
    bool OK = false;
    for (int i = 0; i < D; i++)
    {
        if (hashs[st][i]==pitchs[cur])
            OK = true;
    }
    if (!OK) return -INF;
    if (cur==N-1)
        return INF;
    if (dp[cur][st]!=-1.0) return dp[cur][st];
    double ans = 0.0;
    for (int i = 0; i < tot; i++)
    {
        double cnt = 0;
        for (int j = 0; j < D; j++)
            if (hashs[st][j]!=hashs[i][j])
                cnt++;
        if (cnt==0.0)
        {
            ans = max(ans, dfs(cur+1,i));
        }
        else
        {
            ans = max(ans, min((sec[cur+1]-sec[cur])/cnt,dfs(cur+1, i)));
        }
    }
    return dp[cur][st] = ans;
}
int main()
{
    cin>>N>>D;
    for(int i = 0; i < N; i++)
    {
        cin>>sec[i]>>pitchs[i];
    }
    recur(0);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < tot; j++)
            dp[i][j] = -1;
    }
    double ans = 0.0;
    for (int i = 0; i < tot; i++)
    {
        ans = max(ans, dfs(0,i));
    }
    if (ans == INF)
    {
        cout<<"0.00";
    }
    else
    {
        cout<<fixed<<setprecision(2)<<ans;
    }
}

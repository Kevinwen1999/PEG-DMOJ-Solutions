#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
int adj[20][20];
int dp[1<<15];
pair <int,int> pa[1<<15];
vector <int> group;
int tot;
int N, M;
void printmask (int mask)
{
    for (int i = 0; i < N; i++)
    {
        if (mask & (1<<i))
            cout<<i+1<<" ";
    }
    cout<<"\n";
}
int recur(int mask)
{
    if (dp[mask]!=-1) return dp[mask];
    if (mask == (1<<N)-1) return 0;
    int ans = INF;
    for (int i : group)
    {
        if (mask & i) continue;
        if (ans > 1 + recur(mask|i))
        {
            //printmask(mask); cout<<"to\n";
            //printmask(i); cout<<"\n";
            ans = 1 + recur(mask|i);
            pa[mask] = {mask|i, i};
        }
    }
    return dp[mask] = ans;
}
void backtrack(int mask)
{
    //printmask(mask);
    //cout<<": \n";
    printmask(pa[mask].second);
    if (pa[mask].first != (1<<N)-1)backtrack(pa[mask].first);
}
int main()
{
    cin>>N>>M;
    for (int i = 0, a, b; i < M; i++)
    {
        cin>>a>>b;
        a--; b--;
        adj[a][b] = adj[b][a] = 1;
    }
    for (int i = 1; i < (1<<N); i++)
    {
        bool OK = true;
        for (int j = 0; j < N && OK; j++)
        {
            if (!(i&(1<<j))) continue;
            for (int k = j + 1; k < N && OK; k++)
            {
                if (!(i&(1<<k))) continue;
                if (adj[j][k])
                {
                    OK = false;
                }
            }
        }
        if (OK)
        {
            //printmask(i);
            group.push_back(i);
        }
    }
    memset(dp,-1,sizeof dp);
    int ans = recur(0);
    cout<<ans<<"\n";
    backtrack(0);
}

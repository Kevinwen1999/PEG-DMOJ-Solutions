#include <bits/stdc++.h>
using namespace std;
int dp[51][1<<20];
bool use[51];
int grid[21][51];
int judgef[51];
int N, M;
int fin;
int A;
#define INF 0x3f3f3f3f
int recur(int idx, int mask)
{
    int &ans = dp[idx][mask];
    if (~ans) return ans;
    if (idx == M)
    {
        if (mask == fin)
            return ans = 0;
        else
            return ans = INF;
    }
    int choose = mask & judgef[idx];
    ans = min(recur(idx+1, choose)+1, recur(idx+1, mask));
    return ans;
}
void getans(int idx,int mask)
{
    if (idx==M) return;
    int choose = mask & judgef[idx];
    int next;
    if (dp[idx+1][choose] + 1==dp[idx][mask])
    {
        use[idx] = true;
        next = choose;
    }
    else
    {
        use[idx] = false;
        next = mask;
    }
    getans(idx+1, next);
}
int main()
{
    memset(dp, -1, sizeof dp);
    cin>>N>>M;
    fin = (1<<N)-1;
    for (int i = 0 ; i < N; i++)
    {
        string in;
        cin>>in;
        for (int j = 0; j < M; j++)
            grid[i][j] = (in[j]=='O');
    }
    for (int i = 0 ; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[j][i])
                judgef[i] |= (1<<j);
        }
        fin &= judgef[i];
    }
    memset(use,-1,sizeof use);
    A = (recur(0, (1<<N)-1) == 0) ? 1 : recur(0, (1<<N)-1);
    cout<<A<<"\n";
    if (recur(0, (1<<N)-1)==0) {cout<<"1"; return 0;}
    getans(0, (1<<N)-1);
    for (int i = 0 ; i < M; i++)
        if (use[i])
            cout<<i+1<<" ";
}

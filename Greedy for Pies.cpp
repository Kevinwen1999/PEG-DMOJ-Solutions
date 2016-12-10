#include <bits/stdc++.h>

using namespace std;

int N, M;
int piesn[3005];
vector <int> piesm;
long long dp[3005][2][105][105];
long long recur(int curN, int prev, int l, int r)
{
    if (dp[curN][prev][l][r]!=-1) return dp[curN][prev][l][r];
    long long &ans = dp[curN][prev][l][r];
    if (curN == N+1)
    {
        if (l > r)
        {
            return  ans = 0;
        }
        else if (prev)
        {
            ans = recur(curN, 0, l+1, r);
        }
        else
        {
            ans = recur(curN, 1, l, r-1) + piesm[r];
        }
        return ans;
    }
    else if (prev)
    {
        ans = recur(curN+1, 0, l, r);
        if (l <= r) ans = max(ans, recur(curN, 0, l+1, r));
    }
    else
    {
        ans = max(recur(curN+1, 1, l, r) + piesn[curN], recur(curN+1, 0, l, r));
        if (l <= r) ans = max(ans, recur(curN, 1, l, r-1) + piesm[r]);
    }
    return ans;
}
int main()
{
    cin>>N;
    for (int i = 1; i <= N; i++)
        cin>>piesn[i];
    cin>>M;
    piesm.push_back(-999999);
    for (int i = 1,in;i <= M; i++) // use one indexing to avoid special M=0 case causing trouble
    {
        cin>>in; piesm.push_back(in);
    }
    sort(piesm.begin(), piesm.end());
    memset(dp, -1, sizeof dp);
    cout<<recur(1,0,1,M)<<"\n";
}

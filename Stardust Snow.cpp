#include <bits/stdc++.h>
using namespace std;
int R, C, S, B, K, M;
int price[52][52], temp[52][52];
int dp[52][52][52][52];
int recur(int r, int c, int k, int b)
{
    if (k==K || r>R)
        return 0;
    if (dp[r][c][k][b]!=-1) return dp[r][c][k][b];
    int ans = 0;
    for (int i = max(1,c-M); i <= min(C,c+M); i++)
    {
        ans = max(ans, recur(r+1, i, k, b));
        if (price[r+1][i]!=-1 && b+temp[r+1][i] < B)
        {
            ans = max(ans, price[r+1][i] + recur(r+1, i, k+1, b+temp[r+1][i]));
        }
    }
    return dp[r][c][k][b] = ans;
}
int main()
{
    cin>>R>>C>>S>>B>>K>>M;
    memset(price, -1, sizeof price);
    for (int i = 1; i <= S; i++)
    {
        int r,c, t, v;
        cin>>t>>v>>c>>r;
        price[r][c] = v, temp[r][c] = t;
    }
    memset(dp,-1,sizeof dp);
    cout<<recur(0,1,0,0);
}

#include <iostream>
#include <cstring>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 16;
int N;
int H, W;
int parts[MAXN];
int cnt;
bool dp[1<<15][101];
bool visited[1<<15][101];
int msum[1<<15];
int counton(int mask)
{
    if (mask == 0) return 0;
    return counton(mask>>1) + (mask&1);
}
bool dfs(int mask, int shortest)
{
    if (visited[mask][shortest]) return dp[mask][shortest];
    bool &ans = dp[mask][shortest];
    visited[mask][shortest] = true;
    ans = 0;
    if (counton(mask) == 1) return ans = 1;
    if (msum[mask] % shortest != 0) return ans = 0;
    int longest = msum[mask] / shortest;
    for (int choice = (mask - 1) & mask; choice > 0; choice = (choice-1) & mask)
    {
        int other = (mask ^ choice);
        if (msum[choice] % shortest == 0 && dfs(choice, min(shortest, msum[choice] / shortest)) && dfs(other, min(shortest, msum[other] / shortest)))
            return ans = 1;
        if (msum[choice] % longest == 0 && dfs(choice, min(longest, msum[choice] / longest)) && dfs(other, min(longest, msum[other] / longest)))
            return ans = 1;
    }
    return ans = 0;
}
int main()
{
    while (~scanf("%d", &N) && N)
    {
        memset(visited, 0, sizeof visited);
        memset(msum, 0, sizeof msum);
        scanf("%d%d", &H, &W);
        for (int i = 0 ; i < N; i++)
            scanf("%d", &parts[i]);
        for (int i = 0 ; i < (1<<N); i++)
        {
            for (int j = 0 ; j < N; j++)
                if (i & (1<<j)) msum[i] += parts[j];
        }
        bool flag;
        if (msum[(1<<N)-1] != H*W) flag = false;
        else flag = dfs((1<<N)-1, min(H,W));
        printf("Case %d: %s\n", ++cnt, flag ? "Yes" : "No");
    }
}

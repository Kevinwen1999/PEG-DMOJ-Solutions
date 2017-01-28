#include <bits/stdc++.h>
using namespace std;
int Acard[20];
int dp[1<<20][2];
int dfs(int tot, int mask, int player)
{
    if (!tot) return 0;
    if (~dp[mask][player]) return dp[mask][player];
    int ans = 0, ans1, color, val;
    for (int i = 0; i < 20; i++)
    {
        if ((mask & (1<<i) )&&Acard[i]==player)
        {
            mask ^= (1<<i);
            ans1 = 10;
            color = i/5, val = i%5;
            bool hasSameColor = false;
            for (int j = 0; j < 20; j++)
            {
                if ((mask & (1<<j) )&&Acard[j]!=player&&(j/5)==color)
                {
                    hasSameColor = true;
                    if (j%5 > val)
                    {
                        ans1 = min(ans1, tot-1-dfs(tot-1,mask^(1<<j), 1-player));
                    }
                    else
                    {
                        ans1 = min(ans1, 1 + dfs(tot-1,mask^(1<<j), player));
                    }
                }
            }
            if (!hasSameColor)
            {
                ans1 = 10;
                for (int j = 0; j < 20; j++)
                {
                    if ((mask & (1<<j) )&&Acard[j]!=player)
                    {
                        ans1 = min(ans1, 1 + dfs(tot-1,mask^(1<<j), player));
                    }
                }
            }
            mask ^= (1<<i);
            ans = max(ans, ans1);
        }
    }
    return dp[mask][player] = ans;
 }
int main()
{
    string ori, tmp;
    while (true)
    {
        getline(cin,ori);
        if (ori == "* * * * * * * * * *") break;
        memset(dp,-1,sizeof dp);
        memset(Acard, 0, sizeof Acard);
        stringstream ss(ori);
        while(ss>>tmp)
        {
            int color = 0;
            if (tmp[0]=='Y')
                color = 5;
            else if (tmp[0]=='G')
                color = 10;
            else if (tmp[0]=='B')
                color = 15;
            color += (tmp[1]-'0')-1;
            Acard[color] = 1;
        }
        cout<<dfs(10,(1<<20)-1,1)<<"\n";
    }
}

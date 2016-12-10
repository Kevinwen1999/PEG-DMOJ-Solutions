#include <bits/stdc++.h>
#define UNVISITED -1
#define WIN 1
#define DIE 0
using namespace std;
int sum[7] = {4,4,4,4,4,4,4};
int ori[7];
int dp[7][7][7][7][7][7];
void r(int tot)
{
    bool win = false; // current player lose or win
    for (int i = 1; i <= 6; i++)
    {
        if (tot + i <= 31 && sum[i] > 0)
        {
            sum[i]--;

            if (dp[sum[1]][sum[2]][sum[3]][sum[4]][sum[5]][sum[6]] == UNVISITED) // next player
                r(tot+i);
            if (dp[sum[1]][sum[2]][sum[3]][sum[4]][sum[5]][sum[6]] == DIE)
            {
                win = true;
                sum[i]++;
                dp[sum[1]][sum[2]][sum[3]][sum[4]][sum[5]][sum[6]] = WIN;
            }
            else
                sum[i]++;
        }
    }
    if (!win)
        dp[sum[1]][sum[2]][sum[3]][sum[4]][sum[5]][sum[6]] = DIE;
}
int main()
{
    int T; cin>>T;
    while (T--)
    {
        for (int i = 1; i <= 6; i++)
        {
           sum[i] = ori[i] = 4;
        }
        memset(dp,-1,sizeof dp);
        string in;
        cin>>in;
        int ct = 0;
        for (char i : in)
        {
           int num = i - '0';
           sum[num]--;
           ori[num]--;
           ct += num;
        }
        r(ct);
        bool firstwin = dp[ori[1]][ori[2]][ori[3]][ori[4]][ori[5]][ori[6]];
        if (in.size() % 2)
            firstwin = 1 - firstwin;
        if (firstwin)
            cout<<"A\n";
        else
            cout<<"B\n";
    }
}

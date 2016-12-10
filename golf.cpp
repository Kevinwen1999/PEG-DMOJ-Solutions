#include <iostream>
#include <algorithm>
using namespace std;
inline int minx(int a, int b) { return (a < b) ? a : b; }
int coins[34];
int dp[34][5281];
int des;
int nclubs;
int INF = 9999999;
int main()
{
    for (int i = 0 ; i  < 34; i++)
    {
        coins[i] = INF;
    }
    coins[0] = 0;
    cin>>des>>nclubs;
    for (int i = 1 ; i <= nclubs; i++)
    {
        cin>>coins[i];
    }
    sort(begin(coins),end(coins));
    for (int i = 0 ; i <= nclubs; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0 ; i <= des; i++)
    {
        dp[0][i] = INF;
    }
    dp[0][0] = 0;
    for (int i = 1; i <= nclubs; i++)
    {
        for (int j = 0 ; j <= des; j++)
        {
            if (coins[i]>j)
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = min( dp[i-1][j] , 1 + dp[i][j-coins[i]] );
            }
        }
    }
    if (dp[nclubs][des] == INF)
    {
        cout<<"Roberta acknowledges defeat."<<endl;
    }
    else
    cout<<"Roberta wins in "<<dp[nclubs][des]<<" strokes."<<endl;
    return 0;
}

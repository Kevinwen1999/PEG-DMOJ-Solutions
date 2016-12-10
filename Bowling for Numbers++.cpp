#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
inline long long max(long long a, long long  b) { return (a > b) ? a : b; }
long long  dp[550][10100];
long long  sum[10100];
int turns;
int width;
int npins;
int nballs;
long long  sums,temp;
int main()
{
    cin>>turns;
    for (int i = 0 ; i < turns; i++)
    {
        cin>>npins>>nballs>>width;
        memset(sum,0,sizeof sum);
        memset(dp,0,sizeof dp);
        for (int j = 1 ; j <= npins ; j++)
            cin>>sum[j];
        npins+=width;
        for(int j = 1 ; j <= npins; j++)
                sum[j]+=sum[j-1];
        for (int j = 1 ; j <= nballs; j++)
        {
            for (int k = 1; k <= npins; k++)
            {
                int b = max(0,k-width);
                dp[j][k] = max(dp[j-1][b]+sum[k]-sum[b],dp[j][k-1]);
                if (j>=2)
                {
                    for (int w = 1 ; w < width; w++ )
                    {
                        int nb = b-w;
                        if (nb<0)break;
                        dp[j][k] = max(dp[j][k],dp[j-2][nb]+sum[k]-sum[nb] );
                    }
                }
            }
        }
        int maxi = 0;
        for(int i = 0; i <= npins; i++){ maxi = max(maxi, dp[nballs][i]); }
        cout << maxi << endl;
    }
    return 0;
}

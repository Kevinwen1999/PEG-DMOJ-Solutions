#include <iostream>
using namespace std;
inline int max(int a, int b) { return (a > b) ? a : b; }
int dp[501][30001];
int sum[30001];
int pin[30001];
int turns;
int width;
int npins;
int nballs;
int main()
{
    cin>>turns;
    for (int i = 0 ; i < turns; i++)
    {
        cin>>npins>>nballs>>width;
        for (int j = 0 ; j < npins ; j++)
        {
            cin>>pin[j];
        }
        for (int j = 0 ; j < npins ; j++)
        {
            sum[j] = 0;
        }
        for(int j = 0 ; j < npins; j++)
        {
            for (int k = 0 ; j-k>=0&&k<width ;k++)
            {
                sum[j]+=pin[j-k];
            }
        }
        for (int j = 0 ; j < npins; j++)
        {
            dp[0][j] = 0;
        }
        for (int j = 1 ; j <= nballs ; j++)
            dp[j][0] = pin[0];
        for (int j = 1 ; j <= nballs; j++)
        {
            for (int k = 1; k < npins; k++)
            {
                int sums = sum[k];
                if(k-width>=0)
                {
                    sums = sums + dp[j-1][k-width];
                }
                dp[j][k] = max(sums,dp[j][k-1]);
            }
        }
        for (int i = 0 ; i < npins; i++)
        cout<<dp[nballs][i]<<endl;
    }
    return 0;
}


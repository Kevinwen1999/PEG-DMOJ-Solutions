#include <iostream>
#include <cstring>
#include <cmath>
#define INF 0x3f3f3f3f
using namespace std;
inline long long min(long long a, long long b) {return a < b ? a : b;}
int N, M, K;
int building[120];
long long dp[120][520];
long long sum(int total, int times)
{
    times++;
    long long x = total/ times;
    long long big = total % times;
    long long small = times - big;
    return x* (x+1)/2*small + (x+1)*(x+2)/2*big;
}
long long  recur(int index, int turn)
{
    if(dp[index][turn]!=-1) return dp[index][turn];
    if (index ==1) return dp[index][turn] = sum(building[index],turn);
    long long ans = INF;
    for (int i = 0 ; i <= turn; i++)
        ans = min(ans, recur(index-1, turn - i)+ sum(building[index], i));
    return dp[index][turn] = ans;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M>>K;
    for (int i = 0,a ;i < N; i++)
    {
        cin>>a;
        building[a]++;
    }
    memset(dp,-1,sizeof dp);
    /*memset(dp,63,sizeof dp);
    for (int i = 0 ; i <= K; i++)
        dp[1][i] = sum(building[1],i);
    for (int i = 2; i <= M; i++)
        for (int j = 0 ; j <= K; j++)
            for (int k = 0 ; k <= j; k++)
                dp[i][j] = min(dp[i][j], dp[i-1][j-k] + sum(building[i], k));
    cout<<dp[M][K]<<"\n";*/
    cout<<recur(M,K)<<endl;
}

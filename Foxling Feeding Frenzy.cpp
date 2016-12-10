#include <iostream>
#include <cstring>
#define MOD 1000000007
using namespace std;
int T, N, M;
int lower[220], upper[220];
long long dp[220][220];
int recur(int index, int remain)
{
    if (remain<lower[index]) return 0;
    if (dp[index][remain]!=-1) return dp[index][remain];
    if (index == N)
    {
        if (remain > upper[index]) return 0;
        return 1;
    }
    long long ans = 0;
    for (int i = lower[index]; i <= remain && i <= upper[index]; i++ )
        ans+=recur(index+1, remain-i)%MOD;
    return dp[index][remain] = ans%MOD;

}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while (T--)
    {
        cin>>N>>M;
        for (int i = 1 ; i <= N; i++)
            cin>>lower[i]>>upper[i];
        memset(dp,-1,sizeof dp);
        cout<<recur(1,M)<<endl;
    }
}

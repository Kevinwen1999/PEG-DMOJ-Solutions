#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int N, M;
string str1, str2;
int dp[1010][1010];
int recur(int n, int m)
{
    if (n==-1&&m==-1) return 0;
    if (n==-1) return  m/3+1;
    if (m==-1) return  n/3+1;
    if (dp[n][m]!=-1) return dp[n][m];
    if (str1[n]==str2[m]) return dp[n][m] = recur(n-1,m-1);
    dp[n][m] = 1+min(recur(n-1,m),min(recur(n,m-1),recur(n-1,m-1)));
    if (n>=2) dp[n][m] = min(dp[n][m], 1+recur(n-2,m));
    if (m>=2) dp[n][m] = min(dp[n][m], 1+recur(n,m-2));
    if (n>=3) dp[n][m] = min(dp[n][m], 1+recur(n-3,m));
    if (m>=3) dp[n][m] = min(dp[n][m], 1+recur(n,m-3));
    return dp[n][m];

}
int main()
{
    cin>>N>>M;
    cin>>str1>>str2;
    memset(dp,-1,sizeof dp);
    cout<<recur(N-1,M-1)<<endl;
}

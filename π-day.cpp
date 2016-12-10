#include <iostream>
#include <cstring>
using namespace std;
int N, K;
int dp[260][260][260];
int recur (int pies, int pleft, int person)
{
    if (pleft < pies) return 0;
    if (person == K) return 1;
    if (dp[pies][pleft][person]!=-1) return dp[pies][pleft][person];
    int ans = 0;
    for (int i = pies; i <= pleft; i++)
    {
        ans += recur(i,pleft-i,person+1);
    }
    return dp[pies][pleft][person] = ans;
}
int main()
{
    cin>>N>>K;
    if (K==N)
    {
        cout<<1<<endl;
        return 0;
    }
    if (K==1)
    {
        cout<<1<<endl;
        return 0;
    }
    memset(dp,-1,sizeof dp);
    cout<<recur(1,N,1);
}

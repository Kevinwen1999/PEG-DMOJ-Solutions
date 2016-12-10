#include <iostream>
#include <cstring>
using namespace std;
int N, T;
int p[2010][3], v[2010][3];
//long long   dp[2010][10010];
long  dp[10010];
inline long   max(long   a, long   b) {return a > b? a : b;}
/*long long  recur(int id, int timeleft)
{
    if (id==N)
    {
        int  ans = 0;
        for (int i = 0 ; i < 3; i++)
        {
            if (timeleft>=p[id][i])
                ans = max(ans, v[id][i] );
        }
        return dp[id][timeleft] = ans;
    }
    if (dp[id][timeleft]!=-1) return dp[id][timeleft];
    if (timeleft < p[id][0]) return dp[id][timeleft] = recur(id+1, timeleft);
    int  ans = 0;
    for (int i = 0 ; i < 3; i++)
    {
        if (timeleft>=p[id][i])
            ans = max(ans, recur(id+1, timeleft-p[id][i])+v[id][i] );
    }
    ans = max(ans, recur(id+1, timeleft));
    return dp[id][timeleft] = ans;
}
*/
int main()
{
    cin>>N>>T;
    for (int i = 1; i <= N; i++)
        cin>>p[i][0]>>v[i][0]>>p[i][1]>>v[i][1]>>p[i][2]>>v[i][2];
    memset(dp,-1,sizeof dp);
    dp[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int k = T; k >=0; k--)
        {
            if (k-p[i][0]>=0&&dp[k-p[i][0]]!=-1)
                dp[k] = max(dp[k],dp[k-p[i][0]]+v[i][0]);
            if (k-p[i][1]>=0&&dp[k-p[i][1]]!=-1)
                dp[k] = max(dp[k],dp[k-p[i][1]]+v[i][1]);
            if (k-p[i][2]>=0&&dp[k-p[i][2]]!=-1)
                dp[k] = max(dp[k],dp[k-p[i][2]]+v[i][2]);
        }
    }
    long  maxx = 0;
    for (int i = 0 ; i <= T; i++ )
        maxx = max(maxx, dp[i]);
    cout<<maxx<<endl;

    //cout<<recur(1, T)<<"\n";
}

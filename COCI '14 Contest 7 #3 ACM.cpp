#include <iostream>
#include <cstring>
#define INF 0x3f3f3f3f
using namespace std;
inline int min(int a, int b) {return a < b ? a : b;}
int N,first,second,third,fsum,ssum,tsum,K;
int p[3][150010];
int seq[6][3]= { {0,1,2},{0,2,1},{1,2,0},{1,0,2},{2,0,1},{2,1,0} };
int dp[150010][3];

int recur (int index, int person)
{
    if (index== N && (person!=2)) return INF;
    if (person > 2) return INF;
    if (dp[index][person]!=-1) return dp[index][person];
    int ans ;
    ans = min( recur(index+1, person+1), recur(index+1, person));
    return dp[index][person] = p[seq[K][person]][index] + ans;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for (int i = 0 ; i < 3; i++)
        for (int j = 1; j <= N; j++)
        {
            cin>>p[i][j];
            //p[i][j]+=p[i][j-1];
        }
    int ans = INF;
    /*for (int k = 0 ; k < 6; k++)
    {
        first = seq[k][0];second = seq[k][1];third = seq[k][2];
        for (int i = 2; i <N; i++)
        {
            fsum = p[first][i-1]-p[first][0];
            if (fsum > ans) break;
            for (int j = i; j < N; j++)
            {
                 ssum = p[second][j] - p[second][i-1];
                 if (fsum+ssum > ans) break;
                 tsum = p[third][N] - p[third][j];
                 ans = min(ans,fsum+ssum+tsum);
            }
        }
    }*/
    int best = INF;
    for ( K = 0 ; K < 6; K++)
    {
        memset(dp,-1,sizeof dp);
        dp[N][0] = p[seq[K][0]][N];dp[N][1] = p[seq[K][1]][N];dp[N][2] = p[seq[K][2]][N];
        ans = min(ans, recur(1,0));
        best = min(best, ans);
    }
    cout<<best;
}

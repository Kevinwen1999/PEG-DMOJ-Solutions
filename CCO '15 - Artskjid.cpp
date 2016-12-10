#include <iostream>
#include <cstring>
#define N 20
#define NBITS (1 << N)
#define NINF -999999999
using namespace std;
long long adj[N][N];
long long dp[N][NBITS];
long long V;
long long E;
inline long long max(long long a, long long b) {return a>b?a:b;}
long long subsolve(long long node, long long bitmask)
{
    if (dp[node][bitmask]!=-1) return dp[node][bitmask];
    long long best  = 0,x;
    bool isend = true;
    for (int i = 0 ; i < V; i++)
    {
        if (adj[node][i]!=-1 && i!=node && ( bitmask&(1<<i) ))
        {
            x = subsolve(i, bitmask & ~(1<<i));
            if (x != NINF)
            {
                isend = false;
                x += adj[node][i];
                best = max(best, x);
            }
        }
    }
    if (isend && (bitmask & (1<<(V-1)))) return dp[node][bitmask] = NINF;
    return dp[node][bitmask] = best;
}
int main()
{
    cin>>V;
    cin>>E;
    memset(dp,-1,sizeof dp);
    memset(adj,-1,sizeof adj);
    for (int j = 1; j <=E ; j++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        adj[a][b] = c;
    }
    for (int i = 0 ; i < (1<<V); i++)
        dp[V-1][i] = 0;
    long long ans = 0;
    int start = (1<<V)-1;
    start = start & ~(1);
    ans = subsolve(0,start);
    cout<<ans<<endl;
    return 0;
}

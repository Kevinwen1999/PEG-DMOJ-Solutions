#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
struct rock
{
    int x, y;
} r;
vector <rock> ar;
set <int> s[210];
bool cmp (rock &a, rock &b)
{
    if (a.y==b.y)
    {
        return a.x < b.x;
    }
    return a.y < b.y;
}
int L, N;
int tx, ty;
int dp[10010][2];
int recur (int depth, int taken)
{
    if (depth>=10001) return -1;
    if (dp[depth][taken]!=-1) return dp[depth][taken];
    int ans = INF;
    for (int i = 0; i < L; i++)
    {
        int nex = *(s[i].upper_bound(depth));
        if (nex==ty&&i==tx) continue;
        nex--;
        if (nex==depth) continue;
        if (!taken)
        {
            if (nex > ty)
            {
                if (abs(i-tx) > 1) continue;
                ans = min(ans, 1+recur(nex, 1));
            }
            else if (nex == ty)
            {
                ans = min(ans, 1+recur(nex, 1));
            }
            else
            {
                ans = min(ans, 1+recur(nex, 0));
            }
        }
        else
        {
            ans = min(ans, 1+recur(nex, 1));
        }
    }
    return dp[depth][taken] = ans;
}
int main()
{
    cin>>L>>N;
    for (int i = 0; i < N; i++)
    {
        cin>>r.y>>r.x;
        s[r.x].insert(r.y);
    }
    cin>>ty>>tx;
    s[tx].insert(ty);
    for (int i = 0; i <= L; i++)
        s[i].insert(INF);
    memset(dp,-1,sizeof dp);
    int ans = recur(0,0);
    if (ans >= INF)
    {
        cout<<"Use dynamite\n";
    }
    else
        cout<<ans<<"\n";
}

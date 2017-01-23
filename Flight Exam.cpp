#include <bits/stdc++.h>
#define MAXN 2010
using namespace std;
int N, I, D, S;
vector <pair <int,int> > pnts;
set <pair <int,int> > rl;
int dp[MAXN];
int pnttotal = 0;
int recur(int cur)
{
    if (~dp[cur]) return dp[cur];
    int x = pnts[cur].first, y = pnts[cur].second, nx, ny, dist;
    int ans = 0, add = 0;
    if (rl.count(pnts[cur])) add++;
    if (S>0 && rl.count({x,y+S})) add++;
    for (int i = cur+1; i < pnttotal; i++)
    {
        nx = pnts[i].first, ny = pnts[i].second, dist = nx-x;
        if (nx==x) continue;
        unsigned long long u =1ULL*dist*I, dd = 1ULL*dist*D;
        if (ny > y && u >= ny-y)
            ans = max(ans, recur(i));
        if (ny < y && dd >= y-ny)
            ans = max(ans, recur(i));
        if (ny==y)
            ans = max(ans, recur(i));

    }
    return dp[cur] = ans + add;
}
int main()
{
    cin>>N>>I>>D>>S;
    pnts.push_back({0,0});
    for (int i = 0, a, b; i < N; i++)
    {
        cin>>a>>b;
        pnts.push_back({a,b});
        rl.insert({a,b});
    }
    for (auto i : rl)
    {
        if (i.second-S <0 ) continue;
        if (rl.count({i.first, i.second-S})) continue;
        pnts.push_back({i.first, i.second-S});
    }
    sort(pnts.begin(), pnts.end());
//    for (auto i : pnts)
//        cout<<i.first<<" "<<i.second<<"\n";
    pnttotal = pnts.size();
    memset(dp,-1,sizeof dp);
    //if (recur(0)==75&&N!=6&&N!=4) cout<<N<<"\n"<<I<<"\n"<<D<<"\n"<<S<<"\n";
    cout<<recur(0)<<" ";
}

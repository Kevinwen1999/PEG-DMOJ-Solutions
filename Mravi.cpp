#include <bits/stdc++.h>
#define MAXN 1001
using namespace std;
int N;
vector < pair <int,int> > adj[MAXN];
double need[MAXN];
bool v[MAXN];
bool OK;
void dfs(int cur, int pa, double tot)
{
    if (need[cur]!=-1)
    {
        if (tot<need[cur]) OK = false;
    }
    for (auto i : adj[cur])
    {
        if (i.first==pa) continue;
        double per = i.second*0.01;
        if (per < 0) per = (per*tot)*(per*tot);
        else per = per*tot;
        dfs(i.first, cur, per);
    }
}
bool check(double feed)
{
    OK = true;
    dfs(1,-1,feed);
    return OK;
}
int main()
{
    cin>>N;
    for (int i = 0, a, b, c, d; i < N - 1; i++)
    {
        cin>>a>>b>>c>>d;
        c = (d ? -c:c);
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    for (int i = 1; i <= N; i++)
        cin>>need[i];
    double l = 0.0, h = 2*1e9, ans, mid;
    while (l<=h)
    {
        mid = (l+h)/2;
        if (check(mid))
        {
            ans = mid;
            h = mid-0.001;
        }
        else
        {
            l = mid+0.001;
        }
    }
    cout<<ans<<"\n";
}

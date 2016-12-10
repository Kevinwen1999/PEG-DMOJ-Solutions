#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
long long seton(long long mask, int i) { return mask | (1<<i);}
bool ison(long long mask, int i) {return mask & (1<<i);}
long long toggle(long long mask, int i) {return mask ^ (1<<i);}
long long setoff (long long mask, int i) {return mask & ~(1<<i);}
//int dp[(1<<22)];
int K;
long long process(long long mask, int idx)
{
    int l = idx, r = idx;
    mask = toggle(mask, idx);
    while (l >= 0 && ison(mask, l)) l--;
    while (r < K && ison(mask, r)) r++;
    l++; r--;
    if (r-l+1 >= 4)
    {
        for (int j = l; j <= r; j++)
            mask = toggle(mask, j);
    }
    return mask;
}
/*int shortest (long long mask)
{
    int& ans = dp[mask];
    if (ans!=-1) return ans;
    ans = INF;
    if (mask==0) return ans = 0;
    long long nxt;
    for (int i = 0; i < K; i++)
    {
        if (!ison(mask, i))
        {
            nxt = process(mask, i);
            ans = min(ans, shortest(nxt)+1);
        }
    }
    return ans;
}*/
int main()
{
    //memset(dp,-1,sizeof dp);
    cin>>K;
    long long init = 0;
    for (int i = 0 ; i < K; i++)
    {
        int in;
        cin>>in;
        if (in) init = seton(init, i);
    }
    queue <pair <long long, int> > q;
    unordered_set <long long> visited;
    q.push(make_pair(init, 0));
    visited.insert(init);
    long long mask, nxt; int steps;
    while(!q.empty())
    {
        mask = q.front().first; steps = q.front().second;
        q.pop();
        if (mask == 0)
        {
            cout<<steps<<"\n";
            return 0;
        }
        for (int i = 0; i < K; i++)
        {
            if (!ison(mask, i))
            {
                nxt = process(mask, i);
                if (!visited.count(nxt))
                {
                    visited.insert(nxt);
                    q.push(make_pair(nxt, steps+1));
                }
            }
        }
    }
    //cout<<shortest(init)<<"\n";
}

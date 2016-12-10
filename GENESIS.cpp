#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
const int MAXN = 110 * 2;
using namespace std;
inline int getfront(int n) {return n*2;}
inline int getback(int n) {return n*2 + 1;}
int N;
int E[MAXN];
int res[MAXN][MAXN];
int dist[MAXN];
int M, mf, f, s = 1, t;
int par[MAXN];
void aug(int cur, int minE)
{
    if (cur==getfront(s)) {f = minE; return;}
    else if (par[cur]!=-1)
    {
        aug(par[cur], min(minE, res[par[cur]][cur]));
        res[par[cur]][cur] -= f; res[cur][par[cur]] += f;
    }
}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    t = N;
    for (int i = 1; i <N; i++)
    {
        cin>>E[i];
        res[getfront(i)][getback(i)] = E[i];
    }
    cin>>M;
    for (int i = 0 ; i < M; i++)
    {
        int a, b;
        cin>>a>>b;
        a = getback(a);
        b = getfront(b);
        res[a][b] = INF;
    }
    while(1)
    {
        f = 0;
        memset(dist, 63, sizeof dist);
        memset(par, -1, sizeof par);
        dist[getfront(s)] = 0;
        queue <int> q; q.push(getfront(s));
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            if (cur == getfront(t)) break;
            for (int next = getfront(1) ; next <= getfront(N); next++)
            {
                if (res[cur][next] > 0 && dist[next] == INF)
                {
                    dist[next] = dist[cur] + 1;
                    q.push(next);
                    par[next] = cur;
                }
            }
        }
        aug(getfront(t), INF);
        if (f==0) break;
        mf += f;
    }
    cout<<mf<<"\n";
}

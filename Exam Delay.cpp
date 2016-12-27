#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;
struct edge
{
    int to;
    double dist, speed;
} e, pa[1010];
vector <edge> adj[1010];
int V, E;
double t[1010];
int npass[1010];
bool done[1010];
void spfa(int st)
{
    for (int i = 0; i <= V; i++)
    {
        t[i] = INF;
        npass[i] = INF;
    }
    t[st] = 0;
    npass[st] = 0;
    done[st] = 1;
    pa[st].to = -1;
    queue <int> buff;
    buff.push(st);
    while (!buff.empty())
    {
        int cur = buff.front();
        buff.pop();
        done[cur] = false;
        for (auto i : adj[cur])
        {
            double nt = i.dist/i.speed;
            if (t[cur] + nt < t[i.to] || (t[cur] + nt == t[i.to] && npass[cur]+1 < npass[i.to]))
            {
                t[i.to] = t[cur] + nt;
                npass[i.to] = npass[cur] + 1;
                pa[i.to].to = cur; pa[i.to].dist = i.dist; pa[i.to].speed = i.speed*0.75;
                if (!done[i.to])
                {
                    done[i.to] = true;
                    buff.push(i.to);
                }
            }
        }
    }
}
int sum1; double sum2;
void backtrack(int cur)
{
    //cout<<cur<<"\n";
    if (pa[cur].to==-1) return;
    backtrack(pa[cur].to);
    sum1++;
    //cout<<pa[cur].dist/pa[cur].speed<<"\n";
    sum2+=pa[cur].dist/pa[cur].speed;
}
int main()
{
    cin>>V>>E;
    for (int i = 0, a, b; i < E; i++)
    {
        cin>>a>>b>>e.dist>>e.speed;
        e.to = b;
        adj[a].push_back(e);
        e.to = a;
        adj[b].push_back(e);
    }
    spfa(1);
    backtrack(V);
    printf("%d\n%.0lf\n", sum1, (sum2-t[V])*60);
}

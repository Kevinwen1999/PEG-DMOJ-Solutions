#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int S;
int V, E;
struct edge
{
    int to, sec, burn;
};
int dist[1610][3610];
bool done[1610][3610];
vector <edge> adj[1610];
void spfa()
{
    memset(dist,0x3f,sizeof dist);
    dist[0][0] = 0;
    done[0][0] = true;
    queue <pair <int,int> > buff;
    buff.push({0,0});
    while (!buff.empty())
    {
        pair <int,int> cur = buff.front();
        buff.pop();
        done[cur.first][cur.second] = false;
        for (edge i : adj[cur.first])
        {
            int sun = (!i.burn ? 0 : i.sec);
            if (cur.second + sun > S) continue;
            if (dist[cur.first][cur.second] + i.sec < dist[i.to][cur.second+sun])
            {
                dist[i.to][cur.second+sun] = dist[cur.first][cur.second] + i.sec;
                if (!done[i.to][cur.second+sun])
                {
                    done[i.to][cur.second+sun] = true;
                    buff.push({i.to, cur.second + sun});
                }
            }
        }
    }
}
int main()
{
    cin>>S;
    cin>>V>>E;
    for (int i = 0,a,b,c,d; i < E; i++)
    {
        cin>>a>>b>>c>>d;
        adj[a].push_back((edge){b,c,d});
        adj[b].push_back((edge){a,c,d});
    }
    spfa();
    int maxx = INF;
    for (int i = 0; i <= S; i++)
        maxx = min(maxx, dist[V-1][i]);
    if (maxx == INF)
        cout<<"-1";
    else
        cout<<maxx;
}

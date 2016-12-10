#include <bits/stdc++.h>
#define MAXN 101
#define INF 0x3f3f3f3f
using namespace std;
int N;
int t[MAXN];
int M;
vector <pair <int,int> > adj[MAXN];
int dist[MAXN];
int cargo[MAXN];
bool done[MAXN];
void spfa(int st)
{
    memset(dist, 63, sizeof dist);
    queue <int> buff;
    buff.push(st);
    dist[st] = 0;
    done[st] = true;
    cargo[st] = t[st];
    while (!buff.empty())
    {
        int cur = buff.front();
        buff.pop();
        done[cur] = false;
        for (int i = 0; i < adj[cur].size(); i++)
        {
            pair <int,int> v  = adj[cur][i];
            if (dist[cur] + v.second < dist[v.first])
            {
                dist[v.first] = dist[cur] + v.second;
                cargo[v.first] = cargo[cur] + t[v.first];
                if (!done[v.first])
                {
                    done[v.first] = true;
                    buff.push(v.first);
                }
            }
            else if (dist[cur] + v.second == dist[v.first])
            {
                if (cargo[cur] + t[v.first] <= cargo[v.first]) continue;
                cargo[v.first] = cargo[cur] + t[v.first];
                if (!done[v.first])
                {
                    done[v.first] = true;
                    buff.push(v.first);
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for (int i = 1; i <= N; i++)
        cin>>t[i];
    cin>>M;
    for (int i = 0, a, b, d; i < M; i++)
    {
        cin>>a>>b>>d;
        adj[a].push_back({b,d});
        adj[b].push_back({a,d});
    }
    spfa(1);
    if (dist[N]>=INF)
        cout<<"impossible";
    else
        cout<<dist[N]<<" "<<cargo[N];
}

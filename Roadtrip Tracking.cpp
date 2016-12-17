#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAXN 40010
using namespace std;
vector <int> adj[MAXN];
int N, M;
int dist[MAXN], pa[MAXN];
bool visited[MAXN],done[MAXN];
queue <int> buff;
int BFS()
{
    memset(dist,-1,sizeof dist);
    pa[1] = -1;
    dist[1] = 0;
    buff.push(1);
    visited[1] = true;
    while (!buff.empty())
    {
        int u = buff.front();
        buff.pop();
        for (int v : adj[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                dist[v] = dist[u]+1;
                pa[v] = u;
                buff.push(v);
            }
        }
    }
    return dist[N];
}
vector <int> shortest;
set <pair <int,int> > cut;
void mark (int cur)
{
    if (cur==-1) return;
    mark(pa[cur]);
    shortest.push_back(cur);
}
int spfa()
{
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;
    done[1] = true;
    while (!buff.empty()) buff.pop();
    buff.push(1);
    while (!buff.empty())
    {
        int u = buff.front();
        buff.pop();
        done[u] = false;
        for (int v : adj[u])
        {
            int w = cut.count({u,v})? 2: 1;
            if (dist[v] > dist[u] + w-1)
            {
                dist[v] = dist[u] + w-1;
                if (!done[v])
                {
                    done[v] = true;
                    buff.push(v);
                }
            }
        }
    }
    return dist[N];
}
int main()
{
    cin>>N>>M;
    for (int i = 0, a, b; i < M; i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int dist1 = BFS();
    if (dist1 == -1)
    {
        cout<<"No";
        return 0;
    }
    mark(N);
    for (int i = 0; i < shortest.size()-1; i++)
    {
        cut.insert({shortest[i], shortest[i+1]});
        cut.insert({shortest[i+1], shortest[i]});
    }
    int dist2 = spfa();
    if (dist2!=dist1)
        cout<<"Yes";
    else
        cout<<"No";
}

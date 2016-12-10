#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int N, M, A, B;
struct path
{
    int dist, cost;
    path(int a, int b) {dist = a; cost = b;}
};
struct edge
{
    int from , to, dist, cost;
    edge(int a, int b, int c, int d) {from = a; to = b; dist = c; cost = d;}
    edge(int a, int b) {dist = a; cost = b;}
};
bool cmp(edge a, edge b)
{
    return a.dist < b.dist;
}
vector <pair <int, path> > adj[100005];
vector <pair <int, path> > radj[100005];
vector <edge> all, sorted;
int Dist[100005], Rdist[100005];
bool done[100005];
int sum[100005];
void SPFA(int start, int dist[])
{
    dist[start] = 0; done[start] = true;
    queue <int> buff;
    buff.push(start);
    while (!buff.empty())
    {
        int cur = buff.front();
        buff.pop();
        done[cur] = false;
        for (int i = 0 ; i < adj[cur].size(); i++)
        {
            pair <int, path> nex = adj[cur][i];
            if (dist[nex.first] > dist[cur] + nex.second.dist)
            {
                dist[nex.first] = dist[cur] + nex.second.dist;
                if (!done[nex.first])
                {
                    done[nex.first] = true;
                    buff.push(nex.first);
                }
            }
        }
    }
}
void RSPFA(int start, int dist[])
{
    dist[start] = 0; done[start] = true;
    queue <int> buff;
    buff.push(start);
    while (!buff.empty())
    {
        int cur = buff.front();
        buff.pop();
        done[cur] = false;
        for (int i = 0 ; i < radj[cur].size(); i++)
        {
            pair <int, path> nex = radj[cur][i];
            if (dist[nex.first] > dist[cur] + nex.second.dist)
            {
                dist[nex.first] = dist[cur] + nex.second.dist;
                if (!done[nex.first])
                {
                    done[nex.first] = true;
                    buff.push(nex.first);
                }
            }
        }
    }
}
int main()
{
    cin>>N>>M>>A>>B;
    A--; B--;
    for (int i = 0 ; i < M; i++)
    {
        int x, y, l, c;
        cin>>x>>y>>l>>c;
        x--; y--;
        adj[x].push_back(make_pair(y, path(l,c)));
        radj[y].push_back(make_pair(x, path(l,c)));
        all.push_back(edge(x,y,l,c));
    }
    memset(Dist, 63, sizeof Dist);
    memset(Rdist, 63, sizeof Rdist);
    SPFA(A,Dist);
    RSPFA(B, Rdist);
    for (int i = 0; i < M; i++)
    {
        int src = all[i].from, dest = all[i].to;
        if (Dist[src]==INF || Rdist[dest]==INF) continue;
        int len = Dist[src] + Rdist[dest] + all[i].dist;
        sorted.push_back(edge(len,all[i].cost));
    }
    sort(sorted.begin(), sorted.end(), cmp);
    int cnt = 1;
    for (edge i : sorted)
    {
        sum[cnt] = sum[cnt-1] + i.cost;
        cnt++;
    }
    int Q; cin>>Q;
    for (int i = 0 ; i < Q; i++)
    {
        int D; cin>>D;
        int l = 0, r = sorted.size()-1;
        while (l <= r)
        {
            int mid = l + (r - l)/2;
            if (sorted[mid].dist > D)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        cout<<sum[l]<<"\n";
    }
}

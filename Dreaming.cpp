#include <bits/stdc++.h>
#define INF 1e15
using namespace std;
vector <pair <int, int> > adj[100010];

int ans, cnt;
bool visited[100010];
int dist[100010], sum[100010];
int deepest, tmax;
vector <int> rs;

void bfs1(int st)
{
    queue <int> buff;
    buff.push(st);
    visited[st] = true;
    //memset(dist, -1, sizeof dist);
    dist[st] = 0;
    tmax = 0; deepest = st;
    while (!buff.empty())
    {
        int cur = buff.front();
        buff.pop();
        for (auto &i : adj[cur])
        {
            if (!visited[i.first])
            {
                visited[i.first] = true;
                dist[i.first] = dist[cur] + i.second;
                if (dist[i.first] > tmax)
                {
                    tmax = dist[i.first];
                    deepest = i.first;
                }
                buff.push(i.first);
            }
        }
    }
}
int maxdist, maxidx;
void bfs2(int st)
{
    queue <pair <int, int > > buff;
    buff.push({st,-2});
    //memset(dist, -1, sizeof dist);
    dist[st] = 0;
    maxdist = 0; maxidx = st;
    while (!buff.empty())
    {
        auto x = buff.front();
        int cur = x.first;
        buff.pop();
        for (auto &i : adj[cur])
        {
            if (i.first == x.second) continue;
            dist[i.first] = dist[cur] + i.second;
            if (dist[i.first] > maxdist)
            {
                maxdist = dist[i.first];
                maxidx = i.first;
            }
            buff.push({i.first,cur});
        }
    }
}
int radius, maxradius = -1, smaxradius = 0;
bool dfs1(int cur, int pa, int tar)
{
    if (cur==tar)
    {
        radius = min(radius, maxdist);
        sum[cur] = 0;
        return true;
    }
    for (auto i : adj[cur])
    {
        if (i.first==pa) continue;
        if (dfs1(i.first, cur, tar))
        {
            sum[cur] = sum[i.first] + i.second;
            radius = min(radius, max(sum[cur], maxdist - sum[cur]));
            return true;
        }
    }
    return false;
}
/*
int travelTime(int N, int M, int L, int A[], int B[], int T[])
{
    for (int i = 0, a, b, c; i < M; i++)
    {
        //cin>>a>>b>>c;
        a = A[i], b = B[i], c = T[i];
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            bfs1(i);
            bfs2(deepest);
            radius = INF;
            dfs1(deepest, -2, maxidx);
            ans = max(ans, maxdist);
            rs.push_back(radius);
        }
    }
    sort(rs.begin(), rs.end());
    reverse(rs.begin(), rs.end());
    if ((int)rs.size() >= 2) ans = max(ans, rs[0] + rs[1] + L);
    if ((int)rs.size() >= 3) ans = max(ans, rs[1] + rs[2] + L*2);
    return ans;
}

*/
int main()
{
    int N, M, L;
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M>>L;
    for (int i = 0, a, b, c; i < M; i++)
    {
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            bfs1(i);
            bfs2(deepest);
            radius = INF;
            dfs1(deepest, -2, maxidx);
            ans = max(ans, maxdist);
            rs.push_back(radius);
        }
    }
    sort(rs.begin(), rs.end());
    reverse(rs.begin(), rs.end());
    if ((int)rs.size() >= 2) ans = max(ans, rs[0] + rs[1] + L);
    if ((int)rs.size() >= 3) ans = max(ans, rs[1] + rs[2] + L*2);
    cout<<ans<<"\n";
    return 0;
}


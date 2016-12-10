#include <bits/stdc++.h>
#define INF LLONG_MAX
using namespace std;
struct point
{
    long long x, y;
    point() {x = y = 0.0;}
    point(int a, int b) {x = a; y = b;}
}p1, p2, p3;
long long pdist(point a, point b)
{
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}
const int MAXN = 30001;
//long long adj[MAXN][MAXN];
vector <long long> dist;
bool spset[MAXN];
vector <point> points;
int V, source, Q;
long long tlimit;
int main()
{
    dist.resize(MAXN);
    fill(dist.begin(),dist.end(), INF);
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>V;
    for (int i = 0 ; i < V; i++)
    {
        cin>>p1.x>>p1.y;
        points.push_back(p1);
    }
    cin>>source; source--;
    /*
    for (int i = 0 ; i < V; i++)
        for (int j = i + 1; j < V; j++)
            adj[i][j] = adj[j][i] = pdist(points[i], points[j]);
    */
    dist[source] = 0;
    for (int cnt= 0; cnt < V-1; cnt++)
    {
        int minidx = -1;
        for (int i = 0; i < V; i++)
            if (spset[i]==false && ((dist[i] < dist[minidx])||minidx == -1))
                minidx = i;
        spset[minidx] = true;
        for (int i = 0; i < V; i++)
            if (dist[minidx] + pdist(points[minidx], points[i]) < dist[i])
                dist[i] = dist[minidx] + pdist(points[minidx], points[i]);
    }
    sort(dist.begin(), dist.end());
    cin>>Q;
    for (int i = 0 ; i < Q; i++)
    {
        cin>>tlimit;
        auto tot = upper_bound(dist.begin(), dist.end(), tlimit) - dist.begin();
        cout<<tot<<"\n";
    }
}

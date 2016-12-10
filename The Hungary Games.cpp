#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>
#define INF 0x3f3f3f3f
using namespace std;
int dist1[20020],dist2[20020];
vector < pair <int,int> > adj1[20020];
vector < pair <int,int> > adj2[20020];
vector < pair < pair <int,int> ,int > > edges;
bool done[20020];
int V, E, a, b, c;
void spfa(int dist[],vector < pair <int,int> > adj[],int srs)
{
    memset(done,0,sizeof done);
    queue <int > buff;
    dist[srs] = 0;
    done[srs] = 1;
    buff.push(srs);
    while(!buff.empty())
    {
        int cur = buff.front();
        done[cur] = false;
        buff.pop();
        for (int i = 0 ; i < (int)adj[cur].size(); i++)
        {
            pair <int , int> v = adj[cur][i];
            if (dist[cur]+v.second<dist[v.first])
            {
                dist[v.first] = dist[cur] + v.second;
                if (!done[v.first])
                {
                    buff.push(v.first);
                    done[v.first] = true;
                }
            }
        }
    }
}
int main()
{
    cin>>V>>E;
    memset(dist1,63,sizeof dist1);
    memset(dist2,63,sizeof dist2);
    for (int i = 0 ; i < E; i++)
    {
        cin>>a>>b>>c;
        adj1[a].push_back(make_pair(b,c));
        adj2[b].push_back(make_pair(a,c));
        edges.push_back(make_pair(make_pair(a,b),c));
    }
    spfa(dist1,adj1,1);
    spfa(dist2,adj2,V);
    int fshort = dist1[V];
    int sshort = INF;
    for (int j = 0; j < (int)edges.size(); j++)
    {
            pair < pair <int,int> ,int > v = edges[j];
            int distance = dist1[v.first.first] + v.second + dist2[v.first.second];
            if (distance>fshort&&distance<sshort)
                sshort=distance;
    }
    if (sshort == INF) sshort = -1;
    cout<<sshort<<endl;
}

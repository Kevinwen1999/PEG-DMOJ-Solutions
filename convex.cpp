#include<iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
struct edge
{
    int to,weight,hull;
    edge(int bb,int tt,int hh)
    {
        to = bb;
        weight = tt;
        hull = hh;
    }
};
vector <  edge  >adjacencyList[2050];
int   dist[2050][250];
bool done[2050][250];
queue < pair < int,int > > buff;
int V;
int E;
int K;
int head;
int tail;
void spfa( int st);
int main()
{
    cin>>K;
    cin>>V;
    cin>>E;
    for (int i = 0; i <= V; i++)
    {
        for (int j = 0 ; j < 250; j++)
        {
            dist[i][j] = 9999999;
            done[i][j] = false;
        }


    }
    for (int j = 1; j <=E ; j++)
    {
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        adjacencyList[a].push_back(edge(b,c,d));
        adjacencyList[b].push_back(edge(a,c,d));
    }
    cin>>head>>tail;
    spfa(head);
    int best = 9999999;
    for (int i=0;i<K;i++) best = min(best,dist[tail][i]);
    if (best == 9999999)
    {
        cout<<-1;
        return 0;
    }
    cout<<best;
    return 0;
}
void spfa(int st)
{
    dist[st][0] = 0;
    buff.push(make_pair(st,0));
    done[st][0] = true;
    while (!buff.empty())
    {
        pair <int , int > temp = buff.front();
        int curnode = temp.first;
        int curhull = temp.second;
        buff.pop();
        done[curnode][curhull] = false;
        for (int i = 0; i < (int)adjacencyList[curnode].size(); i++)
        {
            edge nextnode = adjacencyList[curnode][i];
            if ( (curhull+nextnode.hull)<K && (dist[curnode][curhull]+nextnode.weight)<dist[nextnode.to][curhull+nextnode.hull] )
            {
                dist[nextnode.to][curhull+nextnode.hull] = dist[curnode][curhull]+nextnode.weight;
                if (done[nextnode.to][curhull+nextnode.hull]==false)
                {
                    buff.push(make_pair(nextnode.to,curhull+nextnode.hull));
                    done[nextnode.to][curhull+nextnode.hull] = true;
                }
            }
        }

    }
}

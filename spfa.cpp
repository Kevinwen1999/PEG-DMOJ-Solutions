#include<iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
vector < pair <int, int> >adjacencyList[1050];
long dist[1500];
bool done[1500];
queue <int> buff;
int V;
int E;

void spfa( int st);
int main()
{
    cin>>V;
    cin>>E;
    for (int i = 0; i <= V; i++)
    {
        dist[i] = 999999999;
        done[i] = false;
    }
    for (int j = 1; j <=E ; j++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        adjacencyList[a].push_back(make_pair(b,c));
    }
    //cout<<"READY TO SPFA:"<<endl;
    spfa(1);
    cout<<dist[V];
    return 0;
}
void spfa(int st)
{
    //cout<<st<<endl;
    dist[st] = 0;
    buff.push(st);
    done[st] = true;
    while (!buff.empty())
    {
        int temp = buff.front();
        buff.pop();
        done[temp] = false;
        for (int i = 0; i < (int)adjacencyList[temp].size(); i++)
        {
            pair<int,int> v = adjacencyList[temp][i];
            if ((dist[temp]+ v.second) < dist[v.first])
            {
                dist[v.first] = dist[temp]+v.second;
                if (done[v.first]==false)
                {
                    buff.push(v.first);
                    done[v.first] = true;
                }
            }
        }

    }
}

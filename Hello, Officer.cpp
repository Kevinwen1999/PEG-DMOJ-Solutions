#include<iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
vector < pair <int, int> >adjacencyList[5020];
long dist[2020];
bool done[2020];
queue <int> buff;
int V;
int E;
int B, Q,A;
void spfa( int st);
int main()
{
    cin>>V;
    cin>>E;
    cin>>B>>Q;
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
        adjacencyList[b].push_back(make_pair(a,c));
    }
    //cout<<"READY TO SPFA:"<<endl;
    spfa(B);
    for (int i = 0 ; i < Q; i++)
    {
        cin>>A;
        if (dist[A] == 999999999 )
            cout<<-1<<endl;
        else
        cout<<dist[A]<<endl;
    }
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
            //cout<<"READY TO CHECK PAIR:"<<endl;
            if ((dist[temp]+ v.second) < dist[v.first])
            {
                dist[v.first] = dist[temp]+v.second;
                //cout<<dist[v.first]<<endl;
                if (done[v.first]==false)
                {
                    buff.push(v.first);
                    done[v.first] = true;
                }
            }
        }

    }
}

#include<iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cmath>
#define ll long long
using namespace std;
vector < pair <ll, ll> >adjacencyList[3050];
vector < pair <ll, ll> > loc;

ll dist[3050];
bool done[3050];
queue <ll> buff;
int V,X,Q;

void spfa( int st);
int main()
{
    loc.push_back(make_pair(0,0));
    cin>>V;
    for (int i = 1; i <= V; i++)
    {
        dist[i] = 999999999;
        done[i] = false;

        ll a,b;
        cin>>a>>b;
        pair <ll,ll> temp = make_pair(a,b);
        loc.push_back(temp);
    }
    for (int i = 1; i <= V; i++)
    {
        for (int j = i+1; j<=V; j++)
        {
            pair<ll,ll> v1 = loc[i];
            pair<ll,ll> v2 = loc[j];
            adjacencyList[i].push_back(make_pair(j,pow(v1.first - v2.first, 2) + pow(v1.second - v2.second, 2)));
            adjacencyList[j].push_back(make_pair(i,pow(v1.first - v2.first, 2) + pow(v1.second - v2.second, 2)));
        }
    }
    cin>>X;
    spfa(X);
    cin>>Q;
    for (int i = 0 ; i < Q; i++)
    {
        ll q;
        ll answer = 1;
        cin>>q;
        for (int i = 2; i <= V ; i++)
        {
            if (dist[i]<=q)
            {
                answer++;
            }
        }
        cout<<answer<<endl;
    }
    return 0;
}
void spfa(int st)
{
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
            pair<ll,ll> v = adjacencyList[temp][i];
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


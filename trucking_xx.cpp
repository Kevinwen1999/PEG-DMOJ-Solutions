#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int UNVISITED = 0;
int VISITED= 1;
int INF = 999999;
int NINF = -999999;
int NUL = -1;
int V;
int E;
int D;
int state[10050];
vector < pair <int, int> >adjacencyList[10050];
int key[10050];
int parent[10050];
vector < pair <int, int> >mst[10050];
bool taken[10050];
int des[10050];
queue <pair <int,int> > q;
int main()
{
    cin>>V>>E>>D;
    for (int i = 1 ; i <= V ; i++)
    {
        state[i] = UNVISITED;
        des[i] = INF;
        key[i] = NINF;
        parent[i] = NUL;
        taken[i] = false;


    }
    for(int j = 1 ; j <= E ; j++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        adjacencyList[a].push_back(make_pair(b,c));
        adjacencyList[b].push_back(make_pair(a,c));

    }
    for (int k = 0 ; k < D; k++)
    {
        int temp;
        cin>> temp;
        des[temp] = 1;
    }
//----------------------------------------------------
    key[1] = 0;
    for (int i = 1 ; i <=V; i++)
    {
        int index; int curmax = NINF;
        for (int i = 1 ; i <= V; i++)
        {
            if (taken[i]==false&&key[i]>curmax)
            {
                index = i;
                curmax = key[i];
            }
        }
        taken[index] = true;
        if (parent[index]!= NUL)
        {
            for (int i = 0 ; i <(int)adjacencyList[index].size(); i++ )
            {
                pair <int,int> v = adjacencyList[index][i];
                if (v.first == parent[index])
                {
                    mst[index].push_back(make_pair(parent[index],v.second));
                    mst[parent[index]].push_back(make_pair(index,v.second));
                    break;
                }
            }

        }
        for (int i = 0; i < (int)adjacencyList[index].size(); i++)
        {
            pair <int,int> v = adjacencyList[index][i];
            if(v.second>key[v.first])
            {
                parent[v.first] = index;
                key[v.first] = v.second;
            }
        }


    }
//--------------------------------------------------------------------------

//---------------------------------------------------------------------------
    q.push(make_pair(1,INF));
    state[1] = VISITED;
    while(!q.empty())
    {
        pair<int,int> v = q.front();
        q.pop();
        for (int i = 0; i < (int)mst[v.first].size(); i++)
        {
            int curmin = v.second;
            pair<int,int> v1 = mst[v.first][i];
            if (state[v1.first] == UNVISITED)
            {

                if (v1.second < curmin)
                {
                    curmin = v1.second;
                }
                if (des[v1.first] == 1)
                {
                    des[v1.first] = curmin;
                }
                q.push(make_pair(v1.first,curmin));
                state[v1.first] = VISITED;
            }
        }
    }
//--------------------------------------------------------------------
    int lowerbound = INF;
    for (int i = 1; i<= V; i++)
    {
        if (des[i]<lowerbound)
        {
            lowerbound = des[i];
        }
    }
    cout<<lowerbound;
    return 0;
}

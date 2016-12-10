#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int main()
{
    int V;
    cin>>V;
    int n = V-1;
    int ary[V][V];
    int UNVISITED = 0;
    int VISITED= 1;
    int state[V];
    for (int i = 0 ; i < V; i ++)
    {
        state[i] = UNVISITED;
    }
    for(int i = 0; i < V; i++)
    {
        for (int j = 0 ; j < V; j++)
        {
            cin>>ary[i][j];
        }
    }
    queue < pair < int,int > > buff;
    buff.push(make_pair(0,0));
    state[0] = VISITED;
    while(!buff.empty())
    {
        pair<int,int> v = buff.front();
        buff.pop();
        int counter = v.second;
        counter++;

        for (int i = 0; i < V; i++)
        {

            if (ary[v.first][i]==1&&state[i] == UNVISITED)
            {

                if (i==(n))
                {
                cout<<counter;
                return 0;
                }
                buff.push(make_pair(i,counter));
                state[i] = VISITED;
            }
        }
    }
    cout<<0;
    return 0;
}

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
int matrix[1050][1050];
int key[10050];
int parent[10050];
int mst[1050][1050];
bool taken[10050];
int des[10050];
queue <pair <int,int> > q;
int mini;
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
        for (int j = 1; j <= V; j++)
        {
            matrix[i][j] = -1;
            mst[i][j] = -1;
        }

    }
    for(int j = 1 ; j <= E ; j++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        if (c>matrix[a][b])
        {
            matrix[a][b] = c;
            matrix[b][a] = c;
        }
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
        //buff.erase(remove(buff.begin(), buff.end(), index), buff.end());
        taken[index] = true;
        if (parent[index]!= NUL)
        {
            mst[index][parent[index]] = 1;
            mst[parent[index]][index] = 1;
        }
        for (int j = 1; j <=V; j++)
        {
            if(matrix[index][j]!=(-1)&&matrix[index][j]>key[j])
            {
                parent[j] = index;
                key[j] = matrix[index][j];
            }
        }


    }
//--------------------------------------------------------------------------
    for(int i = 1 ; i <= V; i++)
    {
        for (int j = 1 ; j <=V; j++)
        {
            if(mst[i][j]==1)
            {
                mst[i][j] = matrix[i][j];
                mst[j][i] = matrix[i][j];
            }
        }
    }
//---------------------------------------------------------------------------
    q.push(make_pair(1,INF));
    state[1] = VISITED;
    while(!q.empty())
    {
        pair<int,int> v = q.front();
        q.pop();
        for (int i = 1; i <= V; i++)
        {
            int curmin = v.second;
            if (mst[v.first][i]!=(-1)&&state[i] == UNVISITED)
            {

                if (mst[v.first][i] < curmin)
                {
                    curmin = mst[v.first][i];
                }
                if (des[i] == 1)
                {
                    des[i] = curmin;
                }
                q.push(make_pair(i,curmin));
                state[i] = VISITED;
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

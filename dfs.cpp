#include<iostream>
#include <vector>
#include <utility>
using namespace std;
vector <int> dfs_num;
int curmin = 99999;
int n;
int UNVISITED = 0;
int VISITED = 1;
vector< vector < pair <int, int> > > adjacencyList;
void dfs(int u, int tracker);
int main()
{
    int nvertics ;
    int nedges;
    cin>>nvertics;
    n = nvertics ;
    for (int i = 0; i <= nvertics; i++)
    {
        dfs_num.push_back(UNVISITED);
    }
    cin>>nedges;
    adjacencyList.resize(nvertics + 1);
    for (int j = 1; j <= nedges; j++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        adjacencyList[a].push_back(make_pair(b,c));
    }
    dfs(1,0);
    cout<<curmin;
    return 0;
}

void dfs(int u,int tracker)
{
    dfs_num[u] = VISITED;
    if (u == n)
        {
            if (tracker < curmin)
            {
                curmin = tracker;
                return;
            }
        }
    for (int k = 0; k < (int)adjacencyList[u].size(); k++)
    {
        pair<int,int> v = adjacencyList[u][k];
        int counter = tracker + v.second;
        if (dfs_num[v.first]==UNVISITED)
        {
            dfs(v.first,counter);
        }
    }

}

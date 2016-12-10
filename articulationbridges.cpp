#include<iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;
vector <int> dfs_num;
vector <int> dfs_low;
vector <int> dfs_parent;
int tracker = 0;
int n;
int UNVISITED = -1;
int VISITED = 1;
int numcounter = 0;
vector< vector < pair <int, int> > > adjacencyList;
char int_to_char[] = {'A', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'B'};
int char_to_int[26] ;


void articulation (int u);
int main()
{

    for (int i=0; i<(int)sizeof(int_to_char); ++i) {
        char_to_int[int_to_char[i]] = i;
    }
    dfs_low.assign(26, 0);
    dfs_num.assign(26, UNVISITED);
    dfs_parent.assign(26, 0);
    char a, b;
    cin>>a>>b;
    while(a!='*'&&b!='*')
    {
        int d = char_to_int[a];
        int e = char_to_int[b];
        adjacencyList[d].push_back(make_pair(e,10));
        adjacencyList[e].push_back(make_pair(d,10));
        cin>>a>>b;
    }
    for (int i = 0; i < 26; i++)
    {
        if (dfs_num[i] == UNVISITED)
        {
            articulation(i);
        }
    }
    cout<<"There are "<<tracker<<" disconnecting roads.";
    return 0;
}

void articulation(int u)
{
    numcounter++;
    dfs_num[u] = dfs_low[u] = numcounter;
    for (int k = 0; k < (int)adjacencyList[u].size(); k++)
    {
        pair<int,int> v = adjacencyList[u][k];

        if (dfs_num[v.first] == UNVISITED)
        {
            dfs_parent[v.first] = u;
            articulation(v.first);
            if (dfs_low[v.first]>dfs_num[v.first])
            {
                cout<<int_to_char[u]<<int_to_char[v.first]<<endl;
                tracker++;
                dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
            }

        }
        else if(v.first!= dfs_parent[u])
        {
            dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
        }

    }
}

#include<iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;
vector <int> dfs_num;
int counter = 0;
int tracker = 0;
int n = 26;
int UNVISITED = 0;
int VISITED = 1;
vector< vector < pair <int, int> > > adjacencyList;
//vector <int> edges;
vector< pair <int, int> > checker;
void dfs(int u, int xv1, int xv2);
//char int_to_char[26] = {'A', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'B'};
//int char_to_int[26] ;
bool iscon = false;
int main()
{
   /* for (int i=0; i<(int)sizeof(int_to_char); ++i) {
        char_to_int[int_to_char[i]] = i;
    }*/

    for (int i = 0; i < n; i++)
    {
        dfs_num.push_back(UNVISITED);
    }
    adjacencyList.resize(n + 1);
    checker.resize(n+1);
    string ab;
    cin>>ab;
    while(ab!="**")
    {

        char a = ab[0];
        char b = ab[1];
        int d = (int)a - 65;
        int e  = (int)b - 65;
        //cout<<d<<e<<endl;
        checker[counter] = (make_pair(d,e));
        counter++;
        //cout<<checker[counter].first<<checker[counter].second<<endl;
        adjacencyList[d].push_back(make_pair(e,10));
        adjacencyList[e].push_back(make_pair(d,10));

        cin>>ab;
    }
    for (int i = 0 ; i < counter; i++)
    {
        //cout<<checker[i].first<<checker[i].second<<endl;
        int xv1 = checker[i].first;
        int xv2 = checker[i].second;
        dfs(0,xv1,xv2);
        if (iscon==false)
        {
            char first = (char)(xv1+65);
            char second = (char)(xv2+65);
            tracker++;
            cout<<first<<second<<endl;
        }
        iscon = false;
        for (int i = 0; i < n; i++)
        {
        dfs_num[i] = UNVISITED;
        }
    }
    cout<<"There are "<<tracker<<" disconnecting roads.";
    return 0;
}

void dfs(int u,int xv1,int xv2)
{
    dfs_num[u] = VISITED;
    if(u== 1)
    {
        //cout<<"THIS IS IT:"<<endl;
        iscon = true;
        return;
    }
    for (int k = 0; k < (int)adjacencyList[u].size(); k++)
    {
        pair<int,int> v = adjacencyList[u][k];
        if (dfs_num[v.first]==UNVISITED)
        {
            if((u==xv1&&v.first==xv2)||(u==xv2&&v.first==xv1))
            {
                continue;
            }

            dfs(v.first,xv1,xv2);

        }
    }
}

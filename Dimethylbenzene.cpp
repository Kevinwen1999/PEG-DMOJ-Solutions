#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;
int N = 0, M = 0;
bool adj[25][25];
bool visited[25];
bool shit = false;
void dfs( int source, int tracker)
{
    visited[source] = true;
    for (int i = 1; i <= N; i++)
    {
        if (adj[source][i]==true)
        {
            if (visited[i]==true&&tracker+1==6)
            {
                shit = true;
                cout<<"YES"<<endl;
                return;
            }
            else if (visited[i] == false)
            {
                dfs(i,tracker+1);
            }
        }
    }
}
int main()
{
    cin>>N>>M;
    for (int i = 0 ; i < M; i++)
    {
        int a , b;
        cin>>a>>b;
        adj[a][b] = true;
        adj[b][a] = true;
    }
    for (int i = 1; i <= N; i++)
    {
        dfs(1,0);
        if (shit)
        {
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}

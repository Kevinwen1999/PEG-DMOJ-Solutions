#include <iostream>
using namespace std;
int N, M, A, B,from,to;
bool adj[2020][2020];
bool visited[2020];
void dfs(int i)
{
    visited[i] = true;
    for (int j = 1; j <= N; j++)
    {
        if (adj[i][j]&&!visited[j])
            dfs(j);
    }
}
int main()
{
    cin>>N>>M>>A>>B;
    for (int i = 0 ; i < M ; i++)
    {
        cin>>from>>to;
        adj[from][to] = true; adj[to][from] = true;
    }
    dfs(A);
    if (visited[B])
        cout<<"GO SHAHIR!"<<endl;
    else
        cout<<"NO SHAHIR!"<<endl;
}

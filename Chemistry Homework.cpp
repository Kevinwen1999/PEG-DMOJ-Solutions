#include <iostream>
using namespace std;
int N, M;
int adj[1001][1001];
int sz[1001];
bool visited[1001];
int Cn, Hn, engtot;
bool OK = true;
void dfs(int cur)
{
    if (!OK) return;
    visited[cur] = true;
    if (sz[cur] == 1) Hn++;
    if (sz[cur] == 4) Cn++;
    for (int i = 1; i <= N; i++)
    {
        if (adj[cur][i] && !visited[i])
        {
            if (sz[cur]==4 && sz[i] == 4 && adj[cur][i]==2)
                engtot+=615;
            else if (sz[cur]==4 && sz[i]==4 && adj[cur][i]==1)
                engtot+=346;
            else if ((sz[cur]==4 && sz[i]==1 && adj[cur][i]==1) || (sz[cur]==1 && sz[i]==4 && adj[cur][i]==1))
                engtot+=413;
            else
            {
                OK = false;
                return;
            }
            //dfs(i);
        }
    }
}
int main()
{
    cin>>N>>M;
    for (int i = 0 ; i < M; i++)
    {
        int a, b;
        cin>>a>>b;
        adj[a][b]++;
        adj[b][a]++;
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            sz[i] += adj[i][j];
        if (sz[i]!=1 && sz[i]!=4)
        {
            cout<<"Impossible";
            return 0;
        }
    }
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
    if (!OK)
    {
        cout<<"Impossible";
        return 0;
    }
    cout<<engtot<<"\n";
    cout<<"C"; if (Cn>1) cout<<Cn;
    cout<<"H"; if (Hn>1) cout<<Hn;
    cout<<"\n";
}

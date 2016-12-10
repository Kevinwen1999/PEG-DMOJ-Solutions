#include <bits/stdc++.h>
#define MAXN 5000
using namespace std;
int N, M, K;
int V;
vector <int> adj[5050];
bool visited[5050];
int main()
{
    cin>>N>>M>>K;
    V = N+M;
    for (int i = 0,a ,b; i < K; i++)
    {
        cin>>a>>b;
        b = b + N;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= N; i++)
    {
        memset(visited,0,sizeof visited);
        for (int j : adj[i])
        {
            for (int k : adj[j])
            {
                if (k==i) continue;
                if (!visited[k])
                    visited[k] = true;
                else
                {
                    cout<<"NO";
                    return 0;
                }
            }
        }
    }
    cout<<"YES";
}

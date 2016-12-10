#include <bits/stdc++.h>
using namespace std;

int N, M;
bool visited[1000001];
vector <int> adj[1000001];
bool taller(int start, int fin)
{
    memset(visited,0,sizeof visited);
    queue <int> q;
    q.push(start);
    visited[start] = true;
    int cur;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        if (cur == fin)
            return true;
        for (int i = 0 ; i < (int)adj[cur].size(); i++)
        {
            if (!visited[adj[cur][i]])
            {
                visited[adj[cur][i]] = true;
                q.push(adj[cur][i]);
            }
        }
    }
    return false;
}
int main()
{
    cin>>N>>M;
    for (int i = 0 ; i < M; i++)
    {
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    int s, e;
    cin>>s>>e;
    if (taller(s,e)) {cout<<"yes\n"; return 0;}
    else if (taller(e,s)) {cout<<"no\n"; return 0;}
    cout<<"unknown\n"; return 0;
}

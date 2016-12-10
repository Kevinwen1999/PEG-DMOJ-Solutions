#include <bits/stdc++.h>
using namespace std;
int E, Q;
unordered_map <char, int> M;
unordered_map <int, char> N;
vector <int> adj[30];
int tot;
int dist[30], pa[30];
void bfs(int st, int ed)
{
    memset(dist, 63, sizeof dist);
    memset(pa,-1,sizeof pa);
    queue <int> buff;
    buff.push(st);
    dist[st] = 0;
    while (!buff.empty())
    {
        int cur = buff.front();
        buff.pop();
        if (cur == ed) break;
        for (int i = 0; i < (int)adj[cur].size(); i++)
        {
            int v = adj[cur][i];
            if (dist[cur] + 1 < dist[v])
            {
                dist[v] = dist[cur] + 1;
                pa[v] = cur;
                buff.push(v);
            }
        }
    }
}
void print(int cur)
{
    if (cur == -1) return;
    print(pa[cur]);
    cout<<N[cur];
}
int main()
{
    cin>>E>>Q;
    string s1,s2;

    for (int i = 0; i < E; i++)
    {
        cin>>s1>>s2;
        char c1 = s1[0], c2 = s2[0];
        if (M.count(c1)==0) M[c1] = tot, N[tot++] = c1;
        if (M.count(c2)==0) M[c2] = tot, N[tot++] = c2;
        adj[M[c1]].push_back(M[c2]);
        adj[M[c2]].push_back(M[c1]);
    }
    for (int a = 0; a < Q; a++)
    {
        cin>>s1>>s2;
        char c1 = s1[0], c2 = s2[0];
        bfs(M[c1],M[c2]);
        print(M[c2]); cout<<"\n";
    }
}

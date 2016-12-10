#include <bits/stdc++.h>
using namespace std;
int N, M, K;
vector <int> adj[1000010];
bool visited[1000010];
bool cycle;
pair<int,int> cur;
int bfs(int st)
{
    queue<pair <int,int>> buff;
    buff.push({st,-1});
    visited[st] = true;
    int ans = 0;
    while (!buff.empty())
    {
        cur = buff.front();
        buff.pop();
        ans++;
        for (int ne : adj[cur.first])
        {
            if (ne == cur.second) continue;
            if (visited[ne])
            {
                cycle = true;
            }
            else
            {
                buff.push({ne, cur.first});
                visited[ne] = true;
            }
        }
    }
    return ans;
}
int totk, totc;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M>>K;
    for (int i = 0, a, b; i < M; i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            cycle = false;
            int tot = bfs(i);
            //cout<<tot<<endl;
            if (tot < K) continue;
            if (tot==K)
            {
                totk += tot;
            }
            else if (cycle)
            {
                if (tot % K == 0)
                {
                    totk += (tot/K)*K;
                    totc += tot/K;
                }
                else
                {
                    totk += (tot/K)*K;
                    totc += tot/K+1;
                }
            }
            else
            {
                if (tot % K == 0)
                {
                    totk += (tot/K)*K;
                    totc += tot/K-1;
                }
                else
                {
                    totk += (tot/K)*K;
                    totc += tot/K;
                }
            }
        }
    }
    cout<<totk<<" "<<totc;
}


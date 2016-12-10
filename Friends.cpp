#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#define INF 0x3f3f3f3f
using namespace std;
const int MAXN = 10001;
int N;
vector <int> adj[10001];
int dist[10001];
int main()
{
    cin>>N;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    int sa, sb;
    while (cin>>sa>>sb&&(sa||sb))
    {
        queue <int> buff;
        memset(dist, 63, sizeof dist);
        dist[sa] = -1;
        buff.push(sa);
        int cur,next;
        while (!buff.empty())
        {
            cur = buff.front();
            buff.pop();
            if (cur==sb) break;
            for (int i = 0 ; i < adj[cur].size(); i++)
            {
                next = adj[cur][i];
                if (dist[next]==INF)
                {
                    dist[next] = dist[cur]+1;
                    buff.push(next);
                }
            }
        }
        if (dist[sb]==INF)
            cout<<"No\n";
        else
            cout<<"Yes "<<dist[sb]<<"\n";
    }
}

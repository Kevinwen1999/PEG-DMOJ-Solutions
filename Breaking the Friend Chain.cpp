#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <vector>
#include <queue>

using namespace std;
const int MAXN = 10010;
int V, E;
int start, fin;
set<int> checked[MAXN];
vector <int> adjlist[MAXN];
queue <int> buff;
bool visited[MAXN];
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>V>>E;
    for (int i = 0 ; i < E; i++)
    {
        int a, b;
        cin>>a>>b;
        if (checked[a].count(b) > 0 || checked[b].count(a) > 0) continue;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
        checked[a].insert(b);
        checked[b].insert(a);
    }
    cin>>start>>fin;
    buff.push(start);
    visited[start] = true;
    while (!buff.empty())
    {
        int cur = buff.front();
        buff.pop();
        for (int i = 0 ; i < adjlist[cur].size(); i++)
        {
            int next = adjlist[cur][i];
            if (visited[next]) continue;
            visited[next] = true;
            buff.push(next);
        }
    }
    printf("%d\n", (visited[fin]) ? 1 : 0);
}

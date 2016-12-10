#include <bits/stdc++.h>
using namespace std;
int N, M;
vector <int> adj[10001];
bool entered[10001][10001];
bool per[10001], temp[10001];
bool flag = true;
void checktopo(int cur)
{
    if (temp[cur]){flag = false; return;}
    if (per[cur]) return;
    temp[cur] = true;
    for (int i = 0; i < (int)adj[cur].size(); i++)
    {
        checktopo(adj[cur][i]);
    }
    temp[cur] = false;
    per[cur] = true;
}
int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        if (entered[a][b]) continue;
        adj[a].push_back(b);
        entered[a][b] = true;
    }
    for (int i = 1; i <= N&&flag; i++)
    {
        if (!per[i])
            checktopo(i);
    }
    if (flag) printf("Y");
    else printf("N");
}

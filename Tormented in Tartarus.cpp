#include <bits/stdc++.h>
#define MAXN 5001
using namespace std;
pair <char, int> aq[200001], cp;
int N, M, K;
bitset <MAXN> now;
short sum[200001];
list <int> adj[200001];
multiset<int> p;
char cr[4] = {'F', 'D', 'R', 'X'};
void proc(int u)
{
    //cout<<u<<endl;
    bool change = false;
    if (aq[u].first==cr[0])
    {
        if (now[aq[u].second]==0)
        {
            sum[u]++;
            change = true;
            now[aq[u].second] = 1;
        }
    }
    if (aq[u].first==cr[1])
    {
        if (now[aq[u].second]==1)
        {
            sum[u]--;
            change = true;
            now[aq[u].second] = 0;
        }
    }
    if (aq[u].first==cr[3])
    {
        change = true;
        now.flip();
        sum[u] = N-sum[u];
    }
    for (int i: adj[u])
    {
        sum[i]=sum[u];
        proc(i);
    }
    if (u+1 <= M && aq[u+1].first!=cr[2])
        sum[u+1] = sum[u], proc(u+1);
    if (change)
    {
        if (aq[u].first==cr[0])
        {
            now[aq[u].second] = 0;
        }
        if (aq[u].first==cr[1])
        {
            now[aq[u].second] = 1;
        }
        if (aq[u].first==cr[3])
        {
            now.flip();
        }
    }
}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M>>K;
    aq[0] = {'q',0};
    char op; int v = 0;
    for (int a = 1; a <= M; a++)
    {
        cin>>op;
        if (op!='X') cin>>v;
        if (op=='R') adj[v].push_back(a);
        aq[a] = {op,v};
    }
    proc(0);
    int start = 0, fin = 1;
    short cursum, vv, maxx;
    multiset<int>::iterator it;
    for (int a = 1; a <= M; a++)
    {
        start++;
        cursum = sum[a];
        p.insert(cursum);
        if (start - fin == K)
        {
            vv = sum[fin];
            it = p.find(vv);
            p.erase(it);
            fin++;
        }
        it = p.end();
        it--;
        maxx = *it;
        cout<<cursum<<" "<<maxx<<"\n";
    }
}

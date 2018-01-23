#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define ll long long
#define MOD 1000000007
#define MAXN 1700
#define MAXM 5010
#define MAXNODE 600010
#define SIGMA 26
#define prm 100003
using namespace std;

int N, M;

int dist[MAXN], order[MAXN], toNode[MAXN], fromNode[MAXN], ans[MAXM];

struct edge {
    int to, wt, id;
};
vector <edge> adj[MAXN];
struct cmp {
   bool operator()(int a, int b) const {
       if (dist[a] == dist[b]) return a < b;
       return dist[a] < dist[b];
   }
};
void exec(int start) {
    memset(dist, 0x3f, sizeof dist);    
    set <int, cmp> s;
    int vis = 0;
    toNode[start] = 1;
    dist[start] = 0;
    s.insert(start);
    while(!s.empty()) {
        auto c = s.begin();
        s.erase(c);
        int u = *c;
        order[vis++] = u;
        for (auto i : adj[u]) {
            if (dist[i.to] < dist[u] + i.wt) continue;
            if (dist[i.to] > dist[u] + i.wt) {
                toNode[i.to] = 0;
                if (s.count(i.to)) s.erase(i.to);
                dist[i.to] = dist[u] + i.wt;
                s.insert(i.to);
            }
            toNode[i.to] = (toNode[i.to] + toNode[u]) % MOD;
        }
    }
    for (int i = vis - 1; i >= 0; i--) {
       int u = order[i];
       fromNode[u] = 1;
       for (auto j : adj[u]) {
           if (dist[u] + j.wt > dist[j.to]) continue;
           fromNode[u] += fromNode[j.to];
           ans[j.id] = (ans[j.id] + toNode[u] * fromNode[j.to]) % MOD;
       }
    }
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0, a, b, c; i < M; i++) {
        scanf("%d%d%d", &a, &b, &c);
        adj[a].push_back((edge){b, c, i});
        //adj[b].push_back((edge){a, c, i});
    }
    for (int i = 1; i <= N; i++) {
        exec(i);
    }
    for (int i = 0; i < M; i++) {
        printf("%d\n", ans[i]);
    }
}

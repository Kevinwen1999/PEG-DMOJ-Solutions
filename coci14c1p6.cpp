#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAXN 500010
#define ll long long
using namespace std;
int N, K;
vector <pair <int, int> > adj[MAXN];
bool needed[MAXN];
ll mx[MAXN], smx[MAXN], midx[MAXN], ans[MAXN];
ll totl;
bool dfs1(int u, int pa) {
    bool shit = false;
    shit |= needed[u];
    for (auto i : adj[u]) {
        int v = i.first;
        if (v == pa) continue;
        if (dfs1(v, u)) {
            shit = true;
            totl += i.second;
        }
    }
    return needed[u] = shit;
}
void dfs2(int u, int pa) {
    for (auto i : adj[u]) {
        int v = i.first, w = i.second;
        if (v == pa) continue;
        if (!needed[v]) continue;
        dfs2(v, u);
        if (mx[v] + w > mx[u]) {
            smx[u] = mx[u];
            mx[u] = mx[v] + w;
            midx[u] = v;
        } else if (mx[v] + w > smx[u]) {
            smx[u] = mx[v] + w;
        }
    }
}
void dfs3(int u, int pa, ll pmax) {
    if (needed[u]) 
        ans[u] = totl * 2 - max(pmax, mx[u]);
    for (auto i : adj[u]) {
        int v = i.first, w = i.second;
        if (v == pa) continue;
        if (!needed[v]) {
            ans[v] = ans[u] + w;
            dfs3(v, u, pmax);
            continue;
        }
        if (v == midx[u]) {
            dfs3(v, u, w + max(pmax, smx[u]));
        } else {
            dfs3(v, u, w + max(pmax, mx[u]));
        }
    }
}
int main() {
    cin >> N >> K;
    for (int i = 0, a, b, c; i < N - 1; i++) {
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    int st;
    for (int i = 0; i < K; i++) {
        int a; cin >> a;
        needed[a] = true;
        st = a;
    }
    dfs1(st, -1);
    dfs2(st, -1);
    dfs3(st, -1, 0);
    for (int i = 1; i <= N; i++)
        cout << ans[i] << "\n";
}

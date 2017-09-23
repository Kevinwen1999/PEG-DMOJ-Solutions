#include <bits/stdc++.h>
#define pii pair <int, int>
#define INF 0x3f3f3f3f
#define MAXN 100010
using namespace std;
int N, K;
int dist[MAXN], pa[MAXN];
vector <int> adj[MAXN];
set <pii> all;
void dfs(int cur, int &midx, int &mdist) {
    if (dist[cur] > mdist) {
        midx = cur;
        mdist = dist[cur];
    }
    for (int i : adj[cur]) {
        if (i == pa[cur]) continue;
        dist[i] = dist[cur] + 1;
        pa[i] = cur;
        dfs(i, midx, mdist);
    }
}
void mark_edge(int cur) {
    if (pa[cur] == -1) return;
    all.insert({min(cur, pa[cur]), max(cur, pa[cur])});
    mark_edge(pa[cur]);
}
int dp[MAXN][2];
bool visited[MAXN];
int maxdiameter;
void dpdfs(int cur) {
    visited[cur] = true;
    dp[cur][0] = 0;
    dp[cur][1] = 0;
    for (int i : adj[cur]) {
        if (visited[i]) continue;
        dpdfs(i);
        int v = all.count({min(cur, i), max(cur, i)}) ? -1 : 1;
        if (dp[i][0] + v >= dp[cur][0]) {
            dp[cur][1] = dp[cur][0];
            dp[cur][0] = dp[i][0] + v;
        } else if (dp[i][0] + v > dp[cur][1]) {
            dp[cur][1] = dp[i][0] + v;
        }
    }
    int ans = 0;
    ans += dp[cur][0];
    ans += dp[cur][1];
    maxdiameter = max(maxdiameter, ans);
}
int main() {
    cin >> N >> K;
    for (int i = 0, a, b; i < N - 1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int midx1 = 1, midx2, mdist = -INF;
    pa[1] = -1;
    dfs(1, midx1, mdist);
    mdist = -INF;
    memset(dist, 0, sizeof dist);
    memset(pa, 0, sizeof pa);
    pa[midx1] = -1;
    dfs(midx1, midx2, mdist);
    if (K == 1) {
       return cout << 2 * (N - 1) - mdist + 1, 0;
    } else {
        maxdiameter = -INF;
        mark_edge(midx2);
        dpdfs(1);
        return cout << 2 * (N - 1) - mdist + 1 - maxdiameter + 1, 0;
    }
}

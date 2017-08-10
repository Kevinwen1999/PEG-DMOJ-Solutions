#include <bits/stdc++.h>
#define MAXN 200010
#define ll long long
using namespace std;
int N, T;
int tot;
int maxpath[MAXN], secondmaxpath[MAXN], maxpathindex[MAXN], dp[MAXN];
vector <pair <int, int> > adj[MAXN];
void dfs(int cur, int par) {
    for (int i = 0 ; i < adj[cur].size(); i++) {
        auto next = adj[cur][i];
        if (next.first == par) continue;
        dfs(next.first, cur);
        if (maxpath[next.first] + next.second > maxpath[cur]) {
            secondmaxpath[cur] = maxpath[cur];
            maxpath[cur] = maxpath[next.first] + next.second;
            maxpathindex[cur] = next.first;
        }
        else if (maxpath[next.first] + next.second > secondmaxpath[cur]) {
            secondmaxpath[cur] = maxpath[next.first] + next.second;
        }
    }
}
void dpdfs(int cur, int par, int parmax) {
    dp[cur] = max(parmax, maxpath[cur]);
    for (int i = 0; i < adj[cur].size(); i++) {
        auto next = adj[cur][i];
        if (next.first == par) continue;
        if (next.first == maxpathindex[cur]) {
            dpdfs(next.first, cur, max(parmax, secondmaxpath[cur]) + next.second);
        }
        else {
            dpdfs(next.first, cur, max(parmax, maxpath[cur]) + next.second);
        }
    }
}
int main() {
    scanf("%d%d", &N, &T);
    for (int i = 0, a, b, c; i < N - 1; i++) {
        scanf("%d%d%d", &a, &b, &c);
        tot += c;
        adj[a].push_back({b, c}), adj[b].push_back({a, c});
    }
    tot *= 2;
    dfs(1, -1);
    dpdfs(1, -1, 0);
    for (int i = 1; i <= N; i++) {
        if (adj[i].size() == T) {
            printf("%d %d\n", i, tot - dp[i]);
        }
    }
}

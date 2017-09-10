#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define MMS(x, y) memset((x), (y), sizeof(x))
#define ll long long
#define vi vector <int>
#define pii pair <int, int>
#define EPS 1e-9

#define MAXN 100010

using namespace std;

int N;
int state[MAXN];
bool visited[MAXN];
vector<int> adj[MAXN];
pii dp[MAXN];
int cnt[MAXN];

void dfs(int cur) {
    if (visited[cur]) return;
    visited[cur] = true;
    cnt[cur] = 1;
    if (adj[cur].empty()) {
        if (state[cur] == 0) {
            dp[cur].first = 0;
            dp[cur].second = 1;
        } else if (state[cur] == 1) {
            dp[cur].first = 0;
            dp[cur].second = 0;
        } else {
            dp[cur].first = 1;
            dp[cur].second = 1;
        }
    } else if (state[cur] == 0) {
        pii a, b;
        b.first = b.second = 1;
        for (int i : adj[cur]) {
            dfs(i);
            cnt[cur] += cnt[i];
            a.first += dp[i].first;
            a.second += dp[i].second;
            b.first += cnt[i] - dp[i].second;
            b.second += cnt[i] - dp[i].first;
        }
        dp[cur].first = min(a.first, b.first);
        dp[cur].second = max(a.second, b.second);
    } else if (state[cur] == 1) {
        for (int i : adj[cur]) {
            dfs(i);
            cnt[cur] += cnt[i];
            dp[cur].first += dp[i].first;
            dp[cur].second += dp[i].second;
        }
    } else {
        dp[cur].first = dp[cur].second = 1;
        for (int i : adj[cur]) {
            dfs(i);
            cnt[cur] += cnt[i];
            dp[cur].first += cnt[i] - dp[i].second;
            dp[cur].second += cnt[i] - dp[i].first;
        }
    }
}

int main() {
    cin >> N;
    char op;
    string tmp;
    for (int i = 1; i <= N; i++) {
        cin >> op;
        if (op == 'C') {
            cin >> tmp;
            state[i] = (tmp == "?" ? 0 : (tmp == "AC" ? 1 : 2));
        } else {
            int id;
            cin >> id >> tmp;
            state[i] = (tmp == "?" ? 0 : (tmp == "AC" ? 1 : 2));
            adj[id].push_back(i);
        }
    }
    int a1 = 0, a2 = 0;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            dfs(i);
            a1 += dp[i].first;
            a2 += dp[i].second;
        }
    }
    cout << a1 << " " << a2 << "\n";
}

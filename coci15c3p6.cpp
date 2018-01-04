#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define INF 0x3f3f
#define MAXN 2010
#define pii pair <int, int>
#define vi vector <int>
#define ld long double
#define ll long long
using namespace std;
int N, K;
int g[MAXN][MAXN];
ll tot;
int sz, lsz;
ll mask[MAXN];
struct Dong {
    int x, y, nx, ny;
    int dir, sum;
    vector <pii> expand;
    Dong(int _x, int _y, int _dir) {
        x = _x, y = _y, dir = _dir;
        nx = x + dir, ny = y + (1 - dir);
        sum = g[x][y] + g[nx][ny];
    }
    void exp() {
        expand.push_back({x, y});
        expand.push_back({nx, ny});
    }
};
bool cmp(Dong &a, Dong &b) {
    return a.sum > b.sum;
}
bool intersect(Dong &a, Dong &b) {
    for (auto i : a.expand) {
        for (auto j : b.expand) {
            if (i == j) return true;
        }
    }
    return false;
}
vector <Dong> ap;
int ans;
void func(int pos, int cnt, int ctot, ll m) {
    if (pos == sz || cnt == K || ctot + (K - cnt) * ap[pos].sum < ans) return;
    for (int i = pos; i < sz; i++) {
        if (! (m & (1LL << i))) {
            ans = max(ans, ctot + ap[i].sum);
            func(i, cnt + 1, ctot + ap[i].sum, m | mask[i]);
        }
    }
}
int main() {
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &g[i][j]);
            tot += g[i][j];
        }
    }
    ap.reserve(N * N * 2);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i + 1 < N) ap.push_back(Dong(i, j, 1));
            if (j + 1 < N) ap.push_back(Dong(i, j, 0));
        }
    }
    // Pigeonhole principle, Dominos must be selected from the first 7(K - 1) + 1 ones
    sz = min(7 * (K - 1) + 1, (int)ap.size());
    sort(ap.begin(), ap.end(), cmp);
    for (int i = 0; i < sz; i++) {
        ap[i].exp();
    }
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            if (intersect(ap[i], ap[j])) {
                mask[i] |= (1LL << j);
            }
        }
    }
    func(0, 0, 0, 0LL);
    printf("%lld\n", tot - ans);
}


#include <iostream>
#include <cstring>
#include <deque>
#define MAXN 2010
#define INF 0x3f3f3f3f
#define ld long double
#define ll long long
using namespace std;
int N, C, tmp;
char in[MAXN][MAXN];
bool ori[MAXN][MAXN];
ll ans, dp[MAXN][MAXN];
ld g(int L, int K, int i) {
    ld ans = (ld)(dp[K][i - 1] - dp[L][i - 1] + (K * K) - (L * L)) / (ld)(2 * (K - L));
    return ans;
}
deque <int> dq, ndq;
int main() {
    scanf("%d %d", &N, &C);
    for (int i = 0; i < C; i++) {
        scanf("%s", in[i]);
        for (int j = 0; j < N; j++) {
            ori[i][j] = (in[i][j] == '1');
        }
    }
    for (int j = 0; j < C; j++) {
        if (ori[j][0]) {
            dp[j][0] = 0;
            dq.push_back(j);
        } else
            dp[j][0] = INF;
    }
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < C; j++) {
            if (!ori[j][i]) {
                dp[j][i] = INF;
                continue;
            }
            while (dq.size() >= 2 && g(dq[0], dq[1], i) <= (ld)j)
                dq.pop_front();
            dp[j][i] = dp[dq[0]][i - 1] + (1LL * j - dq[0]) * (1LL * j - dq[0]);
            while (ndq.size() >= 2 && g(ndq[ndq.size() - 2], ndq[ndq.size() - 1], i + 1) > g(ndq[ndq.size() - 1], j, i + 1))
                ndq.pop_back();
            ndq.push_back(j);
        }
        dq = ndq;
        ndq.clear();
    }
    memset(&ans, 0x3f, sizeof ans);
    for (int i = 0; i < C; i++) {
        if (ori[i][N - 1] && dp[i][N - 1] < ans)
            ans = dp[i][N - 1];
    }
    printf("%lld", ans);
}

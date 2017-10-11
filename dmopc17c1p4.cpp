#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define MMS(x, y) memset((x), (y), sizeof(x))
#define ll long long
#define vi vector <int>
#define pii pair <int, int>
#define EPS 1e-9
#define EPSS 1e-10

#define MAXN 5010
#define MAXL 5010
#define SEGN 300030
using namespace std;

int N;
int H;
ll A[MAXN];
ll g[MAXN], q[MAXN], h[MAXN], t[MAXN];
ll dp[2][MAXN];
bool visited[MAXN];
bool check[MAXN];
ll ans = 0;
int main() {
    scanf("%d %d", &N, &H);
    for (int i = 1; i <= N; i++) {
        cin >> g[i] >> h[i] >> q[i] >> t[i];
    }
    int flag = 0;
    for (int i = 1; i <= N; i++) {
        int rflag = 1 - flag;
        for (int j = 0; j <= H; j++) {
            if (j >= h[i]) {
                if (dp[rflag][j - h[i]] + g[i] >= dp[flag][j]) {
                    dp[flag][j] = dp[rflag][j - h[i]] + g[i];
                    check[j] = true;
                }
            }
            if (j >= t[i]) {
                if (check[j - t[i]] && dp[flag][j] <= dp[flag][j - t[i]] + q[i]) {
                    dp[flag][j] = dp[flag][j - t[i]] + q[i];
                    check[j] = true;
                }
            }
        }
        for (int j = 0; j <= H; j++) {
            dp[flag][j] = max(dp[flag][j], dp[rflag][j]);
            ans = max(ans, dp[flag][j]);
        }
        flag = rflag;
        memset(dp[flag], 0, sizeof dp[flag]);
        memset(check, 0, sizeof check);
    }
    cout << ans << "\n";
}

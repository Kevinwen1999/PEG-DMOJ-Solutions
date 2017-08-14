#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;
int N;
int in[MAXN];
int dp[MAXN][MAXN][2][2];
void DP(int st, int le, int pl) {
    if (dp[st][le][pl][pl] != -1 && dp[st][le][pl][1 - pl] != -1) return;
    dp[st][le][pl][pl] = 0;
    dp[st][le][pl][1 - pl] = 0;
    if (le == N) {
        return;
    }
    DP(st, le + 1, 1 - pl);
    DP((st - 1 + N) % N, le + 1, 1 - pl);
    if (dp[st][le + 1][1 - pl][1 - pl] < dp[(st - 1 + N) % N][le + 1][1 - pl][1 - pl]) {
        dp[st][le][pl][pl] = dp[st][le + 1][1 - pl][pl] + in[(st + le) % N];
        dp[st][le][pl][1 - pl] = dp[st][le + 1][1 - pl][1 - pl];
    } else {
        dp[st][le][pl][pl] = dp[(st - 1 + N) % N][le + 1][1 - pl][pl] + in[(st - 1 + N) % N];
        dp[st][le][pl][1 - pl] = dp[(st - 1 + N) % N][le + 1][1 - pl][1 - pl];
    }
}
int main() {
    memset(dp, -1, sizeof dp);
    cin>>N;
    for (int i = 0, a; i < N; i++) {
        cin>>a;
        in[i] = a % 2;
    }
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        DP(i, 1, 1);
        if (dp[i][1][1][0] + in[i] > dp[i][1][1][1])
            cnt++;
    }
    cout<<cnt<<"\n";
}

#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define MMS(x, y) memset((x), (y), sizeof(x))
#define ll long long
#define vi vector <int>
#define pii pair <int, int>
#define EPS 1e-9
#define EPSS 1e-10

#define MAXN 1010
#define MAXL 5
#define SEGN 300030

using namespace std;
char in[MAXN];
int S;
int N;
int dp[MAXN][MAXN * 5];
int last[MAXN];
pii nxt[MAXN][MAXN * 5];
int sti (int i, int len) {
    int sum = 0;
    for (int j = 0; j < len; j++) {
        sum *= 10;
        sum += in[i + j] - '0';
    }
    return sum;
}
int recur (int cur, int rem) {
    if (rem < 0) return INF;
    if (cur == N) {
        if (rem == 0) return 0;
        else return INF;
    }
    if (~dp[cur][rem]) return dp[cur][rem];
    int &ans = dp[cur][rem];
    ans = INF;
    int tmp = 0;
    for (int i = last[cur]; i < N; i++) {
        tmp *= 10;
        tmp += in[i] - '0';
        if (tmp > rem) break;
        if (ans > recur(i + 1, rem - tmp) + 1) {
            ans = recur(i + 1, rem - tmp) + 1;
            nxt[cur][rem] = {i + 1, rem - tmp};
        }
    }
    return ans;
}
int main() {
    scanf("%[^=]=%d", in, &S);
    N = strlen(in);
    last[N - 1] = N - 1;
    for (int i = N - 2; i >= 0; i--) {
        last[i] = (in[i] == '0') ? last[i + 1] : i;
    }
    memset(dp, -1, sizeof dp);
    recur(0, S);
    pii c = {0, S}, n;
    while (c.first != N) {
        n = nxt[c.first][c.second];
        printf("%.*s", n.first - c.first, in + c.first);
        c = n;
        if (c.first == N) break;
        printf("+");
    }
    printf("=%d\n", S);
}
crci07p4

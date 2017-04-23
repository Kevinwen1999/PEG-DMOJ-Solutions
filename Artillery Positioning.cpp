#include <bits/stdc++.h>
#define MAXM 110
#define INF 0x3f3f3f3f
using namespace std;
int N, M;
inline bool valid (int i) {
    return (i >= 0 && i < M);
}
inline bool biton(int mask, int i) {
    return mask & (1<<i);
}
int calc(int mask) {
    int cnt = 0;
    for (int i = 0; i < M; i++)
        if (mask & (1<<i))
            cnt++;
    return cnt;
}
int totm, ans = -INF;
int allm[MAXM];
int bitot[MAXM];
int dp[MAXM][MAXM][MAXM];
char grid[MAXM][MAXM];
int bgrid[MAXM];
void computeState(int n) {
    int mask = 0;
    int c;
    for (int i = 0; i < (1<<n); i++) {
        bool OK = true;
        for (int j = 0; j < n && OK; j++) {
            if (!biton(i, j)) continue;
            c = j - 2;
            if (valid(c) && biton(i,c)) OK = false;
            c = j - 1;
            if (valid(c) && biton(i,c)) OK = false;
            c = j + 1;
            if (valid(c) && biton(i,c)) OK = false;
            c = j + 2;
            if (valid(c) && biton(i,c)) OK = false;
        }
        if (!OK) continue;
        bitot[totm] = calc(i);
        allm[totm++] = i;
    }
}
int main() {
    cin>>N>>M;
    computeState(M);
//    cout<<totm<<"\n";
    for (int i = 1; i <= N; i++)
        cin>>grid[i];
    for (int i = 1; i <= N; i++) {
        int mask = 0;
        for (int j = 0; j < M; j++) {
//            cout<<grid[i][j]<<" ";
            if (grid[i][j] == 'H')
                mask = mask | (1<<j);
        }
//        cout<<"\n";
        bgrid[i] = mask;
    }
    memset(dp, -1, sizeof dp);
    dp[0][0][0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < totm; j++) {
            if (allm[j] & bgrid[i]) continue;
            for (int k = 0; k < totm; k++) {
                for (int l = 0; l < totm; l++) {
                    if (allm[k] & allm[l]) continue;
                    if (allm[k] & allm[j]) continue;
                    if (allm[l] & allm[j]) continue;
                    if (dp[i-1][k][l] == -1) continue;
                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][k][l] + bitot[j]);
                    ans = max(ans, dp[i][j][k]);
                }
            }
        }
    }

    cout<<ans<<"\n";
}

#include <bits/stdc++.h>
#define MAXN 2010
#define ld long double
using namespace std;
struct edge {
    int to, x, y;
} tin;
vector <edge> adj[MAXN];
int N, M, T;
ld dp[MAXN][MAXN];
int main() {
    cin>>N>>M>>T;
    for (int i = 0, a; i < M; i++) {
        cin>>a>>tin.to>>tin.x>>tin.y;
        if(a != N){
            adj[a].push_back(tin);
        }
    }
    dp[0][1] = 1.0;
    dp[1][1] = -1.0;
    for (int i = 0; i <= T; i++) {
        for (int j = 1; j <= N; j++) {
            if (i != 0) dp[i][j] += dp[i - 1][j];
            for (edge k : adj[j]) {
                if (k.x + i > T) continue;
                ld qi = (k.y - k.x + 1) * (int)adj[j].size();
                ld prob = (1.0 / qi) * dp[i][j];
                dp[k.x + i][k.to] += prob;
                dp[min(k.y + i + 1, T + 1)][k.to] -= prob;
            }
        }
    }
    ld no = 0.0, deno = 0.0;
    for (int t = 1; t <= T; t++) {
        no += t * dp[t][N];
        deno += dp[t][N];
    }
    ld ex = no / deno;
    cout<<fixed<<setprecision(10)<<ex<<"\n";
}

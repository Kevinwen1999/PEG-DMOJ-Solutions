#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define ll long long
#define MOD 1000000007
#define MAXN 20010
#define MAXK 110
#define MAXNODE 600010
#define SIGMA 26
#define prm 100003
using namespace std;

int N, K, sz;
int ch[MAXN][SIGMA];
char in[MAXN];
int pro[MAXN];
int depth[MAXN];
int ans[MAXN][MAXK], tans[MAXN][MAXK];
bool ending[MAXN];

inline int gc(char c) {
    return c - 'a';
}

void init() {
    sz = 1;
    memset(ch, -1, sizeof ch);
    memset(ending, 0, sizeof ending);
}

void insert() {
    int n = strlen(in);
    int u = 0;
    for (int i = 0; i < n; i++) {
        if (ch[u][pro[i]] == -1) {
            depth[sz] = depth[u] + 1;
            ch[u][pro[i]] = sz++;
        }
        u = ch[u][pro[i]];
    }
    ending[u] = true;
}

void solve(int u) {
   memset(ans[u], 0x3f, sizeof ans[u]);
   ans[u][0] = 0;
   for (int i = 0; i < SIGMA; i++) {
       if (ch[u][i] == -1) continue;
       memset(tans[u], 0x3f, sizeof tans[u]);
       solve(ch[u][i]);
       for (int j = 0; j <= K; j++) {
           for (int k = 0; k <= K - j; k++) {
               tans[u][j + k] = min(tans[u][j + k], ans[u][j] + ans[ch[u][i]][k]);
           }
       }
       memcpy(ans[u], tans[u], sizeof tans[u]);
   }
   if (ending[u]) 
       for (int i = K; i >= 1; i--)
           ans[u][i] = min(ans[u][i], ans[u][i - 1] + depth[u]);
   if (u) ans[u][1] = depth[u];
}

int exec() {
    scanf("%d%d", &N, &K);
    init();
    for (int i = 0; i < N; i++) {
        scanf("%s", in);
        for (int i = 0; i < strlen(in); i++) {
            pro[i] = gc(in[i]);
        }
        insert();
    }
    solve(0);
    return ans[0][K];
}

int main() {
    int T; scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        printf("Case #%d: %d\n", i, exec());
    }
}

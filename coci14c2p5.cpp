#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAXN 710
#define ld long double
#define ll long long
using namespace std;
int N;
int B[MAXN][MAXN], V[MAXN][MAXN];
int toint[MAXN][MAXN];
int di[] = {0, 1};
int dj[] = {1, 0};
ld intercept(int i, int j, int ni, int nj) {
    if (B[i][j] == B[ni][nj] && V[i][j] == V[ni][nj]) return INF;
    if (B[i][j] == B[ni][nj]) return 0.0;
    if (B[i][j] != B[ni][nj] && V[i][j] == V[ni][nj]) return -1;
    ld x = (ld)(B[ni][nj] - B[i][j]) / (ld)(V[i][j] - V[ni][nj]);
    return x;
}
int p[MAXN * MAXN], rnk[MAXN * MAXN], sz[MAXN * MAXN], op[MAXN * MAXN], ornk[MAXN * MAXN], osz[MAXN * MAXN];
ld last[MAXN * MAXN];
ld curt;
int mxsz;
void init(int N) {
    mxsz = 0;
    for (int i = 0; i <= N; i++)
        p[i] = i, rnk[i] = 1, sz[i] = 1;
}
int findp(int x) {
    if (last[x] != curt) {
        last[x] = curt;
        p[x] = op[x], rnk[x] = ornk[x], sz[x] = osz[x];
    }
    return p[x] == x ? x : (p[x] = findp(p[x]));
}
bool sameset(int x, int y) {
    return findp(x) == findp(y);
}
void mergeset(int x, int y) {
    if (!sameset(x, y)) {
        x = findp(x), y = findp(y); // EXTREMELY IMPORTANT !!!!!!!!!
        if (rnk[x] > rnk[y])
            rnk[x] += rnk[y], p[y] = x, sz[x] += sz[y], mxsz = max(mxsz, sz[x]);
        else
            rnk[y] += rnk[x], p[x] = y, sz[y] += sz[x], mxsz = max(mxsz, sz[y]);
    }
}
unordered_map <ld, vector <pair <int, pair <int, int> > > > mmp;
vector <pair <int, pair <int, int> > > wow;
int maxans = 0;
int main() {
    //freopen("output1.txt", "r", stdin);
    scanf("%d", &N);
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            toint[i][j] = cnt++;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &V[i][j]);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
           for (int k = 0; k < 2; k++) {
                int ni = i + di[k], nj = j + dj[k];
                if (ni == N || nj == N) continue;
                ld x = intercept(i, j, ni, nj);
                if (x < 0) continue;
                //printf("%.2lf %d %d %d %d\n", x, i, j, ni, nj);
                if (x != INF) mmp[x].push_back(make_pair(k, make_pair(i, j)));
                else wow.push_back(make_pair(k, make_pair(i, j)));
           }
        }
    }
    init(N * N);
    for (int i = 0; i <= N * N; i++)
        last[i] = -1;
    curt = -1;
    for (auto &edge : wow) {
        int i = edge.second.first, j = edge.second.second;
        int ni = i + di[edge.first], nj = j + dj[edge.first];
        mergeset(toint[i][j], toint[ni][nj]);
    }
    memcpy(op, p, sizeof p);
    memcpy(ornk, rnk, sizeof rnk);
    memcpy(osz, sz, sizeof sz);
    for (auto &a : mmp) {
        curt = a.first;
        for (auto &edge : a.second) {
            int i = edge.second.first, j = edge.second.second;
            int ni = i + di[edge.first], nj = j + dj[edge.first];
            mergeset(toint[i][j], toint[ni][nj]);
        }
        maxans = max(maxans, mxsz);
    }
    cout << maxans << "\n";
}

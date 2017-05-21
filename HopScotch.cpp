#include <bits/stdc++.h>
#define MAXN 200010
#define MAXQ 450
using namespace std;
int N, Q;
int sq;
int A[MAXN];
int sumblk[MAXN];
int blk[MAXN];
int nextidx[MAXN];
vector <int> inblk[MAXQ];
set <int> ts;
void eval(int cur, int &b, int& sum, int &ori) {
    if (cur >= N || blk[cur] != b) {
        nextidx[ori] = cur;
    }
    else {
        sum += 1;
        eval(cur + A[cur], b, sum, ori);
    }
}
int query(int st) {
    int cnt = 0;
    while (st < N) {
        cnt += sumblk[st];
        st = nextidx[st];
    }
    return cnt;
}
void update(int idx, int val) {
    ts.clear();
    int tmp = sumblk[idx];
    A[idx] = val;
    sumblk[idx] = 0;
    eval(idx, blk[idx], sumblk[idx], idx);
    tmp = sumblk[idx] - tmp;
    for (int i = idx-1; i >= 0 && blk[i] == blk[idx]; i--) {
        if (i + A[i] == idx || ts.count(i + A[i])) {
            sumblk[i] += tmp;
            nextidx[i] = nextidx[idx];
            ts.insert(i);
        }
    }
}
int main() {
    scanf("%d", &N);
    sq = sqrt(N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        blk[i] = i/sq;
        inblk[blk[i]].push_back(i);
    }
    for (int i = 0; i < N; i++) {
        eval(i, blk[i], sumblk[i], i);
    }
    scanf("%d", &Q);
    for (int j = 0, op, x, v; j < Q; j++) {
        scanf("%d%d", &op, &x);
        if (op == 1) {
            printf("%d\n",query(x));
        }
        else {
            scanf("%d", &v);
            update(x, v);
        }
    }
}

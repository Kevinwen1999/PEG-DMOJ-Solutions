#include <bits/stdc++.h>
#define MAXN 250010
using namespace std;
int N, Q;
char in[MAXN];
struct t {
    int times[10];
    int sum;
} node[4*MAXN];
int lazy[4*MAXN];
int tmp[10];
void build(int sid, int L, int R) {
    if (L == R) {
        node[sid].times[in[L] - '0']++;
        node[sid].sum = in[L] - '0';
//        cout<<L<<" "<<sid<<" "<<node[sid].sum<<"\n";
        return;
    }
    build(sid << 1, L, (L + R) / 2);
    build(sid << 1 | 1, (L + R) / 2 + 1, R);
    for (int i = 0; i < 10; i++) {
        node[sid].times[i] = node[sid << 1].times[i] + node[sid << 1 | 1].times[i];
    }
    node[sid].sum = node[sid << 1].sum + node[sid << 1 | 1].sum;
}
void pushdown(int sid, int val, int L, int R) {
    for (int i = 0; i < 10; i++)
        tmp[(i + val) % 10] = node[sid].times[i];
    for (int i = 0; i < 10; i++)
        node[sid].times[i] = tmp[i];
    node[sid].sum = 0;
    for (int i = 0; i < 10; i++)
        node[sid].sum += node[sid].times[i] * i;
    if (L != R) {
        lazy[sid << 1] += val;
        lazy[sid << 1 | 1] += val;
    }
}
void update(int sid, int L, int R, int ql, int qr, int val) {
    if (lazy[sid] != 0) {
        pushdown(sid, lazy[sid], L, R);
        lazy[sid] = 0;
    }
    if (L > qr || R < ql)
        return;
    if (L >= ql && R <= qr) {
        pushdown(sid, val, L, R);
        return;
    }
    int mid = (L + R) / 2;
    update(sid << 1, L, mid, ql, qr, val);
    update(sid << 1 | 1, mid + 1, R, ql, qr, val);
    for (int i = 0; i < 10; i++)
        node[sid].times[i] = node[sid << 1].times[i] + node[sid << 1 | 1].times[i];
    node[sid].sum = 0;
    for (int i = 0; i < 10; i++)
        node[sid].sum += node[sid].times[i] * i;
}
int query (int sid, int L, int R, int ql, int qr) {
    if (lazy[sid] != 0) {
        pushdown(sid, lazy[sid], L, R);
        lazy[sid] = 0;
    }
    if (L > qr || R < ql)
        return 0;
    if (L >= ql && R <= qr)
        return node[sid].sum;
    //else do it the old way
    int mid = (L + R) / 2;
    return query(sid << 1, L, mid, ql, qr) + query(sid << 1 | 1, mid + 1, R, ql, qr);
}
int main() {
    scanf("%d %d", &N, &Q);
    scanf("%s", in);
    build(1, 0, N - 1);
    for (int i = 0, a, b; i < Q; i++) {
        scanf("%d %d", &a, &b);
        a--; b--;
        printf("%d\n", query(1, 0, N - 1, a, b));
//        for (int i = 0; i < N; i++)
//            cout<<node[i + N].sum<<" ";
//        cout<<"\n";
        update(1, 0, N - 1, a, b, 1);
    }
}

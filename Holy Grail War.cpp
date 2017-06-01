#include <bits/stdc++.h>
#define MAXN 100010
#define MID (L+R)/2
#define ll long long
using namespace std;

ll INF = 0x3f3f3f3f;
struct nd {
    ll sum = 0;
    ll lmax = 0;
    ll rmax = 0;
    ll cmax = 0;
} node[4*MAXN];
ll A[MAXN];

void build(int stidx, int L, int R) {
    if (L == R) {
        node[stidx].sum = node[stidx].lmax = node[stidx].rmax = node[stidx].cmax = A[L];
        return;
    }
    int li = stidx << 1, ri = stidx << 1 | 1;
    build(li, L, MID);
    build(ri, MID + 1, R);
    node[stidx].sum = node[li].sum + node[ri].sum;
    node[stidx].cmax = max(node[li].cmax, node[ri].cmax);
    node[stidx].cmax = max(node[stidx].sum, node[stidx].cmax);
    node[stidx].lmax = max(node[li].lmax, node[li].sum + node[ri].lmax);
    node[stidx].rmax = max(node[ri].rmax, node[ri].sum + node[li].rmax);
    node[stidx].cmax = max(node[stidx].cmax, max(node[stidx].lmax, node[stidx].rmax));
    node[stidx].cmax = max(node[stidx].cmax, node[li].rmax + node[ri].lmax);
    node[stidx].cmax = max(-INF, node[stidx].cmax);
    node[stidx].lmax = max(-INF, node[stidx].lmax);
    node[stidx].rmax = max(-INF, node[stidx].rmax);
}
void update(int stidx, int L, int R, int idx, ll val) {
    if (L==R) {
        node[stidx].sum = node[stidx].lmax = node[stidx].rmax = node[stidx].cmax = A[L] = val;
        return;
    }
    int li = stidx << 1, ri = stidx << 1 | 1;
    if (idx <= MID)
        update(li, L, MID, idx, val);
    else
        update(ri, MID + 1, R, idx, val);
    node[stidx].sum = node[li].sum + node[ri].sum;
    node[stidx].cmax = max(node[li].cmax, node[ri].cmax);
    node[stidx].cmax = max(node[stidx].sum, node[stidx].cmax);
    node[stidx].lmax = max(node[li].lmax, node[li].sum + node[ri].lmax);
    node[stidx].rmax = max(node[ri].rmax, node[ri].sum + node[li].rmax);
    node[stidx].cmax = max(node[stidx].cmax, max(node[stidx].lmax, node[stidx].rmax));
    node[stidx].cmax = max(node[stidx].cmax, node[li].rmax + node[ri].lmax);
    node[stidx].cmax = max(-INF, node[stidx].cmax);
    node[stidx].lmax = max(-INF, node[stidx].lmax);
    node[stidx].rmax = max(-INF, node[stidx].rmax);
}
nd query (int stidx, int L, int R, int i, int j) {
    nd ans, a1, a2;
    if (j < L || i > R) {
        ans.sum = ans.lmax = ans.rmax = ans.cmax = -INF;
//        printf("fuck\n");
        return ans;
    }
    if (L >= i && R <= j) {
//        printf("shit\n");
        return node[stidx];
    }
    int li = stidx << 1, ri = stidx << 1 | 1;
    a1 = query(li, L, MID, i, j);
    a2 = query(ri, MID + 1, R, i, j);
    ans.sum = a1.sum + a2.sum;
    ans.cmax = max(ans.sum, max(a1.cmax, a2.cmax));
    ans.lmax = max(a1.lmax, a1.sum + a2.lmax);
    ans.rmax = max(a2.rmax, a2.sum + a1.rmax);
    ans.cmax = max(ans.cmax, max(ans.lmax, ans.rmax));
    ans.cmax = max(ans.cmax, a1.rmax + a2.lmax);
    ans.cmax = max(-INF, ans.cmax);
    ans.lmax = max(-INF, ans.lmax);
    ans.rmax = max(-INF, ans.rmax);
//    printf("in interval %d, %d: , sum is %lld,\n left sum is %lld and max is %lld,\n right sum is %lld and max is %lld\n", L, R, ans.sum, a1.sum, a1.cmax, a2.sum, a2.cmax);
    return ans;
}

int N, Q;
char op;
int main () {
    scanf("%d%d", &N, &Q);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
//        printf("%lld\n", A[i]);
    }
    build(1, 0, N - 1);
    ll b;
    for (int i = 0, a; i < Q; i++) {
        scanf(" %c %d %lld", &op, &a, &b);
        if (op == 'S') {
            update(1, 0, N - 1, a - 1, b);
        } else {
            nd ans = query(1, 0, N - 1, a - 1, b - 1);
            printf("%lld\n", ans.cmax);
        }
    }
}

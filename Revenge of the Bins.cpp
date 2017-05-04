#include <bits/stdc++.h>
#define MAXN 100010
#define INF 0x3f3f3f3f
using namespace std;
struct node {
    int l;
    int r;
    int sum = 0;
    int minn = INF;
};
node seg[10*MAXN];
int N;
inline int rev(int a) {return N + 1 - a;}
int hx[MAXN], xh[MAXN], A[MAXN];

void build (int L, int R, int sid) {
    if (L == R) {
        seg[sid].l = seg[sid].r = L;
        seg[sid].minn = seg[sid].sum = A[L];
        return;
    }
    seg[sid].l = sid << 1;
    seg[sid].r = (sid << 1) | 1;
    int mid = (L + R) / 2;
    build(L, mid, seg[sid].l);
    build(mid+1, R, seg[sid].r);
    seg[sid].minn = min(seg[seg[sid].l].minn,  seg[seg[sid].l].sum + seg[seg[sid].r].minn);
    seg[sid].sum = seg[seg[sid].l].sum + seg[seg[sid].r].sum;
}
void update (int L, int R, int idx, int sid) {
    if (L == R) {
        seg[sid].minn = seg[sid].sum = A[L];
        return;
    }
    int mid = (L + R) / 2;
    if (idx <= mid) {
        update(L, mid, idx, seg[sid].l);
    }
    else {
        update(mid+1, R, idx, seg[sid].r);
    }
    seg[sid].minn = min(seg[seg[sid].l].minn,  seg[seg[sid].l].sum + seg[seg[sid].r].minn);
    seg[sid].sum = seg[seg[sid].l].sum + seg[seg[sid].r].sum;
}
int query(int L, int R, int i, int j, int sid) {
    if (i > R || j < L) return INF;
    if (L >= i && R <= j) return seg[sid].minn;
    int p1 = INF, p2 = INF;
    int mid = (L + R) / 2;
    p1 = query(L, mid, i, j, seg[sid].l);
    p2 = query(mid+1, R, i, j, seg[sid].r);
    return min(p1, p2);
}
int main () {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    int x = N/2;
    for (int i = 1; i <= N; i++) {
        A[i] = 1;
    }
    for (int i = 1, a; i <= N; i++) {
        cin>>a;
        hx[a] = i;
        xh[i] = a;
        if (i > x) {
            A[rev(a)] = -1;
        }
    }
    build(1, N, 1);
    if (seg[1].minn >= 0) {
        cout<<x;
        return 0;
    }

    for (int i = x-1; i > 0; i--) {

        A[rev(xh[2 * i + 1])] = 0;
        A[rev(xh[2 * i + 2])] = 0;
        A[rev(xh[i + 1])] += -2 * A[rev(xh[i + 1])];

        update(1, N, rev(xh[2 * i + 1]), 1);
        update(1, N, rev(xh[2 * i + 2]), 1);
        update(1, N, rev(xh[i + 1]), 1);

        if (seg[1].minn >=0) {
            cout<<i;
            return 0;
        }
    }
    cout<<0<<"\n";
}

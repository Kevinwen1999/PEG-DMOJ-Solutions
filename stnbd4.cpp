#include <bits/stdc++.h>
#define MAXN 100010
#define ll long long
using namespace std;
ll bt[MAXN];
int N, Q, cnt = 1;
ll A[MAXN], ans[MAXN];
set <ll> v;
unordered_map <ll, int> um;
int BLK = 316;
ll sum = 0;
int lidx = 0, ridx = 1;
void upd(int x, int k, ll bit[]) {
    for (;x < cnt; x += (x & -x))
        bit[x] += k;
}
int qry(int x, ll bit[])  {
    ll s = 0;
    for (; x > 0; x -= (x & -x))
        s += bit[x];
    return s;
}
struct query {
    int l;
    int r;
    int idx;
};
vector <query> aq;
void hashu() {
    for (auto i : v) {
        um[i] = cnt++;
    }
    for (int i = 1; i <= N; i++) {
        A[i] = um[A[i]];
    }
}
bool MoSort(query &c, query &b) {
    if (c.l / BLK == b.l / BLK) {
        return c.r < b.r;
    }
    return c.l / BLK < b.l / BLK;
}
void add(int idx, int op) {
    upd(A[idx], 1, bt);
    sum += op ? ridx - lidx + 1 - qry(A[idx], bt) : qry(A[idx] - 1, bt);
}
void del(int idx, int op) {
    upd(A[idx], -1, bt);
    sum -= op ? ridx - lidx + 1 - qry(A[idx], bt) : qry(A[idx] - 1, bt);
}
void doMO(int cl, int cr) {
    while (lidx < cl) {
        del(lidx++, 0);
    }
    while (ridx < cr) {
        add(++ridx, 1);
    }
    while (lidx > cl) {
        add(--lidx, 0);
    }
    while (ridx > cr) {
        del(ridx--, 1);
    }
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    BLK = sqrt(N);
    for (int i = 1; i <= N; i++) {
        cin>>A[i];
        v.insert(A[i]);
    }
    hashu();
    cin>>Q;
    for (int i = 0, x, y; i < Q; i++) {
        cin>>x>>y;
        aq.push_back((query){x, y, i});
    }
    sort(aq.begin(), aq.end(), MoSort);
    int preR = -1;
    for (query &q : aq) {
        if (q.l / BLK != preR) {
            memset(bt, 0, sizeof bt);
            lidx = ridx = q.l;
            add(lidx, 0);
            sum = 0;
            preR = q.l / BLK;
        }
        doMO(q.l, q.r);
        ans[q.idx] = sum;
    }
    for (int i = 0; i < Q; i++)
        printf("%lld\n", ans[i]);
    return 0;
}

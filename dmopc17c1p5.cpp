#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define MMS(x, y) memset((x), (y), sizeof(x))
#define ll long long
#define vi vector <int>
#define pii pair <int, int>
#define EPS 1e-9
#define EPSS 1e-10

#define MAXN 1000010
#define MAXL 5010
#define SEGN 300030
using namespace std;

int bit[MAXN];
void update(int x, int v) {
    for (;x < MAXN; x += (x & -x))
        bit[x] += v;
}
int query(int a) {
    int sum = 0;
    for (; a > 0; a -= (a & -a))
        sum += bit[a];
    return sum;
}
int N, Q;
int A[MAXN];
struct query {
    int l;
    int r;
    int ans;
    int id;
} aq[MAXN];
vector <pair <int, int> > qn[MAXN];
int idx[MAXN];
int main() {
    scanf("%d %d", &N, &Q);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
        idx[A[i]] = i;
    }
    for (int i = 0; i < Q; i++) {
        scanf("%d %d", &aq[i].l, &aq[i].r);
        aq[i].id = i;
        qn[aq[i].l].push_back({aq[i].r, i});
    }
    deque <int> mono;
    for (int i = N; i; i--) {
        while (!mono.empty() && mono.front() < A[i]) {
            update(idx[mono.front()], -1);
            mono.pop_front();
        }
        mono.push_front(A[i]);
        update(idx[mono.front()], 1);
        for (auto j : qn[i]) {
            int tr = j.first, tid = j.second;
            aq[tid].ans = query(tr);
        }
    }
    for (int i = 0; i < Q; i++)
        printf("%d\n", aq[i].ans);
}

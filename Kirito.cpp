#include <bits/stdc++.h>
#define MAXN 2010
#define MAXM 5010
#define seed 31
#define ull unsigned long long
using namespace std;
int N, M;
int ori[MAXN][MAXM];

vector <ull> bases[MAXN];
int mp[MAXN];
int node[4*MAXN];

int findlow (int a, int b, int l, int h) {
    int ans = -1;

    while (l <= h) {
        int mid = (l + h) >> 1;

        if (bases[a][mid] == bases[b][mid]) {
            ans = mid;
            l = mid + 1;
        } else {
            h = mid - 1;
        }
    }

    return ans;
}

void build(int stidx, int L, int R) {

    if (L == R) {
        node[stidx] = M - 1;
        return;
    }

    int mid = (L + R) >> 1;

    build(stidx << 1, L, mid);
    build((stidx << 1) + 1, mid + 1, R);

    node[stidx] = findlow(mp[L], mp[R], 0, min(node[stidx << 1], node[(stidx << 1) + 1]));
}

int query(int stidx, int L, int R, int i, int j) {
    if (i > R || j < L) return -2;
    if (L >= i && R <= j) return node[stidx];

    int mid = (L + R) >> 1;
    int p1 = query(stidx << 1, L, mid, i, j);
    int p2 = query((stidx << 1) + 1, mid + 1, R, i, j);

    if (p1 == -2) return p2;
    else if (p2 == -2) return p1;

    return findlow(mp[max(L, i)], mp[min(R, j)], 0, min(p1, p2));
}

void update(int stidx, int L, int R, int idx) {
    if (L == R) {
        return;
    }

    int mid = (L + R) >> 1;

    if (idx <= mid) update(stidx << 1, L, mid, idx);
    else update((stidx << 1) + 1, mid+1, R, idx);

    node[stidx] = findlow(mp[L], mp[R], 0, min(node[stidx << 1], node[(stidx << 1) + 1]));
}

void hasshu(string& cur, int id) {
    int h = 1;
    for (int i = 0; i < cur.size(); i++) {
        h = h * seed + cur[i] - '0';
        bases[id].push_back(h);
    }
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        string tmp;
        cin >> tmp;
        mp[i] = i;
        hasshu(tmp, i);
    }
    build(1,1,N);
    int Q;
    cin >> Q;
    for (int i = 0, a, b; i < Q; i++) {
        cin >> a >> b;
        printf("%d\n", (query(1,1,N,a,b) + 1) * (b - a + 1));
        swap(mp[a], mp[b]);
        update(1,1,N,a);
        update(1,1,N,b);
    }
}

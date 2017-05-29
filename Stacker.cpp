#include <bits/stdc++.h>
#define MAXN 1000001
#define ll long
using namespace std;
int N, cl, r;
vector <ll> hx;
ll t[2000000];
//ll query(int stidx, int L, int R, int &i, int &j) {
//    if (i > j) return 0;
//    if (i > R || j < L) return 0; //out of range
//    if (L >= i && R <= j) return seg[stidx];
//    int mid = (L + R) / 2;
//    return max(query(2*stidx, L, mid, i,j),  query(2*stidx + 1, mid + 1, R, i,j));
//}
//void update(int stidx, int L, int R, int &idx, ll &val) {
//    if (L == R) {
//        seg[stidx] = max(seg[stidx], val);
//        return;
//    }
//    int mid = (L + R) / 2;
//    if (idx <= mid)
//        update(stidx<<1, L, mid, idx, val);
//    else
//        update(stidx<<1 | 1, mid + 1, R, idx, val);
//    seg[stidx] = max(seg[stidx<<1], seg[stidx<<1|1]);
//}

void update(int p, ll &val) {  // set value at position p
    p += N;
    for (t[p] = max(t[p], val); p > 1; p >>= 1) t[p>>1] = max(t[p], t[p^1]);
}

ll query(int l, int r) {
    if (l > r) return 0;
    ll res = 0;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = max(res, t[l++]);
        if (r&1) res = max(res, t[--r]);
    }
    return res;
}
ll ans = 0, curbest, a;
ll block[MAXN], cpy;
int main() {
    scanf("%d", &N);
//    cin.sync_with_stdio(0);
//    cin.tie(NULL);
//    cin>>N;
    for (int i = 0; i < N; i++) {
        scanf("%ld", &block[i]);
//        cin>>block[i];
        hx.push_back(block[i]);
    }
    sort(hx.begin(), hx.end());
    hx.erase(unique(hx.begin(), hx.end()), hx.end());
    r = hx.size();
    for (int i = 0; i < N; i++) {
//        cout<<i<<":\n";
        block[i] = lower_bound(hx.begin(), hx.end(), block[i]) - hx.begin();
//        cout<<block[i]<<"\n";
    }
    hx.clear();
    for (int i = 0; i < N; i++) {
        scanf("%ld", &a);
//        cin>>a;
//        cout<<i<<":\n";
        cl = block[i] + 1;
        curbest = a + query(cl, r);
//        cout<<cl<<" "<<r<<"\n";
//        cout<<query(cl, r)<<" "<<curbest<<"\n";
//        for (int i = 0; i < N; i++)
//            cout<<t[i+N]<<" ";
//        cout<<endl;
        ans = max(ans, curbest);
        cl--;
        update(cl, curbest);
//        cout<<"done1\n\n";
    }
    printf("%ld\n", ans);
}

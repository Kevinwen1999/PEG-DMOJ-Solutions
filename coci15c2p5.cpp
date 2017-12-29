#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define INF 0x3f3f3f3f
#define MAXN 1000010
#define ld long double
#define ll long long
using namespace std;
int N, P;
ll A[MAXN];
ll ans;
vector <ll> mmp;
int bit[MAXN];
void update(int x, int v) {
    for (;x <= N; x += (x & -x))
        bit[x] += v;
}
int query(int a) {
    int sum = 0;
    for (; a > 0; a -= (a & -a))
        sum += bit[a];
    return sum;
}
int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%lld", &A[i]);
    }
    scanf("%d", &P);
    for (int i = 1; i <= N; i++) {
        A[i] -= P;
        A[i] += A[i - 1]; 
        if (A[i] >= 0) ans++;
        mmp.push_back(A[i]);
    }
    sort(mmp.begin(), mmp.end());
    mmp.erase(unique(mmp.begin(), mmp.end()), mmp.end());
    for (int i = 1; i <= N; i++) {
        A[i] = upper_bound(mmp.begin(), mmp.end(), A[i]) - mmp.begin();
    }
    for (int i = 1; i <= N; i++) {
        ans += query(A[i]);
        update(A[i], 1);
    }
    printf("%lld\n", ans);
}

#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
inline void swap(int &a, int &b) {
    a ^= b;
    b ^= a;
    a ^= b;
}
inline long long hashu (int n, int m) {
    if (n < m) swap(n, m);
    return 1LL*(n * 1e5) + m;
}
unordered_map <long long, pair <int,int> > mem;
void f(int n, int m) {
    if (n < m) swap(n, m);
    long long hnm = hashu(n, m), t;
    if (mem.count(hnm)) return;
    int nm, nn;
    mem[hnm] = {0,0};
    int &maxa = mem[hnm].second, &mina = mem[hnm].first;
    maxa = -INF, mina = INF;
    if (n == 0 || m == 0) {
        maxa = mina = 0;
        return;
    }
    if (n < (m<<1)) {
        if (!(m&1)) {
            nn = n - (m>>1);
            f(nn, m);
            t = hashu(nn, m);
            mina = mem[t].first + 1;
            maxa = mem[t].second + 1;
        }
        if (!(n&1)) {
            nm = m - (n>>1);
            f(n, nm);
            t = hashu(n, nm);
            mina = min(mina, mem[t].first+ 1);
            maxa = max(maxa, mem[t].second + 1);
        }
    }
    else if (n == (m<<1)) {
        mina = maxa = 1;
        if (!(m&1)) {
            nn = n - (m>>1);
            f(nn, m);
            t = hashu(nn, m);
            maxa = mem[t].second + 1;
        }
    }
    else if (n > (m<<1)) {
        int rem = n % (m<<1);
        nn = rem;
        f(nn, m);
        t = hashu(nn, m);
        mina = mem[t].first + n/(m<<1);
        maxa = mem[t].second + n/(m<<1);
        if (!(m&1)) {
            int a = ceil(1.0*rem/(double)(m>>1));
            int b = n/(m<<1) - 1;
            int c = (m<<1) + rem - a*(m>>1);
            f(c, m);
            t = hashu(c, m);
            mina = min(mina, mem[t].first + a + b);
            maxa = max(maxa, mem[t].second + a + (b<<2));
        }
    }
    return;
}
int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    f(a, b);
    long long t = hashu(a, b);
    printf("%d %d", mem[t].first, mem[t].second);
}

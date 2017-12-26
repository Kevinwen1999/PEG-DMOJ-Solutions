#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAXN 100010
using namespace std;
int N, M, J;
int s[MAXN];
int main() {
    cin >> N >> M >> J;
    memset(s, 0x3f, sizeof s);
    for (int i = 0, a, b; i < M; i++) {
        cin >> a >> b;
        s[a] = b;
    }
    s[N + 1] = 0;
    int st = 0, ed = 1;
    set <pair <int, int> > sx;
    sx.insert({INF, 0});
    int tot = 0;
    while (st <= N) {
        while (ed <= N + 1) {
            if (ed - st > J) break;
            sx.insert({s[ed], ed});
            ed++;
        }
        auto x = sx.begin();
        if (x->first == INF) 
            return cout << -1 << "\n", 0;
        if (x->second == N + 1)
            break;
        tot = max(tot, x->first);
        while (st <= x->second) {
            sx.erase({s[st], st});
            st++;
        }
        st--;
    }
    cout << tot << "\n";
}

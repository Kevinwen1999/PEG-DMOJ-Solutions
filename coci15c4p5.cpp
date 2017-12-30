#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define INF 0x3f3f3f3f
#define MAXN 100010
#define ld long double
#define ll long long
using namespace std;
int N;
pair <int, pair <int, int>> el[MAXN];
int proc[MAXN];
stack <ll> ans;
int p[MAXN], rnk[MAXN], path[MAXN];
ll fans;
unordered_map <int, vector <int> > mmp[MAXN];
void init(int N) {
    for (int i = 0; i <= N; i++)
        p[i] = i, rnk[i] = 1, mmp[i][0].push_back(i);
}
int cv;
void mergemap(int x, int y) {
    if (rnk[p[x]] < rnk[p[y]]) swap(x, y);
    int px = p[x], py = p[y];
    for (auto i : mmp[py]) {
        for (auto j : i.second) {
            fans += mmp[px][path[x] ^ cv ^ path[y] ^ path[j]].size();
        }
    }
    int old = path[y];
    for (auto i : mmp[py]) {
        for (auto j : i.second) {
            path[j] = path[x] ^ cv ^ old ^ path[j];
            p[j] = px;
            mmp[px][path[j]].push_back(j);
        }
    }
    rnk[px] += rnk[py];
    mmp[py].clear();
    rnk[py] = 0;
}
int main() {
    scanf("%d", &N);
    for (int i = 0, a, b, c; i < N - 1; i++) {
        scanf("%d %d %d", &a, &b, &c);
        el[i] = make_pair(c, make_pair(a, b));
    }
    for (int i = 0; i < N - 1; i++) {
        scanf("%d", proc + i);
        proc[i]--;
    }
    reverse(proc, proc + N - 1);
    ans.push(0); 
    init(N);
    for (int i = 0, a, b; i < N - 1; i++) {
         a = el[proc[i]].second.first, b = el[proc[i]].second.second;
         cv = el[proc[i]].first;
         //cout << "fucking " << a << " " << b << " " << cv << "\n";
         mergemap(a, b);
         ans.push(fans);
    }
    while (!ans.empty()) {
        printf("%lld\n", ans.top());
        ans.pop();
    }
}

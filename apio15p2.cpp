#include <bits/stdc++.h>
#include <bits/extc++.h>
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define MMS(x, y) memset((x), (y), sizeof(x))
#define ll long long
#define vi vector <int>
#define pii pair <int, int>
#define EPS 1e-9
#define EPSS 1e-10

#define MAXN 30010
#define MAXL 5010
#define SEGN 300030
using namespace std;

int N, M;
set <int> P[MAXN];
int st, ed;
int dist[MAXN];
int main() {
    cin >> N >> M;
    for (int i = 0, a, b; i < M; i++) {
        cin >> a >> b;
        P[a].insert(b);
        if (!i) st = a;
        if (i == 1) ed = a;
    }
    memset(dist, 0x3f, sizeof dist);
    dist[st] = 0;
    __gnu_pbds::priority_queue<pii, greater<pii>, __gnu_pbds::thin_heap_tag> pq;
    pq.push({0, st});
    while(!pq.empty()) {
        int d = pq.top().first, u = pq.top().second;
        pq.pop();
        if (d > dist[u]) continue;
        for (int i : P[u]) {
            int cnt = 0;
            for (int j = u - i; j >= 0; j -= i) {
                cnt++;
                if (dist[u] + cnt < dist[j]) {
                    dist[j] = dist[u] + cnt;
                    pq.push({dist[j], j});
                }
                if (P[j].count(i)) break;
            }
            cnt = 0;
            for (int j = u + i; j < N; j += i) {
                cnt++;
                if (dist[u] + cnt < dist[j]) {
                    dist[j] = dist[u] + cnt;
                    pq.push({dist[j], j});
                }
                if (P[j].count(i)) break;
            }
        }
    }
    cout << (dist[ed] == INF ? -1 : dist[ed]) << "\n";
}

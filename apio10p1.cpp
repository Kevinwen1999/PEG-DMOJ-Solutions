#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define INF 0x3f3f3f3f
#define MAXN 1000010
using namespace std;
int N;
ll a, b, c;
ll p[MAXN];
ll dp[MAXN];
ll sq(ll x) {
    return x * x;
}
ll qs(int i, int j) {
    return p[i] - p[j];
}
ll f(int i, int j) {
    ll t = qs(i, j);
    ll ans = a * sq(t) + b * t + c;
    return ans;
}
ll w(int i, int j) {
    ll ans = dp[j] + f(i, j);
    return ans;
}
// j < k
// lol forgot a is negative and screwed up inequality
ld g(int j, int k) {
    return (ld)(dp[k] - dp[j] - b * p[k] + b * p[j] + a * sq(p[k]) - a * sq(p[j])) / (ld)(a * 2 * qs(k, j));
}
int main() {
    int N;
    cin>>N;
    cin>>a>>b>>c;
    for (int i = 1; i <= N; i++) {
        cin>>p[i];
        p[i] += p[i - 1];
    }
//    int best = 0;
//    for (int i = 1; i <= N; i++) {
//        dp[i] = -INF;
//        for (int j = best; j < i; j++) {
//            if (w(i, j) >= dp[i]) {
//                best = j;
//                dp[i] = w(i, j);
//            }
//        }
//    }
//    return 0;
    deque <int> dq;
    dq.push_back(0);
    for (int i = 1; i <= N; i++) {
        while(dq.size() >= 2 && g(dq[0], dq[1]) <= p[i]) {
            dq.pop_front();
        }
        dp[i] = w(i, dq[0]);
        while (dq.size() >= 2 && g(dq[dq.size() - 1], i) < g(dq[dq.size() - 2], dq[dq.size() - 1]))
            dq.pop_back();
        dq.push_back(i);
    }
    cout<<dp[N]<<"\n";
}

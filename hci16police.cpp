#include <bits/stdc++.h>
#define MAXN 100010
#define ll long long
#define ld long double
using namespace std;
int N, H;
ll a[MAXN];
ll dp[MAXN];
ll sq(ll i) {
    return i * i;
}
// j < k
ld f(int j, int k) {
    return (ld)(dp[k] - dp[j] + sq(a[k + 1]) - sq(a[j + 1])) / (ld)(2 * (a[k + 1] - a[j + 1]));
}
int main() {
    cin>>N>>H;
    for (int i = 1; i <= N; i++) {
        cin>>a[i];
    }
    deque <int> dq; dq.push_back(0);
    dp[0] = 0;
    for (int i = 1; i <= N; i++) {
        while(dq.size() >= 2 && f(dq[0], dq[1]) <= (ld)a[i]) {
            dq.pop_front();
        }
        dp[i] = dp[dq[0]] + sq(a[i] - a[dq[0] + 1]) + H;
        while (dq.size() >= 2 && f(dq[dq.size() - 2], dq[dq.size() - 1]) > f(dq[dq.size() - 1], i)) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout<<dp[N]<<"\n";
}

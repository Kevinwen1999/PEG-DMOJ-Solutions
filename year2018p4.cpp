#include <bits/stdc++.h>
#include <bits/extc++.h>
#pragma GCC optimize ("Ofast")
#define INF 0x3f3f
#define MAXN 2010
#define pii pair <int, int>
#define vi vector <int>
#define ld long double
//#define ll long long

using namespace std;
string L, R;
bool dp[20][170][2][2];
bool shit[170];
int N;
void DP(int pos, int sum, bool s1, bool s2) {
    if (pos == N) {
        shit[sum] = true;
        return;
    }
    if (dp[pos][sum][s1][s2]) return;
    dp[pos][sum][s1][s2] = true;
    int ll = !s1 ? L[pos] - '0' : 0;
    int rl = !s2 ? R[pos] - '0' : 9;
    for (int i = ll; i <= rl; i++) {
        bool n1 = (i == ll) ? 0 : 1;
        bool n2 = (i == rl) ? 0 : 1;
        DP(pos + 1, sum + i, s1 | n1, s2 | n2);
    }
}
int main() {
    cin >> L >> R;
    N = R.size();
    while (L.size() < N)
        L = "0" + L;
    DP(0, 0, 0, 0);
    int cnt = 0;
    for (int i = 0; i < 170; i++)
        if (shit[i]) cnt++;
    cout << cnt << "\n";
}

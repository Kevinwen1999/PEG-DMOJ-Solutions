#include <bits/stdc++.h>
#define MAXN 220
#define MOD 100000
using namespace std;
int N;
string in;
inline int special (int i, int j) { return (in[i] == '?' && in[j] == '?') ? 3 : 1;}
inline unsigned long long modp(unsigned long long i) {return i >= MOD ? MOD + i % MOD : i;}
set <pair <char,char> > valid;

unsigned long long dp[MAXN][MAXN];

unsigned long long recur (int i, int j) {
    if (i > j) return 1;
    if (~dp[i][j]) return dp[i][j];
    unsigned long long& ans = dp[i][j]; ans = 0;

    for (int mid = i + 1; mid <= j; mid += 2) {
        if (valid.count({in[i], in[mid]})) {

            unsigned long long ans1 = recur(i + 1, mid - 1);

            unsigned long long ans2 = recur(mid + 1, j);

            for (int k = 0; k < special(i, mid); k++)
                ans = modp(ans + ans1 * ans2);
        }
    }
    return ans;
}
int main() {
    valid.insert({'?', '?'});
    valid.insert({'?', ')'});
    valid.insert({'?', ']'});
    valid.insert({'?', '}'});
    valid.insert({'(', '?'});
    valid.insert({'[', '?'});
    valid.insert({'{', '?'});
    valid.insert({'(', ')'});
    valid.insert({'{', '}'});
    valid.insert({'[', ']'});
    memset(dp, -1, sizeof dp);
    cin>>N;
    cin>>in;
    unsigned long long ans = recur(0, N-1);
    if (ans >= MOD)
        printf("%05llu", ans - MOD);
    else
        printf("%llu", ans);
}

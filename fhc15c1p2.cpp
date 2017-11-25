#include <bits/stdc++.h>
#define MAXN 100010
#define LG 20
#define SIGMA 26
using namespace std;

int ch[MAXN * LG][SIGMA];
int sz;
int N;
int ans;
string in;
void ins() {
    int n = in.size();
    int u = 0, st = 0, tans = 0;
    while (st < n) {
        int c = in[st] - 'a';
        if (ch[u][c] == -1) {
            if (!tans) tans = st + 1;
            ch[u][c] = sz++;
        }
        st++;
        u = ch[u][c];
    }
    if (!tans) tans = n;
    //cout << tans << "\n";
    ans += tans;
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T; cin >> T;
    for (int cse = 1; cse <= T; cse++) {
        memset(ch, -1, sizeof ch);
        sz = 1;
        ans = 0;
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> in;
            ins();
        }
        cout << "Case #" << cse << ": " << ans << "\n";
    }
}

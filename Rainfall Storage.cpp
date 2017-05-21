#include <bits/stdc++.h>
#define MAXN 25000
using namespace std;
int N;
vector <int> pil;
set <int> height;
int dp[2][MAXN+1];
int main() {
    cin>>N;
    for (int i = 0, a; i < N; i++) {
        cin>>a;
        pil.push_back(a);
    }
    sort(pil.begin(), pil.end());
    reverse(pil.begin(), pil.end());
    int flag = 0;
    dp[1][0] = 1;
    height.insert(pil[1]);
    for (int i = 2; i < N; i++) {
        for (int j = 0; j <= MAXN; j++) {
            if (dp[1-flag][j]) {
                dp[flag][j] = 1;
            }
            for (int k : height) {
                if (j < (k - pil[i])) continue;
                if (dp[1-flag][j - k + pil[i]]) {
                    dp[flag][j] = 1;
                }
            }
        }
        height.insert(pil[i]);
        flag = 1 - flag;
    }
    for (int i = 0; i <= MAXN; i++) {
        if (dp[1-flag][i]) {
            cout<<i<<" ";
        }
    }
}

#include<bits/stdc++.h>
using namespace std;

vector<int> E[10000];
bool vis[10000];
int dp[10000];
int dfs(int cur){
    if(vis[cur]) return dp[cur];
    vis[cur] = true;
    if(E[cur].size() == 0){
        dp[cur]= 1;
        return 1;
    }
    int ans = 0;
    for(auto e : E[cur]){
        ans += dfs(e);
    }
    dp[cur] = ans;
    return dp[cur];
}
int N;
int main()
{
    cin >> N;
    while(true){
        int a, b;
        cin >> a >> b;
        if(a == 0 && b == 0)
            break;
        E[b].push_back(a);
    }
    cout << dfs(N) << endl;
}

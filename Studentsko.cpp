#include <bits/stdc++.h>
using namespace std;
int N, K;
vector <int> ori;
vector <int> srt;
unordered_map <int,int> mp;
int dp[5050];

int main()
{
    cin>>N>>K;
    for (int i = 0, a; i < N; i++)
    {
        cin>>a;
        ori.push_back(a);
    }
    srt = ori;
    sort(srt.begin(), srt.end());
    for (int i = 0; i < N; i+=K)
    {
        for (int j = 0; j < K; j++)
            mp[srt[i+j]] = i;
    }
    for (int i = 0; i < N; i++)
        ori[i] = mp[ori[i]];
    int maxx = 1;
    for (int i = 0; i < N; i++)
    {
        dp[i] = 1;
        for (int j = i-1; j >=0; j--)
        {
            if (ori[j] <= ori[i])
                dp[i] = max(dp[i], dp[j]+1);
        }
        maxx = max(maxx, dp[i]);
    }
    cout<<N-maxx<<"\n";
}

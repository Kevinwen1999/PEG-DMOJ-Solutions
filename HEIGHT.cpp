#include <bits/stdc++.h>
using namespace std;
int N, lastnum;
int arr[1010], dp[1010];
int maxsum;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for (int i = 0 ; i < N; i++)
        cin>>arr[i];
    for (int i = 0; i < N; i++)
    {
        dp[i] = arr[i];
        for (int j = 0 ; j < i; j++)
        {
            if (arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + arr[i]);
        }
    }
    for (int i = 0 ; i < N; i++)
        maxsum = max(maxsum, dp[i]);
    cout<<maxsum<<"\n";
}

#include <iostream>
#include <cstring>
#include <utility>
#include <cmath>
#include <algorithm>
using namespace std;
int N;
int rowl[20001], rowr[20001];
int dp[20001][2];
int cal(int prev, int left, int right, int dir)
{
    if (dir == 0)
    {
        if (prev <= left)
            return (left - prev + (right-left)*2);
        if (prev >= right)
            return (prev - left);
        return (right - prev)*2 + prev - left;
    }
    if (dir == 1)
    {
        if (prev <= left)
            return (right - prev);
        if (prev >= right)
            return (prev - right + (right-left)*2);
        return (prev - left)*2 + right - prev;
    }
}
int main()
{
    cin>>N;
    for (int i = 1; i <= N; i++)
        cin>>rowl[i]>>rowr[i];
    dp[1][0] = cal(1,rowl[1],rowr[1],0);
    dp[1][1] = cal(1,rowl[1],rowr[1],1);
    for (int i = 2 ; i <= N; i++)
    {
        dp[i-1][0]++;dp[i-1][1]++;
        dp[i][0] = min(dp[i-1][0]+cal(rowl[i-1],rowl[i],rowr[i],0),dp[i-1][1]+cal(rowr[i-1],rowl[i],rowr[i],0));
        dp[i][1] = min(dp[i-1][0]+cal(rowl[i-1],rowl[i],rowr[i],1),dp[i-1][1]+cal(rowr[i-1],rowl[i],rowr[i],1));
    }
    int ans = min(dp[N][0]+cal(rowl[N],N,N,0),dp[N][1]+cal(rowr[N],N,N,0));
    cout<<ans<<endl;
}

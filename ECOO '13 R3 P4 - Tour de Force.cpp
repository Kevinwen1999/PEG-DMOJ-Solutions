#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int card[1001][2];
int N;
int dp[1001][11];
int recur (int index, int streak)
{
    if (dp[index][streak]!=-1) return dp[index][streak];
    if (index == N-1)
    {
        if (streak<=7)return card[N-1][0]+card[N-1][1];
        if (streak==8)return card[N-1][0]-1;
        if (streak==9)return -1;
    }
    if (streak==9) return dp[index][streak] = (-1 + recur(index+1, 0));
    if (streak==8) return dp[index][streak] = (card[index][0]-1+recur(index+1, 0));
    return dp[index][streak] = max(card[index][0]+card[index][1]+recur(index+1,streak+2),card[index][0] -1 + recur(index+1, 0));
}
int main()
{
    int cnt = 10;
    while(cnt--)
    {
        cin>>N;
        for (int i = 0 ; i < N; i++)
            cin>>card[i][0]>>card[i][1];
        memset(dp,-1,sizeof dp);
        cout<<recur(0,0)<<endl;
    }
}

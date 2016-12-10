#include <iostream>
#include <cstring>
#define NINF -99999999
using namespace std;
inline int max(int a, int b) {return a > b? a:b;}
int N;
int ary[220];
int dp[220][220];

int recur (int left, int right)
{
    if (left==right) return 0;
    if (dp[left][right]!=-1) return dp[left][right];
    int ans = 0;
    for (int i = left + 1; i <= right-1; i++)
        ans = max(ans, ary[left]+ary[right]+ary[i]+recur(left,i)+recur(i,right));
    return dp[left][right] = ans;
}

int main()
{
    while(1)
    {
        cin>>N;
        if (N==0) break;
        for (int i = 0 ; i < N; i++)
            cin>>ary[i];
        memset(dp,-1,sizeof dp);
        cout<<recur(0,N-1)<<endl;
    }
}

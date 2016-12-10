#include <iostream>
#include <cstring>
#define NINF -9999999
using namespace std;
int M, U, R;
int v[155], t[155], f[155];
int dp[155][310][110];
inline int max(int a, int b) {return a > b? a : b;}
int recur (int index, int time, int food)
{
    if (index==R) return 0;
    if (time==M||food==U) return  0;
    if (dp[index][time][food]!=-1) return dp[index][time][food];
    if (time+t[index]>M||food+f[index]>U) return dp[index][time][food] = recur(index+1,time,food);
    return dp[index][time][food] = max( recur(index+1,time,food), recur(index+1, time+t[index],food+f[index])+v[index]);
}

int main()
{
    cin>>M>>U>>R;
    for (int i = 0 ; i < R; i++)
        cin>>v[i]>>t[i]>>f[i];
    memset(dp,-1,sizeof dp);
    cout<<recur(0,0,0)<<endl;
}

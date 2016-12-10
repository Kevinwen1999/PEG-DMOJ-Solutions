#include <iostream>
#include <cstring>
#include <cmath>
#define INF 9999999
using namespace std;
int W, L, R;
int l[11], r[11];
int dp[1<<10][1<<10];
int RT, LT;
inline int min(int a, int b) {return a < b? a:b;}
int recur(int lset,int rset,int lsum,int rsum,int cur)
{
    if (lsum==0&&rsum==0) return 0;
    if (abs(lsum-rsum)>W) return INF;
    if (lsum==0 ||rsum==0) return 1;
    if (dp[lset][rset]!=-1) return dp[lset][rset];
    int ans = INF,last = INF;
    int addl = 0, addr = 0;
    if (cur==1) addl = 1;
    else if (cur==0)addr = 1;
    else{addl = 1; addr = 1;}
    for (int i = 0 ; i < L; i++)
    {
        if (lset&(1<<i))
            ans = min(ans,recur(lset&~(1<<i),rset,lsum-l[i],rsum,0)+addl);
    }
    last = min(last,ans);
    ans = INF;
    for (int i = 0 ; i < R; i++)
    {
        if (rset&(1<<i))
            ans = min(ans,recur(lset,rset&~(1<<i),lsum,rsum-r[i],1)+addr);
    }
    last = min(last,ans);
    return dp[lset][rset] = last;
}

int main()
{
    cin>>L>>R>>W;
    int sum = 0;
    for (int i = 0 ; i < L; i++)
        {cin>>l[i]; sum+=l[i];}
    for (int j = 0 ; j < R; j++)
        cin>>r[j];
    int ans = INF;
    LT = (1<<L)-1; RT = (1<<R)-1;
    memset(dp,-1,sizeof dp);
    ans =recur(LT,RT,sum,sum,2);
    cout<<ans<<endl;
}

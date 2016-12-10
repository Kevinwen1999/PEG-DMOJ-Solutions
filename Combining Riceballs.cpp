#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int N;
int psum[410];
int in[410];
int dp[410][410];
int maxballs(int l, int r)
{
    if (dp[l][r]!=-1) return dp[l][r];
    int ans = dp[l][r],curl,curr,curm;
    if (l==r) return in[l];
    if (l+1==r)
    {
        if (in[l]==in[r])
            return dp[l][r] = in[l]+in[r];
        else
            return dp[l][r] = max(in[l],in[r]);
    }
    for (int i = l; i < r; i++)
    {
        for (int j = i+1; j < r; j++)
        {
            if ((psum[i]-psum[l-1])!=(psum[r]-psum[j])) continue;
            curl = maxballs(l,i); curr = maxballs(j+1,r);curm = maxballs(i+1,j);
            if (curl!=curr)
            {
                ans = max(ans, max(curl,max(curm,curr)));
                continue;
            }
            if (curl!=(psum[i]-psum[l-1])||curr!=(psum[r]-psum[j]))
            {
                ans = max(ans, max(curl,max(curm,curr)));
                continue;
            }
            if (curm==(psum[j]-psum[i]))
            {
                ans = max(ans,psum[r]-psum[l-1]);
                return dp[l][r] = ans;
            }
            else
                ans = max(ans, max(curl,max(curm,curr)));
        }
    }
    for (int i = l; i < r; i++)
    {
        curl = maxballs(l,i); curr = maxballs(i+1,r);
        if (curl!=curr)
        {
             ans = max(ans,max(curl,curr));
             continue;
        }
        if (curl==(psum[i]-psum[l-1])&&curr==(psum[r]-psum[i]))
        {
            ans = max(ans,curl+curr);
            break;
        }
        else
            ans = max(ans,max(curl,curr));
    }
    return dp[l][r] = ans;
}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for (int i = 1,temp ; i <= N; i++)
    {
        cin>>temp;
        in[i]=psum[i] = temp;
        psum[i]+=psum[i-1];
    }
    memset(dp,-1,sizeof dp);
    cout<<maxballs(1,N)<<"\n";
}

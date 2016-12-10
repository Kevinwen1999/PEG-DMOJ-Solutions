#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <utility>
using namespace std;
int N,T;
vector <int> pos, neg;
int dp[1010][1010][3];
int recur(int rindex, int lindex , int total, int side)
{
    if (dp[lindex][rindex][side]!=-1) return dp[lindex][rindex][side];
    int cur;
    if (side == 0) cur = neg[lindex-1];
    else if (side==1) cur = pos[rindex-1];
    else cur = 0;
    if (total == T-1)
    {
        if (lindex==(int)neg.size())
            return dp[lindex][rindex][side] = abs(cur-pos[rindex]);
        if (rindex==(int)pos.size())
            return dp[lindex][rindex][side] = abs(cur-neg[lindex]);
        return dp[lindex][rindex][side] = min( abs(cur-pos[rindex]) , abs(cur-neg[lindex]) );
    }
    if (lindex==(int)neg.size())
        return dp[lindex][rindex][side] = abs(cur-pos[rindex])+recur(rindex+1,lindex,total+1,1);
    if (rindex==(int)pos.size())
        return dp[lindex][rindex][side] = abs(cur-neg[lindex])+recur(rindex,lindex+1,total+1,0);
    return dp[lindex][rindex][side] = min (  abs(cur-pos[rindex])+recur(rindex+1,lindex,total+1,1) , abs(cur-neg[lindex])+recur(rindex,lindex+1,total+1,0)  );
}
int main()
{
    cin>>N>>T;
    for (int i = 0,temp ; i < N; i++)
    {
        cin>>temp;
        if (temp>0)
            pos.push_back(temp);
        if (temp<0)
            neg.push_back(temp);
    }
    sort(pos.begin(),pos.end());
    sort(neg.begin(),neg.end());
    reverse(neg.begin(),neg.end());
    memset(dp,-1,sizeof dp);
    cout<<recur(0,0,0,2)<<endl;
}

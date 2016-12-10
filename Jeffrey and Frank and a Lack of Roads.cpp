#include <bits/stdc++.h>
using namespace std;
int N, R, S;
struct apple
{
    string name;
    int val, wgt, vol;
    bool operator< (const apple &a) const
    {
        return name < a.name;
    }
};
vector <apple> v;
int dp[1010][1010];
int cnt[11];
int main()
{
    cin>>N>>R>>S;
    for (int i = 0; i < N; i++)
    {
        string n; int a, b, c;
        cin>>n>>a>>b>>c;
        v.push_back((apple){n,a,b,c});
    }
    sort(v.begin(), v.end());
    //memset(dp,-1,sizeof dp);
    dp[0][0] = 0;
    for (int i = 0; i < N; i++)
    {
        for (int r = 0; r <= R-v[i].wgt; r++)
        {
            for (int s = 0; s <= S-v[i].vol; s++)
            {
                apple &a = v[i];
                dp[r+a.wgt][s+a.vol] = max(dp[r][s] + a.val,dp[r+a.wgt][s+a.vol]);
            }
        }
    }
    int tr = R, ts = S;
    bool OK = true;
    while (OK)
    {
        OK = false;
        for (int i = 0; i < N; i++)
        {
            apple &a = v[i];
            if (a.wgt > tr || a.vol > ts) continue;
            if (dp[tr-a.wgt][ts-a.vol] + a.val == dp[tr][ts])
            {
                cnt[i]++;
                tr-=a.wgt;
                ts-=a.vol;
                OK = true;
                break;
            }
        }
    }
    cout<<dp[R][S]<<endl;
    for (int i = 0; i < N; i++)
    {
        cout<<v[i].name<<" "<<cnt[i]<<"\n";
    }
}

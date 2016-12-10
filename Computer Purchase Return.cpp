#include <bits/stdc++.h>

/*
2
1
1 1 2
1


*/
using namespace std;
int T, N, B;
vector <pair <int,int> > v[6];
pair <int,int> cur;
int dp[6][3010];
int main()
{
    cin>>T>>N;
    for (int i = 0, a, b, c; i < N; i++)
    {
        cin>>a>>b>>c;
        v[c].push_back({a,b});
    }
    cin>>B;
    memset(dp,-1,sizeof dp);
    /*for (int i = 0; i <= T; i++)
        dp[i][0] = 0;*/
    for (int i = 0; i <= B; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= T; i++)
    {
        for (int k = 0; k < v[i].size(); k++)
        {
            cur = v[i][k];
            //cout<<"current val is"<<cur.first<<","<<cur.second<<endl;
            for (int j = 0; j <= B; j++)
            {
                if (cur.first > j) continue;
                //cout<<j<<":\n";
                if (dp[i-1][j-cur.first]!=-1)
                //cout<<dp[i][j-1]<<", "<< dp[i-1][j-cur.first]<<" \n";
                    dp[i][j] = max(dp[i][j], max(dp[i][j-1], cur.second + dp[i-1][j-cur.first]));
            }
        }
    }
    cout<<dp[T][B]<<"\n";
    /*for (int i = 0; i <= T; i++)
    {
        for (int j = 0; j <= B; j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }*/
}

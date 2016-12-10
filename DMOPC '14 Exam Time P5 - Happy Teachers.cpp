#include <iostream>
#include <cstring>
#include <utility>
#define INF 999999
using namespace std;
int N,S,H[55],E[55],P[55];
pair <int,int> dp[1010];
inline int min(int a, int b) { return a < b? a: b;}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for (int i = 1 ; i <= N; i++)
        cin>>H[i]>>E[i]>>P[i];
    cin>>S;
    for (int i = 0 ; i < N; i++)
        dp[i] = make_pair(-1,INF);
    dp[0] = make_pair(0,0);
    for (int i = 1 ; i <= N; i++)
    {
        for (int j = S; j >=0; j--)
        {
            int time = 1, cost,total= 0;
            while (1)
            {
                cost = P[i]*time;
                if (cost > j) break;
                total+=H[i]-E[i]*(time-1);
                if (total < 0) break;
                if (dp[j-cost].first!=-1)
                {
                    if (dp[j-cost].first+total > dp[j].first)
                    {
                       dp[j].first = dp[j-cost].first+total;
                       dp[j].second = dp[j-cost].second+time;
                    }
                    else if (dp[j-cost].first+total == dp[j].first)
                    {
                        dp[j].second = min(dp[j].second,dp[j-cost].second+time);
                    }
                }
                time++;
            }
        }
    }
    int maxx = 0,ttotal = 0;
    for (int i = 0; i <= S; i++)
    {
        if (dp[i].first > maxx)
        {
            maxx = dp[i].first;
            ttotal = dp[i].second;
        }
        else if (dp[i].first==maxx&&dp[i].second < ttotal)
        {
            ttotal = dp[i].second;
        }
    }
    cout<<maxx<<"\n"<<ttotal;
}

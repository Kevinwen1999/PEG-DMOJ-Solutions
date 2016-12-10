#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
inline long long max(long long a, long long b){return a > b?a:b;}
int N, E,R, C1, V1, CA , CB, CM, VA, VB , VM;
long long dp[2002],bonus;
priority_queue <int, vector <int> , greater <int> > item[2002];
int main()
{
    cin>>N>>R;
    for(int i=0; i<N; i++)
    {
        cin>>E>>C1>>V1>>CA>>CB>>CM>>VA>>VB>>VM;
        for (int j = 0; j < E; j++)
        {
            if (C1<=R)
            {
                if (C1==0) bonus+=V1;
                else
                {
                    item[C1].push(V1);
                    if (item[C1].size()*C1>R) item[C1].pop();
                }
            }
            C1 = (1LL*C1*CA+CB)%CM; V1 = (1LL*V1*VA+VB)%VM;
        }
    }
//--------------------------------------------------------------------------------------
    for (int i = 1; i <= R; i++)
    {
        while (!item[i].empty())
        {
            int v = item[i].top(); item[i].pop();
            for (int j = R; j >= i; j--)
                dp[j] = max(dp[j],dp[j-i]+v);
        }
    }
    cout<<dp[R]+bonus<<endl;
    return 0;
}

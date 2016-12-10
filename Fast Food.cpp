#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAXN 210
using namespace std;
int N, K;
int a[MAXN];
int dp[MAXN][MAXN];
pair <int,int> pa[MAXN][MAXN];
int maxin(int cur, int num)
{
    if (cur==N-1)
    {
        if (num!=1)
            return INF;
        else
            return 0;
    }
    if (num == 1) return a[N-1] - a[cur];
    if (dp[cur][num]!=-1)
        return dp[cur][num];
    int ans = INF;
    for (int i = cur + 1; i < N; i++)
    {
        int btw = i==cur+1? 0 : -1;
        for (int j = cur+1; j < i; j++)
            btw = max(btw, min(a[j]-a[cur], a[i] - a[j]));
        int temp = max(btw, maxin(i,num-1));
        if (temp< ans)
        {
            ans = temp;
            pa[cur][num] = {i,num-1};
        }
    }
    return dp[cur][num] = ans;
}
void print(int cur, int num)
{
    printf("%d ", a[cur]);
    if (pa[cur][num].first==-1) return;
    print(pa[cur][num].first,pa[cur][num].second);
}
int main()
{
    while (scanf("%d%d", &N, &K)==2 && N)
    {
        for (int i = 0; i < N; i++)
            cin>>a[i];
        for (int i = 0; i < N; i++)
            for (int j = 0; j <= K; j++)
                pa[i][j].first = -1;
        memset(dp,-1,sizeof dp);
        int ans = INF, idx;
        for (int i = 0; i < N; i++)
        {
            int cm = max(a[i] - a[0], maxin(i,K));
            if (ans > cm)
            {
                ans = cm;
                idx = i;
            }
        }
        print(idx,K);
        printf("\n");
        printf("%d\n", ans);

    }
}

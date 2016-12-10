#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 100 + 10;
int pre[MAXN], dp[MAXN][MAXN];
bool visited[MAXN][MAXN];
int N;
int DP (int i, int j) //dp[i][j] rep the best sum in i to j when it's your move
{
    if (visited[i][j]) return dp[i][j];
    visited[i][j] = 1;
    int m = 0;
    for (int k = i + 1; k <= j; k++) m = min(m, DP(k,j)); // pick from left
    for (int k = i ; k < j; k++) m = min(m, DP(i,k));  // pick from right
    return dp[i][j] = pre[j] - pre[i-1] - m;
}
int main()
{
    while (scanf("%d", &N) && N)
    {
        pre[0] = 0;
        for (int i = 1; i <= N; i++)
        {
            scanf("%d", &pre[i]);
            pre[i] += pre[i-1];
        }
        memset(visited, 0, sizeof visited);
        printf("%d\n", 2*DP(1,N) - pre[N]); // DP(1,N) - (S[N] - DP(1,N))
    }
}

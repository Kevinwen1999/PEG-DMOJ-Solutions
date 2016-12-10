#include <iostream>

using namespace std;
int N, M, K, Q;
long answer;
int dp[5001][5001];
int main()
{
    cin>>N>>M>>K;
    for (int i = 0 ; i < K; i++)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        dp[y1][x1]++;
        dp[y2+1][x2+1]++;
        dp[y1][x2+1]--;
        dp[y2+1][x1]--;
    }
    for(int i = 1; i <= M; i++){
        for(int j = 1; j <= N; j++){
            dp[i][j] = dp[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }
    for(int i = 1; i <= M; i++){
        for(int j = 1; j <= N; j++){
            dp[i][j] = dp[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }
    cin>>Q;
    for (int i = 0 ; i < Q; i++)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        cout << (dp[y2][x2] - dp[y2][x1-1] - dp[y1-1][x2] + dp[y1-1][x1-1]) << endl;
    }

    return 0;
}

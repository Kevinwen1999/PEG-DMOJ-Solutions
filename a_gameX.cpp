#include<iostream>

using namespace std;
int origin[1001];
int dp[1001][1001];
int N;
inline int maxx(int a, int b) { return (a > b) ? a : b; }
inline int minx(int a, int b) { return (a < b) ? a : b; }
int game(int i , int j)
{
    if (dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    else
    {
        dp[i][j] = maxx( minx( game(i+1,j-1) , game(i+2, j) ) + dp[i][i] , minx( game(i , j-2) ,game(i+1,j-1) ) + dp[j][j] );
        return dp[i][j];
    }
}
int main()
{
    for (int i = 0 ; i < 1001; i++)
    {
        for (int j = 0 ; j < 1001; j++)
        {
            dp[i][j] = -1;
        }
    }
    cin>>N;
    for (int i = 0 ; i < N; i++)
    {
        cin>>origin[i];
        dp[i][i] = origin[i];
    }
    for (int i = 0 ; i < N; i++)
    {
        dp[i][i+1] = maxx(dp[i][i],dp[i+1][i+1]);
    }
    long answer = game(0,N-1);
    cout<<answer<<endl;
    return 0;
}

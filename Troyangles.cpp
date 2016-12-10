#include <iostream>
#include <cstring>

using namespace std;
inline long long min(long long a,long long b) {return a>b?b:a;}
int N, dp[2020][2020];
char grid[2020][2020];
string temp;

int main()
{
    cin>>N;
    for (int i = 0 ; i < N; i++)
    {
        cin>>temp;
        for (int j = 0 ; j < N; j++)
            grid[i][j]=temp[j];
    }
    int ans = 0;
    for (int i = N-1; i >=0; i--)
        for (int j = 0 ; j < N; j++)
            if (grid[i][j]=='#')
            {
                ans+=1;
                dp[i][j]=1;
                if (i+1<N&&j-1>=0&&j+1<N&&grid[i+1][j-1]=='#'&&grid[i+1][j]=='#'&&grid[i+1][j+1]=='#')
                {
                    dp[i][j]+=min(min(dp[i+1][j-1] ,dp[i+1][j] ) ,dp[i+1][j+1] );
                    ans+=dp[i][j]-1;
                }
            }
    cout<<ans<<endl;
}

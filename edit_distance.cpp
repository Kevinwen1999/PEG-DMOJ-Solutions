#include <iostream>
#include <cstring>
inline int min (int a, int b){return a<b?a:b;}
inline int min (int a, int b, int c){return min(min(a,b),c);}
using namespace std;
string str1,str2;
int D, I, R,m,n;
int dp[1010][1010];
void edit()
{
    m = (int) str1.size();
    n = (int) str2.size();
    for (int i = 0 ; i <= m ; i++)
    {
        for (int j = 0 ; j <= n; j++)
        {
            if (i==0)
                dp[i][j] = j*I;
            else if (j==0)
                dp[i][j] = i*D;
            else if (str1[i-1]==str2[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=min(dp[i][j-1]+I,dp[i-1][j]+D,dp[i-1][j-1]+R);
        }
    }
}
int main()
{
    cin>>D>>I>>R;
    cin>>str1>>str2;
    edit();
    cout<<dp[m][n]<<endl;
}

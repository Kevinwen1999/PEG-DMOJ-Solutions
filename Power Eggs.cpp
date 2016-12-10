#include <iostream>
#include <cstring>
using namespace std;
int T,A;
long long  N;
long long dp[33][33];
int main()
{
    cin>>T;
    for (int i = 0 ; i <= 32; i++)
    {
        dp[0][i] = 1;
        dp[i][0] = 1;
    }
    for (int i = 1; i <= 32; i++)
        for (int j = 1; j <= 32; j++)
            dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
    while (T--)
    {
        cin>>N>>A;
        int low = 0, high = 32;
        while (low<=high)
        {
            int mid = (high+low)>>1;
            if (dp[mid][A]-1 >= N)
                high = mid-1;
            else
                low = mid+1;
        }
        if (low>32)
            cout<<"Impossible"<<endl;
        else
            cout<<low<<endl;
    }
}

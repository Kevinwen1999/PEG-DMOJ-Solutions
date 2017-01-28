#include <bits/stdc++.h>
using namespace std;
int N;
string ori, rev;
int lcs[2][5010];
int main()
{
    cin>>N>>ori;
    rev = ori;
    reverse(rev.begin(), rev.end());
    int flag = 0;
    for (int i = 0; i <= N; i++)
    {
        flag = 1-flag;
        for (int j = 0; j <= N; j++)
        {
            if (!i||!j)
                lcs[flag][j] = 0;
            else if (ori[i-1]==rev[j-1])
                lcs[flag][j] = lcs[1-flag][j-1]+1;
            else
                lcs[flag][j] = max(lcs[1-flag][j],lcs[flag][j-1]);
        }
    }
    cout<<N-lcs[flag][N];
}

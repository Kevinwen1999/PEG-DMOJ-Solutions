#include <bits/stdc++.h>
using namespace std;
int K, A;
int dp[110][110];
int recur(int k, int f)
{
    if (k==0||f==1||k==f)
        return 1;
    if (f > k)
        return 0;
    if (dp[k][f])
        return dp[k][f];
    for (int i = 1; i <= f; i++)
    {
        dp[k][f] += recur(k-f,i);
    }
    return dp[k][f];
}
int main()
{
    int T; cin>>T;
    while(T--)
    {
        cin>>K>>A;
        vector <int> all;
        bool OK = true;
        while (K > 0 && OK)
        {
            int co;
            bool found = false;
            for (int i = 1; i <= K; i++)
            {
                int ord = recur(K, i);
                if (ord >= A)
                {
                    co = i;
                    found = true;
                    break;
                }
                A -= ord;
            }
            if (!found)
            {
                OK = false;
                break;
            }
            else
            {
                K -= co;
                all.push_back(co);
            }
        }
        if (!OK)
        {
            cout<<"Too big\n";
        }
        else
        {
            cout<<"(";
            for (int i = 0; i < all.size(); i++)
            {
                if (i>0) cout<<",";
                cout<<all[i];
            }
            cout<<")\n";
        }
    }
}

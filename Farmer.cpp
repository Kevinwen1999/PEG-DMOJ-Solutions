#include <bits/stdc++.h>
using namespace std;
int Q, M, K;
int sum;
vector <int> F, S;
bool p[2][150010];
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>Q>>M>>K;
    for (int i = 0, a; i < M; i++)
    {
        cin>>a; F.push_back(a);
        sum += a;
    }
    for (int i = 0, a; i < K; i++)
    {
        cin>>a; S.push_back(a);
    }
    if (sum == Q)
    {
        cout<<sum<<"\n";
        return 0;
    }
    if (sum < Q)
    {
        sort(S.begin(),S.end());
        int i = 0;
        for (; K-i-1 >=0 && sum < Q; i++)
        {
            sum += S[K-1-i];
        }
        cout<<Q-i<<"\n";
        return 0;
    }
    else
    {
        //sort(F.begin(),F.end());
        int flag = 0;
        p[0][0] = p[1][0]=true;
        for (int i = 0; i < M; i++)
        {
            for (int q = 0; q<= Q; q++)
            {
                if (p[flag][q])
                {
                    p[1-flag][q] = true;
                    if (q+F[i]<=Q)
                        p[1-flag][q+F[i]] = true;
                }
            }
            flag = 1 - flag;
        }
        cout<<Q- (p[flag][Q]? 0 : 1);
    }
}

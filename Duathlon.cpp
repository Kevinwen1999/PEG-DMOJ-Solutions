#include <bits/stdc++.h>
using namespace std;
double t, rt[30], kt[30], rb, kb, ans, ar, ak;
int N;
int main()
{
    cin>>t>>N;
    for (int i = 0; i < N-1; i++)
    {
        cin>>rt[i]>>kt[i];
    }
    cin>>rb>>kb;
    ans = -1e5;
    double tot, cheat, diff, tmp;
    for (double r = 0.0; r <= t; r+=0.001)
    {
        r = round(r*1000)/1000;
        tot = 1e9+1e9;
        for (int i = 0; i < N-1; i++)
        {
            tmp = r/rt[i] + (t-r)/kt[i];
            tot = min(tot, tmp);
        }
        cheat = (r/rb + (t-r)/kb);
        diff = (tot - cheat)*3600;
        if (diff>=0.0)
        {
            if (diff> ans)
            {
                ans = diff;
                ar = r; ak = t-r;
            }
        }
    }
    if (ans == -1e5)
        cout<<"The cheater cannot win.\n";
    else
        printf("The cheater can win by %.0lf seconds with r = %.2lfkm and k = %.2lfkm.\n", ans, ar, ak);
}

#include <bits/stdc++.h>
using namespace std;
vector <double> v;
int N;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for (int i = 0,a; i < N; i++)
    {
        cin>>a;
        v.push_back(a);
    }
    double ans = 0;
    while (true)
    {
        ans ++;
        bool OK = true;
        for (int i = 0; i < N && OK; i++)
        {
            //cout<<"considering"<<v[i]<<endl;
            bool pos = false;
            for (double j = 0; j <= ans && !pos; j++)
            {
                double cur = j /ans * 100;
                if (round(cur) == v[i])
                    pos = true;
            }
            if (!pos)
                OK = false;
        }
        if (OK)
        {
            break;
        }
    }
    cout<<ans<<endl;
}

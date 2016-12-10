#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    ll h;
    int t;
}p;
int N;
ll cur, tot;
deque <node> d;
int main()
{
    cin>>N;
    for (int i = 0; i < N; i++)
    {
        cin>>cur;
        bool same = false;
        while (!d.empty())
        {
            if (d.back().h <= cur)
            {
                tot+=d.back().t;
                if (d.back().h == cur)
                {
                    d.back().t++;
                    p = d.back();
                    same = true;

                }
                d.pop_back();
            }
            else {tot++; break;}
        }
        if (!same) d.push_back((node){cur,1});
        else d.push_back(p);
    }
    cout<<tot<<endl;
}

#include <bits/stdc++.h>
using namespace std;
struct node
{
    int rk, id;
    bool operator< (const node i) const
    {
        if (rk == i.rk)
            return id > i.id;
        return rk > i.rk;
    }
} cur;
vector <node> all;
set <node> S;
int N;
bool choosed[100010];
int main()
{
    cin>>N;
    for (int i = 1; i <=N; i++)
    {
        cin>>cur.rk;
        cur.id = i;
        all.push_back(cur);
    }
    S.insert(all[0]);
    set <node>::iterator it;
    for (int i = 1; i < N; i++)
    {
        it = S.upper_bound(all[i]);
        cur = *it;
        //cout<<i<<" "<<all[i].rk<<" "<<all[i].id<<" "<<cur.rk<<" "<<cur.id<<endl;
        if (it == S.end())
        {
            cout<<"NO";
            return 0;
        }
        if (choosed[it->id])
            S.erase(it);
        else
            choosed[it->id] = 1;
        S.insert(all[i]);
    }
    cout<<"YES";
}

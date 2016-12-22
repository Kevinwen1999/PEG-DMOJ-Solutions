#include <bits/stdc++.h>
using namespace std;
struct q
{
    long long a, b;
}cur;
int N, A, C;
map <long long,int> mx;
vector <q> anime, work;
long long xm[500010], diff[500010];
int xtot = 0;
int main()
{
    cin>>N>>A>>C;
    for (int i = 0, a, b; i < A; i++)
    {
        cin>>cur.a>>cur.b;
        mx[cur.a] = 0; mx[cur.b+1] = 0;
        anime.push_back(cur);
    }
    for (int i = 0, a, b; i < C; i++)
    {
        cin>>cur.a>>cur.b;
        mx[cur.a] = 0; mx[cur.b+1] = 0;
        work.push_back(cur);
    }
    for (auto &i : mx)
    {
        xtot++;
        i.second = xtot;
        xm[xtot] = i.first;
    }
    for (auto i : anime)
    {
        diff[mx[i.a]]++;
        diff[mx[i.b+1]]--;
    }
    for (auto i : work)
    {
        diff[mx[i.a]]-=1e7;
        diff[mx[i.b+1]]+=1e7;
    }
    unsigned long long sum = 0;
    for (int i = 0; i < xtot; i++)
    {
        diff[i] += diff[i-1];
        //cout<<diff[i]<<" ";
        if (diff[i] > 0)
            sum += xm[i+1]-xm[i];
    }
    cout<<sum<<"\n";
}

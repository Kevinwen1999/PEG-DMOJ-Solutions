#include <bits/stdc++.h>
using namespace std;
struct node
{
    int m, v;
    bool operator< (const node i) const
    {
        if (v==i.v)
        {
            return m < i.m;
        }
        return v > i.v;
        /*
        if (m==i.m)
        {
            return v > i.v;
        }
        return m < i.m;
        */
    }
} cur;
vector <node> V;
multiset <int> bag;
int N, K;
int main()
{
    cin>>N>>K;
    for (int i = 0; i < N; i++)
    {
        cin>>cur.m>>cur.v;
        V.push_back(cur);
    }
    sort(V.begin(), V.end());
    for (int i = 0, w; i < K; i++)
    {
        cin>>w;
        bag.insert(w);
    }
    set<int>::iterator it;
    long long ans = 0;
    for (int a = 0; a < N; a++)
    {
        if (bag.empty()) break;
        it = bag.lower_bound(V[a].m);
        if (it==bag.end()) continue;
        ans += V[a].v;
        bag.erase(it);
    }
    cout<<ans<<"\n";
}

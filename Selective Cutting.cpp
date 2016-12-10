#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100011;
long long bit[MAXN];
void update(int x, int v)
{
    for (;x < MAXN; x += (x & -x))
        bit[x]+=v;
}
long long Query(int a)
{
    long long sum  = 0;
    for (; a > 0; a-=(a & -a))
        sum+=bit[a];
    return sum;
}
struct query
{
    int idx, q, a, b; long long ans = -1;
    query(int i1,int i2,int i3,int i4) {idx = i1; q = i2; a = ++i3; b = ++i4;}
};
bool cmpidx (query a, query b)
{
    return a.idx < b.idx;
}
bool cmpq (query a, query b)
{
    return a.q < b.q;
}
int arr[MAXN];
bool updated[MAXN];
int N, Q;
vector <int> all;
int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &arr[i]);
        all.push_back(arr[i]);
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(),all.end()), all.end());
    reverse(all.begin(), all.end());
    /*for (int i : all)
        cout<<i<<"\n";*/
    scanf("%d", &Q);
    vector <query> v;
    for (int i = 0 ; i < Q; i++)
    {
        int q, a, b;
        scanf("%d%d%d", &a, &b, &q);
        v.push_back(query(i,q,a,b));
    }
    sort(v.begin(), v.end(), cmpq);
    vector <query> tv= v;
    /*for (query i : tv)
        cout<<i.a<<" "<<i.b<<" "<<i.q<<"\n";*/
    for (int i = 0 ; i < all.size(); i++)
    {
        for (int j = 1; j<= N; j++)
        {
            if (arr[j]==all[i])
            {
                update(j,all[i]);
            }
        }
        while (!tv.empty())
        {
            if (tv[tv.size()-1].q > all[0]) {v[tv.size()-1].ans = 0; tv.pop_back(); continue;}
            else if (i!=all.size()-1 &&(tv[tv.size()-1].q <= all[i]&&tv[tv.size()-1].q > all[i+1]))
            {
                query cur = tv[tv.size()-1]; int id = tv.size()-1;
                tv.pop_back();
                long long aa = Query(cur.b)-Query(cur.a-1);
                v[id].ans = aa;
            }
            else break;
        }
    }
    for (int i = 0 ; i < v.size(); i++)
    {
        if (v[i].ans == -1)
        {
            long long aa = Query(v[i].b) - Query(v[i].a-1);
            v[i].ans = aa;
        }
    }
    /*for (int i = v.size()-1; i >=0; i--)
    {
        bool checked = false;
        for (int j = 1; j<= N; j++)
        {
            if (arr[j]>=v[i].q)
            {
                checked = true;
                if (!updated[j])
                {
                    update(j,arr[j]);
                    updated[j] = true;
                }
            }
        }
        if (!checked) {v[i].ans = 0; continue;}
        long long aa = Query(v[i].b)-Query(v[i].a-1);
        v[i].ans = aa;
    }*/
    sort(v.begin(),v.end(),cmpidx);
    for (query i : v)
    {
        printf("%lld\n", i.ans);
    }
}

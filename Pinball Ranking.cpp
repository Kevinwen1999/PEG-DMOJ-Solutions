#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100001;
int bit[MAXN];
void update(int x, int v)
{
    for (;x < MAXN; x += (x & -x))
        bit[x]+=v;
}
int query(int a)
{
    int sum  = 0;
    for (; a > 0; a-=(a & -a))
        sum+=bit[a];
    return sum;
}
int main()
{
    int N, rk;
    double sum = 0.0;
    cin>>N;
    int all = 0;
    vector <long long> in;
    map<long long, int> m;
    long long cur;
    int label = 0;
    for (int i = 0; i < N; i++)
    {
        cin>>cur;
        in.push_back(cur);
    }
    vector <long long> cp = in;
    sort(cp.begin(), cp.end());
    for (long long i : cp)
    {
        if (!m.count(i))
            m[i] = ++label;
    }
    for (int i = 0 ; i < N; i++)
    {
        cur = m[in[i]];
        all++;
        update(cur,1);
        rk = all - query(cur) + 1;
        sum+=rk;
    }
    sum/=all;
    cout<<fixed<<setprecision(2)<<sum<<"\n";
}

#include <bits/stdc++.h>

using namespace std;

#define ll long long

struct query
{
    ll x, yup, ydown, t;
    query(ll a, ll b, ll c, ll d)
    {
        x = a; yup = b; ydown = c; t = d;
    }
};
bool cmp(query a, query b)
{
    return a.x < b.x;
}
int N, T;
ll tint[2010];
vector <ll> ycor;
vector <query> allx;
unordered_map <ll, int> haxh;
int main()
{
    cin>>N>>T;
    ll x1, x2, y1, y2, tt;
    for (int i = 0 ; i < N; i++)
    {
        cin>>x1>>y1>>x2>>y2>>tt;
        ycor.push_back(y1);
        ycor.push_back(y2);
        allx.push_back(query(x1,y1,y2,tt));
        allx.push_back(query(x2,y1,y2,-1 * tt));
    }

    sort(allx.begin(),allx.end(),cmp);
    sort(ycor.begin(),ycor.end());
    ycor.erase(unique(ycor.begin(),ycor.end()), ycor.end());

    for (int i = 0 ; i  < ycor.size(); i++)
        haxh[ycor[i]] = i;

    ll ans = 0, lastx = allx[0].x;
    for (query q : allx)
    {
        for (int i = 0 ; i < ycor.size()-1; i++)
        {
            if (tint[i] >= T)
                ans+=(ycor[i+1]-ycor[i]) * (q.x- lastx);
        }
        for (int i = haxh[q.yup]; i < haxh[q.ydown]; i++)
            tint[i]+=q.t;
        lastx = q.x;
    }
    cout<<ans<<"\n";
}

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
int N, M;
ll tint[200010];
vector <ll> ycor;
vector <query> allx;
unordered_map <ll, int> haxh;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    //scanf("%d%d", &N, &M);
    ll x1, x2, y1, y2;
    for (int i = 0 ; i < M; i++)
    {
        cin>>x1>>y1>>x2>>y2;
        x2+=x1; y2+=y1;
        ycor.push_back(y1);
        ycor.push_back(y2);
        allx.push_back(query(x1,y1,y2,1));
        allx.push_back(query(x2,y1,y2,-1));
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
            if (tint[i] % 2 == 1)
                ans+=(ycor[i+1]-ycor[i]) * (q.x- lastx);
        }
        for (int i = haxh[q.yup]; i < haxh[q.ydown]; i++)
            tint[i]+=q.t;
        lastx = q.x;
    }
    cout<<ans<<"\n";
}

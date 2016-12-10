#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m ,t;
struct point
{
    int x,y;
};
bool cmpx (point a, point b)
{
    return a.x < b.x;
}
bool cmpy (point a, point b)
{
    return a.y > b.y;
}
vector <point> v;
int main()
{
    cin>>n>>m>>t;
    /*v.push_back((point){0,0});
    v.push_back((point){0,m});
    v.push_back((point){n,0});
    v.push_back((point){n,m});*/
    for (int i = 0; i < t; i++)
    {
        cin>>a>>b;
        v.push_back((point){a,b});
    }
    sort(v.begin(), v.end(), cmpx);
    ll MGAP = 0, MAXR = 0;
    for (int i = 0; i < v.size()-1; i++)
    {
        MGAP = max(MGAP, v[i+1].x - v[i].x);
    }
    MGAP = max(MGAP, v[0].x);
    MGAP = max(MGAP, n-v[t-1].x);
    MAXR = max(MAXR, 1LL*MGAP * m);
    sort(v.begin(), v.end(), cmpy);
    for (int i = 0; i < v.size(); i++)
    {
        //cout<<"compute point "<<v[i].x<<" "<<v[i].y<<" :\n";
        int tl = 0, tr = n;
        for (int j = i+1; j < v.size(); j++)
        {
            //cout<<"compare with point "<<v[j].x<<" "<<v[j].y<<" :\n";
            if (tl < v[j].x && v[j].x < tr)
            {
                MAXR = max(MAXR, 1LL*(tr-tl) * (v[i].y-v[j].y));
                if (v[j].x < v[i].x)
                    tl = v[j].x;
                else
                    tr = v[j].x;
            }
            MAXR = max(MAXR, 1LL*(tr - tl) * (v[i].y - 0));
            //cout<<"CURRENT MAXN: "<<MAXR<<"\n";
            //cout<<"tl is "<<tl<<" tr is "<<tr<<"\n";
        }
    }
    sort(v.begin(), v.end(), cmpx);
    for (int i = 0; i < v.size(); i++)
    {
        int ri = -1, li = -1;
        for (int j = i-1; j >= 0; j--)
            if (v[j].y > v[i].y)
            {
                li = v[j].x;
                break;
            }
        for (int j = i+1; j < v.size(); j++)
            if (v[j].y > v[i].y)
            {
                ri = v[j].x;
                break;
            }
        if (li==-1) li = 0;
        if (ri==-1) ri = n;
        MAXR = max(MAXR, 1LL*(ri-li) * (m-v[i].y));
    }
    cout<<MAXR<<endl;
}

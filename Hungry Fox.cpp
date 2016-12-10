#include <bits/stdc++.h>
using namespace std;
int N, W;
vector <long long> v;
long long pfwd[100010], pbck[100010];
int main()
{
    cin>>N>>W;
    for (int i = 0; i < N; i++)
    {
        long long t;
        cin>>t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    /*for (int i : v)
        cout<<i<<endl;*/
    long long tmin = 0, tmin2 = 0;
    int cur = W;
    for (int i = 1; i <N; i++)
    {
        long long minn = min(abs(v[i]-v[i-1]), abs(W-v[i]));
        pfwd[i] = minn + pfwd[i-1];
    }
    for (int i = N-2; i >= 0; i--)
    {
        long long minn = min(abs(v[i]-v[i+1]), abs(W-v[i]));
        pbck[i] = minn + pbck[i+1];
    }
    tmin = abs(W-v[0]) + pfwd[N-1];
    tmin2 = abs(W-v[N-1]) + pbck[0];
    long long fmin = min(tmin,tmin2);
    for (int i = 1; i < N-1; i++)
    {
        long long rs = abs(W-v[i]) + pfwd[N-1] - pfwd[i] + min(abs(v[N-1] - v[i-1]),abs(W-v[i-1])) + pbck[0] - pbck[i-1];
        long long ls = abs(W-v[i]) + pbck[0] - pbck[i] + min(abs(v[0] - v[i+1]), abs(W-v[i+1])) + pfwd[N-1] - pfwd[i+1];
        fmin = min(fmin,min(rs,ls));
    }
    //cout<<fmin<<endl;
    //max
    long long tmax = 0, tmax2 = 0;
    cur = W;

    int l = 0, r = N-1;
    while (true)
    {
        //cout<<cur<<endl;
        tmax += max(abs(cur - v[l]), abs(W - v[l]));
        cur = v[l];
        l++;
        //cout<<l<<endl;
        if (l>r) break;
        //cout<<cur<<endl;
        tmax += max(abs(cur - v[r]), abs(W - v[r]));
        cur = v[r];
        r--;
        //cout<<r<<endl;
        if (l>r) break;
    }
    cur = W;
    l = 0, r = N-1;
    while (true)
    {
        tmax2 += max(abs(cur - v[r]), abs(W - v[r]));
        cur = v[r];
        r--;
        if (l>r) break;
        tmax2 += max(abs(cur - v[l]), abs(W - v[l]));
        cur = v[l];
        l++;
        if (l>r) break;
    }
    cout<<fmin<<" "<<max(tmax, tmax2);
}

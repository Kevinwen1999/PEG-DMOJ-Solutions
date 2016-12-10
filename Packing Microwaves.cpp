#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    int N; cin>>N;
    long long x, y, z; cin>>x>>y>>z;
    long long a, b, c; cin>>a>>b>>c;
    bool work = false;
    long long best = 0x3f3f3f3f, s, ans;
    s = (a / x) * (b / y) * (c / z);
    if (s != 0)
    {
    	work = true;
    	ans = N/s  + (N%s? 1 : 0);
    	best = min(best, ans);
    }
    s = (a / y) * (b / x) * (c / z);
	if (s != 0)
    {
    	work = true;
    	ans = N/s  + (N%s? 1 : 0);
    	best = min(best, ans);
    }
    s = (a / z) * (b / y) * (c / x);
	if (s != 0)
    {
    	work = true;
    	ans = N/s  + (N%s? 1 : 0);
    	best = min(best, ans);
    }
    s = (a / y) * (b / z) * (c / x);
	if (s != 0)
    {
    	work = true;
    	ans = N/s  + (N%s? 1 : 0);
    	best = min(best, ans);
    }
    s = (a / z) * (b / x) * (c / y);
	if (s != 0)
    {
    	work = true;
    	ans = N/s  + (N%s? 1 : 0);
    	best = min(best, ans);
    }
    s = (a / x) * (b / z) * (c / y);
	if (s != 0)
    {
    	work = true;
    	ans = N/s  + (N%s? 1 : 0);
    	best = min(best, ans);
    }
    if (!work) cout<<"SCAMMED";
    else cout<<best;
}

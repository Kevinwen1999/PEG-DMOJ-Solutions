#include <bits/stdc++.h>
#define ll long long
using namespace std;
int P, N, V;
double R;
int x[100010], y[100010];
int a[12];
int main()
{
    cin>>P>>N>>V>>R;
    for (int i = 0; i < P; i++)
    {
        cin>>x[i]>>y[i];
    }
    for (int i = 1; i <=N; i++)
        cin>>a[i];
    int vx = V;
    ll vy = 0;
    for (int i = 1; i <= N; i++)
    {
        vy += a[i] * pow(vx,N-i+1);
    }
    int tot = 0;
    for (int b = 0; b < P; b++)
    {
        ll yy=0;
        for (int i = 1; i <= N; i++)
        {
            yy += a[i] * pow(x[b],N-i+1);
        }
        if (yy==y[b] && x[b]<=V)
        {
            tot++;
            continue;
        }
        double dist = hypot(vx-x[b],vy-y[b]);
        if (dist <= R)
        {
            tot++;
            continue;
        }
    }
    cout<<tot<<"\n";
}

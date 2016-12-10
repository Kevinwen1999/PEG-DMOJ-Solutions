#include <iostream>
using namespace std;
#define MAXN 100000 + 10
#define INF 0x3f3f3f3f
int N, p[MAXN], f[MAXN], K;
int moves(int maxf)
{
    int cur = 0, tot = 0;
    if (p[0] - cur > maxf) return INF;
    for (int i = 0 ; i < N-1; i++)
    {
        if (f[i])
        {
            if (p[i] - cur > maxf) return INF;
            tot++;
            cur = p[i];
        }
        else if (p[i+1] - cur > maxf)
        {
            tot++;
            cur = p[i];
        }
    }
    if (p[N-1] - cur > maxf) return INF;
    return tot + 1;
}
int main()
{
    cin>>N>>K;
    for (int i = 0 ; i < N; i++)
        cin>>p[i]>>f[i];
    int l = 0, r = 99999999, mid;
    while(l<=r)
    {
        mid = (l+r)>>1;
        if (moves(mid) <= K)
        {
            r = mid-1;
        }
        else
        {
            l = mid+1;
        }
    }
    if (l >= 99999999)
        cout<<"DEA Bust!"<<endl;
    else
        cout<<l<<endl;
}

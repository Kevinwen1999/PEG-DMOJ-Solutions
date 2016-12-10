#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAXN 100010
#define ll long long
using namespace std;
int N;
ll D[MAXN], W[MAXN];
ll hit[MAXN], gethit[MAXN], reduced[MAXN];
// hit: current pillar hit the previous one without getting hit from next one
// gethit: current pillar get hit from previous one without getting hit from next one
// reduced : current pillar getting hit from right and also left is possible
int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld%lld", &D[i], &W[i]);
    }
    reduced[0] = max(1LL*0, D[0] - W[1]);
    gethit[0] = hit[0] = D[0];
    for (int i = 1; i < N; i++)
    {
        // hit current one with cost D[i] + reduced cost of previous one
        hit[i] = D[i] + reduced[i-1];
        // current one get hit from previous one, meaning the previous one is not reduced by current one
        gethit[i] = min(gethit[i-1], hit[i-1]) + (D[i]-W[i-1] > 0 ? D[i]-W[i-1] : 0);
        // reduce current one by hitting from both side
        reduced[i] = max(1LL*0,D[i]-W[i+1]-W[i-1]) + min(gethit[i-1], hit[i-1]);
        // reduce current one only by the right side
        reduced[i] = min(reduced[i], max(1LL*0,D[i]-W[i+1]) + reduced[i-1]);
    }
    cout<<min(hit[N-1],gethit[N-1]);
}

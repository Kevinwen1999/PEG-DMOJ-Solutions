#include <bits/stdc++.h>
#define MAXN 1000001
using namespace std;
int h[MAXN];
long long cnt[MAXN];
int N, Q;
int main()
{
    scanf("%d%d", &N, &Q);
    for (int i = 0; i < N; i++)
        scanf("%d", &h[i]);
    h[N] = N;
    deque <pair <int,int> > D;
    for (int i = 0; i < N; i++)
    {
        int tot = 0;
        while (D.size() > 0 && D.back().first >= h[i])
        {
            int l = 0, r = 0;
            l += i - D.back().second;
            if (D.back().first==h[i]) l++;
            pair <int, int > tmp = D.back();
            D.pop_back();
            if (D.size()>0)
            {
                r += tmp.second - D.back().second;
                if (tmp.first==D.back().first) r++;
            }
            else
                r = tmp.second+1;
            cnt[tmp.first] += 1LL*l*r;
        }
        D.push_back({h[i], i});
    }
    while(!D.empty())
    {
        int l = 0, r = 0;
        pair <int, int > tmp = D.back();
        D.pop_back();
        l += (N-1) - tmp.second + 1;
        if (!D.empty())
        {
            r += tmp.second - D.back().second;
            if (tmp.first == D.back().first) r++;
        }
        else
            r = tmp.second+1;
        cnt[tmp.first]+=1LL*l*r;
    }
    for (int i = 1; i <= MAXN; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0, a, b; i < Q; i++)
    {
        scanf("%d%d", &a, &b);
        printf("%lld\n", cnt[b]-cnt[a-1]);
    }
}

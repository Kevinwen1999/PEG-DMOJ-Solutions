#include <bits/stdc++.h>

using namespace std;
const int MAXN = 100001;

long long BIT[MAXN];
long long cnt[MAXN];
void update(int x, long long (&tree)[MAXN], int v)
{
    for (;x < MAXN; x+=(x & -x))
        tree[x]+=v;
}
long long query(int x, long long (&tree)[MAXN])
{
    long long sum = 0;
    for (;x >0; x-=(x&-x))
        sum+=tree[x];
    return sum;
}
int N, M;
int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 1,tmp; i <= N; i++)
    {
        scanf("%d", &tmp);
        update(i,BIT,tmp);
        update(tmp,cnt,1);
    }
    char in;
    for (int i = 0 ; i < M; i++)
    {
        scanf(" %c", &in);
        if (in == 'C')
        {
            int a, b;
            scanf("%d %d", &a, &b);
            int v = query(a, BIT) - query(a-1,BIT);
            update(a,BIT,b-v);
            update(v,cnt,-1);
            update(b,cnt,1);
        }
        else if (in == 'S')
        {
            int a, b;
            scanf("%d %d", &a, &b);
            printf("%lld\n", query(b,BIT) - query(a-1,BIT));
        }
        else
        {
            int a;
            scanf("%d", &a);
            printf("%lld\n",query(a,cnt));
        }
    }
    return 0;
}

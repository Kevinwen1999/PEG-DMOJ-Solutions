#include <bits/stdc++.h>
#define B 100000 // balance out negative wage
#define MAXN 200002 + B
using namespace std;
int N, minn;
int bit[MAXN];
void update(int x, int v)
{
    for (x;x < MAXN; x += (x & -x))
        bit[x]+=v;
}
int query(int a)
{
    int sum  = 0;
    for (a; a > 0; a-=(a & -a))
        sum+=bit[a];
    return sum;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>minn;
    int tot = 0, totleft = 0, sub = 0;
    for (int i = 0; i < N; i++)
    {
        char op;
        int v;
        cin>>op >> v;
        if (op=='I')
        {
            if (v < minn)
            {
                //totleft++;
                continue;
            }
            update(v+B+sub, 1); // original value + B + sub(shifted value)
            tot++;
        }
        else if (op=='A')
        {
            sub-=v;
        }
        else if (op=='S')
        {
            sub += v;
            int fire = query(minn+sub-1+B);
            tot -= fire;
            totleft += fire;
            for (int j = 1; j <= minn+sub-1+B; j++)
                update(j,-bit[j]);
        }
        else if (op=='F')
        {
            int l = 1, h = MAXN;
            if (v > tot)
            {
                printf("-1\n");
                continue;
            }
            int k = tot - v+1;
            while (l<=h)
            {
                int mid = l+(h-l)/2;
                if (query(mid) < k)
                    l = mid+1;
                else
                    h = mid-1;
            }
            printf("%d\n", l-B-sub);
        }
    }
    printf("%d\n", totleft);
}

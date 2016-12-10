#include <iostream>
#include <algorithm>
#define MAXN 2010
#define MOD 1000000007
using namespace std;
int bit[MAXN][MAXN];
void update(int x, int y ,int v)
{
    for (;x < MAXN; x += (x & -x))
        bit[y][x]= (bit[y][x] + v)%MOD;
}
int query(int x, int y)
{
    int sum  = 0;
    for (int a = x; a > 0; a-=(a & -a))
    {
        sum= (sum + bit[y][a]) % MOD;
    }
    return sum;
}
int main()
{
   /* ios::sync_with_stdio(0);
    cin.tie(0);*/
    int N; scanf("%d", &N);
    long long su = 0;
    while (N--)
    {
        int op; scanf("%d", &op);
        if (op==1)
        {
            int r, c, v;
            scanf("%d%d%d", &r,&c,&v);
            update(r,r+c, v);
        }
        else
        {
            int r, c, x;
             scanf("%d%d%d", &r,&c,&x);
            long long s = query(r,r+c) - query(r-x-1, r+c);
            su = (su + s) % MOD;
        }
    }
    cout<<su;
}

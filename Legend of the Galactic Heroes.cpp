#include <bits/stdc++.h>
#define MAXN 30010
using namespace std;
int p[MAXN], rnk[MAXN], tot[MAXN];
void init(int N)
{
    for (int i = 0; i <= N; i++)
        p[i] = i, rnk[i] = 0, tot[i] = 1;
}
int findp(int x)
{
    if (x==p[x]) return x;
    else
    {
        int t = findp(p[x]);
        rnk[x] += rnk[p[x]];
        p[x] = t;
        return t;
    }
}
void mergeset(int x, int y)
{
    x = findp(x), y = findp(y); // EXTREMELY IMPORTANT !!!!!!!!!
    p[x] = y;
    rnk[x] += tot[y];
    tot[y] += tot[x];
}
int main()
{
    int T; cin>>T;
    char op; int a,b;
    init(30001);
    for (int i = 0; i < T; i++)
    {
        cin>>op>>a>>b;
        if (op=='M')
        {
            mergeset(a,b);
        }
        else
        {
            if (findp(a)!=findp(b)) {cout<<"-1\n"; continue;}
            //cout<<findd(x)<<" "<<findd(y)<<"\n";
            cout<<abs(rnk[b]-rnk[a])-1<<"\n";
        }
    }
}

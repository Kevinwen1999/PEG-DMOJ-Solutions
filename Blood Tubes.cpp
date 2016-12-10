#include <bits/stdc++.h>
using namespace std;
vector <int> all;
const int MAXN = 500001;
int bit_front[MAXN], bit_back[MAXN];
void update(int x, int v, int bit[])
{
    for (;x < MAXN; x += (x & -x))
        bit[x]+=v;
}
int query(int a, int bit[])
{
    int sum  = 0;
    for (; a > 0; a-=(a & -a))
        sum+=bit[a];
    return sum;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin>>N;
    long long sum = 0;

    for (int i = 0, a; i < N; i++)
    {
        cin>>a;
        //cout<<a<<"\n";
        int x = query(a,bit_front), y = query(N-a+1, bit_back);
        sum += min(x,y);
        update(a,1,bit_front); update(N-a+1,1,bit_back);
        //cout<<sum<<"\n";
    }
    cout<<sum;
}

#include <bits/stdc++.h>
using namespace std;
int N;
string op;
int n, last, laststop = 25;
int dir = 1;
char tar;
long long sum[30];
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for (int i = 0; i < N; i++)
    {
        cin>>op>>n;
        if (op=="UPIT") cin>>tar;
        int nup = n-last;
        last = n;
        int q = nup/26, r = nup%26;
        for (int i = 0; i < 26; i++)
            sum[i]+=q;
        int nlast = laststop;
        for (int i = 1; i <= r; i++)
        {
            nlast = (laststop+i*(dir) + 26)%26;
            sum[nlast]++;
        }
        laststop = nlast;
        if (op=="UPIT")
        {
            printf("%d\n", sum[tar-'a']);
        }
        else
            dir = -dir;
    }
}

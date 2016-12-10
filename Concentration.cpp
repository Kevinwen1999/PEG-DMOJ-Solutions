#include <bits/stdc++.h>
using namespace std;
int T, N, W, H;
/*

2*(W*a+H*b) + 2*(W*x + H*y)
2*(W(a+x) + H(b+y))
*/
int main()
{
    cin>>T;
    for (int a = 0; a < T; a++)
    {
        cin>>N>>W>>H;
        int per = 999999999;
        for (int i = 1; i <= N; i++)
        {
            if (N % i==0)
            {
                int w = i * W, h = (N/i)*H;
                per = min(per, 2*(w+h));
            }
        }
        for (int i = 1; i < N; i++)
        {
            int w = W * i;
            if (w % H ==0)
            {
                int j = w / H;
                for (int k = 1; k*j <= N-i; k++)
                {
                    int extra = N-i-k*j;
                    if (extra % i== 0)
                    {
                        per = min (per, 2 * (w + H*(1+extra/i) + W*(k)));
                    }
                }
            }
        }
        cout<<per<<"\n";
    }
}

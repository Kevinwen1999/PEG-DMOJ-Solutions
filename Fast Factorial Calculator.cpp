#include <bits/stdc++.h>
using namespace std;
unsigned long long in, i;
unsigned int ans;
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%llu", &in);
        if (in>=34)
            printf("0\n");
        else
        {
            ans = 1;
            for (i = 1; i <= in; i++)
            {
                ans = ans * i;
            }
            printf("%u\n", ans);
        }
    }
}

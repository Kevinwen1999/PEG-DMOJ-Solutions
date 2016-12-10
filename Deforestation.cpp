#include <iostream>
using namespace std;
int N, Q;
long long p[1000001];
int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        int t;
        scanf("%d", &t);
        p[i] = p[i-1] + t;
    }
    scanf("%d", &Q);
    for (int i = 0 ; i < Q; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a++, b++;
        printf("%lld\n", p[b] - p[a-1]);
    }
}

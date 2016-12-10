#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 500001 + 10;
int N;
long long W;
long long pp[MAXN], pc[MAXN], dp[MAXN];
int top = 1;
int main()
{
    scanf(" %d %lld", &N, &W);
    for (int c = 0 ; c < N; c++)
    {
        char t;
        scanf(" %c", &t);
        if (t=='A')
        {
            long long tp, tc;
            scanf(" %lld %lld", &tp, &tc);
            pp[top] = pp[top-1] + tp;
            pc[top] = pc[top-1] + tc;
            int l = 0, h = top;
            long long tmp;
            while (l <= h)
            {
                int mid = l + (h-l) / 2;
                tmp = pp[top] - pp[mid];
                if (tmp<= W)
                    h = mid - 1;
                else
                    l = mid + 1;
            }
            tmp = pc[top] - pc[l];
            dp[top] = max(dp[top-1], tmp);
            printf("%lld\n", dp[top]);
            top++;
        }
        else
            top--;
    }
}

#include <iostream>
#include <algorithm>
using namespace std;
int N, K;
double KK;
int arr[300003];
double pre[300003];
int main()
{
    scanf("%d%d", &N, &K);
    for (int i = 1 ; i <= N; i++)
        scanf("%d", &arr[i]);
    double lo = 0, hi = 1<<30;
    while ((hi-lo) > 0.000000001)
    {
        double avg = lo + (hi - lo) / 2;
        bool OK = false;
        for (int i = 1; i <= N; i++)
            pre[i] = arr[i] + pre[i-1] - avg;
        double minn = 0;
        for (int i = K; i <= N; i++)
        {
            if (pre[i] >= minn) OK = true;
            minn = min(minn, pre[i-K+1]);
        }
        if (!OK) hi = avg;
        else lo = avg;
    }
    printf("%.6lf", lo);
}

#include <bits/stdc++.h>
using namespace std;
int num[100001];
vector <int> v[100001];
int K, A, B, T;
int main()
{
    for (int i = 1; i < 100001; i++)
            for (int j = i; j < 100001; j+=i)
                num[j]++;
    for (int i = 1; i < 100001; i++)
    {
        v[num[i]].push_back(i);
    }
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d %d", &K, &A, &B);
        if (B < A) {int C = B; B = A; A = C;}
        int cnt = 0;
        auto low = lower_bound(v[K].begin(), v[K].end(), A);
        auto up = upper_bound(v[K].begin(), v[K].end(), B);
        printf("%d\n", up - low);
    }
}

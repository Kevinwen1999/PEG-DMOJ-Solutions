#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K; cin>>N>>K;
    if (1LL*K*K<N) {cout<<-1; return 0;}
    //Erdos-Szekeres theorem (on monotone subsequences).
    //A sequence of length mn+1 has an increasing subsequence m+1 long, or a length n+1 decreasing subsequence
    //In other words, in any sequence of length there has to be a monotone subsequence of length at least sqrt(N)
    //A good proof? http://math.stackexchange.com/questions/616027/how-long-does-a-sequence-need-to-be-to-be-guaranteed-to-have-a-monotonic-subsequ

    for (int i = N; i >= 1; i-=K)
        for (int j = max(1, i-K+1); j <= i; j++)
            printf("%d ", j);
    return 0;
}

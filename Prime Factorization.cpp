#include <bitset>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector <int> vi;
ll sieve_size;
bitset <10000010> bs;
vi primes;
int N;
void sieve(ll upper)
{
    sieve_size = upper +1;
    bs.set();
    for (ll i = 2; i <= sieve_size; i++)
        if (bs[i])
        {
            for (ll j = i*i; j < sieve_size; j+=i)
                bs[j] = 0;
            primes.push_back((int)i);
        }
}
vi primefactors(ll N)
{
    vi factors;
    ll idx = 0, PF = primes[idx]; // sieve first
    while (PF * PF <= N) //stop at sqrt(N)
    {
        while (N % PF ==0)
        {
            N/= PF;
            factors.push_back(PF);
        }
        PF = primes[++idx];
    }
    if (N != 1) factors.push_back(N);
    return factors;
}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    sieve(10000000);
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int in;
        scanf("%d", &in);
        vi ans = primefactors(in);
        for (int i = 0 ; i < ans.size(); i++)
            printf("%d ", ans[i]);
        printf("\n");
    }
}

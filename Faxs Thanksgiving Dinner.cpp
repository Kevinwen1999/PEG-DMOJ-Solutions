#include <bits/stdc++.h>
#define MAXN 1010
#define MAXR 1000010
using namespace std;
typedef long long ll;
typedef vector <int> vi;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
ll sieve_size;
bitset <1000010> bs;
vi primes;
// Sieve of E
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
int c[MAXN];
int a[MAXN];
set <int> cuts;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    sieve(1000000);
    int N, C;
    cin>>N>>C;
    for (int i = 0; i < C; i++)
    {
        cin>>c[i];
        int n = c[i];
        for (int j = 0; j < primes.size(); j++)
        {
            if (n % primes[j] == 0)
            {
                cuts.insert(primes[j]);
                while (n % primes[j]==0)
                {
                    n/= primes[j];
                }
            }
            if (n==1) break;
        }
    }
    for (int i = 0; i < N; i++)
    {
        cin>>a[i];
        int n = a[i];
        for (int j = 0; j < primes.size(); j++)
        {
            if (n % primes[j] == 0)
            {
                if (cuts.count(primes[j])==0)
                {
                    cout<<"N";
                    return 0;
                }
                while (n % primes[j]==0)
                {
                    n/= primes[j];
                }
            }
            if (n==1) break;
        }
    }
    cout<<"Y";
}

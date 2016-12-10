#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector <int> vi;
ll sieve_size;
bitset <150010> bs;
vi primes;
//int nDiffPM[148740];
// Sieve of E
int n;
int x;
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
int main()
{
    cin>>n>>x;
    int counter = 0;
    sieve(n);

    for (int i = 0; i < primes.size() && primes[i] <= n; i++)
    {
        if ((n - primes[i]) % x ==0)
            counter += 2 * ((n-primes[i]) / x + 1) - 1;
        else
            counter += 2 * ((n-primes[i]) / x + 1);
    }
    cout<<counter;
    return 0;
}

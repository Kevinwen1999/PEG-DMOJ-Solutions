#include <bits/stdc++.h>
#define MAXN 100000000
using namespace std;
typedef long long ll;
typedef vector <int> vi;
ll sieve_size;
bitset <MAXN> bs;
vi primes;
long long sum = 0;
int a,b,c,d;
// Sieve of E
void sieve(ll upper)
{
    sieve_size = upper +1;
    bs.set();
    for (ll i = 2; i <= sieve_size && i < MAXN; i++)
        if (bs[i])
        {
            primes.push_back((int)i);
            for (ll j = i*i; j < sieve_size && j < MAXN; j+=i)
            {
                bs[j] = 0;
            }
        }
}
bool isprime(ll N)
{
    if (N <= sieve_size) return bs[N];
    for (int i = 0; i < (int)primes.size(); i++)
    {
        if (N % primes[i]==0)return false;
    }
    return true;
}

int main()
{
    cin>>a>>b>>c>>d;
    sieve(100000);
    for (int i = a; i <= b; i++)
    {
        if (isprime(i))
        {
            for (int j = 1;; j++)
            {
                if (i*j < c ) continue;
                else if (i*j > d) break;
                sum += i*j;
                sum %= 2016420;
            }
        }
    }
    cout<<sum;
}

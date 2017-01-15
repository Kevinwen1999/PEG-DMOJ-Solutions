#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
typedef vector <ll> vi;
long long sp1, sp2;
ll sieve_size;
bitset <20000010> bs;
vi primes;
ll N, M;
// Sieve of E
void sieve(ll upper)
{
    sieve_size = upper;
    bs.set();
    for (ll i = 3; i <= sieve_size; i+=2)
        if (bs[i])
        {
            for (ll j = i*i; j < sieve_size; j+=i)
                bs[j] = 0;
            primes.push_back(i);
        }
}
void segmented_sieve(ll upper)
{
    //cout<<sqrt(upper)<<"\n";
    ll limit = ceil(sqrt(upper));
    sieve(limit);

    ll low = N, high = M;
    //cout<<low<<"\n";
    bs.set();
    ll lomin;
    for (int i = 0; i < primes.size(); i++)
    {
        //cout<<primes[i]<<"\n";
        lomin = floor(low/primes[i])*primes[i];
        if (lomin < low)
            lomin += primes[i];
        for (ll j = lomin; j <high; j+=primes[i])
            bs[j-low] = false;
        if (primes[i] >= N && primes[i] < M) bs[primes[i]-low] = true;
    }
    //cout<<"done1\n";
    for (ll i = (low%2 ? low : low+1) ; i < high; i+=2)
    {
        if (bs[i-low] || i==2)
        {
            sp1++;
        }
    }
}

int main()
{
    cin>>N>>M;
    //cout<<N<<" "<<M;
    segmented_sieve(M);
    cout<<sp1<<"\n";
}

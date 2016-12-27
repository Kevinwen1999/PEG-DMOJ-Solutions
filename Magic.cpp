#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector <int> vi;

ll sieve_size;
bitset <1000010> bs;
vi primes;
// Sieve of E
void sieve(ll upper)
{
    sieve_size = upper;
    bs.set();
    bs[0] = bs[1] = false;
    for (ll i = 2; i <= sieve_size; i++)
        if (bs[i])
        {
            for (ll j = i*i; j < sieve_size; j+=i)
                bs[j] = 0;
            primes.push_back((int)i);
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
int K, D;
int sa, sb;
int pa, pb;
int main()
{
    sieve(5000);
    cin>>K>>D>>sa>>sb>>pa>>pb;
    int turn = 0;
    int ca = pa, cb = pb;
    if (abs(ca-cb) < D || abs(ca-cb+K)< D )
    {
        if (ca>=cb)
            cb = ((ca-D)+ K)%K;
        else
            cb = (ca+D)%K;
    }
    while (true)
    {
        if (turn > 10000000) break;
        turn++;
        ca = (ca+sa)%K, cb = (cb + sb) % K;
        if (abs(ca-cb) < D || abs(ca-cb+K)< D )
        {
            if (ca>=cb)
                cb = ((ca-D) + K)%K;
            else
                cb = (ca+D)%K;
        }
        if (isprime(min(ca, K-ca)+min(cb,K-cb)))
        {
            cout<<"Alice\n"; return 0;
        }
    }
    cout<<"Bob\n"; return 0;
}

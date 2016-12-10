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
bool isprime(ll N)
{
    if (N <= sieve_size) return bs[N];
    for (int i = 0; i < (int)primes.size(); i++)
    {
        if (N % primes[i]==0)return false;
    }
    return true;
}
int N;
ll sum[10010];
int main()
{
    sieve(1000000);
    int T; cin>>T;
    while (T--)
    {
        memset(sum,0,sizeof sum);
        int N;
        cin>>N;
        for (int i = 1; i <= N; i++)
        {
            cin>>sum[i];
            sum[i] += sum[i-1];
        }
        bool OK = true;
        for (int l = 2; l <= N && OK; l++)
        {
            for (int i = l; i <= N && OK; i++)
            {
                ll cm = sum[i] - sum[i-l];
                if (isprime(cm))
                {
                    cout<<"Shortest primed subsequence is length "<<l<<": ";
                    for (int j = i-l+1; j <= i; j++)
                        cout<<sum[j]-sum[j-1]<<" ";
                    cout<<"\n";
                    OK = false;
                }
            }
        }
        if (OK)
            cout<<"This sequence is anti-primed.\n";
    }
}

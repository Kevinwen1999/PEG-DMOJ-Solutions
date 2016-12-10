#include <bits/stdc++.h>
using namespace std;
int N;
inline long long gcd(long long a, long long b){return b == 0 ? a : gcd(b,a%b);}
vector <long long> v;
int main()
{
    cin>>N;
    for (int i = 0,a; i < N; i++)
    {
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    long long g = v[N-1];
    for (int i = 1; i < N; i++)
    {
        if (v[i]%v[i-1]!=0) {cout<<"0\n"; return 0;}
            g = gcd(g,v[i]/v[i-1]);
    }
    cout<<g<<"\n";
}

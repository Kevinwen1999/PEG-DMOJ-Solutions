#include <bits/stdc++.h>
using namespace std;
int N, Q;
set <int> S;
unordered_map<int, int> M;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for (int i = 0, t; i < N; i++)
    {
        cin>>t;
        S.insert(t);
        M[t]++;
    }
    cin>>Q;
    for (int i = 0, t; i < Q; i++)
    {
        cin>>t;
        set <int>:: iterator it = S.lower_bound(t);
        cout<<*it<<" "<<M[*it]<<"\n";
    }
}

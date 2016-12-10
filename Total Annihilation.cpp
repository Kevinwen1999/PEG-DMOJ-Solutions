#include <bits/stdc++.h>
using namespace std;
int N, M;
vector <int> A;
unordered_map<long long, int> m;
int main()
{
    cin>>N>>M;
    for (int i = 0, a; i < N; i++)
    {
        cin>>a;
        A.push_back(a);
    }
    for (int i = 0, a; i < M; i++)
    {
        cin>>a;
        A.push_back(-a);
    }
    int mid = (N+M)/2;
    //for (int i = 0; i < mid; i++) cout<<A[i]<<endl;
    //for (int i = 0; i < N+M-mid; i++) cout<<A[i+mid]<<endl;
    long long sum1,cnt = 0;
    for (unsigned long long a = 1; a < (1<<mid); a++)
    {
        sum1 = 0;
        for (int i = 0; i < mid; i++) {if (a&(1<<i)) sum1 += A[i];}
        if (sum1==0) cnt++;
        else m[sum1]++;
    }
    for (unsigned long long a = 1; a < (1<<(N+M-mid)); a++)
    {
        sum1 = 0;
        for (int i = 0; i < (N+M-mid); i++) {if (a&(1<<i)) sum1 += A[i+mid];}
        if (sum1==0) cnt++;
        else if (m.count(-sum1)) cnt += m[-sum1];
    }
    cout<<cnt<<"\n";
}

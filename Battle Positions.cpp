#include <iostream>
#include <cstring>
using namespace std;
int I, N,J;
long long d[100001];
int main()
{
    cin>>I>>N>>J;
    for (int i = 0, x1, x2, k; i < J; i++)
    {
        cin>>x1>>x2>>k;
        x1--;
        d[x1]+=k; d[x2]-=k;
    }
    for (int i = 1 ; i < I; i++)
        d[i] = d[i]+d[i-1];
    int cnt = 0;
    for (int i = 0 ; i < I; i++)
    {
        if (d[i]<N)
            cnt++;
    }
    cout<<cnt<<endl;
}

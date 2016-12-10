#include <iostream>
#include <algorithm>

using namespace std;
long long N, K;
int main()
{
    cin>>N>>K;
    if (N < K)
        cout<<K-N;
    else
        cout<<min(N%K, K - (N%K));
}

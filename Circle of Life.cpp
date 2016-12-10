#include <iostream>
#include <cstring>
#define ll long long
using namespace std;
int N;
ll T;
string in;
int ori[100001], tmp[100001];
int main()
{
    cin>>N>>T;
    cin>>in;
    for (int i = 0; i < N; i++)
        ori[i] = in[i] - '0';
    for (int i = 50; i >= 0; i--)
    {
        if ((T>>i)&1)
        {
            int p1 = (1LL<<i) % N;
            int p2 = (N-p1) % N;
            for (int i = 0 ; i < N; i++)
                tmp[i] = ori[(i+p1) % N] ^ ori[(i+p2)%N];
            memcpy(ori, tmp, sizeof ori);
        }
    }
    for (int i = 0 ; i < N; i++)
        cout<<ori[i];
    cout<<"\n";
}

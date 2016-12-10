#include <iostream>
using namespace std;
int ways[7];
int main()
{
    int N;
    cin>>N;
    for (int i = 1; i <= N; i++) ways[i] = 1;
    for (int i = 1; i < N; i++)
    {
        int pa;
        cin>>pa;
        ways[pa] = ways[pa] * (1+ways[i]);
    }
    cout<<ways[N];
}

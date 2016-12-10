#include <iostream>
#include <cmath>
using namespace std;
int N;
int main()
{
    cin>>N;
    int cost = 0;
    while (N>1)
    {
        for ( int i = 2; i <= N ; i++)
        {
            if (N%i==0)
            {
                int x = N / i;
                N -= x;
                cost+= N / x;
                break;
            }
        }
    }
    cout<<cost<<endl;
    return 0;
}

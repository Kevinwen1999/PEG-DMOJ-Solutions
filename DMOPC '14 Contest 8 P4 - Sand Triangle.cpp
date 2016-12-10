#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long N;
    cin>>N;
    int start = 1, pre;
    for (long long i = 0 ;;i++)
    {
        start+=i;
        if (start>N)
        {
            long long sum = 0;
            for (long long i = pre; i <start ;i++)
            {
                sum+=i;
            }
            cout<<sum<<endl;
            return 0;
        }
        pre = start;
    }
}

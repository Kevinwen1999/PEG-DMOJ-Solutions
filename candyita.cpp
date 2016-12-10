#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    int x;
    cin>>n>>x;
    int counter = 0;
    for (int i = 2; i <= n; i++)
    {
        int total = n;
        bool isPrime = true;
        for (int j = 2; j <= sqrt(i); j++ )
        {
            if (i%j==0)
            {
                isPrime = false;

            }
        }
        if (isPrime == true)
        {

            total-=i;


        for (int k = 0; k <= total; k++)
        {
            if(k%x==0)
            {

            if ((total-k)>0)
            {
                counter+=2;
            }
            if ((total-k)==0)
            {
                counter++;
            }

            }
        }
        }

    }
    cout<<counter;
    return 0;
}

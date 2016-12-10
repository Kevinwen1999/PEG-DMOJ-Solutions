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
        {cout<<"prime::"<<i<<endl;

            total-=i;
            cout<<"total:"<<total<<endl;


        for (int k = 0; k*x <= total; k++)
        {
            int temp = k*x;


            if ((total-temp)>0)
            {
                counter+=2;
                cout<<"counter+2"<<endl;
            }
            if ((total-temp)==0)
            {
                counter++;
                cout<<"counter++"<<endl;
            }
            if(temp==1&&x==1)
            {
                break;
            }

cout<<"counter=="<<counter<<endl;

        }
        }

    }
    cout<<counter;
    return 0;
}

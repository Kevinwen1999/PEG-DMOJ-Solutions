#include <iostream>
#include <algorithm>
//Not entirely correct
using namespace std;
int curmax = 0;
int N;
int n;
int X[100001];
int Y[100001];
int main()
{
    cin>>N;
    while(N--)
    {
        cin>>n;
        curmax = 0;
        for (int i = 0 ; i < n; i++)
        {
            cin>>X[i];
        }
        for (int i = 0 ; i < n; i++)
        {
            cin>>Y[i];
        }
        for (int i = 0 ; i < n; i++)
        {
            int low = 0,high = n-1,mid;
            while (low<=high)
            {
                mid = ( low+high ) /2;
                if (Y[mid]>=X[i])
                {
                    low = mid+1;
                }
                else
                {
                    high = mid-1;
                }
            }
            curmax = max(curmax,mid-i);
           // cout<<curmax<<endl;
        }
        cout<<"The maximum distance is "<<curmax<<endl;
    }
}

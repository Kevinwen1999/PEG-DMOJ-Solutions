#include <iostream>
using namespace std;
int N;
int arr[25];
int main()
{
    while (cin>>N && N)
    {
        for (int i = 0 ; i < N; i++)
            cin>>arr[i];
        if (N==1) {cout<<"0\n"; continue;}
        for (int i = 1; i <= N; i++)
        {
            int j;
            for (j = 1;;j++)
            {
                if ((j + i > N-1 )||(arr[j]-arr[j-1] != arr[j+i] - arr[j+i-1])) break;
            }
            if (j+i > N-1) {cout<<i<<"\n"; break;}
        }
    }
}

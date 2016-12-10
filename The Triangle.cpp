#include <bits/stdc++.h>
using namespace std;
int N;
int arr[110][110];
int maxx = 0;
int main()
{
    cin>>N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int a;
            cin>>a; arr[i][j] += a;
            if (i==N-1)
            {
                maxx = max(maxx, arr[i][j]);
            }
            else
            {
                arr[i+1][j] = max(arr[i+1][j], arr[i][j]);
                arr[i+1][j+1] = max(arr[i+1][j+1], arr[i][j]);
            }
        }
    }
    cout<<maxx<<"\n";
}

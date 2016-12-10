#include <bits/stdc++.h>
using namespace std;
int arr[60];
int N;

int main()
{
    int T; cin>>T;
    while (T--)
    {
        cin>>N;
        for (int i = 0; i < N; i++)
        {
            cin>>arr[i];
        }
        int j = 0;
        int tot = 0;
        while(j++ != N)
        {
            bool swapped = false;
            for(int i = 0; i < N - j; i++)
            {
                if(arr[i] > arr[i + 1])
                {
                    int temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                    swapped = true;
                    tot++;
                }
            }
            if (!swapped) break;
        }
        printf("Optimal train swapping takes %d swap(s).\n", tot);
    }
}

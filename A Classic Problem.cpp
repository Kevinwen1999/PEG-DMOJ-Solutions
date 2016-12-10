#include <bits/stdc++.h>
using namespace std;
int N, arr[3000010], K;
int useful[3000010]; //denote the number of subarrays that contain this element
priority_queue <int, vector <int>, greater<int> > mins;
priority_queue <int, vector <int>> maxs;
long long ans;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    for (int i = 0 ; i  < N; i++)
        cin>>arr[i];
    int startx = 0, endx = 0;
    for (; startx < N; startx++) // for every subarray starting with index startx
    {
        if (startx == endx)
        {
            useful[arr[endx]]++;
            mins.push(arr[endx]);
            maxs.push(arr[endx]);
            endx++;
        }
        while (useful[mins.top()] == 0) mins.pop();
        while (useful[maxs.top()] == 0) maxs.pop();
        while (endx < N && max(maxs.top(), arr[endx]) - min(mins.top(), arr[endx]) <= K)
        {
            useful[arr[endx]]++;
            mins.push(arr[endx]);
            maxs.push(arr[endx]);
            endx++;
        }
        useful[arr[startx]]--;
        ans += endx - startx;
    }
    cout<<ans<<"\n";
}

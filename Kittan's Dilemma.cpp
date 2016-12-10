#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M;
vector <int> good, bad;
long long psumg[100001], psumb[100001];
int main()
{
    cin>>N>>M;
    for (int i = 0 ; i < N; i++)
    {
        int s, p;
        cin>>s>>p;
        if (p==1) bad.push_back(s);
        else good.push_back(s);
    }
    sort(bad.begin(), bad.end());
    sort(good.begin(), good.end());
    for (int i = 1; i <= good.size(); i++)
        psumg[i] = good[i-1] + psumg[i-1];
    for (int i = 1 ; i <= bad.size(); i++)
        psumb[i] = bad[i-1] + psumb[i-1];
    int maxx = 0;
    for (int i = 0 ; i <= good.size(); i++)
    {
        long long rem = M - psumg[i];
        if (rem < 0) break;
        int l = 0, h = bad.size();
        while (l <= h)
        {
            int mid = l + (h-l) / 2;
            if (psumb[mid] <=rem)
                l = mid + 1;
            else
                h = mid - 1;
        }
        //cout<<"test:\n"<<rem<<" "<<i*2<<" "<<h<<"\n";
        maxx = max(maxx, i*2 + h);
    }
    cout<<maxx;
}

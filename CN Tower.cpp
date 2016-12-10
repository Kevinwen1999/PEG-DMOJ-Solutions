#include <bits/stdc++.h>
using namespace std;
int N;
string wtf;
vector <double> allp;
int main()
{
    cin>>N;
    for (int i = 0; i < N; i++)
    {
        cin>>wtf;
        double cur; cin>>cur;
        allp.push_back(cur);
    }
    sort(allp.begin(), allp.end());
    allp.erase(unique(allp.begin(), allp.end()), allp.end());
    N = allp.size();
    double ma = allp[0] - allp[N-1] + 360;
    for (int i = 0; i < N-1; i++)
    {
        ma = max(ma, allp[i+1]-allp[i]);
    }
    double result = (360.0-ma) / 360.0 * 72.0 * 60.0;
    result = ceil(result);
    cout<<result;
}

#include <iostream>
#include <deque>
#include <utility>
using namespace std;

int main()
{
    int N, D;
    cin>>N>>D;
    deque <pair <int,int> > buff;
    for (int i = 0; i < N; i++)
    {
        int val; cin>>val;
        while (!buff.empty() && i - buff.front().second > D) buff.pop_front();
        int minval = val;
        if (!buff.empty())
            minval += buff.front().first;
        while (!buff.empty() && buff.back().first >= minval) buff.pop_back();
        buff.push_back(make_pair(minval, i));
    }
    cout<<buff.back().first;
}

#include <iostream>
#include <cstring>
#include <utility>
#include <deque>
using namespace std;
int N, K;
long long pre[200010];
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    for (int i = 0 ; i < N; i++)
    {
        cin>>pre[i];
        pre[i+N] = pre[i];
        //if (i > 0) pre[i] += pre[i-1];
    }
    for (int i = 1; i < N+K; i++)
    {
        pre[i]+= pre[i-1];
    }
    deque <pair <long long, int> > mq;
    long long sum, maxx = pre[0];
    //mq.push_back(make_pair(0LL, -1));
    pair <long long ,int> cur;
    for (int i = 0 ; i < N+K; i++)
    {
        while (!mq.empty() && i - mq.front().second  > K)
            mq.pop_front();
        cur = mq.front();
        maxx = max(maxx, pre[i] - cur.first);
        cur = make_pair(pre[i], i);
        while (!mq.empty() && mq.back().first > cur.first)
            mq.pop_back();
        mq.push_back(cur);
    }
    cout<<maxx<<"\n";
}

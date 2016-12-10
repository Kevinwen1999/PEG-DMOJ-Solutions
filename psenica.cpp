#include <bits/stdc++.h>
using namespace std;
multiset<int> M;
set<int>S;
string win[2] = {"Mirko","Slavko"};
int N;
map <int, int> m;
deque <pair <int,int> > D;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for (int i = 0 ;i < N; i++)
    {
        int t; cin>>t;
        m[t]++;
        M.insert(t);
        S.insert(t);
    }
    for (set<int>::iterator it = S.begin(); it != S.end(); it++)
    {
        D.push_back({*it, m[*it]});
    }
    int cur = 1;
    while(D.size() >= 3)
    {
        pair <int, int> f = D.front(), b = D.back();
        if (f.second <= b.second)
        {
            D.pop_front();
            D.front().second += f.second;
            D.back().second -= f.second - 1;
            D[D.size()-2].second += f.second - 1;
            cur = 0;
        }
        else if (f.second > b.second)
        {
            D.pop_back();
            D.back().second += b.second;
            D.front().second -= b.second - 1;
            D[1].second += b.second - 1;
            cur = 1;
        }
        /*else
        {
            D.pop_front();
            D.front().second += f.second;
            D.back().second = ;
            cur = 0;
        }*/
    }
    cout<<win[cur]<<"\n";
    cout<<D.front().first<<" "<<D.back().first;
}

#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int N, M;
struct node
{
    long long first, second;
}p1;
bool cmp (node a, node b)
{
    return (a.first < b.first);
}

vector <node> all;
long long x, y;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for (int i = 0 ; i < M; i++)
    {
        cin>>x>>y;
        p1.first = y;
        p1.second = N-x+1;
        all.push_back(p1);
    }
    sort (all.begin(), all.end(),cmp);
    long long total = 0, top = 0;
    int index = 0;
    for (int col = 1; col <= N; col++)
    {
        while (index < all.size() && (all[index].first == col) )
        {
            top = max(top, all[index++].second);
        }
        total += top;
        if (top > 0) top--;
    }
    cout<<total<<"\n";
}

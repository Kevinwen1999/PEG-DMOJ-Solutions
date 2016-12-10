#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
struct node
{
    int price, freq;
    node (int x, int y) { price = x; freq = y;}
    bool operator< (const node &rhs) const
    {
        return (freq < rhs.freq) || ( (freq==rhs.freq) && (price < rhs.price) );
    }
};
int main()
{
    int N;
    cin>>N;
    vector <int> v;
    map <int,int> m;
    for (int i = 0 ,in ; i < N; i++)
    {
        cin>>in;
        v.push_back(in);
        m[in]++;
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    vector <node> all;
    for (int i = 0 ; i < v.size(); i++)
    {
        all.push_back(node(v[i],m[v[i]]));
    }
    sort(all.begin(),all.end());
    int la = all.size()-1;
    cout<<abs(all[0].price - all[la].price);
}

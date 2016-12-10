#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;
int N,a;
vector < int > numbers , d1,d2;
int b,c,d;
map <int,int> cnt;
int main()
{
    cin>>N;
    for (int i = 0 ; i < N; i++)
    {
        cin>>a;
        numbers.push_back(a);
        cnt[a]+=1;

    }
    sort(numbers.begin(),numbers.end());
    numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());
    int m1 = 0 ,m2 = 0;
    for (int i = 0 ; i < (int)numbers.size(); i++)
    {
        int cur = numbers[i];
        if (cnt[cur]>m1)
        {
            m2 = m1;
            m1 = cnt[cur];
        }
        else if (cnt[cur]>m2)
            m2 = cnt[cur];
    }
    for (int i = 0; i < (int)numbers.size(); i++)
    {
        if (cnt[numbers[i]] == m1)
            d1.push_back(numbers[i]);
        if (cnt[numbers[i]] == m2)
            d2.push_back(numbers[i]);
    }
    int ans = -1;
    for (int i = 0 ; i < (int)d1.size(); i++)
        for (int j = 0 ; j < (int)d2.size(); j++)
            ans = max(ans,abs(d1[i]-d2[j]));
    cout<<ans<<endl;
    return 0;
}

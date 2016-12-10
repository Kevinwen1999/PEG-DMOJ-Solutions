#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
int N, M, T;
struct people
{
    long long start; long long htime;
    bool operator<(const people &another) const
    {
        return start < another.start;
    }
} all[100001];
long long fastest,fastest2,dif,index,insertx;
multiset <long long> micro;
long long best = 0x3f3f3f3f;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M>>T;
    for (int i = 0 ; i < M; i++)
        cin>>all[i].start>>all[i].htime;
    sort (all,all+M);
    for (int i = 0 ; i < N; i++)
        micro.insert(0);
    for (int i = 0 ; i < M; i++)
    {
        multiset <long long>:: iterator it;
        it = (micro.upper_bound(all[i].start));
        fastest2 = *micro.begin();
        //cout<<"%%lower: "<<fastest<<" first: "<<fastest2<<endl;
        if (it == micro.begin())
        {
            micro.erase(micro.begin());
            insertx = fastest2+all[i].htime;
            micro.insert(insertx);
            //continue;
        }
        else
        {
            it--;
            fastest = *it;
            //cout<<"lower: "<<fastest<<" first: "<<fastest2<<endl;
            if (all[i].start- fastest2 >= T)
            {
                cout<<fastest2<<"\n";
                return 0;
            }
            micro.erase(it);
            insertx = all[i].start+all[i].htime;
            micro.insert(insertx);
        }
        /*std::cout << "myset contains:";
        for (std::set<long long>::iterator it=micro.begin(); it!=micro.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';*/
    }

    fastest = *micro.begin();
    cout<<fastest<<"\n";
}

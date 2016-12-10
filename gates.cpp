#include <bits/stdc++.h>
using namespace std;

int G, P;
int root[100009];
set <int> ss;

int main()
{
    cin>>G>>P;
    for (int i = 1; i <= G; i++)
        ss.insert(i);
    bool OK = true;
    int p, cnt = 0;
    set<int>::iterator lb;
    for (int i = 0; i < P; i++)
    {
        cin>>p;
        lb = ss.upper_bound(p);
        if (lb != ss.begin()&& OK)
        {
            ss.erase(--lb);
            cnt++;
        }
        else
            OK = false;
    }
    cout<<cnt<<"\n";
}

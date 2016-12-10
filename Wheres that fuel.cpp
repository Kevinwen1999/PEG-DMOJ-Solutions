#include <bits/stdc++.h>
using namespace std;
struct planet
{
    int v; int c;
    bool operator < (const planet& b) const
    {
        return (c) < (b.c);
    }
} cur;
int N;
vector <planet> all;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, P; cin>>N>>P;
    int start, np = 1;
    for (int i = 1; i <= N; i++)
    {
        cin>>cur.v>>cur.c;
        if (i==P) start = cur.v;
        else if (cur.v >= cur.c)
            all.push_back(cur);
    }
    sort(all.begin(), all.end());
    for (int i = 0; i < all.size(); i++)
    {
        //cout<<all[i].v<<" "<<all[i].c<<"\n";
        if (start >= all[i].c && start + all[i].v- all[i].c >=start)
        {
            start += all[i].v - all[i].c;
            np++;
        }
        else break;
    }
    cout<<start<<"\n"<<np;
}

#include <bits/stdc++.h>
using namespace std;
unordered_map <string , int> mp;
list <pair <int,double> > adj[501];
int N, E;
double v[501];
int main()
{
    cin>>N>>E;
    string a, b;
    double conv;
    for (int i = 0; i < N; i++)
    {
        cin>>a;
        mp[a] = i;
    }
    for (int i = 0; i < E; i++)
    {
        cin>>a>>b>>conv;
        adj[mp[a]].push_back({mp[b], conv});
    }
    queue < pair <int, double> > buff;
    buff.push({mp["APPLES"], 1.0});
    v[mp["APPLES"]] = (1.0);
    pair <int, double> u, ne;
    while (!buff.empty())
    {
        u = buff.front();
        buff.pop();
        if (u.first==mp["APPLES"] && u.second > 1.0 && ceil(u.second) == u.second)
        {
            cout<<"YA\n";
            return 0;
        }
        for (auto i : adj[u.first])
        {
            ne = {i.first, u.second * i.second};
            if (ne.second  <= v[ne.first]) continue;
            v[ne.first] = ne.second;
            buff.push(ne);
        }
    }
    cout<<"NAW\n";
    return 0;
}

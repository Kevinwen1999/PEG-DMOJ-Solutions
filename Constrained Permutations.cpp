#include <bits/stdc++.h>
using namespace std;
int N, K;
vector <int> forbid[11], all;
int main()
{
    cin>>N>>K;
    for (int i = 1; i <= N; i++)
        all.push_back(i);
    for (int i = 0; i < K; i++)
    {
        int a, b; cin>>a>>b;
        forbid[a].push_back(b);
    }
    int tot = 0;
    do
    {
        int mask = 0;
        bool OK = true;
        unordered_set<int> taken;
        for (int i : all)
        {
            if (!OK) break;
            for (int j : forbid[i])
            {
                if (taken.count(j)>0)
                {
                    OK = false;
                    break;
                }
            }
            taken.insert(i);
        }
        if (OK) tot++;
    }
    while (next_permutation(all.begin(),all.end()));
    cout<<tot;
}

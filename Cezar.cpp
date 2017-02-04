#include <bits/stdc++.h>
using namespace std;
vector <int> adj[30];
struct word
{
    string s;
    int id;
};
bool cmp(const word &a, const word &b)
{
    return a.id < b.id;
}
vector <word> wd;
vector <int> topo;
int state[30];
bool hasTopo = true;
char ans[26];
void dfs1(int cur)
{
    state[cur] = 1;
    for (auto i : adj[cur])
    {
        if (!state[i])
            dfs1(i);
        else if (state[i]==1)
        {
            hasTopo = false;
        }
    }
    state[cur] = 2;
    topo.push_back(cur);
}
int main()
{
    int N;
    cin>>N;
    for (int i = 0; i < N; i++)
    {
        string tmp; cin>>tmp;
        wd.push_back((word){tmp,0});
    }
    for (int i = 0, a; i < N; i++)
    {
        cin>>a;
        wd[--a].id = i;
    }
    sort(wd.begin(), wd.end(), cmp);
    for (int i = 0; i < N; i++)
    {
        for (int j = i+1; j < N; j++)
        {
            int diff = -1;
            for (int k = 0; k < min((int)wd[i].s.size(),(int)wd[j].s.size()); k++)
            {
                if (wd[i].s[k]!=wd[j].s[k])
                {
                    diff=k; break;
                }
            }
            if (~diff)
                adj[wd[i].s[diff]-'a'].push_back(wd[j].s[diff]-'a');
            else if (wd[i].s.size() > wd[j].s.size())
            {
                cout<<"NE\n"; return 0;
            }
        }
    }
    for (int i = 0; i < 26; i++)
        if (!state[i])
            dfs1(i);
    if (!hasTopo)
    {
        cout<<"NE\n"; return 0;
    }
    cout<<"DA\n";
    reverse(topo.begin(), topo.end());
    int st = 0;
    for (int i : topo)
        ans[i] = (char)(st++ + 'a');
    cout<<ans<<"\n";
}

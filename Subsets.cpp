#include <bits/stdc++.h>
using namespace std;
int M;
unordered_map <char, int> m;
char nm[60];
bool visited[60];
int tot;
vector <int> V[60];
set<char> s, allu;
void dfs(int cur)
{
    if (islower(nm[cur]))
        s.insert(nm[cur]);
    visited[cur] = true;
    for (int i : V[cur])
    {
        if (!visited[i])
            dfs(i);
    }
}
int main()
{
    cin>>M;
    for (int i = 0; i < M; i++)
    {
        string cont;
        char a, b;
        cin>>a>>cont>>b;
        if (isupper(a))
            allu.insert(a);
        if (isupper(b))
            allu.insert(b);
        if (m.count(a) ==0)
        {
            m[a] = tot;
            nm[tot++] = a;
        }
        if (m.count(b) ==0)
        {
            m[b] = tot;
            nm[tot++] = b;
        }
        V[m[a]].push_back(m[b]);
    }
    for (char cur : allu)
    {
        s.clear();
        memset(visited,0,sizeof visited);
        dfs(m[cur]);
        cout<<cur<<" = {";
        for (set<char>::iterator it = s.begin(); it != s.end(); it++)
        {
            if (it != s.begin())
                cout<<",";
            cout<<*it;
        }
        cout<<"}\n";
    }
}

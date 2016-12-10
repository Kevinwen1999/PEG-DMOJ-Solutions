#include <bits/stdc++.h>
using namespace std;
int N;
vector <int> s[10];
void tonode(string st)
{
    //cout<<st<<endl;
    for (int i = 0; i < N; i++)
        s[i].clear();
    for (int i = N-1; i >= 0; i--)
    {
        int idx = st[i] - '0';
        s[idx].push_back(i+1);
    }
}
bool mv(int u, int op)
{
    int o;
    if (op==1)
        o = -1;
    else
        o = 1;
    if (!s[u+o].empty()&&s[u].back()>s[u+o].back())
        return false;
    else
    {
        s[u+o].push_back(s[u].back());
        s[u].pop_back();
        return true;
    }
}
string tostring()
{
    string r;
    r.assign(N,'0');
    for (int i = 0; i < N; i++)
    {
        for (int j : s[i])
        {
            r[j-1] = i+'0';
        }
    }
    return r;
}
int main()
{
    while (cin>>N && N)
    {
        unordered_set <string> S;
        unordered_map <string, int> M;
        S.clear();
        string ini, gg;
        gg.assign(N,'0');
        for (int i = 0; i < N; i++)
            gg[i] = i + '0';
        ini.assign(N,'0');
        for (int i = 0; i < N; i++)
        {
            int a; cin>>a;
            s[i].push_back(a);
            ini[a-1] = i+'0';
        }
        S.insert(ini);
        queue<string> buff;
        buff.push(ini);
        M[ini] = 0;
        bool OK = false;
        //cout<<"up "<<ini<<" "<<gg<<endl;
        while(!buff.empty())
        {
            string cs = buff.front();
            buff.pop();
            //cout<<"starting at state: "<<cs<<"\n";
            if (cs == gg)
            {
                cout<<"\n"<<M[cs]<<"\n";
                OK = true;
                break;
            }
            tonode(cs);
            for (int i = 0; i < N; i++)
            {
                //cout<<"checking "<<i<<" stack\n";
                if (s[i].empty())
                {
                    //cout<<"this stack is empty\n";
                    continue;
                }
                // adjacent left
                if (i > 0)
                {
                    if (mv(i,1))
                    {
                        string nx = tostring();
                        if (!S.count(nx))
                        {
                            //cout<<"created "<<nx<<"\n";
                            S.insert(nx);
                            M[nx] = M[cs] + 1;
                            buff.push(nx);
                        }
                        tonode(cs);
                    }
                }
                if (i < N-1)
                {
                    if (mv(i,0))
                    {
                        string nx = tostring();
                        if (!S.count(nx))
                        {
                            //cout<<"created "<<nx<<"\n";
                            S.insert(nx);
                            M[nx] = M[cs] + 1;
                            buff.push(nx);
                        }
                        tonode(cs);
                    }
                }
            }
        }
        if (!OK) cout<<"IMPOSSIBLE\n";
    }
}

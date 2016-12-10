#include <bits/stdc++.h>
using namespace std;
map <char, char> m;
char ne, cur;
string in, tmp;
vector <string> all;
int tot, N;
void change()
{
    for (int i = 0; i < tmp.size(); i++)
    {
        tmp[i] = m[tmp[i]];
    }
}
int main()
{
    for (cur = 'A'; cur <= 'Z'; cur++)
    {
        cin>>ne;
        m[cur] = ne;
    }
    cur = '_';
    cin>>ne;
    m[cur] = ne;
    cin>>N;
    cin>>in;
    //cout<<in<<endl;
    tmp = in;
    all.push_back(in);
    change();
    tot=1;
    while (true)
    {
        if (tmp == in) break;
        //cout<<tmp<<endl;
        all.push_back(tmp);
        tot++;
        change();
    }
    cout<<all[N%tot]<<endl;
}

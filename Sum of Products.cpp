#include <bits/stdc++.h>
using namespace std;
string in;
int ptr;
vector <string> gen(string ori)
{
    vector <string> fin;
    if (str.size()==0) return fin;
    if (str.size()==1)
    {
        fin.push_back(ori);
        return fin;
    }
    int l= 0, degree = 0;
    vector <string> buff;
    for (int r = 0; r < ori.size(); r++)
    {
        if (ori[r]=='(')
            degree++;
        else if (ori[r] == ')')
            degree--;
        if (degree == 0)
        {
            if (ori[r] == '+')
            {
                for (int i = 0; i < buff.size(); i++)
                    fin.push_back(buff[i]);
                buff.clear();
                l = r + 1;
                continue;
            }
            vector <string> rbuff, tmp;
            if (ori[r] == ')')
            {
                tmp = gen(ori.substr(l+1, r-l-1));
                for (int i = 0; i < tmp.size(); i++)
                    rbuff.push_back(tmp[i]);
            }
            else
            {
                tmp = gen(ori.substr(l, r-l+1));
                for (int i = 0; i < tmp.size(); i++)
                    rbuff.push_back(tmp[i]);
            }
        }
    }
}
int main()
{
    int T; cin>>T;
    while (T--)
    {
        cin>>in;
        ptr = 0;
        vector <string> fin = gen(in);
    }
}

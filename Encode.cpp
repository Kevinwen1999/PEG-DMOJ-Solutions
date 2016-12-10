#include <bits/stdc++.h>
using namespace std;
string u = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string l = "abcdefghijklmnopqrstuvwxyz";
int main()
{
    int N;
    cin>>N;
    //N = -N;
    string cur;
    while (cin>>cur)
    {
        string o = cur;
        for (int i = 0; i < cur.size(); i++)
        {
            char c = cur[i];
            if (isupper(c))
            {
                int idx = c - 'A';
                int nex;
                if (N < 0)
                    nex = (idx-N) % 26;
                else
                    nex = (idx%26 - (N%26) + 26) % 26;
                o[i] = u[nex];
            }
            else
            {
                int idx = c - 'a';
                int nex;
                if (N < 0)
                    nex = (idx-N) % 26;
                else
                    nex = (idx%26 - (N%26) + 26) % 26;
                o[i] = l[nex];
            }
        }
        cout<<o<<" ";
    }
}

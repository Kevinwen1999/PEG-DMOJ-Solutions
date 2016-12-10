#include <bits/stdc++.h>
using namespace std;
int ori[6];
set <string> alls;
/*1 1 2 2 3 3
1 3 3 2 2 1
0 1 2 3 4 5*/
int main()
{
    int N; cin>>N;
    for (int i = 0; i < N; i++)
    {
        int minn = 100000000, id;
        for (int j = 0; j < 6; j++)
        {
            cin>>ori[j];
            if (ori[j] < minn)
            {
                minn = ori[j];
                id = j;
            }
        }
        bool OK = true;
        string conv = "", rev = "", fnl;
        for (int a = 0; a < 6 && OK; a++)
        {
            if (ori[a] == minn)
            {
                int idx = a;
                conv = "", rev = "";
                for (int j = 0; j < 6; j++)
                {
                    conv += to_string(ori[(idx+j)%6]) + " ";
                }
                for (int j = 0; j < 6; j++)
                {
                    rev += to_string(ori[(idx-j+6)%6]) +  " ";
                }
                fnl = min(conv, rev);
                if (alls.count(fnl))
                {
                    OK = false;
                }
            }
        }
        if (OK)
            alls.insert(fnl);
    }
    if (alls.size() == N)
        cout<<"No two snowflakes are alike.\n";
    else
        cout<<"Twin snowflakes found.\n";
}

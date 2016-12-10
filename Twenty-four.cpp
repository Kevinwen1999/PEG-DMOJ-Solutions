#include <iostream>
#include <cstring>
using namespace std;
int c[4];
bool used[4];
int ANS;
void recur(int nused, int ans)
{
    if (nused == 4)
    {
        if (ans <= 24)
        {
            ANS = max(ANS, ans);
        }
    }
    else if (ans == -1)
    {
        for (int i = 0 ; i < 4; i++)
        {
            if (!used[i])
            {
                used[i] = true;
                recur(1,c[i]);
                used[i] = false;
            }
        }
    }
    else if (nused == 2)
    {
        int a = 0, b = 0,cc = 1, d = 1; bool one = false,pro = true;
        for (int i = 0 ; i < 4; i++)
        {
            if (!used[i])
            {
                used[i] = true;
                recur(nused + 1, ans + c[i]);
                recur(nused + 1, ans - c[i]);
                recur(nused + 1, ans * c[i]);
                if (ans % c[i] == 0)
                    recur(nused + 1, ans / c[i]);
                used[i] = false;
                a+=c[i];
                if (!one) b = c[i]; else b-=c[i];
                cc*=c[i];
                if (!one) d = c[i]; else if (d % c[i]==0) d/= c[i]; else pro = false;
                one = true;
            }
        }
        recur(4,ans * a);
        recur(4,ans * b);
        if (a!=0 && ans % a ==0 ) recur(4,ans / a);
        if (b!=0 && ans % b ==0 ) recur(4,ans / b);
        recur(4,ans + cc);
        if (pro == true)recur(4,ans + d);
        recur(4,ans - cc);
        if (pro == true)recur(4,ans - d);
    }
    else
    {
        for (int i = 0 ; i < 4; i++)
        {
            if (!used[i])
            {
                used[i] = true;
                recur(nused + 1, ans + c[i]);
                recur(nused + 1, ans - c[i]);
                recur(nused + 1, ans * c[i]);
                if (ans % c[i] == 0)
                    recur(nused + 1, ans / c[i]);
                used[i] = false;
            }
        }
    }
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        for (int i = 0 ; i < 4; i++)
            cin>>c[i];
        memset(used, 0, sizeof used);
        ANS = 0;
        recur(0,-1);
        cout<<ANS<<endl;
    }
}

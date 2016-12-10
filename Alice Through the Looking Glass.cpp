#include <bits/stdc++.h>
using namespace std;

bool iscry(int m, int x, int y)
{
    if (m==0) return false;
    int nx = x / pow(5,m-1);
    int ny = y / pow(5,m-1);
    if (nx > 0 && nx < 4 && ny ==0) return true;
    if (nx==2 && ny == 1) return true;
    if ( ( (nx==1||nx==3)&&ny==1) || (nx == 2 && ny == 2) )
        return iscry(m-1, x % (int)pow(5,m-1), y % (int)pow(5,m-1));
    return false;
}
int main()
{
    int T; cin>>T;
    int m, x, y;
    while (T--)
    {
        cin>>m>>x>>y;
        if (iscry(m,x,y))
            cout<<"crystal\n";
        else cout<<"empty\n";
    }
}

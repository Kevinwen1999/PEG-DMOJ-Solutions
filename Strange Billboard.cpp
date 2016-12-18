#include <bits/stdc++.h>
using namespace std;
int R, C;
int ori[17][17], tmp[17][17];
void flip(int i, int j)
{
    tmp[i][j] ^= 1;
    if (i>0) tmp[i-1][j]^=1;
    if (i<R-1) tmp[i+1][j]^=1;
    if (j>0) tmp[i][j-1]^=1;
    if (j<C-1) tmp[i][j+1]^=1;
}
void init()
{
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            tmp[i][j] = ori[i][j];
}
int main()
{
    cin>>R>>C;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            char t; cin>>t;
            if (t=='X')
                ori[i][j] = 1;
        }
    }
    int ans = 0x3f3f3f3f;
    for (int mask = 0; mask < (1<<R); mask++)
    {
        init();
        bool OK = true;
        int tot = 0;
        for (int i = 0; i < R; i++)
            if (mask & (1<<i))
                flip(i,0), tot+=1;
        for (int j = 1; j < C; j++)
        {
            for (int i = 0; i < R; i++)
            {
                if (tmp[i][j-1])
                    flip(i,j), tot+=1;
            }
        }
        for (int i = 0; i < R&OK; i++)
        {
            for (int j  =0; j <C&OK; j++)
            {
                if (tmp[i][j])
                    OK = false;
            }
        }
        if (OK) ans = min(ans, tot);
    }
    if (ans == 0x3f3f3f3f)
        cout<<"Damaged billboard.\n";
    else
        printf("You have to tap %d tiles.\n", ans);
}

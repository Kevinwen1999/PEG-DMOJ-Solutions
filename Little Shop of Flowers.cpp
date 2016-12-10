#include <bits/stdc++.h>
using namespace std;
int R, C;
int grid[110][110];
int maxa[110][110], idx[110][110];
void print (int cur, int id)
{
    if (cur > 0)
        print(cur - 1, idx[cur-1][id-1]);
    cout<<idx[cur][id]+1<<" ";
}
int main()
{
    cin>>R>>C;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin>>grid[i][j];
    for (int i = 0; i < C; i++)
    {
        if (i==0) { maxa[0][0] = grid[0][0]; idx[0][0] = 0; continue;}
        if (grid[0][i] > maxa[0][i-1])
        {
            maxa[0][i] = grid[0][i];
            idx[0][i] = i;
        }
        else
        {
            maxa[0][i] = maxa[0][i-1];
            idx[0][i] = idx[0][i-1];
        }
    }
    for (int i = 1; i < R; i++)
    {
        for (int j = i; j < C; j++)
        {
            if (j==i)
            {
                maxa[i][j] = grid[i][j] + maxa[i-1][j-1];
                idx[i][j] = j;
                continue;
            }
            int nw = grid[i][j] + maxa[i-1][j-1];
            if (nw > maxa[i][j-1])
            {
                maxa[i][j] = nw;
                idx[i][j] = j;
            }
            else
            {
                maxa[i][j] = maxa[i][j-1];
                idx[i][j] = idx[i][j-1];
            }
        }
    }
    int mx = 0, midx = 0;
    for (int i = R-1; i < C; i++)
    {
        if (maxa[R-1][i] > mx)
        {
            mx = maxa[R-1][i];
            midx = i;
        }
    }
    cout<<mx<<"\n";
    print(R-1, midx);
}

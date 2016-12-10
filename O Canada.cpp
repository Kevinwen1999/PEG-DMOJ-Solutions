#include <bits/stdc++.h>
using namespace std;
int N,G;
char cur[20];
int grid[10010][11][11];
pair <int,int> cg[10010];
bool check(int a, int b)
{
    return cg[a] == cg[b];
}
int main()
{
    cin>>N>>G;
    for (int i = 0; i < G; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin>>cur;
            for (int k = 0; k < N; k++)
            {
                if (cur[k]=='R')
                    grid[i][j][k]++;
            }
        }
    }
    for (int i = 0;  i < G; i++)
    {
        for (int j = 0; j < N-1; j++)
        {
            for (int k = 0; k < N-1; k++)
            {
                if (grid[i][j][k] == 1)
                {
                    grid[i][j][k] = 0;
                    grid[i][j+1][k] = 1 - grid[i][j+1][k];
                    grid[i][j][k+1] = 1 - grid[i][j][k+1];
                    grid[i][j+1][k+1] = 1 - grid[i][j+1][k+1];
                }
            }
        }
    }
    for (int i = 0; i < G; i++)
    {
        int bottom = 0, right = 0;
        for (int j = 0; j < N; j++)
        {
            if (grid[i][N-1][j])
                bottom ^= (1<<j);
            if (grid[i][j][N-1])
                right ^= (1<<j);
        }
        cg[i] = {bottom,right};
    }
    int tot = 0;
    for (int i = 0; i < G; i++)
    {
        for (int j = i+1; j < G; j++)
        {
            if (check(i,j))
                tot++;
        }
    }
    cout<<tot;
}

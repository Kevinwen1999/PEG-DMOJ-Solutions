#include <bits/stdc++.h>
#define MAXN 360
using namespace std;
int R, C, M;
vector <int> all;
bool grid[MAXN][MAXN][MAXN];
int sqtot[MAXN];
void dfs(int sl, int i, int j)
{
    if (grid[sl][i][j])
    {
        grid[sl][i][j] = false;
        dfs(sl+1, i, j);
        dfs(sl+1, i-1, j);
        dfs(sl+1, i, j-1);
        dfs(sl+1, i-1, j-1);
        sqtot[sl]--;
        if (!sqtot[sl])
            while (all.back()>=sl)
                all.pop_back();
    }
}
int main()
{
     cin>>R>>C>>M;
     all.push_back(0);
     int lmax = min(R, C);
     for (int i = 0; i < lmax; i++)
     {
         for (int j = 1; j+i <= R; j++)
         {
             for (int k = 1; k+i <= C; k++)
             {
                 grid[i+1][j][k] = true;
                 sqtot[i+1]++;
             }
         }
         all.push_back(i+1);
     }
     for (int i = 0, a, b; i < M; i++)
     {
         cin>>a>>b;
         dfs(1,a,b);
         cout<<all.back()<<"\n";
     }
}

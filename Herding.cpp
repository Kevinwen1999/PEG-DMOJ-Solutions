#include <bits/stdc++.h>
using namespace std;
int N, M;
char g[1010][1010];
bool v[1010][1010];
int c[1010][1010];
int di[4] = {-1,1,0,0};
int dj[4] = {0,0,1,-1};
unordered_map <char, int> mp;
int dfs(int i, int j, int clr)
{
    if (v[i][j])
    {
        if (!c[i][j])
            return c[i][j] = clr;
        else
            return c[i][j];
    }
    v[i][j] = true;
    int d = mp[g[i][j]];
    int ni = i + di[d], nj = j + dj[d];
    return c[i][j] = dfs(ni,nj, clr);
}
int tot = 0;
int main()
{
    mp['N'] = 0; mp['S'] = 1; mp['E'] = 2; mp['W'] = 3;
    cin>>N>>M;
    for (int i = 0; i < N; i++)
    {
        cin>>g[i];
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (!v[i][j])
            {
                tot++;
                int rc = dfs(i,j,tot);
                if (tot != rc)
                    tot--;
            }
        }
    }
    cout<<tot<<"\n";
}

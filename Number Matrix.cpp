#include <bits/stdc++.h>
using namespace std;
int N, M;
int grid[110][110];
bool allowed[10];
bool visited[110][110];
int di[4] = {1,-1,0,0};
int dj[4] = {0,0,1,-1};
int main()
{
    cin>>N>>M;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin>>grid[i][j];
        }
    }
    for (int i = 0; i <= 9; i++)
    {
        for (int j = i; j <= 9; j++)
        {
            for (int k = j; k <= 9; k++)
            {
                allowed[i] = true;
                allowed[j] = true;
                allowed[k] = true;
                queue <pair <int,int> > buff;
                memset(visited, 0, sizeof visited);
                for (int l = 0; l < N; l++)
                {
                    if (allowed[grid[0][l]])
                    {
                        visited[0][l] = true;
                        buff.push({0,l});
                    }
                }
                while (!buff.empty())
                {
                    pair <int,int> cur = buff.front();
                    buff.pop();
                    if (cur.first == M-1)
                    {
                        cout<<i<<" "<<j<<" "<<k<<"\n";
                        return 0;
                    }
                    for (int d = 0; d < 4; d++)
                    {
                        int ni = cur.first + di[d];
                        int nj = cur.second + dj[d];
                        if (ni < 0 || nj < 0 || ni >= M || nj >= N)
                            continue;
                        if (visited[ni][nj] || !allowed[grid[ni][nj]])
                            continue;
                        visited[ni][nj] = true;
                        buff.push({ni,nj});
                    }
                }
                allowed[k] = 0;
                allowed[j] = 0;
                allowed[i] = 0;
            }
        }
    }
    cout<<"-1 -1 -1\n";
}

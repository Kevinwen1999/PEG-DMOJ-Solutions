#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#define MAXN 11
#define INF 0x3f3f3f3f
using namespace std;
int grid[MAXN][MAXN];
int di[4] = {1,0,-1,0};
int dj[4] = {0,1,0,-1};
int C, R;
int si, sj, ei, ej;
int cost[MAXN][MAXN], dist[MAXN][MAXN]; // dist is how many tree cut
bool done[MAXN][MAXN];
int edist(int i, int j)
{
    return (i-si)*(i*si) + (j-sj)*(j-sj);
}
void spfa()
{
    queue <pair <int,int> > buff;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cost[i][j] = INF;
            dist[i][j] = INF;
            done[i][j] = false;
        }
    }
    cost[si][sj] = 0;
    dist[si][sj] = 0;
    done[si][sj] = true;
    buff.push(make_pair(si,sj));
    int ci, cj, ni, nj;
    pair <int,int> cur;
    while (!buff.empty())
    {
        cur = buff.front();
        buff.pop();
        ci = cur.first; cj = cur.second;
        done[ci][cj] = false;
        for (int d = 0; d < 4; d++)
        {
            ni = ci + di[d]; nj = cj + dj[d];
            if (ni < 0 || nj < 0 || ni >= R || nj >= C || cost[ni][nj] < cost[ci][cj] + grid[ni][nj])
                continue;
            if (cost[ni][nj] == cost[ci][cj] + grid[ni][nj] && dist[ni][nj] <= dist[ci][cj] + (grid[ni][nj] == 0 ? 0 : 1))
                continue;
            cost[ni][nj] = cost[ci][cj] + grid[ni][nj];
            dist[ni][nj] = dist[ci][cj] + (grid[ni][nj] == 0 ? 0 : 1);
            if (!done[ni][nj])
            {
                done[ni][nj] = true;
                buff.push(make_pair(ni,nj));
            }
        }
    }
}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>R>>C;
    int largest = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            char cur; cin>>cur;
            if (cur == 'X')
            {
                si = i; sj = j;
                grid[i][j] = 0;
            }
            else if (cur == '.')
                grid[i][j] = 0;
            else
                grid[i][j] = cur - '0';
            largest = max(largest, grid[i][j]);
        }
    }
    int maxdist = 0x3f3f3f3f;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (grid[i][j] == largest && edist(i,j) < maxdist)
            {
                maxdist = edist(i,j);
                ei = i; ej = j;
            }
        }
    }
    spfa();
    cout<<dist[ei][ej]-1<<endl;
}
